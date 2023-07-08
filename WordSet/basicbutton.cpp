#include "basicbutton.h"

/**
 * @brief BasicButton::BasicButton
 * @param parent
 * userinterface
 * it has round corner
 * component: icon label1 label2 icon2
 *
 * when mouse move in, it will expand
 * when mouse clicked, it will send a signal
 * @author 派蒙今天吃什么
 */
BasicButton::BasicButton(
    QWidget* parent, int red, int green, int blue, QString leftIconPath, QString mainContentText, QString otherContentText, QString rightIconPath)
    : myButton(parent, red, green, blue)
{
    //设置总大小
    this->setFixedSize(380, 80);
    //设置背景颜色
//    this->setAutoFillBackground(true);
//    QPalette pal = this->palette();
//    pal.setBrush(this->backgroundRole(), QBrush(QColor(0,255,255)));
//    setPalette(pal);
    //构建左边图标sheet内容
    QString leftIconSheet = "border-image:url(";
    leftIconSheet += leftIconPath;
    leftIconSheet += ");";
    //构建右边图标sheet内容
    QString rightIconSheet = "border-image:url(";
    rightIconSheet += rightIconPath;
    rightIconSheet += ");";

    //创建左右图标
    leftIcon = new QLabel(this);
    leftIcon->resize(60, 60);
    leftIcon->move(10, 10);
    rightIcon = new QLabel(this);
    rightIcon->resize(60, 60);
    rightIcon->move(310, 10);

    //加载左右图标
    leftIcon->setStyleSheet(leftIconSheet);
    rightIcon->setStyleSheet(rightIconSheet);

    //构建左右label内容
    mainContent = new QLabel(this);
    mainContent->resize(60, 30);
    mainContent->move(70, 25);
    mainContent->setText(mainContentText);
}

void BasicButton::ResizeObject(QLabel* obj, QSize size)
{
    obj->resize(size);
}

void BasicButton::MoveObject(QLabel* obj, QPoint point)
{
    obj->move(point);
}

void BasicButton::enterEvent(QEnterEvent* event)
{
    setOpacity(170);
}

void BasicButton::leaveEvent(QEvent* event)
{
    setOpacity(50);
}
