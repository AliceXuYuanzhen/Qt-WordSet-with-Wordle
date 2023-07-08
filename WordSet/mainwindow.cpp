#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "wordsetwidget.h"

#include <QGraphicsOpacityEffect>
#include <QPushButton>
#include <QDebug>
#include <QLabel>
#include <QFont>

/**
 * @brief MainWindow::MainWindow
 * @param parent
 * 基类界面
 * @author 派蒙今天吃什么
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置窗口大小
    this->setFixedSize(400, 700);

    //加载背景图片
    background_widget = new MyBackground(this);
    background_widget->SetBlurEffect(0);
    //构建词库界面
    wordSet_widget = new WordSetWidget(this);
    //将词库界面移动到底部
    wordSet_widget->move(0, 700);
    wordSet_widget->show();

    //添加词库界面
    adding_widget = new AddingWidget(this);
    adding_widget->move(-400, 0);
    adding_widget->show();
    //添加cardset对象
    cardSetP = MyFile::ReadFile();
    adding_widget->setCardSet(cardSetP);

    //复习词汇界面
    review_widget = new ReviewWidget(this, cardSetP, 3);
    review_widget->move(400, 0);
    review_widget->show();

    //设置生词本界面
    newWordWidget = new NewWordWidget(this, cardSetP);
    newWordWidget->move(0, 700);
    //设置熟词界面
    oldWordWidget = new OldWordWidget(this, cardSetP);
    oldWordWidget->move(0, 700);
    //设置句库界面
    sentenceWidget = new SentenceWidget(this, cardSetP);
    sentenceWidget->move(0, 700);
    //设置笔记界面
    noteWidget = new NoteWidget(this, cardSetP);
    noteWidget->move(0, 700);
    // wordle界面
    wordle_widget = new WordleWidget(this);
    wordle_widget->move(0, -700);
    wordle_widget->show();

    //设置开始界面
    main_widget = new MainWidget(this);
    SetMainPage();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete data_widget;
}

//设置stackWidget的MainPage
void MainWindow::SetMainPage()
{
    int animation_time = 200;
    /**
     * Animation part
     */
    //设置词库进入动画
    animation = new QPropertyAnimation(wordSet_widget, "pos");
    animation->setStartValue(QPoint(0, this->height()));
    animation->setEndValue(QPoint(0, 0));
    animation->setDuration(animation_time);
    //构造词库退出动画
    animation2 = new QPropertyAnimation(wordSet_widget, "pos");
    animation2->setStartValue(QPoint(0, 0));
    animation2->setEndValue(QPoint(0, this->height()));
    animation2->setDuration(animation_time);


    //设置添加词汇进入动画
    animation3 = new QPropertyAnimation(adding_widget, "pos");
    animation3->setStartValue(QPoint(-400, 0));
    animation3->setEndValue(QPoint(0, 0));
    animation3->setDuration(animation_time);
    //设置添加词汇退出动画
    animation4 = new QPropertyAnimation(adding_widget, "pos");
    animation4->setStartValue(QPoint(0, 0));
    animation4->setEndValue(QPoint(-400, 0));
    animation4->setDuration(animation_time);

    //设置复习词汇进入动画
    animation5 = new QPropertyAnimation(review_widget, "pos");
    animation5->setStartValue(QPoint(400, 0));
    animation5->setEndValue(QPoint(0, 0));
    animation5->setDuration(animation_time);
    //设置复习词汇退出动画
    animation6 = new QPropertyAnimation(review_widget, "pos");
    animation6->setStartValue(QPoint(0, 0));
    animation6->setEndValue(QPoint(400, 0));
    animation6->setDuration(animation_time);

    // wordle进入动画
    animation7 = new QPropertyAnimation(wordle_widget, "pos");
    animation7->setStartValue(QPoint(0, -700));
    animation7->setEndValue(QPoint(0, 0));
    animation7->setDuration(animation_time);
    // wordle退出动画
    animation8 = new QPropertyAnimation(wordle_widget, "pos");
    animation8->setStartValue(QPoint(0, 0));
    animation8->setEndValue(QPoint(0, -700));
    animation8->setDuration(animation_time);

    //点击词库进入词库界面
    connect(main_widget->wordSet_btn, &myLabelButton::clicked, this, [=](){
        wordSet_widget->raise();
        main_widget->hide();
        animation->start();
        background_widget->SetBlurEffect(blurValue);
    });
    //点击词库退出词库界面
    connect(wordSet_widget->exit_btn, &QPushButton::clicked, this, [=](){
        animation2->start();
        main_widget->show();
        background_widget->SetBlurEffect(0);
    });

    //connect 添加词汇
    connect(main_widget->addNew_btn, &myLabelButton::clicked, this, [=](){
        adding_widget->raise();
        main_widget->hide();
        animation3->start();
        background_widget->SetBlurEffect(blurValue);
    });
    connect(adding_widget->exit_btn, &QPushButton::clicked, this, [=](){
        adding_widget->clearContent();
        animation4->start();
        main_widget->show();
        background_widget->SetBlurEffect(0);
    });

    //connect 复习词汇
    connect(main_widget->review_btn, &myLabelButton::clicked, this, [=](){
        review_widget->raise();
        review_widget->refresh();
        animation5->start();
        main_widget->hide();
        background_widget->SetBlurEffect(blurValue);
    });
    connect(review_widget->exit_btn, &QPushButton::clicked, this, [=](){
        animation6->start();
        main_widget->show();
        background_widget->SetBlurEffect(0);
    });

    //Animation part
    //设置进入动画
    animation_new = new QPropertyAnimation(newWordWidget, "pos");
    animation_new->setStartValue(QPoint(0, 700));
    animation_new->setEndValue(QPoint(0, 0));
    animation_new->setDuration(animation_time);
    //设置退出动画
    animation_new2 = new QPropertyAnimation(newWordWidget, "pos");
    animation_new2->setStartValue(QPoint(0, 0));
    animation_new2->setEndValue(QPoint(0, 700));
    animation_new2->setDuration(animation_time);

    //connect 词汇 生词本
    connect(wordSet_widget->newWord_btn, &BasicButton::clicked, this, [=](){
        newWordWidget->refresh();
        newWordWidget->raise();
        animation_new->start();
    });
    connect(newWordWidget->exit_btn, &QPushButton::clicked, this, [=](){
        animation_new2->start();
    });

    //设置进入动画
    animation_old = new QPropertyAnimation(oldWordWidget, "pos");
    animation_old->setStartValue(QPoint(0, 700));
    animation_old->setEndValue(QPoint(0, 0));
    animation_old->setDuration(animation_time);
    //设置退出动画
    animation_old2 = new QPropertyAnimation(oldWordWidget, "pos");
    animation_old2->setStartValue(QPoint(0, 0));
    animation_old2->setEndValue(QPoint(0, 700));
    animation_old2->setDuration(animation_time);

    //connect 词汇 生词本
    connect(wordSet_widget->learned_btn, &BasicButton::clicked, this, [=](){
        oldWordWidget->refresh();
        oldWordWidget->raise();
        animation_old->start();
    });
    connect(oldWordWidget->exit_btn, &QPushButton::clicked, this, [=](){
        animation_old2->start();
    });

    //设置进入动画
    animation_sentence = new QPropertyAnimation(sentenceWidget, "pos");
    animation_sentence->setStartValue(QPoint(0, 700));
    animation_sentence->setEndValue(QPoint(0, 0));
    animation_sentence->setDuration(animation_time);
    //设置退出动画
    animation_sentence2 = new QPropertyAnimation(sentenceWidget, "pos");
    animation_sentence2->setStartValue(QPoint(0, 0));
    animation_sentence2->setEndValue(QPoint(0, 700));
    animation_sentence2->setDuration(animation_time);

    //connect 词汇 生词本
    connect(wordSet_widget->sentence_btn, &BasicButton::clicked, this, [=](){
        sentenceWidget->refresh();
        sentenceWidget->raise();
        animation_sentence->start();
    });
    connect(sentenceWidget->exit_btn, &QPushButton::clicked, this, [=](){
        animation_sentence2->start();

    });

    //设置进入动画
    animation_note = new QPropertyAnimation(noteWidget, "pos");
    animation_note->setStartValue(QPoint(0, 700));
    animation_note->setEndValue(QPoint(0, 0));
    animation_note->setDuration(animation_time);
    //设置退出动画
    animation_note2 = new QPropertyAnimation(noteWidget, "pos");
    animation_note2->setStartValue(QPoint(0, 0));
    animation_note2->setEndValue(QPoint(0, 700));
    animation_note2->setDuration(animation_time);

    //connect 词汇 生词本
    connect(wordSet_widget->notes_btn, &BasicButton::clicked, this, [=](){
        noteWidget->refresh();
        noteWidget->raise();
        animation_note->start();
    });
    connect(noteWidget->exit_btn, &QPushButton::clicked, this, [=](){
        animation_note2->start();
    });

    //connect wordle
    connect(main_widget->wordle_btn,&myLabelButton::clicked, this, [=](){
        wordle_widget->raise();
        animation7->start();
        main_widget->hide();
        background_widget->SetBlurEffect(blurValue);
    });
    connect(wordle_widget->exit_btn,&QPushButton::clicked, this, [=](){
        animation8->start();
        main_widget->show();
        background_widget->SetBlurEffect(0);
    });
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    MyFile::WriteFile(cardSetP);
}
