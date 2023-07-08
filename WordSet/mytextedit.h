#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QWidget>
#include <QTextEdit>
#include <QCheckBox>

class myTextEdit : public QWidget
{
    Q_OBJECT
public:
    explicit myTextEdit(QWidget *parent = nullptr);
    void setText(const QString& s);
    QString text();

    QTextEdit* textEdit;
    QCheckBox* edit;
    QCheckBox* collect;

signals:

};

#endif // MYTEXTEDIT_H
