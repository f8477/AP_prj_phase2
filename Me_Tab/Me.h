#ifndef ME_H
#define ME_H

#include <QWidget>
#include "profileedit.h"

namespace Ui {
class Me;
}

class Me : public QWidget
{
    Q_OBJECT

public:
    explicit Me(QWidget *parent = nullptr);
    ~Me();

private slots:
    void on_companySign_Button_2_clicked();

    void on_companySign_Button_3_clicked();

private:
    Ui::Me *ui;
    ProfileEdit *profile_edit;
};

#endif // ME_H
