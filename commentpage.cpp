#include "commentpage.h"
#include "ui_commentpage.h"
#include "account.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
//#include <QString>
#include <QMessageBox>


CommentPage::CommentPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CommentPage)
{
    ui->setupUi(this);
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("F:\\coding\\Projects\\AP_prj_phase2\\project.db");
    database.open();

    QSqlQuery q;
    QString post_id = GlobalUser::getInstance().getUsername();
//    QMessageBox::information(this, "khikhi", post_id);
    q.exec("SELECT * FROM Post WHERE Post_ID = '"+post_id+"'");
    q.next();
    QString Uid = q.value("Sender_ID").toString();
    ui->mainuser->setText(Uid);
    QString text = q.value("Content_Text").toString();
    ui->PostText->setText(text);

    int i = 1;
    q.exec("SELECT * FROM Comment WHERE Post_ID = '"+post_id+"'");
//    q.next();
    if (!q.first()){
//        QMessageBox::information(this, "hoee", "buggggggg");
    }
    while(q.isValid() && i <= 3){
        QString text = q.value("Content_Text").toString();
        QString Uid = q.value("Sender_ID").toString();
//        QMessageBox::information(this, "cont", text);
//        QMessageBox::information(this, "Sendi", Uid);
        if (i == 1){
            ui->comment1->setText(text);
            ui->user1->setText(Uid);
        }else if (i == 2){
            ui->comment2->setText(text);
            ui->user2->setText(Uid);

        }else if (i == 3){

            ui->comment3->setText(text);
            ui->user3->setText(Uid);
        }
        i++;
        q.next();
    }


//    showcomment(post_id);


}

CommentPage::~CommentPage()
{
    delete ui;
}

void CommentPage::on_ViewMore_clicked()
{
//    QSqlQuery q;
//    QString post_id = GlobalUser::getInstance().getUsername();
////    QMessageBox::information(this, "khikhi", post_id);
//    q.exec("SELECT * FROM Post WHERE Post_ID = '"+post_id+"'");
//    q.next();
//    QString Uid = q.value("Sender_ID").toString();
//    ui->mainuser->setText(Uid);
//    QString text = q.value("Content_Text").toString();
//    ui->PostText->setText(text);

////    showcomment(post_id);
}


void CommentPage::on_Send_clicked()
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("F:\\coding\\Projects\\AP_prj_phase2\\project.db");
    database.open();
    QString text = ui->mycomment->toPlainText();
    QString useid = User::getInstance().getUsername();
    QString post_id = GlobalUser::getInstance().getUsername();

    QMessageBox::information(this, "postid", post_id);
    QMessageBox::information(this, "useid", useid);
    QMessageBox::information(this, "text", text);
    QSqlQuery q;
    q.exec("INSERT INTO Comment(Content_Text, Sender_ID, Post_ID)VALUES('"+text+"', '"+useid+"', '"+post_id+"')");

}


void CommentPage::on_reload_clicked()
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("F:\\coding\\Projects\\AP_prj_phase2\\project.db");
    database.open();

    QSqlQuery q;
    QString post_id = GlobalUser::getInstance().getUsername();

    int i = 1;
    q.exec("SELECT * FROM Comment WHERE Post_ID = '"+post_id+"'");
    while(q.isValid() && i <= 3){
        QString text = q.value("Content_Text").toString();
        QString Uid = q.value("Sender_ID").toString();

        if (i == 1){
            ui->comment1->setText(text);
            ui->user1->setText(Uid);
        }else if (i == 2){
            ui->comment2->setText(text);
            ui->user2->setText(Uid);

        }else if (i == 3){

            ui->comment3->setText(text);
            ui->user3->setText(Uid);
        }
        i++;
        q.next();
    }
}

