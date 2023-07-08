#include "wordsection.h"

WordSection::WordSection(QWidget *parent, Card* pt)
    : QWidget{parent}, p(pt)
{
    this->setFixedSize(400, 70);

    word = new QLabel(this);
    checkBox = new QCheckBox(this);
    checkBox->setCheckState(Qt::Unchecked);

    //设置大小位置
    checkBox->resize(30, 30);
    checkBox->move(10, 20);
    word->resize(360, 70);
    word->move(40, 0);

    loadWord();
    hide();
}

void WordSection::loadWord()
{
    word->setText(*(p->word));
}

void WordSection::showCheckBox()
{
    checkBox->show();
}
void WordSection::hideCheckBox()
{
    checkBox->hide();
}

bool WordSection::isChecked()
{
    return checkBox->checkState();
}

void WordSection::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);	// 反锯齿;
    painter.setBrush(QBrush(QColor(0, 191, 255, 170)));
    painter.setPen(Qt::transparent);
    QRect rect = this->rect();
    rect.setWidth(rect.width() - 1);
    rect.setHeight(rect.height() - 1);
    painter.drawRoundedRect(rect, 10, 10);
    QWidget::paintEvent(event);
}
