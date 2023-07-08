#include "wordlewidget.h"
#include "mylabelbutton.h"
#include "myfont.h"
#include <QFont>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QPauseAnimation>
#include <QSequentialAnimationGroup>
#include <QKeyEvent>

WordleWidget::WordleWidget(QWidget *parent)
    : QWidget{parent}
{
    this->setFixedSize(400, 700);
    // 三行字母的高度
    int line_h[3] = { 100, 150, 200 };
    // 每行字母边缘距离
    int edge[3] = { 62, 22, 2 };
    // 字母宽度
    int char_width = 36;
    int char_h = 45;
    int interval = 4;

    for(int i = 0; i < 6; ++i){
        int edge = 65;
        int itv = 5;
        QPalette pe;
        pe.setColor(QPalette::WindowText,Qt::white);
        letterboxes.push_back(QVector<myLabelButton*>());
        for(int j = 0; j < 5; ++j){
            letterboxes.back().push_back(new myLabelButton(this, 50, 50, 50, 155));
            letterboxes.back().back()->myResize(50, 50);
            letterboxes.back().back()->myMove(edge + (itv + 50) * j, 100 + i * (itv + 50));
            letterboxes.back().back()->setText("");
            letterboxes.back().back()->label->setPalette(pe);
            QFont font;
            font.setPointSize(16);
            font.setBold(true);
            letterboxes.back().back()->label->setFont(font);
        }
    }

    // 创建各字母按钮
    // 各字母按钮左下角的横坐标
    QVector<QVector<int> > pos;
    // 第一层
    pos.push_back(QVector<int>());
    for(int i = 0; i < 7; ++i){
        myLabelButton * btn = new myLabelButton(this, 255, 255, 255, 155);
        btn->myResize(char_width, char_h);
        btn->myMove(edge[0] + (char_width + interval) * i, 700 - line_h[0]);
        char_btns.push_back(btn);
    }
    // 第二层
    pos.push_back(QVector<int>());
    for(int i = 0; i < 9; ++i){
        myLabelButton * btn = new myLabelButton(this, 255, 255, 255, 155);
        btn->myResize(char_width, char_h);
        btn->myMove(edge[1] + (char_width + interval) * i, 700 - line_h[1]);
        char_btns.push_back(btn);
    }
    // 第三层
    pos.push_back(QVector<int>());
    for(int i = 0; i < 10; ++i){
        myLabelButton * btn = new myLabelButton(this, 255, 255, 255, 155);
        btn->myResize(char_width, char_h);
        btn->myMove(edge[2] + (char_width + interval) * i, 700 - line_h[2]);
        char_btns.push_back(btn);
    }

    enter_btn = new myLabelButton(this, 255, 255, 255, 155);
    enter_btn->myResize(edge[0] - edge[2] - interval, char_h);
    enter_btn->myMove(edge[2], 700 - line_h[0]);
    enter_btn->setText("ENTER");

    cancel_btn = new myLabelButton(this, 255, 255, 255, 155);
    cancel_btn->myResize(edge[0] - edge[2] - interval, char_h);
    cancel_btn->myMove(400 - edge[0], 700 - line_h[0]);
    cancel_btn->setText("DEL");

    msg_box = new myLabelButton(this, 255, 255, 255, 155);
    msg_box->myResize(270, char_h);
    msg_box->myMove(20, 440);
    msg_box->setText("Congratulations! You win!");
    clr = QColor(255, 20, 147);
    QPalette pe;
    pe.setColor(QPalette::WindowText, clr);
    ft.setPointSize(12);
    ft.setBold(false);
    ft.setItalic(true);
    msg_box->label->setPalette(pe);
    msg_box->label->setFont(ft);
    msg_box->hide();

    lose_btn = new myLabelButton(this, 255, 255, 255, 155);
    lose_btn->myResize(270, char_h);
    lose_btn->myMove(20, 440);
    lose_btn->setText("Wasted");
    clr = QColor(50, 50, 50);
    pe.setColor(QPalette::WindowText, clr);
    ft.setPointSize(12);
    ft.setBold(false);
    ft.setItalic(true);
    lose_btn->label->setPalette(pe);
    lose_btn->label->setFont(ft);
    lose_btn->hide();

    anni_2 = new QPropertyAnimation(msg_box, "pos");
    anni_2->setStartValue(QPoint(-270, 440));
    anni_2->setEndValue(QPoint(20, 440));
    anni_2->setDuration(100);

    next_btn = new myLabelButton(this, 79, 133, 229, 155);
    next_btn->myResize(70, char_h);
    next_btn->myMove(310, 440);
    next_btn->setText("NEXT");
    next_btn->hide();

    anni_3 = new QPropertyAnimation(next_btn, "pos");
    anni_3->setStartValue(QPoint(400, 440));
    anni_3->setEndValue(QPoint(310, 440));
    anni_3->setDuration(100);

    err_box = new myLabelButton(this, 255, 255, 255, 155);
    err_box->myResize(320, char_h);
    err_box->myMove(-320, 440);
    err_box->setText("Word not found 0.0");
    err_box->label->setAlignment(Qt::AlignCenter);
    pe.setColor(QPalette::WindowText,Qt::red);
    err_box->label->setPalette(pe);

    anni_0 = new QPropertyAnimation(err_box, "pos");
    anni_0->setStartValue(QPoint(-320, 440));
    anni_0->setEndValue(QPoint(40, 440));
    anni_0->setDuration(100);

    anni_1 = new QPropertyAnimation(err_box, "pos");
    anni_1->setStartValue(QPoint(40, 440));
    anni_1->setEndValue(QPoint(400, 440));
    anni_1->setDuration(100);

    pause = new QPauseAnimation(3000);

    anni_group.addAnimation(anni_0);
    anni_group.addAnimation(pause);
    anni_group.addAnimation(anni_1);

    char_btns[0]->setText("Z");
    char_btns[1]->setText("X");
    char_btns[2]->setText("C");
    char_btns[3]->setText("V");
    char_btns[4]->setText("B");
    char_btns[5]->setText("N");
    char_btns[6]->setText("M");

    char_btns[7]->setText("A");
    char_btns[8]->setText("S");
    char_btns[9]->setText("D");
    char_btns[10]->setText("F");
    char_btns[11]->setText("G");
    char_btns[12]->setText("H");
    char_btns[13]->setText("J");
    char_btns[14]->setText("K");
    char_btns[15]->setText("L");

    char_btns[16]->setText("Q");
    char_btns[17]->setText("W");
    char_btns[18]->setText("E");
    char_btns[19]->setText("R");
    char_btns[20]->setText("T");
    char_btns[21]->setText("Y");
    char_btns[22]->setText("U");
    char_btns[23]->setText("I");
    char_btns[24]->setText("O");
    char_btns[25]->setText("P");

    this->resize(400, 700);
    this->setAutoFillBackground(true);
    QPalette pal = this->palette();
    pal.setBrush(this->backgroundRole(), QBrush(QColor(255,255,255, 150)));
    setPalette(pal);
    //设置标题
    QLabel* label = new QLabel(this);
    //设置标题内容
    label->setText("WORDLE");
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
    exit_btn->setStyleSheet("border-image:url(:/img/top.png);");

    connect(char_btns[0], &myLabelButton::clicked, this, [=](){
        game.enter('Z', letterboxes);
    });
    connect(char_btns[1], &myLabelButton::clicked, this, [=](){
        game.enter('X', letterboxes);
    });
    connect(char_btns[2], &myLabelButton::clicked, this, [=](){
        game.enter('C', letterboxes);
    });
    connect(char_btns[3], &myLabelButton::clicked, this, [=](){
        game.enter('V', letterboxes);
    });
    connect(char_btns[4], &myLabelButton::clicked, this, [=](){
        game.enter('B', letterboxes);
    });
    connect(char_btns[5], &myLabelButton::clicked, this, [=](){
        game.enter('N', letterboxes);
    });
    connect(char_btns[6], &myLabelButton::clicked, this, [=](){
        game.enter('M', letterboxes);
    });
    connect(char_btns[7], &myLabelButton::clicked, this, [=](){
        game.enter('A', letterboxes);
    });
    connect(char_btns[8], &myLabelButton::clicked, this, [=](){
        game.enter('S', letterboxes);
    });
    connect(char_btns[9], &myLabelButton::clicked, this, [=](){
        game.enter('D', letterboxes);
    });
    connect(char_btns[10], &myLabelButton::clicked, this, [=](){
        game.enter('F', letterboxes);
    });
    connect(char_btns[11], &myLabelButton::clicked, this, [=](){
        game.enter('G', letterboxes);
    });
    connect(char_btns[12], &myLabelButton::clicked, this, [=](){
        game.enter('H', letterboxes);
    });
    connect(char_btns[13], &myLabelButton::clicked, this, [=](){
        game.enter('J', letterboxes);
    });
    connect(char_btns[14], &myLabelButton::clicked, this, [=](){
        game.enter('K', letterboxes);
    });
    connect(char_btns[15], &myLabelButton::clicked, this, [=](){
        game.enter('L', letterboxes);
    });
    connect(char_btns[16], &myLabelButton::clicked, this, [=](){
        game.enter('Q', letterboxes);
    });
    connect(char_btns[17], &myLabelButton::clicked, this, [=](){
        game.enter('W', letterboxes);
    });
    connect(char_btns[18], &myLabelButton::clicked, this, [=](){
        game.enter('E', letterboxes);
    });
    connect(char_btns[19], &myLabelButton::clicked, this, [=](){
        game.enter('R', letterboxes);
    });
    connect(char_btns[20], &myLabelButton::clicked, this, [=](){
        game.enter('T', letterboxes);
    });
    connect(char_btns[21], &myLabelButton::clicked, this, [=](){
        game.enter('Y', letterboxes);
    });
    connect(char_btns[22], &myLabelButton::clicked, this, [=](){
        game.enter('U', letterboxes);
    });
    connect(char_btns[23], &myLabelButton::clicked, this, [=](){
        game.enter('I', letterboxes);
    });
    connect(char_btns[24], &myLabelButton::clicked, this, [=](){
        game.enter('O', letterboxes);
    });
    connect(char_btns[25], &myLabelButton::clicked, this, [=](){
        game.enter('P', letterboxes);
    });

    connect(cancel_btn, &myLabelButton::clicked, this, [=](){
        game.cancel(letterboxes);
    });
    connect(enter_btn, &myLabelButton::clicked, this, [=](){
        int res = game.guess(letterboxes, char_btns);
        if(res == 9){
            anni_group.start();
        }
        else if(res == 2){
            msg_box->show();
            next_btn->show();
            anni_2->start();
            anni_3->start();
        }
        else if(res == -2){
            lose_btn->show();
            lose_btn->setText("Wasted [answer: " + game.target +"]");
            next_btn->show();
            anni_3->start();
        }
    });
    connect(next_btn,  &myLabelButton::clicked, this, [=](){
        game.reset();
        for(int i = 0; i < 6; ++i){
            for(int j = 0; j < 5; ++j){
                letterboxes[i][j]->Recolor(50, 50, 50);
                letterboxes[i][j]->setText("");
            }
        }
        for(int i = 0; i < 26; ++i){
            char_btns[i]->Recolor(255, 255, 255);
        }
        msg_box->hide();
        next_btn->hide();
        lose_btn->hide();
    });
    this->grabKeyboard();
}
