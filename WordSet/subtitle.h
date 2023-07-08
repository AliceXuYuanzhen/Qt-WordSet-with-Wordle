#ifndef SUBTITLE_H
#define SUBTITLE_H

#include <QWidget>
#include <QLabel>
#include <QPainter>

class SubTitle : public QWidget
{
    Q_OBJECT
public:
    explicit SubTitle(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* event);

    QLabel* bar;
    QLabel* rightBar;
    QLabel* mainContent;

signals:

};

#endif // SUBTITLE_H
