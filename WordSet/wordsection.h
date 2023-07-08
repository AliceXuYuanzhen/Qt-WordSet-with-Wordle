#ifndef WORDSECTION_H
#define WORDSECTION_H

#include <QWidget>
#include <QCheckBox>
#include <QLabel>
#include <QPainter>
#include "card.h"

class WordSection : public QWidget
{
    Q_OBJECT
public:
    explicit WordSection(QWidget *parent = nullptr, Card* pt = nullptr);
    void loadWord();
    void showCheckBox();
    void hideCheckBox();
    bool isChecked();
    void paintEvent(QPaintEvent* event);

    Card* p;
    QLabel* word;
    QCheckBox* checkBox;

signals:

};

#endif // WORDSECTION_H
