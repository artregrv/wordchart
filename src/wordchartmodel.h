#ifndef WORDCHARTMODEL_H
#define WORDCHARTMODEL_H

#include <QAbstractListModel>
#include <QQmlEngine>

class WordChartModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT

public:
    enum Roles {
        WordRole = Qt::UserRole + 1,
        CountRole
    };

    explicit WordChartModel();
    WordChartModel(const WordChartModel &other);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void updateWords(const QList<QPair<QString, int>> &words);

private:
    QList<QPair<QString, int>> m_words;
};

#endif // WORDCHARTMODEL_H
