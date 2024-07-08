#include "mainwindow.h"
#include "signup_login_page/signup_login.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    signup_login s;
    MainWindow w;

    QObject::connect(&s, &signup_login::signup_login_closed, [&]() {
            w.show();
        });

    s.show();

    return a.exec();
}
