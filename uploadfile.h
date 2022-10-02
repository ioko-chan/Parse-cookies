#ifndef UPLOADFILE_H
#define UPLOADFILE_H

#include <QString>
#include <QVector>
#include <QFile>
#include <QMessageBox>

class FileLoader
{
public:
    FileLoader(const QString &path);

    QVector<QString> getFiles() const;
    void setFiles(QVector<QString> newFiles);

    const QString &getFileData() const;
    void setFileData(const QString &newFileData);

    const QString &getFilePath() const;
    void setFilePath(const QString &newFilesPath);

    void readFile();

private:
    QString filePath;
    QString fileData;
};

#endif // UPLOADFILE_H
