#ifndef NEWPOST_H
#define NEWPOST_H

#include <QDialog>
#include "post.h"


namespace Ui {
class newpost;
}

class newpost : public QDialog
{
    Q_OBJECT

public:
    explicit newpost(QWidget *parent = nullptr);
    ~newpost();

private slots:
    void on_pushButton_clicked();

private:
    Ui::newpost *ui;
};

#endif // NEWPOST_H
