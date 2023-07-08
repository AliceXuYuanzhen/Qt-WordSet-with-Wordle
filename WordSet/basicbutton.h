#ifndef BASICBUTTON_H
#define BASICBUTTON_H

#include "mybutton.h"
#include <QWidget>
#include <QLabel>
#include <QPalette>
#include <QDebug>
#include <QPainter>
#include <QPainterPath>

class BasicButton : public myButton
{
    Q_OBJECT
public:
    explicit BasicButton(QWidget *parent = nullptr, int red = 255, int blue = 255, int green = 255 , QString leftIconPath = ":/img/background.jpg",
    QString mainContentText = "Hello", QString otherContentText = "World", QString rightIconPath = ":/img/background.jpg");

    //对象左侧图标
    QLabel* leftIcon;
    QLabel* mainContent;
    QLabel* rightIcon;

    void ResizeObject(QLabel* obj, QSize size);
    void MoveObject(QLabel* obj, QPoint point);

    //鼠标进入事件
    void enterEvent(QEnterEvent* event);
    //鼠标离开事件
    void leaveEvent(QEvent* event);

signals:

};

#endif // BASICBUTTON_H
