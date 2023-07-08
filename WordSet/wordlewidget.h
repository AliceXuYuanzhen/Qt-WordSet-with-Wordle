#ifndef WORDLEWIDGET_H
#define WORDLEWIDGET_H

#include "mylabelbutton.h"
#include <QWidget>
#include <QPushButton>
#include <QFile>
#include <QRandomGenerator>
#include <QMessageBox>
#include<QPropertyAnimation>
#include <QPauseAnimation>
#include <QSequentialAnimationGroup>
#include <QFont>
#include <QColor>

class WordleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WordleWidget(QWidget *parent = nullptr);

    QVector<myLabelButton*> char_btns;
    myLabelButton* enter_btn;
    myLabelButton* cancel_btn;
    QPushButton* exit_btn;
    myLabelButton* msg_box;
    myLabelButton* next_btn;
    myLabelButton* err_box;
    myLabelButton* lose_btn;
    QPropertyAnimation * anni_0;
    QPropertyAnimation * anni_1;
    QPropertyAnimation * anni_2;
    QPropertyAnimation * anni_3;
    QPauseAnimation * pause;
    QSequentialAnimationGroup anni_group;
    QFont ft;
    QColor clr;
    QVector<QVector<myLabelButton*> > letterboxes;

    class Game{
    public:
        int guess_time = 0;
        int ptr = 0;
        char now_word[6] = {0};
        bool game_over = false;
        QStringList target_list;
        QStringList possible_list;
        QString target;
        Game(){
            QFile file1(":/img/officialWords.txt");
            file1.open(QIODevice::ReadOnly);
            target_list = QStringList();
            while( !file1.atEnd() ){
                QString word = file1.readLine();
                target_list.push_back(word.trimmed());
            }
            file1.close();
            QFile file2(":/img/allWords.txt");
            file2.open(QIODevice::ReadOnly);
            possible_list = QStringList();
            while( !file2.atEnd() ){
                QString word = file2.readLine();
                possible_list.push_back(word.trimmed());
            }
            file2.close();
            int rand_idx = QRandomGenerator::global()->bounded(target_list.size());
            target = target_list.at(rand_idx);
            qDebug() << target;
        }

        void generate_target(){
            int rand_idx = QRandomGenerator::global()->bounded(target_list.size());
            target = target_list.at(rand_idx);
            qDebug() << target;
        }

        void reset(){
            guess_time = 0;
            ptr = 0;
            generate_target();
            for(int i = 0; i < 6; ++i){
                now_word[i] = 0;
            }
            game_over = false;
        }

        void enter(char c, QVector<QVector<myLabelButton*> > letterboxes){
            if(game_over){ return; }
            if(ptr < 4){
                now_word[ptr] = c;
                QString str = "";
                str = c;
                letterboxes[guess_time][ptr]->setText(str);
                ++ptr;
            }
            else if(ptr == 4 && now_word[4] == 0){
                now_word[ptr] = c;
                QString str = "";
                str = c;
                letterboxes[guess_time][ptr]->setText(str);
            }
        }
        void check(){
            qDebug() << now_word;
        }
        void cancel(QVector<QVector<myLabelButton*> > letterboxes){
            if(game_over){ return; }
            if(ptr == 4 && now_word[4] != 0){
                now_word[ptr] = 0;
                letterboxes[guess_time][ptr]->setText("");
            }
            else if(ptr > 0){
                --ptr;
                now_word[ptr] = 0;
                letterboxes[guess_time][ptr]->setText("");
            }
            else if(ptr == 0){
                now_word[ptr] = 0;
                letterboxes[guess_time][ptr]->setText("");
            }
        }
        int guess(QVector<QVector<myLabelButton*> > letterboxes, QVector<myLabelButton*> btns){
            if(ptr != 4 || now_word[4] == 0){
                return -1;
            }
            if(guess_time == 6){
                return -1;
            }
            QString word(now_word);
            word = word.toLower();
            if(!possible_list.contains(word)){
                return 9;
            }
            for(int i = 0; i < 5; ++i){
                int tmp = 0;
                if(word[i] == target.toLower()[i]){
                    letterboxes[guess_time][i]->Recolor(83, 141, 78);
                    tmp = 1;
                }
                else if(target.toLower().contains(word[i])){
                    letterboxes[guess_time][i]->Recolor(181, 159, 59);
                    tmp = 2;
                }
                else{
                    letterboxes[guess_time][i]->Recolor(0, 0, 0);
                }
                int r[3] = { 50, 83, 181 };
                int g[3] = { 50, 141, 159 };
                int b[3] = { 50, 78, 59 };
                for(int j = 0; j < 3; ++j){
                    if(tmp == j){
                        if(word[i] == 'z'){
                            btns[0]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 'x'){
                            btns[1]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 'c'){
                            btns[2]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 'v'){
                            btns[3]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 'b'){
                            btns[4]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 'n'){
                            btns[5]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 'm'){
                            btns[6]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 'a'){
                            btns[7]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 's'){
                            btns[8]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 'd'){
                            btns[9]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 'f'){
                            btns[10]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 'g'){
                            btns[11]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 'h'){
                            btns[12]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 'j'){
                            btns[13]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 'k'){
                            btns[14]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 'l'){
                            btns[15]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 'q'){
                            btns[16]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 'w'){
                            btns[17]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 'e'){
                            btns[18]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 'r'){
                            btns[19]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 't'){
                            btns[20]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 'y'){
                            btns[21]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 'u'){
                            btns[22]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 'i'){
                            btns[23]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 'o'){
                            btns[24]->Recolor(r[j], g[j], b[j]);
                        }
                        else if(word[i] == 'p'){
                            btns[25]->Recolor(r[j], g[j], b[j]);
                        }
                    }
                }
            }

            int ret = 0;
            if(word.toLower() == target.toLower()){
                game_over = true;
                ret = 2;
            }
            else{
                qDebug() << "fail";
                ret = 0;
            }
            ++guess_time;
            ptr = 0;
            for(int i = 0; i <= 5; ++i){
                now_word[i] = 0;
            }
            qDebug() << now_word;
            if(guess_time == 6){
                game_over = true;
                ret = -2;
                qDebug() << "no more guess left";
            }
            return ret;
        }
    };
    Game game;

protected:
    void key_press_event(QKeyEvent *event);
};

#endif // WORDLEWIDGET_H
