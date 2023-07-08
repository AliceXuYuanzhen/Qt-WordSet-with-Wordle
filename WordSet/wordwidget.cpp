#include "wordwidget.h"

WordWidget::WordWidget(QWidget *parent, CardSet* pt, int i)
    : QWidget{parent},p(pt), index(i)
{
    tmp = p->GetIndex(index);
    refresh();
}

void WordWidget::refreshTmp()
{
    tmp = p->GetIndex(index);
}

void WordWidget::refreshWidgetSet()
{
    widgetSet.clear();
    QVector<Card*>::Iterator itr;
    for(itr = tmp.begin(); itr != tmp.end(); ++itr)
    {
        widgetSet.append(new WordSection(this, *itr));
    }
}

void WordWidget::load()
{
    int height = 75*widgetSet.size();
    int ds = 5;
    int nowH = 0;
    this->resize(400, height);
    QVector<WordSection*>::Iterator itr;
    for(itr = widgetSet.begin(); itr != widgetSet.end(); ++itr)
    {
        (*itr)->move(0, nowH);
        nowH += (ds + 70);
        (*itr)->show();
        (*itr)->hideCheckBox();
    }
}

void WordWidget::refresh()
{
    refreshTmp();
    refreshWidgetSet();
    load();
}

void WordWidget::uncheckedAllCheckBox()
{
    QVector<WordSection*>::Iterator itr;
    for(itr = widgetSet.begin(); itr != widgetSet.end(); ++itr)
        (*itr)->checkBox->setCheckState(Qt::Unchecked);
}
void WordWidget::showAllCheckBox()
{
    QVector<WordSection*>::Iterator itr;
    for(itr = widgetSet.begin(); itr != widgetSet.end(); ++itr)
        (*itr)->showCheckBox();
}
void WordWidget::hideAllCheckBox()
{
    QVector<WordSection*>::Iterator itr;
    for(itr = widgetSet.begin(); itr != widgetSet.end(); ++itr)
        (*itr)->hideCheckBox();
}
