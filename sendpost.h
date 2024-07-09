#ifndef SENDPOST_H
#define SENDPOST_H

#include <QDialog>

namespace Ui {
class SendPost;
}

class SendPost : public QDialog
{
    Q_OBJECT

public:
    explicit SendPost(QWidget *parent = nullptr);
    ~SendPost();

private:
    Ui::SendPost *ui;
};

#endif // SENDPOST_H
