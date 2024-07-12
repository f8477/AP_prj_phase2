#include "companysignup.h"
#include "ui_companysignup.h"

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QRandomGenerator>
#include <QPainter>

#include <QStringList>
#include <QMessageBox>

CompanySignup::CompanySignup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CompanySignup)
{
    ui->setupUi(this);

    ui->EyeBTN_1->setCursor(Qt::PointingHandCursor);
    ui->EyeBTN_2->setCursor(Qt::PointingHandCursor);
    ui->RefreshBTN->setCursor(Qt::PointingHandCursor);

    ui->EyeBTN_1->setIcon(QIcon(":/images/assets/eye-close.png"));
    ui->EyeBTN_2->setIcon(QIcon(":/images/assets/eye-close.png"));
    ui->RefreshBTN->setIcon(QIcon(":/images/assets/refresh.png"));

    ui->EditPassword->setEchoMode(QLineEdit::Password);
    ui->EditConfrimPassword->setEchoMode(QLineEdit::Password);

    showPassword = showConfrimPassword = false;

    const QPixmap China(":/images/assets/china.png");
    const QPixmap Germany(":/images/assets/germany.png");
    const QPixmap Iran(":/images/assets/iran.png");
    const QPixmap Iraq(":/images/assets/iraq.png");
    const QPixmap Russia(":/images/assets/russia.png");
    const QPixmap UnitedStates(":/images/assets/united_states.png");

    QStringList countries = {"choose country", "China    +86", "Germany    +49", "Iran    +98", "Iraq    +964", "Russia    +7095", "United States    +1"};
    ui->PhoneComboBox->addItems(countries);

    ui->PhoneComboBox->setItemIcon(1,QIcon(China));
    ui->PhoneComboBox->setItemIcon(2,QIcon(Germany));
    ui->PhoneComboBox->setItemIcon(3,QIcon(Iran));
    ui->PhoneComboBox->setItemIcon(4,QIcon(Iraq));
    ui->PhoneComboBox->setItemIcon(5,QIcon(Russia));
    ui->PhoneComboBox->setItemIcon(6,QIcon(UnitedStates));

    on_RefreshBTN_clicked();
}

CompanySignup::~CompanySignup()
{
    delete ui;
}

void CompanySignup::on_EyeBTN_1_clicked()
{
    if(showPassword)
    {
        showPassword = false;
        ui->EyeBTN_1->setIcon(QIcon(":/images/assets/eye-close.png"));
        ui->EditPassword->setEchoMode(QLineEdit::Password);
    }

    else
    {
        showPassword = true;
        ui->EyeBTN_1->setIcon(QIcon(":/images/assets/eye.png"));
        ui->EditPassword->setEchoMode(QLineEdit::Normal);
    }
}


void CompanySignup::on_EyeBTN_2_clicked()
{
    if(showConfrimPassword)
    {
        showConfrimPassword = false;
        ui->EyeBTN_2->setIcon(QIcon(":/images/assets/eye-close.png"));
        ui->EditConfrimPassword->setEchoMode(QLineEdit::Password);
    }

    else
    {
        showConfrimPassword = true;
        ui->EyeBTN_2->setIcon(QIcon(":/images/assets/eye.png"));
        ui->EditConfrimPassword->setEchoMode(QLineEdit::Normal);
    }
}

int CompanySignup::searchUser(QString username, QString password)
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:\\Users\\Sajjad\\Desktop\\AP Project_july 2024\\AP_prj_phase2\\project.db");
    database.open();

    QSqlQuery query;
    query.exec("SELECT Password FROM Company WHERE Username = '"+ username +"'");

    if(query.first())
    {
        if(password == query.value(0).toString())
        {
            database.close();
            return 1;
        }

        else
        {
            database.close();
            return 0;
        }
    }

    database.close();
    return -1;
}

int CompanySignup::checkConfrimPassword()
{
    if(ui->EditConfrimPassword->text() != ui->EditPassword->text())
        return 0;

    return 1;
}

QString CompanySignup::generateRandomTxt(int len)
{
    QString randomTxt;
    for (int i = 0; i < len; i++)
        {
            int index = QRandomGenerator::global()->bounded(dictionary.length());
            randomTxt.append(dictionary.at(index));
        }
    return randomTxt;
}

QPixmap CompanySignup::generateCaptchaImg(const QString &text)
{
    QPixmap pixmap(160, 50);
    pixmap.fill(Qt::white);

    QPainter painter(&pixmap);
    painter.setPen(Qt::black);
    QFont font("Arial", 16);
    painter.setFont(font);
    painter.drawText(pixmap.rect(), Qt::AlignCenter, text);

    return pixmap;
}


void CompanySignup::on_RefreshBTN_clicked()
{
    QString captchatext = generateRandomTxt(4);
    captchaCode = captchatext;
    QPixmap captchaimage = generateCaptchaImg(captchatext);
    ui->ShowCaptcha->setPixmap(captchaimage);
}

void CompanySignup::clickForSignup()
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:\\Users\\Sajjad\\Desktop\\AP Project_july 2024\\AP_prj_phase2\\project.db");
    database.open();

    QSqlQuery query;
    QString username = ui->EditUsername->text();
    QString email = ui->EditEmail->text();
    QString password = ui->EditPassword->text();
    QString phoneNum = ui->EditPhoneNum->text();
    QString CompanyName = ui->Edit_CoName->text();

    query.exec("SELECT Username FROM Company WHERE Username = '"+ username +"'");

    if(query.first())
    {
        QMessageBox::warning(this, "duplicate username", "An account with the entered username exists");
        database.close();
        return;
    }

    else if(ui->CaptchaLineEdit->text() == captchaCode)
    {
        QSqlQuery tmpQuery;
        tmpQuery.exec("INSERT INTO Company(CO_Name, Username, Email, Password, Phone_Num)VALUES('"+ CompanyName +"', '"+ username +"', '"+email+"', '"+ password +"', '"+ phoneNum +"')");
        ui->EditUsername->clear();
        ui->EditPassword->clear();
        ui->EditConfrimPassword->clear();
        ui->EditPhoneNum->clear();
        ui->Edit_CoName->clear();
        ui->CaptchaLineEdit->clear();
        QMessageBox::information(this, "signup successfully", "the account created");
        database.close();
    }
    else
    {
        QMessageBox::warning(this, " ", "captcha code incorrect");
        on_RefreshBTN_clicked();
        ui->CaptchaLineEdit->clear();
        database.close();
    }
}
