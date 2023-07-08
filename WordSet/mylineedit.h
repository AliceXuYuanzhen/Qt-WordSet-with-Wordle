#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QWidget>
#include <QCheckBox>
#include <QLineEdit>

class myLineEdit : public QWidget
{
    Q_OBJECT
public:
    explicit myLineEdit(QWidget *parent = nullptr);
    void setText(const QString& s);
    QString text();

    QLineEdit* lineEdit;
    QCheckBox* edit;
signals:

};

#endif // MYLINEEDIT_H
