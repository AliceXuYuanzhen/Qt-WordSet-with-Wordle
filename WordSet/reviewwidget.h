#ifndef REVIEWWIDGET_H
#define REVIEWWIDGET_H

#include <QWidget>
#include <qpushbutton>
#include <QLabel>
#include "cardset.h"
#include "mylineedit.h"
#include "mytextedit.h"
#include "myLabelButton.h"
#include "myfont.h"

class ReviewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ReviewWidget(QWidget *parent = nullptr, CardSet* p = nullptr, int i = 3);
    void setCardSet(CardSet* p);
    void setInvisible();
    void setVisible();
    void setContainer(int index);
    int refresh();
    void loadWord();
    void refreshContents();

    int index;
    QPushButton* exit_btn;
    CardSet* cardSetP = nullptr;

    QLabel* word;
    QLabel* word_label;
    myLineEdit* mean_edit;
    QLabel* mean_label;
    myTextEdit* sentence_edit;
    QLabel* sentence_label;
    myTextEdit* note_edit;
    QLabel* note_label;

    QVector<Card*> container;
    QVector<Card*>::Iterator itr;


    //底下的按键
    myLabelButton* recognize;
    myLabelButton* notSure;
    myLabelButton* forget;

    myLabelButton* nextWord;
    myLabelButton* nextWord2; //备用按键
    myLabelButton* gotWro;

    myLabelButton* reachEnd;

    //记完了所有单词
    QLabel* final;

signals:

};

#endif // REVIEWWIDGET_H
