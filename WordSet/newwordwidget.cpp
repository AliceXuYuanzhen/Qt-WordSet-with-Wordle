#include "newwordwidget.h"

NewWordWidget::NewWordWidget(QWidget* parent, CardSet* pt)
    :MySubWidget(parent, pt, 3)
{
    QString title_ = "生词本";
    this->title->setText(title_);
}
