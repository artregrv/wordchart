#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <QObject>
#include <QQmlEngine>

class FileProcessor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)
    QML_ELEMENT

public:
    QString path() const;
    void setPath(const QString &path);
    Q_SIGNAL void pathChanged(const QString &path);

    Q_INVOKABLE void start();

    Q_SIGNAL void wordsChanged(QList<QPair<QString, int>> words);
    // Q_SIGNAL void wordsChanged(QMap<QString, int> words);

private:
    void process();

    QString m_path;

};

#endif // FILEPROCESSOR_H
