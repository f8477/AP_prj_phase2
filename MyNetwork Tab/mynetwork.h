#ifndef MYNETWORK_H
#define MYNETWORK_H

#include <QWidget>

namespace Ui {
class MyNetwork;
}

class MyNetwork : public QWidget
{
    Q_OBJECT

public:
    explicit MyNetwork(QWidget *parent = nullptr);
    ~MyNetwork();

private:
    Ui::MyNetwork *ui;
};

#endif // MYNETWORK_H
