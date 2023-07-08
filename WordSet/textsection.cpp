#include "textsection.h"

TextSection::TextSection(QWidget *parent, Card* pt, int index)
    : QWidget{parent}, p(pt)
{
    this->setFixedSize(400, 70);
    text = new QTextEdit(this);
    text->resize(this->size());
    text->setReadOnly(true);
    if(index == 4)
        text->setText(*(p->sentence));
    else if(index == 5)
        text->setText(*(p->note));
}

void TextSection::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);	// 反锯齿;
    painter.setBrush(QBrush(QColor(255, 0, 0, 170)));
    painter.setPen(Qt::transparent);
    QRect rect = this->rect();
    rect.setWidth(rect.width() - 1);
    rect.setHeight(rect.height() - 1);
    painter.drawRoundedRect(rect, 10, 10);
    QWidget::paintEvent(event);
}
