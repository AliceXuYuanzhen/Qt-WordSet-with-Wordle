#include "notewidget.h"

NoteWidget::NoteWidget(QWidget* parent, CardSet* pt)
    :MySubWidget(parent, pt, 5)
{
    QString title_ = "笔记（收藏的笔记）";
    this->title->setText(title_);
}
