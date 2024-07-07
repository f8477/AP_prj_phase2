#ifndef NEWPOST_H
#define NEWPOST_H

#include <QDialog>

namespace Ui {
class newpost;
}

class newpost : public QDialog
{
    Q_OBJECT

public:
    explicit newpost(QWidget *parent = nullptr);
    ~newpost();

private:
    Ui::newpost *ui;
};

#endif // NEWPOST_H
