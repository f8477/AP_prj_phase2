#ifndef MESSAGING_H
#define MESSAGING_H

#include <QWidget>

namespace Ui {
class Messaging;
}

class Messaging : public QWidget
{
    Q_OBJECT

public:
    explicit Messaging(QWidget *parent = nullptr);
    ~Messaging();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

private:
    Ui::Messaging *ui;
};

#endif // MESSAGING_H
