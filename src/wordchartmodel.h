#ifndef WORDCHARTMODEL_H
#define WORDCHARTMODEL_H

#include <QAbstractListModel>
#include <QQmlEngine>
#include <QThread>

#include "fileprocessor.h"

class WordChartModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int maxWordCount READ maxWordCount WRITE setMaxWordCount NOTIFY maxWordCountChanged)
    QML_ELEMENT

public:
    enum Roles {
        WordRole = Qt::UserRole + 1,
        CountRole
    };

    explicit WordChartModel();
    WordChartModel(const WordChartModel &other);
    ~WordChartModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    int maxWordCount() const;
    void setMaxWordCount(int maxWordCount);
    Q_SIGNAL void maxWordCountChanged(int maxWordCount);

    void updateWords(const QList<QPair<QString, int>> &words);

    Q_SIGNAL void filePathUpdated(const QString &path);

    Q_SIGNAL void startProcessing();
    Q_SIGNAL void pauseProcessing();
    Q_SIGNAL void stopProcessing();


private:
    QList<QPair<QString, int>> m_words;

    int m_maxWordCount { 0 };

    QThread m_processThread;
    FileProcessor *m_fileProcessor = nullptr;
};

#endif // WORDCHARTMODEL_H
