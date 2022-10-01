#include "uploadfile.h"

#include <QFile>
#include <QMessageBox>


FilesLoader::FilesLoader()
{
    filesPath = new QVector<QString>();
}

QVector<QString> *FilesLoader::getFiles() const
{
    return filesPath;
}

void FilesLoader::setFiles(QVector<QString> *newFiles)
{
    filesPath = newFiles;
}


 QString *FilesLoader::getFile(int count) const
 {
    //сделать проверку существует ли вообще путь под таким индексом
    // и если существует, вернуть путь, иначе что-нибудь кинуть
 }

 void FilesLoader::addNewPath( QString &path)
 {
     filesPath->append(path);
     qInfo()<< *filesPath;
 }


 void FilesLoader::clearCurrentFile()
 {
     if(currentFile!=nullptr)
     {
        currentFile->clear();
     }
 }

bool FilesLoader::isExistsIntoList(QString &path)
{
    QVector<QString>::iterator it = std::find_if
            (filesPath->begin(), filesPath->end(), [path](const QString& s){
                return s==path;
            });
    if(it!= filesPath->end()){
        return true;
    }
    return false;

}

QString *FilesLoader::getCurrentFile() const
{
    return currentFile;
}

void FilesLoader::setCurrentFile(QString *newCurrentFile)
{
    currentFile = newCurrentFile;
}

 void FilesLoader::readFile(QString &path)
 {
     QFile file(path);
     if(!file.exists()) {
        qCritical()<<"File don't found";
        return;
     }

    if(!file.open(QIODevice::ReadOnly)) {
         QMessageBox::information(0, "Error", file.errorString());
     }

     QTextStream stream(&file);
     QString data = stream.readAll();
     setCurrentFile(&data);
     qInfo() << *currentFile;
     file.close();
 }

FilesLoader::~FilesLoader()
 {
     clearCurrentFile();
     filesPath->clear();
 }
