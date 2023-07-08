#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPainter>

class myButton : public QWidget
{
    Q_OBJECT
public:
    explicit myButton(QWidget *parent = nullptr, int red = 255, int green = 255, int blue = 255, int t = 255);

    int r, g, b;
    int transparentValue;
    qreal xRadius = 15;
    qreal yRadius = 15;

    void paintEvent(QPaintEvent* event);
    void setBackColor(QColor c);
    void setBackColor(int red, int green, int blue);
    void setOpacity(int value);
    void setXRadius(qreal value);
    void setYRadius(qreal value);

    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

signals:
    void clicked();

private:
    QPointF mousePos;
};

#endif // MYBUTTON_H
