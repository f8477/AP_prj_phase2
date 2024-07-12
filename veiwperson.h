#ifndef VEIWPERSON_H
#define VEIWPERSON_H

#include <QDialog>
#include <string>

namespace Ui {
class veiwperson;
}

class veiwperson : public QDialog
{
    Q_OBJECT

public:
    explicit veiwperson(QWidget *parent = nullptr);
    ~veiwperson();

private slots:
    void on_Reload_clicked();

private:
    Ui::veiwperson *ui;
};

#endif // VEIWPERSON_H
