#include "oldwordwidget.h"


OldWordWidget::OldWordWidget(QWidget* parent, CardSet* pt)
    :MySubWidget(parent, pt, 2)
{
    QString title_ = "熟词本";
    this->title->setText(title_);
}
