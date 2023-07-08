#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "mylabelbutton.h"
#include "calendar.h"

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);

    myLabelButton* wordSet_btn;
    myLabelButton* addNew_btn;
    myLabelButton* review_btn;
    myLabelButton* wordle_btn;
    //日历对象
    Calendar* calendar;

signals:

};

#endif // MAINWIDGET_H
