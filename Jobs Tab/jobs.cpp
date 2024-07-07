#include "jobs.h"
#include "ui_jobs.h"

Jobs::Jobs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Jobs)
{
    ui->setupUi(this);
}

Jobs::~Jobs()
{
    delete ui;
}
