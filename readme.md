
# Merge Content

Merge Content is a C++ application built with Qt5 and CMake, designed to merge the contents of multiple text files. It provides a graphical interface for users to select files, view their contents, and either save the merged result to a new file or copy it to the clipboard. The application supports file filtering by extensions and includes a favorites system for quick access to frequently used directories.

## Features

- **Graphical File System Navigation**: Allows users to browse directories and select files within the application.
- **Multi-file Selection**: Enables selecting multiple files for merging.
- **Extension Filtering**: Filters files displayed in the file selection dialog based on specified extensions.
- **Content Preview**: Offers a preview of the merged content before finalizing.
- **Save or Copy Options**: Users can choose to save the merged content to a new file or copy it directly to the clipboard.
- **Favorites System**: Provides quick access to favorite or frequently used folders.

## Getting Started

### Prerequisites

- Qt 5.12 or higher
- CMake 3.10 or higher
- A C++11 compatible compiler

### Building the Application

1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/merge-content.git
   ```
2. Change into the project directory:
   ```sh
   cd merge-content/src
   ```
3. Create a build directory and change into it:
   ```sh
   mkdir build && cd build
   ```
4. Run CMake to configure the project:
   ```sh
   cmake ..
   ```
5. Build the project:
   ```sh
   cmake --build .
   ```

### Running the Application

After building, you can run the application by executing the generated binary, which is located in the `build` directory.

## Usage

Start Merge Content and navigate through the file system tree to locate the files you want to merge. Use the extension filter to narrow your search to specific file types. Select all files you wish to merge, and then click "Merge Files" to see a preview of the merged content. You can save the merged content to a file or copy it to the clipboard as needed.

## Contributing

We welcome contributions to Merge Content! If you have suggestions for improvements or encounter any issues, please feel free to submit an issue or pull request.

For more information on how to contribute, please refer to [CONTRIBUTING.md](CONTRIBUTING.md).

## License

Merge Content is available under the MIT License. For more information, see the [LICENSE](LICENSE.md) file in this repository.


这个模板假设您会创建 `CONTRIBUTING.md` 和 `LICENSE.md` 文件。如果您的项目还没有这些文件，我建议您添加它们。`CONTRIBUTING.md` 应该包含有关如何参与项目的指导原则，而 `LICENSE.md` 则包含项目许可证的全文。这有助于澄清项目的贡献规则和法律条款。

请确保替换模板中的 `https://github.com/yourusername/merge-content.git` 为您的实际项目仓库URL。