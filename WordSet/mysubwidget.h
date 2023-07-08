#ifndef MYSUBWIDGET_H
#define MYSUBWIDGET_H

#include <QWidget>
#include <QScrollArea>
#include "cardset.h"
#include <QPushButton>
#include <QPainter>
#include <QLabel>

class MySubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MySubWidget(QWidget *parent = nullptr, CardSet* pt = nullptr, int k= 1);
    void refresh();
    void paintEvent(QPaintEvent* event);
    /**
     * kind
     * 1->add card
     * 2->mastered card
     * 3->unmastered card
     * 4->sentencecollected card
     * 5->notescollected card
     */

    QPushButton* exit_btn;
    QLabel* title;

    int kind;
    QScrollArea* scroll;

    CardSet* p;

signals:

};

#endif // MYSUBWIDGET_H
