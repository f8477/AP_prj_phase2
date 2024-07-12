#ifndef COMMENTPAGE_H
#define COMMENTPAGE_H

#include <QDialog>

namespace Ui {
class CommentPage;
}

class CommentPage : public QDialog
{
    Q_OBJECT

public:
    explicit CommentPage(QWidget *parent = nullptr);
//    void showcomment(QString post_id);
    ~CommentPage();

private slots:
    void on_ViewMore_clicked();

    void on_Send_clicked();

    void on_reload_clicked();

private:
    Ui::CommentPage *ui;
};

#endif // COMMENTPAGE_H
