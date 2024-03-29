#include "mainwindow.h"
#include "fontawesomeicons.h"





MainWindow::MainWindow(QWidget* parent /*= nullptr*/) : QMainWindow(parent)
{
	setWindowTitle("Merge Content");
	setGeometry(100, 100, 1280, 720);
	// Create QSettings object
	settings = new QSettings("beyond", "Merge Content", this);
	// Create file system model
	model = new QFileSystemModel(this);
	model->setRootPath(QDir::homePath());
	model->setNameFilters(QStringList() << "*.*"); // Show all files
	model->setNameFilterDisables(false); // Enable filtering

	// Create tree view
	treeView = new QTreeView(this);
	treeView->setModel(model);
	treeView->setRootIndex(model->index(QDir::homePath()));
	treeView->setSelectionMode(QAbstractItemView::ExtendedSelection); // Multi-select mode
	treeView->setColumnWidth(0, 300); // Set Name column width
	connect(treeView, &QTreeView::clicked, this, &MainWindow::onTreeViewClicked);

	

	// Create drive selector
	driveSelector = new QComboBox(this);

	// Get a list of available drives
	QList<QStorageInfo> drives = QStorageInfo::mountedVolumes();

	// Add drives to the combo box
	for (const QStorageInfo& drive : drives) {
		if (drive.isValid() && drive.isReady()) {
			driveSelector->addItem(drive.rootPath());
		}
	}
	connect(driveSelector, &QComboBox::currentTextChanged, this, &MainWindow::onUpdateRootPath);

	// Create path input
	pathInput = new QLineEdit(this);
	pathInput->setText(QDir::homePath());
	connect(pathInput, &QLineEdit::returnPressed, this, &MainWindow::onUpdateRootPath);

	// Create merge button
	mergeButton = new QPushButton("Merge Files", this);
	auto f = mergeButton->font();
	f.setPointSize(12);
	connect(mergeButton, &QPushButton::clicked, this, &MainWindow::mergeFiles);
	mergeButton->setEnabled(false); // Initially disabled
	mergeButton->setMinimumSize(QSize(200, 30));
	mergeButton->setMaximumSize(QSize(200, 30));
	mergeButton->setFont(f);

	// Create copy to clipboard button
	copyButton = new QPushButton("Copy to Clipboard", this);
	connect(copyButton, &QPushButton::clicked, this, &MainWindow::copyToClipboard);
	copyButton->setEnabled(false); // Initially disabled
	copyButton->setMinimumSize(QSize(200, 30));
	copyButton->setMaximumSize(QSize(200, 30));
	copyButton->setFont(f);
	// Create prefix input
	prefixLabel = new QLabel("Prefix:", this);
	prefixInput = new QLineEdit(this);
	prefixInput->setText("// {file_path}");

	// Create extension filter input
	extensionLabel = new QLabel("Extensions (separated by ;):", this);
	extensionInput = new QLineEdit(this);
	extensionInput->setText("txt;py;md");
	connect(extensionInput, &QLineEdit::textChanged, this, &MainWindow::updateNameFilters);

	// Create reset root path button
	resetButton = new QPushButton("Update", this);
	connect(resetButton, &QPushButton::clicked, this, &MainWindow::resetRootPath);
	resetButton->setEnabled(false); // Initially disabled

	
	// Create back and forward buttons
	backButton = new QPushButton("", this);
	backButton->setFont(FontAwesomeIcons::Instance().getFont());
	backButton->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_arrow_left));
	forwardButton = new QPushButton("", this);
	forwardButton->setFont(FontAwesomeIcons::Instance().getFont());
	forwardButton->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_arrow_right));
	upButton = new QPushButton("", this);
	upButton->setFont(FontAwesomeIcons::Instance().getFont());
	upButton->setText(FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_chevron_up));
	connect(upButton, &QPushButton::clicked, this, &MainWindow::onUpButtonClicked);


	connect(backButton, &QPushButton::clicked, this, &MainWindow::back);
	connect(forwardButton, &QPushButton::clicked, this, &MainWindow::forward);
	//backButton->setEnabled(false); // Initially disabled
	//forwardButton->setEnabled(false); // Initially disabled

	previewText = new QTextEdit(this);
	previewText->setReadOnly(true);

	// Create main layout
	QWidget* centralWidget = new QWidget(this);
	QVBoxLayout* mainLayout = new QVBoxLayout;
	QHBoxLayout* filterLayout = new QHBoxLayout;
	QHBoxLayout* pathLayout = new QHBoxLayout;
	QHBoxLayout* mainList = new QHBoxLayout;
	QHBoxLayout* opList = new QHBoxLayout;

	pathLayout->addWidget(backButton);
	pathLayout->addWidget(forwardButton);
	pathLayout->addWidget(driveSelector);
	pathLayout->addWidget(upButton);
	
	pathLayout->addWidget(pathInput);
	pathLayout->addWidget(resetButton);
	filterLayout->addWidget(prefixLabel);
	filterLayout->addWidget(prefixInput);
	filterLayout->addWidget(extensionLabel);
	filterLayout->addWidget(extensionInput);
	mainList->addWidget(treeView);
	mainList->addWidget(previewText);
	mainLayout->addLayout(pathLayout);
	mainLayout->addLayout(mainList);
	mainLayout->addLayout(filterLayout);
	mainLayout->addLayout(opList);
	opList->addWidget(copyButton);
	opList->addWidget(mergeButton);
	centralWidget->setLayout(mainLayout);
	setCentralWidget(centralWidget);


	setupFavoritesMenu();

	// Load saved settings
	loadSettings();

	pathHistory << model->rootPath();
	pathHistoryIndex = 0;
	updateButtonStatus();
}

