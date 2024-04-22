#include <QFile>

#include "fileprocessor.h"

#include <QThread>

QString FileProcessor::path() const
{
    return m_path;
}

void FileProcessor::setPath(const QString &path)
{
    if (m_path == path)
        return;

    m_path = path;

    emit pathChanged(path);
}

void FileProcessor::start()
{
    process();
}

void FileProcessor::process()
{
    if (m_path.isEmpty()) {
        qWarning() << "Empty file path";
        return;
    }

    QFile file(m_path);

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Can't open file";
        return;
    }

    QTextStream stream(&file);

    QString word;

    QMap<QString, int> wordsMap;
    QList<QPair<QString, int>> wordsList;

    while (!stream.atEnd()) {
        stream >> word;
        wordsMap[word] += 1;
    }

    for (auto it = wordsMap.begin(); it != wordsMap.end(); ++it) {
        wordsList.push_back({ it.key(), it.value() });
    }

    std::sort(wordsList.begin(), wordsList.end(), [](auto lhs, auto rhs) {
        return lhs.second > rhs.second;
    });

    emit wordsChanged(wordsList.first(15));
}
