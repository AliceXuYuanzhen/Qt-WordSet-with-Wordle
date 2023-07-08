#ifndef TEXTWIDGET_H
#define TEXTWIDGET_H

#include <QWidget>
#include "textsection.h"
#include "cardset.h"

class TextWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TextWidget(QWidget *parent = nullptr, CardSet* pt = nullptr, int i= 4);
    //把widgetSet充填
    void refreshWidgetSet();
    //刷新tmp
    void refreshTmp();
    void refresh();

    void load();
    int index;
    QVector<TextSection*> widgetSet;
    QVector<Card*> tmp;
    CardSet* p;

signals:

};

#endif // TEXTWIDGET_H
