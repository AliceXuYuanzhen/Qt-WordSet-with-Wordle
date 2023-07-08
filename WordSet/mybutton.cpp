#include "mybutton.h"
#include <QMouseEvent>

/**
 * @brief myButton::myButton
 * @param parent
 * inherents: QLabel
 * A self designed button
 * @author 派蒙今天吃什么
 */
myButton::myButton(QWidget *parent, int red, int green, int blue, int t)
    : QWidget{parent},r(red),g(green),b(blue),transparentValue(t)
{
}

void myButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);	// 反锯齿;
    painter.setBrush(QBrush(QColor(r, g, b, transparentValue)));
    painter.setPen(Qt::transparent);
    QRect rect = this->rect();
    rect.setWidth(rect.width() - 1);
    rect.setHeight(rect.height() - 1);
    painter.drawRoundedRect(rect, xRadius, yRadius);
    QWidget::paintEvent(event);
}

void myButton::mousePressEvent(QMouseEvent* event)
{
    mousePos = event->position();
}
void myButton::mouseReleaseEvent(QMouseEvent* event)
{
    if(mousePos == event->position()) emit clicked();
}

void myButton::setBackColor(int red, int green, int blue)
{
    r = red; g = green; b = blue;
}

void myButton::setBackColor(QColor c)
{
    r = c.red(); g = c.green(); b = c.blue();
}

void myButton::setOpacity(int value)
{
    transparentValue = value;
    repaint();
}

void myButton::setXRadius(qreal value){ xRadius = value; }
void myButton::setYRadius(qreal value){ yRadius = value; }
