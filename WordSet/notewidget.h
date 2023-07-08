#ifndef NOTEWIDGET_H
#define NOTEWIDGET_H

#include "mysubwidget.h"

class NoteWidget : public MySubWidget
{
public:
    NoteWidget(QWidget* parent = nullptr, CardSet* pt = nullptr);
};

#endif // NOTEWIDGET_H
