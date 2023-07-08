#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include "cardset.h"
#include "wordsetwidget.h"
#include "addingwidget.h"
#include "mainwidget.h"
#include "reviewwidget.h"
#include "mybackground.h"
#include "myfile.h"
#include "newwordwidget.h"
#include "oldwordwidget.h"
#include "sentencewidget.h"
#include "notewidget.h"
#include "wordlewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QString GetDate();

    void SetMainPage();
    void ShowWordSetWidget();
    //退出事件
    void closeEvent(QCloseEvent* event);

    ~MainWindow();
private:
    Ui::MainWindow *ui;
    //设置虚化值
    int blurValue = 10;

    QWidget* data_widget;
    //词库动画对象
    QPropertyAnimation* animation;
    QPropertyAnimation* animation2;
    //添加词汇动画对象
    QPropertyAnimation* animation3;
    QPropertyAnimation* animation4;
    //复习词汇动画对象
    QPropertyAnimation* animation5;
    QPropertyAnimation* animation6;
    // wordle动画对象
    QPropertyAnimation* animation7;
    QPropertyAnimation* animation8;
    //背景图片对象
    MyBackground* background_widget;
    //主界面对象
    MainWidget* main_widget;
    //词库对象
    WordSetWidget* wordSet_widget;
    //添加词汇对象
    AddingWidget* adding_widget;
    //复习词汇对象
    ReviewWidget* review_widget;
    //卡库对象
    CardSet* cardSetP;
    //生词本动画
    QPropertyAnimation* animation_new;
    QPropertyAnimation* animation_new2;
    //熟词本动画
    QPropertyAnimation* animation_old;
    QPropertyAnimation* animation_old2;
    //生词本界面
    NewWordWidget* newWordWidget;
    //熟词本界面
    OldWordWidget* oldWordWidget;

    //句库动画
    QPropertyAnimation* animation_sentence;
    QPropertyAnimation* animation_sentence2;
    //笔记动画
    QPropertyAnimation* animation_note;
    QPropertyAnimation* animation_note2;
    //句库界面
    SentenceWidget* sentenceWidget;
    //笔记界面
    NoteWidget* noteWidget;
    WordleWidget* wordle_widget;

};
#endif // MAINWINDOW_H
