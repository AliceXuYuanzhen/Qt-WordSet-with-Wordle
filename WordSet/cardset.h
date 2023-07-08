#ifndef CARDSET_H
#define CARDSET_H

#include <QObject>
#include <QVector>
#include "card.h"

class CardSet : public QObject
{
    Q_OBJECT
public:
    explicit CardSet(QObject *parent = nullptr);
    int AddNewCard(Card* newCard);
    //获取所有例句收藏的Card对象
    QVector<Card*> GetSentenceCollectedCards();
    //获取所有笔记收藏的Card对象
    QVector<Card*> GetNoteCollectedCards();
    //获取所有熟练掌握的Card对象
    QVector<Card*> GetMasterdCards();
    //获取所有没有掌握的Card对象
    QVector<Card*> GetUnmasterdCards();
    QVector<Card*> GetAllCards();

    QVector<Card*> GetIndex(int index);
    //Disconnect card's sentence collection
    void SentenceDiscollect(Card* p);
    //Disconnect card's note collection
    void NoteDiscollect(Card* p);
    //delete card
    void DeleteCard(Card* p);

    int len = 0;
    int maxLen = 10;
    QVector<Card*> cardSet;
signals:

};

#endif // CARDSET_H
