#ifndef SIGNUP_LOGIN_H
#define SIGNUP_LOGIN_H

#include <QMainWindow>
#include <QLineEdit>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class signup_login; }
QT_END_NAMESPACE



//QString user_name;

class signup_login : public QMainWindow
{
    Q_OBJECT

public:
    signup_login(QWidget *parent = nullptr);
    ~signup_login();

private slots:
    void on_eyeBTN_clicked();

    void on_editUsername_textChanged(const QString &);

    void on_editPassword_textChanged(const QString &);

    void on_loginBTN_clicked();

    void on_signupBTN_clicked();

    void on_eyeBTN_2_clicked();

    void on_eyeBTN_3_clicked();

    void on_editUsername_2_textChanged(const QString &);

    void on_editPassword_2_textChanged(const QString &);

    void on_editPassword_3_textChanged(const QString &);

    void on_refreshBTN_clicked();

    void on_signupBTN_2_clicked();

    void on_editEmail_textChanged(const QString &arg1);

private:
    Ui::signup_login *ui;
    bool showPass, showPass_2, showPass_3;
    const QString dictionary = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    QString captchaCode;
    void hideLoginPage();
    void hideSignupPage();
    void showSignupPage();
    void showLoginPage();
    int checkUsername(QLineEdit*);
    bool checkPassword(QLineEdit*);
    int searchUser(QString, QString);
    int checkConfrimPass();
    QString generateRandomTxt(int);
    QPixmap generateCaptchaImg(const QString &);

signals:
    void signup_login_closed();

protected:
    void closeEvent(QCloseEvent *event) override;

};
#endif // SIGNUP_LOGIN_H
