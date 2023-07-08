#include "mylabelbutton.h"

/**
 * @brief myLabelButton::myLabelButton
 * @param parent
 * @param red
 * @param green
 * @param blue
 * @author 派蒙今天吃什么
 */
myLabelButton::myLabelButton(QWidget* parent, int red, int green, int blue, int t):myButton(parent, red, green, blue,t)
{
    label = new QLabel(this);
    label->setAlignment(Qt::AlignCenter);
    label->resize(this->size());
}

void myLabelButton::myResize(QSize s)
{
    this->resize(s);
    label->resize(this->size());
}

void myLabelButton::myResize(int w, int h)
{
    this->myResize(QSize(w, h));
}

void myLabelButton::myMove(QPoint p)
{
    this->move(p);
}

void myLabelButton::myMove(int x, int y)
{
    this->myMove(QPoint(x, y));
}

void myLabelButton::setText(QString s)
{
    label->setText(s);
}

void myLabelButton::Recolor(int r, int g, int b){
    myButton::setBackColor(r, g, b);
    QWidget::repaint();
}
