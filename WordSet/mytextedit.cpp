#include "mytextedit.h"

/**
 * @brief myTextEdit::myTextEdit
 * @param parent
 * 能够编辑和收藏的TextEdit对象
 * @author 派蒙今天吃什么
 */
myTextEdit::myTextEdit(QWidget *parent)
    : QWidget{parent}
{
    this->resize(340, 100);
    textEdit = new QTextEdit(this);
    edit = new QCheckBox(this);
    collect = new QCheckBox(this);

    //设置textEdit
    textEdit->resize(270, 100);

    //设置edit
    edit->resize(60, 20);
    edit->setText("编辑");
    edit->move(280, 0);

    //设置collect
    collect->resize(60, 20);
    collect->setText("收藏");
    collect->move(280, 30);

    //初始化edit
    textEdit->setEnabled(false);

    //connect part
    connect(edit, &QCheckBox::stateChanged, textEdit, [=](){
        if(edit->isChecked()) textEdit->setEnabled(true);
        else textEdit->setEnabled(false);
    });
}

void myTextEdit::setText(const QString& s)
{
    textEdit->setText(s);
}

QString myTextEdit::text()
{
    return textEdit->toPlainText();
}
