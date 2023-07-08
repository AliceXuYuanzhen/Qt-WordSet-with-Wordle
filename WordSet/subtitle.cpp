#include "subtitle.h"

SubTitle::SubTitle(QWidget *parent)
    : QWidget{parent}
{
    this->setFixedSize(400, 30);

    bar = new QLabel(this);
    bar->resize(40, 20);
    bar->move(0, 5);

    mainContent = new QLabel(this);
    mainContent->resize(100, 15);
    mainContent->move(40, 8);

    rightBar = new QLabel(this);
    rightBar->resize(30, 30);
    rightBar->move(360, 0);
    rightBar->setStyleSheet("border-image:url(:/img/right.png);");
}

void SubTitle::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);	// 反锯齿;
    painter.setBrush(QBrush(QColor(255, 0, 0, 170)));
    painter.setPen(Qt::transparent);
    QRect rect = this->rect();
    rect.setWidth(rect.width() - 1);
    rect.setHeight(rect.height() - 1);
    painter.drawRoundedRect(rect, 5, 5);
    QWidget::paintEvent(event);
}
