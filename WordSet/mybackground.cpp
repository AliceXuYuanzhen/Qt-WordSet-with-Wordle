#include "mybackground.h"

/**
 * @brief MyBackground::MyBackground
 * @param parent
 * @param background
 * 背景界面
 * @author 派蒙今天吃什么
 */
MyBackground::MyBackground(QWidget *parent, QString background)
    : QWidget{parent}
{
    this->setFixedSize(400, 700);

    this->setAutoFillBackground(true);
    QPalette pal = this->palette();
    pal.setBrush(this->backgroundRole(), QBrush(QPixmap(background).scaled(this->size())));
    setPalette(pal);

    blureffect = new QGraphicsBlurEffect;
    blureffect->setBlurRadius(5);
    this->setGraphicsEffect(blureffect);
}

void MyBackground::SetBlurEffect(int k)
{
    blureffect->setBlurRadius(k);
    this->setGraphicsEffect(blureffect);
}
