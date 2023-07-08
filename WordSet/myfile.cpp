#include "myfile.h"
#include "cardset.h"
#include "card.h"
#include <QFileInfo>
#include <QFile>
#include <QDebug>

QString MyFile::filePath = "./data.txt";

/**
 * @brief MyFile::MyFile
 * 读取文件对象
 * @author 小组组长
 */
MyFile::MyFile()
{

}

void MyFile::WriteFile(CardSet * cs){
    QFile file(filePath);
    file.open(QIODevice::WriteOnly);

    // write
    // 目前的逻辑是 每次存储都将data.txt清空重新写入
    // data.txt中每列数据依次代表：
    // 单词 | 意思 | 例句 | 笔记 | 熟练度 | 例句是否被收藏 | 笔记是否被收藏
    file.resize(0);
    QTextStream out(&file);
    QVector<Card*> cards = cs->GetAllCards();
    for(QVector<Card*>::iterator it = cards.begin(); it != cards.end(); ++it){
        QString str = *((*it)->word);
        str.append("|");
        str.append(*((*it)->meaning)).append("|");
        QString tmp = (*(*it)->sentence);
        tmp.replace("\n", "@");
        str.append(tmp).append("|");
        QString tmp2 = (*(*it)->sentence);
        tmp2.replace("\n", "@");
        str.append(tmp2).append("|");
        str.append(QString::number((*it)->masterLevel)).append("|");
        if( (*it)->IsSentenceCollected() ){
            str += "1|";
        }
        else{
            str += "0|";
        }
        if( (*it)->IsNoteCollected() ){
            str += "1|";
        }
        else{
            str += "0";
        }
        out << str << "\n";
    }

    file.close();
}

CardSet * MyFile::ReadFile(){
    QFile file("./data.txt");
    QFileInfo  info(file);
    MyFile::filePath = info.absoluteFilePath();
    file.open(QIODevice::ReadOnly);

    // read
    CardSet * cs = new CardSet(nullptr);
    while( !file.atEnd() ){
        QString line = file.readLine();
        QStringList variable_list = line.split('|');
        QString word = variable_list[0];
        QString meaning = variable_list[1];
        QString sentence = variable_list[2];
        QString note = variable_list[3];
        int master_level = variable_list[4].toInt();
        bool sentence_collected = (variable_list[5] == "1");
        bool note_collected = (variable_list[6] == "1");
        sentence.replace("@", "\n");
        note.replace("@", "\n");
        Card * card = new Card(new QString(word), new QString(meaning), new QString(sentence), new QString(note));
        card->ChangeMasterLevel(master_level);
        if( sentence_collected ){ card->CollectSentence(); }
        if( note_collected ){ card->CollectNote(); }
        cs->AddNewCard(card);
    }
    file.close();
    qDebug() << ("open " + filePath + " successfully");
    return cs;
}
