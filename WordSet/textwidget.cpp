#include "textwidget.h"

TextWidget::TextWidget(QWidget *parent, CardSet* pt, int i)
    : QWidget{parent}, p(pt), index(i)
{
    refresh();
}

void TextWidget::refreshTmp()
{
    tmp = p->GetIndex(index);
}

void TextWidget::refreshWidgetSet()
{
    widgetSet.clear();
    QVector<Card*>::Iterator itr;
    TextSection* pp;
    for(itr = tmp.begin(); itr != tmp.end(); ++itr)
    {
        pp = new TextSection(this, *itr, index);
        widgetSet.append(pp);
    }
}

void TextWidget::load()
{
    int height = 75*widgetSet.size();
    int ds = 5;
    int nowH = 0;
    this->resize(400, height);
    QVector<TextSection*>::Iterator itr;
    for(itr = widgetSet.begin(); itr != widgetSet.end(); ++itr)
    {
        (*itr)->move(0, nowH);
        nowH += (ds + 70);
        (*itr)->show();
    }
}

void TextWidget::refresh()
{
    refreshTmp();
    refreshWidgetSet();
    load();
}
