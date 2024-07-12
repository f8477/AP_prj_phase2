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
#include "account.h"
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home),
    newpostWindow(nullptr),
    commentP(nullptr)
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
    if (commentP) {
            delete commentP;
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
//    QString useid = User::getInstance().getUsername();

    QSqlQuery query;
    query.prepare("SELECT Skills FROM Person WHERE Username = '"+ useid +"'");

    if (!query.exec()) {
        qWarning() << "Error: query execution failed -" << query.lastError();
//            db.close();
        return;
    }

    if (query.next()) {

        QString skills = query.value("Skills").toString();
        ui->textEdit->setText(skills);
    } else {
        qWarning() << "No data found";
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


QString pid(){
    QString post_id = "1";
    QSqlQuery q;

    q.exec("SELECT * FROM Post");
    q.last();
    if (q.isValid()){
        int index = q.value("Post_ID").toInt();
        index++;
        post_id = QString::number(index);;
    }else{
        post_id = "1";
    }

    return post_id;
}


void Home::on_pushButton_23_clicked()
{
    QString useid = User::getInstance().getUsername();
    QString text = ui->textEdit_2->toPlainText();
    QString post_id = pid();

    QSqlQuery q;
    q.exec("INSERT INTO Post(Content_Text, Sender_ID, Post_ID)VALUES('"+text+"', '"+useid+"', '"+post_id+"')");
    QMessageBox::information(this, "Repost", "Repost successfuly");

}


void Home::on_pushButton_35_clicked()
{
    QString useid = User::getInstance().getUsername();
    QString text = ui->textEdit_8->toPlainText();
    QString post_id = pid();

    QSqlQuery q;
    q.exec("INSERT INTO Post(Content_Text, Sender_ID, Post_ID)VALUES('"+text+"', '"+useid+"', '"+post_id+"')");
    QMessageBox::information(this, "Repost", "Repost successfuly");
}


void Home::on_pushButton_37_clicked()
{
    QString useid = User::getInstance().getUsername();
    QString text = ui->textEdit_4->toPlainText();
    QString post_id = pid();

    QSqlQuery q;
    q.exec("INSERT INTO Post(Content_Text, Sender_ID, Post_ID)VALUES('"+text+"', '"+useid+"', '"+post_id+"')");
    QMessageBox::information(this, "Repost", "Repost successfuly");
}


void Home::on_pushButton_39_clicked()
{
    QString useid = User::getInstance().getUsername();
    QString text = ui->textEdit_5->toPlainText();
    QString post_id = pid();

    QSqlQuery q;
    q.exec("INSERT INTO Post(Content_Text, Sender_ID, Post_ID)VALUES('"+text+"', '"+useid+"', '"+post_id+"')");
    QMessageBox::information(this, "Repost", "Repost successfuly");
}


void Home::on_pushButton_41_clicked()
{
    QString useid = User::getInstance().getUsername();
    QString text = ui->textEdit_6->toPlainText();
    QString post_id = pid();

    QSqlQuery q;
    q.exec("INSERT INTO Post(Content_Text, Sender_ID, Post_ID)VALUES('"+text+"', '"+useid+"', '"+post_id+"')");
    QMessageBox::information(this, "Repost", "Repost successfuly");
}


void Home::on_pushButton_25_clicked()
{

}


void Home::on_pushButton_5_clicked()
{
//    GlobalUser::getInstance().setUsername("new_username");
    QString text = ui->textEdit_2->toPlainText();
    QString username = ui->label_6->text();
//    QMessageBox::information(this, "text", text);
//    QMessageBox::information(this, "username", username);


//    QSqlQuery q;
//    q.exec("SELECT * FROM Post WHERE Content_Text = '"+text+"' AND Sender_ID = '"+username+"'");
    QString Uid;



    QSqlQuery query;
    query.prepare("SELECT Post_ID FROM Post WHERE Sender_ID = '"+username+"' AND Content_TEXT = '"+text+"'");

    if (!query.exec()) {
        QMessageBox::information(this, "Uid", username);

        qWarning() << "Error: query execution failed -" << query.lastError();
//            db.close();
        return;
    }

    if (query.next()) {
        Uid = query.value(0).toString();
    } else {
        qWarning() << "No data found";
    }

    GlobalUser::getInstance().setUsername(Uid);

//    QMessageBox::information(this, "Uid", Uid);
    if (!commentP) {
       commentP = new CommentPage(this);
    }
    commentP->show();
}


void Home::on_pushButton_32_clicked()
{
        QString text = ui->textEdit_8->toPlainText();
        QString username = ui->label_29->text();
        QString Uid;
        QSqlQuery query;
        query.prepare("SELECT Post_ID FROM Post WHERE Sender_ID = '"+username+"' AND Content_TEXT = '"+text+"'");
        if (!query.exec()) {
            QMessageBox::information(this, "Uid", username);
            qWarning() << "Error: query execution failed -" << query.lastError();
            return;
        }
        if (query.next()) {
            Uid = query.value(0).toString();
        } else {
            qWarning() << "No data found";
        }
        GlobalUser::getInstance().setUsername(Uid);
        if (!commentP) {
           commentP = new CommentPage(this);
        }
        commentP->show();
}


void Home::on_pushButton_11_clicked()
{
    QString text = ui->textEdit_4->toPlainText();
    QString username = ui->label_10->text();
    QString Uid;
    QSqlQuery query;
    query.prepare("SELECT Post_ID FROM Post WHERE Sender_ID = '"+username+"' AND Content_TEXT = '"+text+"'");
    if (!query.exec()) {
        QMessageBox::information(this, "Uid", username);
        qWarning() << "Error: query execution failed -" << query.lastError();
        return;
    }
    if (query.next()) {
        Uid = query.value(0).toString();
    } else {
        qWarning() << "No data found";
    }
    GlobalUser::getInstance().setUsername(Uid);
    if (!commentP) {
       commentP = new CommentPage(this);
    }
    commentP->show();
}


void Home::on_pushButton_17_clicked()
{
    QString text = ui->textEdit_5->toPlainText();
    QString username = ui->label_12->text();
    QString Uid;
    QSqlQuery query;
    query.prepare("SELECT Post_ID FROM Post WHERE Sender_ID = '"+username+"' AND Content_TEXT = '"+text+"'");
    if (!query.exec()) {
        QMessageBox::information(this, "Uid", username);
        qWarning() << "Error: query execution failed -" << query.lastError();
        return;
    }
    if (query.next()) {
        Uid = query.value(0).toString();
    } else {
        qWarning() << "No data found";
    }
    GlobalUser::getInstance().setUsername(Uid);
    if (!commentP) {
       commentP = new CommentPage(this);
    }
    commentP->show();
}


void Home::on_pushButton_20_clicked()
{
    QString text = ui->textEdit_6->toPlainText();
    QString username = ui->label_14->text();
    QString Uid;
    QSqlQuery query;
    query.prepare("SELECT Post_ID FROM Post WHERE Sender_ID = '"+username+"' AND Content_TEXT = '"+text+"'");
    if (!query.exec()) {
        QMessageBox::information(this, "Uid", username);
        qWarning() << "Error: query execution failed -" << query.lastError();
        return;
    }
    if (query.next()) {
        Uid = query.value(0).toString();
    } else {
        qWarning() << "No data found";
    }
    GlobalUser::getInstance().setUsername(Uid);
    if (!commentP) {
       commentP = new CommentPage(this);
    }
    commentP->show();
}

