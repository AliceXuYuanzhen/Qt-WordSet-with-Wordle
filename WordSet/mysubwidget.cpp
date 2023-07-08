#include "mysubwidget.h"
#include "wordwidget.h"
#include "textwidget.h"

MySubWidget::MySubWidget(QWidget *parent, CardSet* pt, int k)
    : QWidget{parent}, p(pt)
{
    this->setFixedSize(400, 700);

    kind = k;

    exit_btn = new QPushButton(this);
    exit_btn->resize(40, 40);
    exit_btn->setStyleSheet("border-image:url(:/img/down.png);");

    title = new QLabel(this);
    title->resize(320, 40);
    title->move(40, 0);
    title->setAlignment(Qt::AlignCenter);

    scroll = new QScrollArea(this);
    scroll->move(0, 40);
    scroll->resize(400, 600);


    QWidget* a;
    if(kind <= 3)
        a = new WordWidget(this, p, kind);
    else
        a = new TextWidget(this, p, kind);
    scroll->setWidget(a);
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void MySubWidget::refresh()
{
    delete scroll->widget();
    QWidget* a;
    if(kind <= 3)
        a = new WordWidget(this, p, kind);
    else
        a = new TextWidget(this, p, kind);

    scroll->setWidget(a);
}


void MySubWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);	// 反锯齿;
    painter.setBrush(QBrush(QColor(255, 255, 255)));
    painter.setPen(Qt::transparent);
    QRect rect = this->rect();
    rect.setWidth(rect.width() - 1);
    rect.setHeight(rect.height() - 1);
    painter.drawRoundedRect(rect, 0, 0);
    QWidget::paintEvent(event);
}
