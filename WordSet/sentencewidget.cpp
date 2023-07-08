#include "sentencewidget.h"

SentenceWidget::SentenceWidget(QWidget* parent, CardSet* p)
    :MySubWidget(parent, p, 4)
{
    QString title_ = "句库（收藏的句子）";
    this->title->setText(title_);
}
