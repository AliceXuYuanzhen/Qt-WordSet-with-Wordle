#ifndef ADDINGWIDGET_H
#define ADDINGWIDGET_H

#include "mylabelbutton.h"
#include "cardset.h"
#include <QWidget>
#include <qpushbutton>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>

class AddingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AddingWidget(QWidget *parent = nullptr);

    QPushButton* exit_btn;
    myLabelButton* adding_btn;
    QLabel* word_label;
    QLineEdit* word_edit;
    QLabel* mean_label;
    QLineEdit* mean_edit;
    QLabel* sentence_label;
    QTextEdit* sentence_edit;
    QLabel* note_label;
    QTextEdit* note_edit;

    CardSet* cardSetP = nullptr;

    void setCardSet(CardSet* p);
    void clearContent();

signals:

};

#endif // ADDINGWIDGET_H
