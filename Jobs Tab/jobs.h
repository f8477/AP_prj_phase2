#ifndef JOBS_H
#define JOBS_H

#include <QWidget>

namespace Ui {
class Jobs;
}

class Jobs : public QWidget
{
    Q_OBJECT

public:
    explicit Jobs(QWidget *parent = nullptr);
    ~Jobs();

private:
    Ui::Jobs *ui;
};

#endif // JOBS_H
