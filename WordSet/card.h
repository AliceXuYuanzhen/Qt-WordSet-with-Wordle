#ifndef CARD_H
#define CARD_H
#include<QObject>

class Card
{
public:
    explicit Card(QString* w = nullptr, QString* m = nullptr, QString* s = nullptr, QString* n = nullptr);
    QString* word;
    QString* meaning;
    QString* sentence;
    QString* note;

    bool sentence_collected = false;
    bool note_collected = false;
    int masterLevel = 0;

    //修改例句
    void changeSentence(QString news);
    //修改笔记
    void changeNote(QString newn);
    //将此card标记为例句已收藏
    void CollectSentence();
    //将此card标记为笔记已收藏
    void CollectNote();

    void DiscollectSentence();
    void DiscollectNote();

    //修改单词熟练度
    void ChangeMasterLevel(int d);
    //修改意思
    void ChangeMeaning(QString s);
    //这两个方法应该重复使用了（不用在意QWQ
    void ChangeSentence(QString s);
    void ChangeNote(QString s);

    bool IsSentenceCollected();
    bool IsNoteCollected();
    bool IsMasterdCard();
signals:
};

#endif // CARD_H
