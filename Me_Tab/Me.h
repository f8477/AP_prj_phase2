#ifndef ME_H
#define ME_H

#include <QWidget>

namespace Ui {
class Me;
}

class Me : public QWidget
{
    Q_OBJECT

public:
    explicit Me(QWidget *parent = nullptr);
    ~Me();

private:
    Ui::Me *ui;
};

#endif // ME_H
