#ifndef MYLABELBUTTON_H
#define MYLABELBUTTON_H

#include "mybutton.h"
#include <QLabel>

class myLabelButton : public myButton
{
public:
    myLabelButton(QWidget* parent = nullptr, int red = 255, int green = 255, int blue = 255, int t = 255);

    void myResize(QSize s);
    void myResize(int w, int h);
    void myMove(QPoint p);
    void myMove(int x, int y);
    void setText(QString s);
    void Recolor(int r, int g, int b);
    QLabel* label;
};

#endif // MYLABELBUTTON_H
