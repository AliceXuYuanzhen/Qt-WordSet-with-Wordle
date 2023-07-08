#include "calendar.h"

/**
 * @brief Calendar::Calendar
 * @param parent
 * @param red
 * @param green
 * @param blue
 * @param t
 * 日历模块
 * @author 派蒙今天吃什么
 */
Calendar::Calendar(QWidget *parent, int red, int green, int blue, int t)
    : QWidget{parent}, r(red), g(green), b(blue), transparentValue(t)
{
    this->setFixedSize(150, 150);
    label_date = new QLabel(this);
    label_date->resize(140, 30);
    label_date->move(5, 110);
    label_date->setAlignment(Qt::AlignCenter);
    label_date->setText(GetDate());

    icon = new QWidget(this);
    icon->resize(54, 54);
    icon->move(75-27, 30);
    icon->setStyleSheet("border-image:url(:/img/calendar.png);");
}

QString Calendar::GetDate()
{
    QString res = QDateTime::currentDateTime().toString("MM/dd ddd.");
    return res;
}

void Calendar::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);	// 反锯齿;
    painter.setBrush(QBrush(QColor(r, g, b, transparentValue)));
    painter.setPen(Qt::transparent);
    QRect rect = this->rect();
    rect.setWidth(rect.width() - 1);
    rect.setHeight(rect.height() - 1);
    painter.drawRoundedRect(rect, 15, 15);
    QWidget::paintEvent(event);
}
