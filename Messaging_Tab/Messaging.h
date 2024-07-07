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

private:
    Ui::Messaging *ui;
};

#endif // MESSAGING_H
