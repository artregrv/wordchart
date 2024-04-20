#include "wordchartmodel.h"
#include "fileprocessor.h"

WordChartModel::WordChartModel()
{
    FileProcessor fileProcessor;

    updateWords({ { "word", 10 } });
}

WordChartModel::WordChartModel(const WordChartModel &other) { }

int WordChartModel::rowCount(const QModelIndex &parent) const
{
    return m_words.size();
}

QVariant WordChartModel::data(const QModelIndex &index, int role) const
{
    const auto row = index.row();

    switch (role) {
    case WordRole:
        return m_words.at(row).first;
    case CountRole:
        return m_words.at(row).second;
    default:
        return {};
    }
}

QHash<int, QByteArray> WordChartModel::roleNames() const
{
    return { { WordRole, "word" }, { CountRole, "count" } };
}

void WordChartModel::updateWords(const QList<QPair<QString, int>> &words)
{
    beginResetModel();

    m_words = words;

    endResetModel();
}
