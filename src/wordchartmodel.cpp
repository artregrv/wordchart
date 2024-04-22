#include "wordchartmodel.h"

WordChartModel::WordChartModel() : m_fileProcessor(new FileProcessor)
{
    m_fileProcessor->moveToThread(&m_processThread);
    m_processThread.start();

    connect(this, &WordChartModel::filePathUpdated, m_fileProcessor, &FileProcessor::setPath);

    connect(this, &WordChartModel::startProcessing, m_fileProcessor, &FileProcessor::start);

    connect(m_fileProcessor, &FileProcessor::wordsChanged, this, &WordChartModel::updateWords);
}

WordChartModel::WordChartModel(const WordChartModel &other) { }

WordChartModel::~WordChartModel()
{
    m_fileProcessor->deleteLater();
    m_processThread.quit();
}

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

int WordChartModel::maxWordCount() const
{
    return m_maxWordCount;
}

void WordChartModel::setMaxWordCount(int maxWordCount)
{
    if (m_maxWordCount == maxWordCount)
        return;

    m_maxWordCount = maxWordCount;

    emit maxWordCountChanged(maxWordCount);
}

void WordChartModel::updateWords(const QList<QPair<QString, int>> &words)
{
    beginResetModel();

    m_words = words;

    setMaxWordCount(m_words.at(0).second);

    endResetModel();
}


