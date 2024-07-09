#include "Messaging.h"
#include "ui_Messaging.h"
#include "account.h"
#include "directmessage.h"
#include <QString>
#include <QMessageBox>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>

Messaging::Messaging(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Messaging)
{
    ui->setupUi(this);
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("F:\\coding\\Projects\\AP_prj_phase2\\project.db");
    database.open();


}

Messaging::~Messaging()
{
    delete ui;
}

void Messaging::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString useid = User::getInstance().getUsername();

    QSqlQuery q;
    q.exec("SELECT Username FROM Person WHERE Username = '"+ username +"'");
    if (!q.first()){
        QMessageBox::warning(this, "Error", "this account not found!");
    }else{
        ui->label_2->setText(username);
    }

}


void Messaging::on_pushButton_2_clicked()
{
    QSqlQuery q;
    QString text = ui->textEdit->toPlainText();
    QString username = ui->label_2->text();
    QString useid = User::getInstance().getUsername();
    q.exec("INSERT INTO DirectMessage(Content_Text, Sender_ID, Receiver_ID)VALUES('"+text+"', '"+useid+"','"+username+"')");

}


void Messaging::on_pushButton_3_clicked()
{
    QString username = ui->label_2->text();
    QString useid = User::getInstance().getUsername();

    QSqlQuery q;
    q.exec("SELECT * FROM DirectMessage");
    q.last();
    int i = 1;
    if (!q.isValid()){
//        QMessageBox::warning(this, "Error", "tErrjeksfn!");

    }
    while (q.isValid() && i <= 5){
//        QMessageBox::warning(this, "Error", "tErrjeksfn!");

        QString checkre = q.value("Receiver_ID").toString();
        QString checkse = q.value("Sender_ID").toString();
        QString text = q.value("Content_Text").toString();
        if (checkse == useid && checkre == username){
//            QMessageBox::warning(this, "Error", "tErrjeksfn!");

            if (i == 1){
                ui->label_7->setText(useid);
                ui->textEdit_6->setText(text);
            }else if (i == 2){
                ui->label_6->setText(useid);
                ui->textEdit_5->setText(text);
            }else if (i == 3){
                ui->label_5->setText(useid);
                ui->textEdit_4->setText(text);
            }else if (i == 4){
                ui->label_4->setText(useid);
                ui->textEdit_3->setText(text);
            }else if (i == 5){
                ui->label_3->setText(useid);
                ui->textEdit_2->setText(text);
            }
            i++;
        }else if (checkse == username && checkre == useid){
            if (i == 1){
                ui->label_7->setText(username);
                ui->textEdit_6->setText(text);
            }else if (i == 2){
                ui->label_6->setText(username);
                ui->textEdit_5->setText(text);
            }else if (i == 3){
                ui->label_5->setText(username);
                ui->textEdit_4->setText(username);
            }else if (i == 4){
                ui->label_4->setText(username);
                ui->textEdit_3->setText(text);
            }else if (i == 5){
                ui->label_3->setText(username);
                ui->textEdit_2->setText(text);
            }
            i++;
        }
        q.previous();
    }



}

