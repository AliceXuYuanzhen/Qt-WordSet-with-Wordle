#ifndef MYBACKGROUND_H
#define MYBACKGROUND_H

#include <QWidget>
#include <QGraphicsBlurEffect>
#include <QPalette>

class MyBackground : public QWidget
{
    Q_OBJECT
public:
    explicit MyBackground(QWidget *parent = nullptr, QString background = ":/img/background.jpg");
    QGraphicsBlurEffect* blureffect;

    void SetBlurEffect(int k);

signals:

};

#endif // MYBACKGROUND_H
