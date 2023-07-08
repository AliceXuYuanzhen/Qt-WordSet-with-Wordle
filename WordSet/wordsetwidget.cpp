#include "wordsetwidget.h"
#include <QLabel>

/**
 * @brief WordSetWidget::WordSetWidget
 * @param parent
 * 词库主界面模块
 * @author 派蒙今天吃什么
 */
WordSetWidget::WordSetWidget(QWidget *parent)
    : QWidget{parent}
{
    this->resize(400, 700);
    this->setAutoFillBackground(true);
    QPalette pal = this->palette();
    pal.setBrush(this->backgroundRole(), QBrush(QColor(255,255,255, 150)));
    setPalette(pal);
    //设置标题
    QLabel* label = new QLabel(this);
    //设置标题内容
    label->setText("我的词库");
    label->setFont(MyFont::font);
    //设置标题内容居中
    label->setAlignment(Qt::AlignCenter);
    //设置大小
    label->resize(320, 40);
    //移动到目标位置
    label->move(40, 0);

    //设置退出按钮
    exit_btn = new QPushButton(this);
    //设置大小
    exit_btn->resize(40, 40);
    exit_btn->setStyleSheet("border-image:url(:/img/down.png);");

    int opacity = 50;
    //设置全部已经学习的词汇
    learned_btn = new BasicButton(this, 0, 191, 255, ":/img/oldWord.png", "熟词本", "词", ":/img/right.png");
    //设置大小
    learned_btn->resize(380, 40);
    //移动到目标位置
    learned_btn->move(10, 100);

    learned_btn->setOpacity(opacity);

    //设置生词本栏目
    newWord_btn = new BasicButton(this, 0, 191, 255, ":/img/newWord.png", "生词本", "词", ":/img/right.png");
    //设置大小
    newWord_btn->resize(380, 40);
    //移动到目标位置
    newWord_btn->move(10, 250);
    newWord_btn->setOpacity(opacity);

    //设置句库栏目
    sentence_btn = new BasicButton(this, 0, 191, 255, ":/img/sentence.png", "句库", "句", ":/img/right.png");
    //设置大小
    sentence_btn->resize(380, 40);
    //移动到目标位置
    sentence_btn->move(10, 400);
    sentence_btn->setOpacity(opacity);

    //设置笔记栏目
    notes_btn = new BasicButton(this, 0, 191, 255, ":/img/note.png", "笔记", "笔记", ":/img/right.png");
    //设置大小
    notes_btn->resize(380, 40);
    //移动到目标位置
    notes_btn->move(10, 550);
    notes_btn->setOpacity(opacity);
}
