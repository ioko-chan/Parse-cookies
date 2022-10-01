#ifndef UPLOADFILE_H
#define UPLOADFILE_H

#include <QString>
#include <QVector>


class FilesLoader
{
public:
    FilesLoader();
    ~FilesLoader();
    QVector<QString> *getFiles() const;
    void setFiles(QVector<QString> *newFiles);
    void addNewPath(QString &path);
    void clearCurrentFile();
    void readFile(QString &path);
    bool isExistsIntoList(QString &path);

    QString *getCurrentFile() const;
    void setCurrentFile(QString *newCurrentFile);

private:
    QVector<QString> *filesPath;
    QString *currentFile;
};

#endif // UPLOADFILE_H
