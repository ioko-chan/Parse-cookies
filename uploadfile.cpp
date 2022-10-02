#include "uploadfile.h"

#include <QFile>
#include <QMessageBox>

#define FILE_LOADED_SUCCESSFULLY 1
#define FILE_HAS_ALREADY_BEEN_LOADED 0

FilesLoader::FilesLoader()
{
}

int FilesLoader::loadFile(const QString &path)
{
    if(!isExistsIntoList(path))
    {
        addNewPath(path);
        readFile(path);
        return FILE_LOADED_SUCCESSFULLY;
    }

    QMessageBox::information(0, "Info","This file has already been uploaded. \nSelect another file");
    return FILE_HAS_ALREADY_BEEN_LOADED;
}

QVector<QString> FilesLoader::getFiles() const
{
    return filesPath;
}

void FilesLoader::setFiles(QVector<QString> newFiles)
{
    filesPath = newFiles;
}

 void FilesLoader::addNewPath(const QString &path)
 {
     filesPath.append(path);
 }


bool FilesLoader::isExistsIntoList(const QString &path)
{
    QVector<QString>::iterator it = std::find_if
            (filesPath.begin(), filesPath.end(), [path](const QString& s){
                return s==path;
            });
    if(it!= filesPath.end()){
        return true;
    }
    return false;

}

QString FilesLoader::getCurrentFile() const
{
    return currentFile;
}

void FilesLoader::setCurrentFile(const QString newCurrentFile)
{
    currentFile = newCurrentFile;
}

 void FilesLoader::readFile(const QString &path)
 {
     QFile file(path);
     if(!file.exists()) {
        qCritical()<<"File don't found";
        return;
     }

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
         QMessageBox::information(0, "Error", file.errorString());
     }

     QTextStream stream(&file);
     QString data = stream.readAll();
     setCurrentFile(data);
     file.close();
 }

FilesLoader::~FilesLoader()
 {
    currentFile.clear();
    filesPath.clear();
 }
