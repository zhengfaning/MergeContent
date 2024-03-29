#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFontDatabase>
#include <QApplication>
#include <QMainWindow>
#include <QFileSystemModel>
#include <QTreeView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QFileDialog>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QComboBox>
#include <QTextEdit>
#include <QSettings>
#include <QClipboard>
#include <QFile>
#include <QTextStream>
#include <QStorageInfo>
#include <QDebug>
#include <QMenuBar>
#include <QAction>
#include <QSettings>
#include <QMessageBox>
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);

private slots:
    void updateNameFilters();

    void onTreeViewClicked(const QModelIndex& index);

    void previewFile(const QString& filepath);

    void resetRootPath();

    void onUpButtonClicked();
    void onUpdateRootPath();

    void updateRootPath(const QString& path);

    void updateButtonStatus() {
        // Update back and forward button states
        backButton->setEnabled(pathHistoryIndex > 0);
        forwardButton->setEnabled(pathHistoryIndex < pathHistory.size() - 1);
		QDir dir(model->rootPath());
        upButton->setEnabled(dir.cdUp());
    }

    void back() {
        if (pathHistoryIndex > 0) {
            pathHistoryIndex--;
            QString path = pathHistory[pathHistoryIndex];
            model->setRootPath(path);
            treeView->setRootIndex(model->index(path));
            pathInput->setText(path); // Update path input

            updateButtonStatus();
        }
    }

    void forward() {
        if (pathHistoryIndex < pathHistory.size() - 1) {
            pathHistoryIndex++;
            QString path = pathHistory[pathHistoryIndex];
            model->setRootPath(path);
            treeView->setRootIndex(model->index(path));
            pathInput->setText(path); // Update path input

            updateButtonStatus();
        }
    }

    void mergeFiles();

    void copyToClipboard() {
        QClipboard* clipboard = QApplication::clipboard();
        updateMerge();
        clipboard->setText(mergedContent);
    }
    
    void updateMerge();

    void setupFavoritesMenu();

    void addToFavorites();

    void updateFavoritesMenu();

    void loadSettings();

private:
    QFileSystemModel* model;
    QTreeView* treeView;
    QComboBox* driveSelector;
    QLineEdit* pathInput;
    QPushButton* mergeButton;
    QPushButton* copyButton;
    QPushButton* upButton;
    QLabel* prefixLabel;
    QLineEdit* prefixInput;
    QLabel* extensionLabel;
    QLineEdit* extensionInput;
    QPushButton* resetButton;
    QPushButton* backButton;
    QPushButton* forwardButton;
    QTextEdit* previewText;
    QSettings* settings;
    QStringList pathHistory;
    int pathHistoryIndex;
    QString mergedContent;
    QMenu* favoritesMenu;
};
#endif // MAINWINDOW_H
