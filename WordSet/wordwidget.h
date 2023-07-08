#ifndef WORDWIDGET_H
#define WORDWIDGET_H

#include <QWidget>
#include <QVector>
#include "cardset.h"
#include "wordsection.h"

class WordWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WordWidget(QWidget *parent = nullptr, CardSet* pt = nullptr, int i= 0);
    //加载界面
    void load();
    //把widgetSet充填
    void refreshWidgetSet();
    //刷新tmp
    void refreshTmp();
    void refresh();
    void uncheckedAllCheckBox();
    void showAllCheckBox();
    void hideAllCheckBox();

    int index;
    QVector<WordSection*> widgetSet;
    QVector<Card*> tmp;
    CardSet* p;

signals:

};

#endif // WORDWIDGET_H
