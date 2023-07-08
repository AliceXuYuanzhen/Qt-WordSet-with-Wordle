#include "card.h"

/**
 * @brief Card::Card
 * @param w
 * @param m
 * @param s
 * @param n
 * 卡牌对象
 * @author 派蒙今天吃什：w么
 */
Card::Card(QString* w, QString* m, QString* s, QString* n)
    : word(w), meaning(m), sentence(s), note(n)
{

}

void Card::changeSentence(QString news)
{
    if(sentence != nullptr) delete sentence;
    sentence = new QString(news);
}

void Card::changeNote(QString newn)
{
    if(note != nullptr) delete note;
    note = new QString(newn);
}

void Card::CollectSentence()
{
    sentence_collected = true;
}
void Card::CollectNote()
{
    note_collected = true;
}
void Card::DiscollectSentence()
{
    sentence_collected = false;
}
void Card::DiscollectNote()
{
    note_collected = false;
}

bool Card::IsSentenceCollected()
{
    return sentence_collected;
}
bool Card::IsNoteCollected()
{
    return note_collected;
}

void Card::ChangeMasterLevel(int d)
{
    masterLevel += d;
}

bool Card::IsMasterdCard()
{
    if(masterLevel <= 3) return false;
    return true;
}

void Card::ChangeMeaning(QString s)
{
    if(meaning != nullptr) delete meaning;
    meaning = new QString(s);
}
void Card::ChangeSentence(QString s)
{
    if(sentence != nullptr) delete sentence;
    sentence = new QString(s);
}
void Card::ChangeNote(QString s)
{
    if(note != nullptr) delete note;
    note = new QString(s);
}
