#ifndef COMPANYSIGNUP_H
#define COMPANYSIGNUP_H

#include <QDialog>
#include <QString>

namespace Ui {
class CompanySignup;
}

class CompanySignup : public QDialog
{
    Q_OBJECT

public:
    explicit CompanySignup(QWidget *parent = nullptr);
    ~CompanySignup();
    void clickForSignup();

private slots:
    void on_EyeBTN_1_clicked();
    void on_EyeBTN_2_clicked();
    void on_RefreshBTN_clicked();

private:
    Ui::CompanySignup *ui;
    const QString dictionary = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    bool showPassword, showConfrimPassword;
    QString captchaCode;
    int searchUser(QString, QString);
    int checkConfrimPassword();
    QString generateRandomTxt(int len);
    QPixmap generateCaptchaImg(const QString &);
};

#endif // COMPANYSIGNUP_H
