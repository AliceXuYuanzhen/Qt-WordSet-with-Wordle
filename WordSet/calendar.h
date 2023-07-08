#ifndef CALENDAR_H
#define CALENDAR_H

#include <QWidget>
#include <QDateTime>
#include <QLabel>
#include <QPainter>

class Calendar : public QWidget
{
    Q_OBJECT
public:
    explicit Calendar(QWidget *parent = nullptr, int red = 255, int green = 255, int blue = 255, int t = 255);
    void paintEvent(QPaintEvent *event);
    QString GetDate();

    QLabel* label_date;
    QWidget* icon;
private:
    int r, g, b;
    int transparentValue;

signals:

};

#endif // CALENDAR_H
