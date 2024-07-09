#include "Home.h"
#include "ui_Home.h"
#include "account.h"
#include "directmessage.h"
#include <QFont>
#include <QString>
#include <QMessageBox>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>



Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home),
    newpostWindow(nullptr)
{

    ui->setupUi(this);

    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("F:\\coding\\Projects\\AP_prj_phase2\\project.db");
    database.open();


//    QString useid = User::getInstance().getUsername();
//    ui->label_20->setText(useid);
}

Home::~Home()
{
    delete ui;
    if (newpostWindow) {
            delete newpostWindow;
    }
}

void Home::on_pushButton_clicked()
{

    if (!newpostWindow) {
       newpostWindow = new newpost(this);
    }
    newpostWindow->show();
}
int i = 1;
void Home::on_pushButton_8_clicked()
{
    QString useid = User::getInstance().getUsername();
    ui->label_20->setText(useid);


    QSqlQuery q;

    if (q.exec("SELECT * FROM Post")) {
            q.last();
            i = 1;
            while (q.isValid() && i <= 5) {
                QString username = q.value("Sender_ID").toString();
                QString text = q.value("Content_Text").toString();

                if (i == 1){
                    ui->label_6->setText(username);
                    ui->textEdit_2->setText(text);
                }else if (i == 2){
                    ui->label_29->setText(username);
                    ui->textEdit_8->setText(text);
                }else if (i == 3){
                    ui->label_10->setText(username);
                    ui->textEdit_4->setText(text);
                }else if (i == 4){
                    ui->label_12->setText(username);
                    ui->textEdit_5->setText(text);
                }else if (i == 5){
                    ui->label_14->setText(username);
                    ui->textEdit_6->setText(text);
                }
                i++;
                q.previous();
            }
        } else {
//            qDebug() << "Error: " << query.lastError().text();
        }

    q.exec("SELECT * FROM Person");
    q.last();
    int j = 1;
    while (q.isValid() && j <= 2){
        QString username = q.value("Username").toString();
        if (username != useid){
            if (j == 1){
                ui->label_4->setText(username);

            }else if (j == 2){
                ui->label_16->setText(username);

            }
            j++;
        }
        q.previous();
    }

}



void Home::on_pushButton_4_clicked()
{
    QSqlQuery q;
    q.exec("SELECT * FROM Post");
    q.last();


    while (i && q.isValid()){
        i--;
        q.previous();
    }
    i = 1;
    while (q.isValid() && i <= 5) {
        QString username = q.value("Sender_ID").toString();
        QString text = q.value("Content_Text").toString();

        if (i == 1){
            ui->label_6->setText(username);
            ui->textEdit_2->setText(text);
        }else if (i == 2){
            ui->label_29->setText(username);
            ui->textEdit_8->setText(text);
        }else if (i == 3){
            ui->label_10->setText(username);
            ui->textEdit_4->setText(text);
        }else if (i == 4){
            ui->label_12->setText(username);
            ui->textEdit_5->setText(text);
        }else if (i == 5){
            ui->label_14->setText(username);
            ui->textEdit_6->setText(text);
        }
        i++;
        q.previous();
    }
}


void Home::on_pushButton_23_clicked()
{
    QString useid = User::getInstance().getUsername();
    QString text = ui->textEdit_2->toPlainText();

    QSqlQuery q;
    q.exec("INSERT INTO Post(Content_Text, Sender_ID)VALUES('"+text+"', '"+useid+"')");
    QMessageBox::information(this, "Repost", "Repost successfuly");

}


void Home::on_pushButton_35_clicked()
{
    QString useid = User::getInstance().getUsername();
    QString text = ui->textEdit_8->toPlainText();

    QSqlQuery q;
    q.exec("INSERT INTO Post(Content_Text, Sender_ID)VALUES('"+text+"', '"+useid+"')");
    QMessageBox::information(this, "Repost", "Repost successfuly");
}


void Home::on_pushButton_37_clicked()
{
    QString useid = User::getInstance().getUsername();
    QString text = ui->textEdit_4->toPlainText();

    QSqlQuery q;
    q.exec("INSERT INTO Post(Content_Text, Sender_ID)VALUES('"+text+"', '"+useid+"')");
    QMessageBox::information(this, "Repost", "Repost successfuly");
}


void Home::on_pushButton_39_clicked()
{
    QString useid = User::getInstance().getUsername();
    QString text = ui->textEdit_5->toPlainText();

    QSqlQuery q;
    q.exec("INSERT INTO Post(Content_Text, Sender_ID)VALUES('"+text+"', '"+useid+"')");
    QMessageBox::information(this, "Repost", "Repost successfuly");
}


void Home::on_pushButton_41_clicked()
{
    QString useid = User::getInstance().getUsername();
    QString text = ui->textEdit_6->toPlainText();

    QSqlQuery q;
    q.exec("INSERT INTO Post(Content_Text, Sender_ID)VALUES('"+text+"', '"+useid+"')");
    QMessageBox::information(this, "Repost", "Repost successfuly");
}


void Home::on_pushButton_25_clicked()
{

}

