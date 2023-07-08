#include "reviewwidget.h"

/**
 * @brief ReviewWidget::ReviewWidget
 * @param parent
 * @param p
 * @param i
 * 复习界面模块
 * @author 派蒙今天吃什么
 */
ReviewWidget::ReviewWidget(QWidget *parent, CardSet* p, int i)
    : QWidget{parent},index(i)
{
    this->resize(400, 700);
    this->setAutoFillBackground(true);
    QPalette pal = this->palette();
    pal.setBrush(this->backgroundRole(), QBrush(QColor(255,255,255, 150)));
    setPalette(pal);
    //设置标题
    QLabel* label = new QLabel(this);
    //设置标题内容
    label->setText("复习词汇");
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
    exit_btn->setStyleSheet("border-image:url(:/img/right.png);");

    //设置内容
    //设置单词word
    word = new QLabel(this);
    word_label = new QLabel(this);
    //调整
    word_label->setText("单词:");
    word_label->setFont(MyFont::font);
    word_label->resize(60, 40);
    word_label->move(30, 50);
    word->resize(340, 40);
    word->move(30, 100);

    //设置意思mean_edit
    mean_label = new QLabel(this);
    mean_edit = new myLineEdit(this);
    //调整
    mean_label->setText("英文释义:");
    mean_label->setFont(MyFont::font);
    mean_label->resize(60, 40);
    mean_label->move(30, 130);
    mean_edit->resize(340, 60);
    mean_edit->move(30, 180);

    //添加sentenceEdit sentenceLabel
    sentence_label = new QLabel(this);
    sentence_edit = new myTextEdit(this);
    //调整
    sentence_label->setText("例句:");
    sentence_label->setFont(MyFont::font);
    sentence_label->resize(60, 40);
    sentence_label->move(30, 210);
    sentence_edit->resize(340, 100);
    sentence_edit->move(30, 260);

    //添加noteEdit noteLabel
    note_label = new QLabel(this);
    note_edit = new myTextEdit(this);
    //调整
    note_label->setText("笔记:");
    note_label->setFont(MyFont::font);
    note_label->resize(60, 40);
    note_label->move(30, 400);
    note_edit->resize(340, 100);
    note_edit->move(30, 450);


    //设置底层按键
    recognize = new myLabelButton(this);
    notSure = new myLabelButton(this);
    forget = new myLabelButton(this);
    nextWord = new myLabelButton(this);
    nextWord2 = new myLabelButton(this);
    gotWro = new myLabelButton(this);
    reachEnd = new myLabelButton(this);
    //安排前三个按钮
    recognize->setText("认识");
    recognize->myResize(100, 60);
    notSure->setText("模糊");
    notSure->myResize(100, 60);
    forget->setText("不认识");
    forget->myResize(100, 60);

    recognize->myMove(20, 640);
    notSure->myMove(150, 640);
    forget->myMove(280, 640);
    //安排后四个按键
    nextWord->setText("下一词");
    nextWord->myResize(160, 60);
    nextWord2->setText("下一词");
    nextWord2->myResize(360, 60);
    gotWro->setText("记错了");
    gotWro->myResize(160, 60);
    reachEnd->setText("回滚记忆");
    reachEnd->myResize(360, 60);

    nextWord->myMove(20, 640);
    nextWord2->myMove(20, 640);
    gotWro->myMove(220, 640);
    reachEnd->myMove(20, 640);

    //set final
    final = new QLabel(this);
    final->setText("你已经记住了所有单词");
    final->resize(400, 660);
    final->move(0, 40);
    final->setAlignment(Qt::AlignCenter);
    final->hide();

    /**
     * 设置属性
     */
    //刚开始的时候隐藏mean sentence note
    setInvisible();
    //设置CardSet的对象
    setCardSet(p);

    //connect part
    //记得按键
    connect(recognize, &myLabelButton::clicked, this, [=](){
        //单词熟练度+1
        (*itr)->ChangeMasterLevel(1);
        //改变界面
        setVisible();
    });
    //模糊按键
    connect(notSure, &myLabelButton::clicked, this, [=](){
        //单词熟练度+0
        (*itr)->ChangeMasterLevel(0);
        //改变界面
        setVisible();
    });
    //忘记按键
    connect(forget, &myLabelButton::clicked, this, [=](){
        //单词熟练度-1
        (*itr)->ChangeMasterLevel(-1);
        //改变界面
        setVisible();
        nextWord->hide();
        gotWro->hide();
        nextWord2->show();
    });

    //下一词按键
    connect(nextWord, &myLabelButton::clicked, this, [=](){
        refreshContents();
        //itr++
        itr++;
        //设置不可见
        setInvisible();
        //加载单词
        loadWord();
    });
    //下一词按键2
    connect(nextWord2, &myLabelButton::clicked, this, [=](){
        refreshContents();
        //itr++
        itr++;
        //设置不可见
        setInvisible();
        //加载单词
        loadWord();
    });
    //记错了按键
    connect(gotWro, &myLabelButton::clicked, this, [=](){
        refreshContents();
        //熟练度-1
        (*itr)->ChangeMasterLevel(-1);
        //itr++
        itr++;
        //设置不可见
        setInvisible();
        //加载单词
        loadWord();
    });
    //回滚按键
    connect(reachEnd, &myLabelButton::clicked, this, [=](){
        //itr = container.begin()
        if(refresh() == -1) return;
        setInvisible();
    });

}

