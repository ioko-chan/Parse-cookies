#ifndef UPLOADFILE_H
#define UPLOADFILE_H

#include <QString>
#include <QVector>


class FilesLoader
{
public:
    FilesLoader();
    ~FilesLoader();
    QVector<QString> getFiles() const;
    int loadFile(const QString &path);
    void setFiles(QVector<QString> newFiles);
    void addNewPath(const QString &path);
    void readFile(const QString &path);
    bool isExistsIntoList(const QString &path);
    QString getCurrentFile() const;
    void setCurrentFile(const QString newCurrentFile);

private:
    QVector<QString> filesPath;
    QString currentFile;
};

#endif // UPLOADFILE_H