void MainWindow::updateNameFilters()
{
	QStringList extensions = extensionInput->text().split(";");
	QStringList nameFilters;
	for (const QString& ext : extensions) {
		nameFilters << QString("*.").append(ext);
	}
	model->setNameFilters(nameFilters);

	// Save extensions setting
	settings->setValue("extensions", extensionInput->text());
}


void MainWindow::setupFavoritesMenu()
{
	favoritesMenu = menuBar()->addMenu(tr("&Favorites"));

	QAction* addToFavoritesAction = new QAction(tr("Add To Favorites"), this);
	connect(addToFavoritesAction, &QAction::triggered, this, &MainWindow::addToFavorites);
	favoritesMenu->addAction(addToFavoritesAction);

	favoritesMenu->addSeparator();

	// 动态加载收藏夹
	//updateFavoritesMenu();
}

void MainWindow::addToFavorites()
{
	QString currentPath = pathInput->text();
	QVariantList favorites = settings->value("favorites").toList();
	if (!favorites.contains(currentPath)) {
		favorites.append(currentPath);
		settings->setValue("favorites", favorites);
		updateFavoritesMenu(); // 更新菜单
	}
}

void MainWindow::updateFavoritesMenu()
{


	// 清除现有的动作，除了"添加到收藏夹"和分隔符
	favoritesMenu->clear();

	QAction* addToFavoritesAction = new QAction(tr("Add To Favorites"), this);
	connect(addToFavoritesAction, &QAction::triggered, this, &MainWindow::addToFavorites);
	favoritesMenu->addAction(addToFavoritesAction);

	favoritesMenu->addSeparator();

	// 重新加载收藏夹
	QVariant storedFavorites = settings->value("favorites");

	QVariantList favorites = storedFavorites.isValid() ? storedFavorites.toList() : QVariantList();
	for (const QVariant& favorite : favorites) {
        QAction* action = new QAction(favorite.toString(), this);
        connect(action, &QAction::triggered, this, [=]() {
            pathInput->setText(favorite.toString());
            onUpdateRootPath(); // 更新根路径
            });
        favoritesMenu->addAction(action);
    }
}


void MainWindow::onTreeViewClicked(const QModelIndex& index)
{
	QModelIndexList selectedIndexes = treeView->selectionModel()->selectedIndexes();
	// Use a QList to store the filtered indexes
	QList<QModelIndex> filteredIndexes;

	// Iterate through the selected indexes
	for (const QModelIndex& index : selectedIndexes) {
		// Check if the index belongs to the Name column (column 0)
		if (index.column() == 0) {
			filteredIndexes.append(index); // Add the index to the filtered list
		}
	}

	if (filteredIndexes.isEmpty()) {
		mergeButton->setEnabled(false);
		copyButton->setEnabled(false);
		resetButton->setEnabled(false);
		return;
	}

	if (filteredIndexes.size() == 1) {
		const QModelIndex& index = filteredIndexes.first();
		if (model->isDir(index)) {
			resetButton->setEnabled(true);
		}
		else {
			QString filePath = model->filePath(index);
			previewFile(filePath);
			copyButton->setEnabled(true);
			resetButton->setEnabled(false);
		}
		return;
	}

	resetButton->setEnabled(false);
	bool hasFile = false;
	for (const QModelIndex& index : filteredIndexes) {
		if (!model->isDir(index)) {
			hasFile = true;
			break;
		}
	}
	if (hasFile) {
		mergeButton->setEnabled(true);
		copyButton->setEnabled(true);
		// Try to preview if selected item is a file
		QString filePath = model->filePath(filteredIndexes.first());
		previewFile(filePath);
	}
}

