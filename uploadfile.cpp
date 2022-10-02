#include "uploadfile.h"

FileLoader::FileLoader(const QString &path)
{
    setFilePath(path);
    readFile();
}

const QString &FileLoader::getFileData() const
{
    return fileData;
}

void FileLoader::setFileData(const QString &newFileData)
{
    fileData = newFileData;
}

const QString &FileLoader::getFilePath() const
{
    return filePath;
}

void FileLoader::setFilePath(const QString &newFilePath)
{
    filePath = newFilePath;
}

 void FileLoader::readFile()
 {
     QFile file(getFilePath());
     if(!file.exists()) {
        qCritical()<<"File don't found";
        return;
     }

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
         QMessageBox::information(0, "Error", file.errorString());
     }

     QTextStream stream(&file);
     QString data = stream.readAll();
     setFileData(data);
     file.close();
 }