void ReviewWidget::setCardSet(CardSet* p)
{
    cardSetP = p;
}

void ReviewWidget::setInvisible()
{
    word_label->show();
    word->show();

    mean_label->hide();
    mean_edit->hide();
    sentence_label->hide();
    sentence_edit->hide();
    note_label->hide();
    note_edit->hide();

    recognize->show();
    notSure->show();
    forget->show();
    nextWord->hide();
    nextWord2->hide();
    gotWro->hide();
    reachEnd->hide();

    final->hide();
}
void ReviewWidget::setVisible(){
    word_label->show();
    word->show();

    mean_label->show();
    mean_edit->show();
    sentence_label->show();
    sentence_edit->show();
    note_label->show();
    note_edit->show();

    recognize->hide();
    notSure->hide();
    forget->hide();
    nextWord2->hide();
    nextWord->show();
    gotWro->show();
    reachEnd->hide();

    final->hide();
}

void ReviewWidget::setContainer(int index)
{
    /**
     * index == 1 -> get all cards
     * index == 2 -> get masterd cards
     * index == 3 -> get unmasterd cards
     * index == 4 -> get sentence collected cards
     * index == 5 -> get note collected cards
     */
    if(cardSetP == nullptr) return;
    switch(index)
    {
    case 1: container = cardSetP->GetAllCards(); break;
    case 2: container = cardSetP->GetMasterdCards(); break;
    case 3: container = cardSetP->GetUnmasterdCards(); break;
    case 4: container = cardSetP->GetSentenceCollectedCards(); break;
    case 5: container = cardSetP->GetNoteCollectedCards(); break;
    }
    itr = container.begin();
    qDebug() << "Container load successfully";
}

void ReviewWidget::loadWord()
{
    mean_edit->edit->setCheckState(Qt::Unchecked);
    sentence_edit->edit->setCheckState(Qt::Unchecked);
    note_edit->edit->setCheckState(Qt::Unchecked);
    if(itr == container.end())
    {
        qDebug() << "Reach the end of container";
        setInvisible();
        recognize->hide();
        notSure->hide();
        forget->hide();
        reachEnd->show();
        return;
    }
    word->setText(*((*itr)->word));
    mean_edit->setText(*((*itr)->meaning));
    sentence_edit->setText(*((*itr)->sentence));
    note_edit->setText(*((*itr)->note));

    if((*itr)->IsSentenceCollected())
        sentence_edit->collect->setCheckState(Qt::Checked);
    else
        sentence_edit->collect->setCheckState(Qt::Unchecked);
    if((*itr)->IsNoteCollected())
        note_edit->collect->setCheckState(Qt::Checked);
    else
        note_edit->collect->setCheckState(Qt::Unchecked);
}

int ReviewWidget::refresh()
{
    setInvisible();
    setContainer(index);
    if(container.isEmpty())
    {
        recognize->hide();
        notSure->hide();
        forget->hide();
        word_label->hide();
        word->hide();
        final->raise();
        final->show();
        return -1;
    }
    loadWord();
    return 1;
}

void ReviewWidget::refreshContents()
{
    QString __meaning = mean_edit->text();
    QString __sentence = sentence_edit->text();
    QString __note = note_edit->text();

    qDebug() << __sentence;

    (*itr)->ChangeMeaning(__meaning);
    (*itr)->ChangeSentence(__sentence);
    (*itr)->ChangeNote(__note);

    qDebug() << (*(*itr)->sentence);

    if(sentence_edit->collect->isChecked())
        (*itr)->CollectSentence();
    else
        (*itr)->DiscollectSentence();
    if(note_edit->collect->isChecked())
        (*itr)->CollectNote();
    else
        (*itr)->DiscollectNote();
}