void MainWindow::previewFile(const QString& filepath)
{
	QFile file(filepath);
	if (!file.open(QIODevice::ReadOnly)) {
		previewText->setText("Cannot open file.");
		return;
	}

	QByteArray rawData = file.readAll();
	//QChardet::Encoding encoding = QChardet::detect(rawData);
	//QString content = QString::fromLatin1(rawData.data(), rawData.size()).toUtf8();
	QString content = QString::fromLocal8Bit(rawData.data(), rawData.size());

	previewText->setText(content); // Show preview
}

void MainWindow::resetRootPath()
{
	QModelIndexList selectedIndexes = treeView->selectionModel()->selectedIndexes();
	QList<QModelIndex> filteredIndexes;

	// Iterate through the selected indexes
	for (const QModelIndex& index : selectedIndexes) {
		// Check if the index belongs to the Name column (column 0)
		if (index.column() == 0) {
			filteredIndexes.append(index); // Add the index to the filtered list
		}
	}

	if (filteredIndexes.size() == 1) {
		const QModelIndex& index = filteredIndexes.first();
		if (model->isDir(index)) {
			QString path = model->filePath(index);
			updateRootPath(path);
		}
	}
}


void MainWindow::onUpButtonClicked()
{
	QDir dir(model->rootPath());
	if (dir.cdUp()) {
		QString path = dir.absolutePath();
		updateRootPath(path);
		//upButton->setEnabled(QDir(path).rootPath() != path);
	}
}

void MainWindow::onUpdateRootPath()
{
	QString path = sender() == driveSelector ? driveSelector->currentText() : pathInput->text();
	if (path == model->rootPath()) {
		return;
	}
	updateRootPath(path);
}

void MainWindow::updateRootPath(const QString& path)
{
	model->setRootPath(path);
	treeView->setRootIndex(model->index(path));
	pathInput->setText(path); // Update path input

	// Update path history
	pathHistory = pathHistory.mid(0, pathHistoryIndex + 1);
	pathHistory << path;
	pathHistoryIndex++;

	updateButtonStatus();

	// Save root_path setting
	settings->setValue("root_path", path);
}

void MainWindow::mergeFiles()
{
	QString outputFile = QFileDialog::getSaveFileName(this, "Save Merged File", QDir::homePath(), "Text Files (*.txt)");
	if (outputFile.isEmpty()) {
		return;
	}

	updateMerge();

	QFile mergedFile(outputFile);
	if (!mergedFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
		return;
	}

	QTextStream out(&mergedFile);
	out << mergedContent << "\n\n";
}

void MainWindow::updateMerge()
{
	QModelIndexList selectedIndexes = treeView->selectionModel()->selectedIndexes();
	QStringList selectedFiles;
	for (const QModelIndex& index : selectedIndexes) {
		if (index.column() != 0 || model->isDir(index)) { // Keep only Name column indexes
			continue;
		}
		QString filePath = model->filePath(index);
		selectedFiles << filePath;
	}

	if (selectedFiles.isEmpty()) {
		return;
	}

	QString prefix = prefixInput->text().arg("{file_path}");
	mergedContent.clear();
	for (const QString& filePath : selectedFiles) {
		mergedContent += prefix.arg(filePath) + "\n";
		QFile file(filePath);
		if (!file.open(QIODevice::ReadOnly)) {
			continue;
		}

		QByteArray rawData = file.readAll();
		//QChardet::Encoding encoding = QChardet::detect(rawData);
		QString content = QString::fromLocal8Bit(rawData.data(), rawData.size());

		mergedContent += content + "\n\n\n";
	}
}

void MainWindow::loadSettings()
{
	// Load saved root_path setting
	QString rootPath = settings->value("root_path", QDir::homePath()).toString();
	model->setRootPath(rootPath);
	treeView->setRootIndex(model->index(rootPath));
	pathInput->setText(rootPath);

	// Load saved extensions setting
	QString extensions = settings->value("extensions", "txt;py;md").toString();
	extensionInput->setText(extensions);
	QStringList nameFilters;
	for (const QString& ext : extensions.split(";")) {
		nameFilters << QString("*.").append(ext);
	}
	model->setNameFilters(nameFilters);

	updateFavoritesMenu();
}
