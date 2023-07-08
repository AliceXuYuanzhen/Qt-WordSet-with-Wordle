#include "cardset.h"
#include <QDebug>
#include <QMessageBox>

/**
 * @brief CardSet::CardSet
 * @param parent
 * 总卡牌集对象
 * @author 派蒙今天吃什么
 */
CardSet::CardSet(QObject *parent)
    : QObject{parent}
{
}

int CardSet::AddNewCard(Card* newCard)
{
    QVector<Card*>::Iterator itr;
    for(itr = cardSet.begin(); itr != cardSet.end(); itr++)
        if((*(*itr)->word) == (*(newCard->word))){
            QMessageBox msgBox;
            msgBox.setText("单词已经存在！");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
            return 0;
        }
    cardSet.append(newCard); return 1;
}

QVector<Card*> CardSet::GetSentenceCollectedCards()
{
    QVector<Card*> ret;
    QVector<Card*>::Iterator itr;
    for(itr = cardSet.begin(); itr != cardSet.end(); itr++)
    {
        if((*itr)->IsSentenceCollected()) ret.append(*itr);
    }
    return ret;
}
QVector<Card*> CardSet::GetNoteCollectedCards()
{
    QVector<Card*> ret;
    QVector<Card*>::Iterator itr;
    for(itr = cardSet.begin(); itr != cardSet.end(); itr++)
    {
        if((*itr)->IsNoteCollected()) ret.append(*itr);
    }
    return ret;
}
QVector<Card*> CardSet::GetMasterdCards()
{
    QVector<Card*> ret;
    QVector<Card*>::Iterator itr;
    for(itr = cardSet.begin(); itr != cardSet.end(); itr++)
    {
        if((*itr)->IsMasterdCard()) ret.append(*itr);
    }
    return ret;
}
QVector<Card*> CardSet::GetUnmasterdCards()
{
    QVector<Card*> ret;
    QVector<Card*>::Iterator itr;
    for(itr = cardSet.begin(); itr != cardSet.end(); itr++)
    {
        if(! (*itr)->IsMasterdCard()) ret.append(*itr);
    }
    return ret;
}
QVector<Card*> CardSet::GetAllCards()
{
    QVector<Card*> ret;
    QVector<Card*>::Iterator itr;
    for(itr = cardSet.begin(); itr != cardSet.end(); itr++)
        ret.append(*itr);
    return ret;
}


void CardSet::SentenceDiscollect(Card* p)
{
    QVector<Card*>::Iterator itr;
    for(itr = cardSet.begin(); itr != cardSet.end(); itr++)
        if((*itr) == p) (*itr)->DiscollectSentence();
}
void CardSet::NoteDiscollect(Card* p)
{
    QVector<Card*>::Iterator itr;
    for(itr = cardSet.begin(); itr != cardSet.end(); itr++)
        if((*itr) == p) (*itr)->DiscollectNote();
}

void CardSet::DeleteCard(Card* p)
{
    QVector<Card*>::Iterator itr;
    for(itr = cardSet.begin(); itr != cardSet.end(); itr++)
        if((*itr) == p) cardSet.erase((QVector<Card*>::const_iterator)itr);
}

QVector<Card*> CardSet::GetIndex(int index)
{
    /**
     * index == 1 -> get all cards
     * index == 2 -> get masterd cards
     * index == 3 -> get unmasterd cards
     * index == 4 -> get sentence collected cards
     * index == 5 -> get note collected cards
     */
    switch(index)
    {
    case 1: return GetAllCards();;
    case 2: return GetMasterdCards();
    case 3: return GetUnmasterdCards();
    case 4: return GetSentenceCollectedCards();
    case 5: return GetNoteCollectedCards();
    }
    return QVector<Card*>();
}
