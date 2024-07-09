#ifndef PROFILEEDIT_H
#define PROFILEEDIT_H

#include <QDialog>

namespace Ui {
class ProfileEdit;
}

class ProfileEdit : public QDialog
{
    Q_OBJECT

public:
    explicit ProfileEdit(QWidget *parent = nullptr);
    ~ProfileEdit();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ProfileEdit *ui;
};

#endif // PROFILEEDIT_H
