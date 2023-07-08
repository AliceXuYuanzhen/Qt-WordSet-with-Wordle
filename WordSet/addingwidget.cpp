#include "addingwidget.h"

/**
 * @brief AddingWidget::AddingWidget
 * @param parent
 * 添加单词界面模块
 * @author 派蒙今天吃什么
 */
AddingWidget::AddingWidget(QWidget *parent)
    : QWidget{parent}
{
    //General Setting
    //添加按键高度
    int adding_height = 60;
    this->resize(400, 700);
    this->setAutoFillBackground(true);
    QPalette pal = this->palette();
    pal.setBrush(this->backgroundRole(), QBrush(QColor(255,255,255, 150)));
    setPalette(pal);
    //设置标题
    QLabel* label = new QLabel(this);
    //设置标题内容
    label->setText("添加词汇");
    //设置标题内容居中
    label->setAlignment(Qt::AlignCenter);
    //设置大小
    label->resize(320, 40);
    //移动到目标位置
    label->move(40, 0);
    this->resize(400, 700);

    //设置退出按钮
    exit_btn = new QPushButton(this);
    //设置大小
    exit_btn->resize(40, 40);
    exit_btn->setStyleSheet("border-image:url(:/img/left.png);");

    //创建词库按钮
    adding_btn = new myLabelButton(this);
    //设置名称为词库
    adding_btn->setText("添加");
    //调整大小
    adding_btn->myResize(this->width(), adding_height);
    //移动至目标位置
    adding_btn->myMove(0, this->height() - adding_btn->height());


    //添加wordEdit wordLabel
    word_label = new QLabel(this);
    word_edit = new QLineEdit(this);
    //调整
    word_label->setText("新单词:");
    word_label->resize(60, 40);
    word_label->move(30, 50);
    word_edit->resize(340, 40);
    word_edit->move(30, 100);

    //添加meanEdit meanLabel
    mean_label = new QLabel(this);
    mean_edit = new QLineEdit(this);
    //调整
    mean_label->setText("英文释义:");
    mean_label->resize(60, 40);
    mean_label->move(30, 130);
    mean_edit->resize(340, 40);
    mean_edit->move(30, 180);

    //添加sentenceEdit sentenceLabel
    sentence_label = new QLabel(this);
    sentence_edit = new QTextEdit(this);
    //调整
    sentence_label->setText("例句:");
    sentence_label->resize(60, 40);
    sentence_label->move(30, 210);
    sentence_edit->resize(340, 100);
    sentence_edit->move(30, 260);

    //添加noteEdit noteLabel
    note_label = new QLabel(this);
    note_edit = new QTextEdit(this);
    //调整
    note_label->setText("笔记:");
    note_label->resize(60, 40);
    note_label->move(30, 400);
    note_edit->resize(340, 100);
    note_edit->move(30, 450);

    //connect
    connect(this->adding_btn, &myLabelButton::clicked, this, [=](){
        QString word = word_edit->text();
        QString meaning = mean_edit->text();
        QString sentence = sentence_edit->toPlainText();
        QString note = note_edit->toPlainText();
        Card* cardp = new Card(new QString(word), new QString(meaning), new QString(sentence), new QString(note));

        int status;
        status = cardSetP->AddNewCard(cardp);
        if(status == 0)
            qDebug() << "Adding the same word";
        else
            qDebug() << ("Adding " + word + " Successfully");
        clearContent();
    });
}

void AddingWidget::setCardSet(CardSet* p)
{
    cardSetP = p;
}

void AddingWidget::clearContent()
{
    word_edit->clear();
    mean_edit->clear();
    sentence_edit->clear();
    note_edit->clear();
}


