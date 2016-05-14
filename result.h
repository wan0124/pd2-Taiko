#ifndef RESULT_H
#define RESULT_H

#include <QMainWindow>
namespace Ui {
class result;
}

class result : public QMainWindow
{
    Q_OBJECT

public:
    explicit result(QWidget *parent = 0);
    ~result();
    void show_result(int);

private slots:
    void on_exit_clicked();


private:
    Ui::result *ui;
    //game *newgame;
};

#endif // RESULT_H
