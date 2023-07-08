#ifndef TEXTSECTION_H
#define TEXTSECTION_H

#include <QWidget>
#include <QTextEdit>
#include "card.h"
#include <QPainter>

class TextSection : public QWidget
{
    Q_OBJECT
public:
    explicit TextSection(QWidget *parent = nullptr, Card* pt = nullptr, int index = 4);
    void paintEvent(QPaintEvent* event);
    QTextEdit* text;
    Card* p;

signals:

};

#endif // TEXTSECTION_H
