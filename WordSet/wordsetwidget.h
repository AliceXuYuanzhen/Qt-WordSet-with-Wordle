#ifndef WORDSETWIDGET_H
#define WORDSETWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QPropertyAnimation>
#include "basicbutton.h"
#include "myfont.h"

class WordSetWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WordSetWidget(QWidget *parent = nullptr);

    QPushButton* exit_btn;
    BasicButton* learned_btn;
    BasicButton* newWord_btn;
    BasicButton* sentence_btn;
    BasicButton* notes_btn;

signals:

};

#endif // WORDSETWIDGET_H
