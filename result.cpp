#include "result.h"
#include "ui_result.h"

result::result(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::result)
{
    ui->setupUi(this);
}

result::~result()
{
    delete ui;
}

void result::on_exit_clicked()
{
    exit(0);
}

void result::show_result(int score)
{
    this->show();
    ui->resultscore->display(score);
}

/*void result::on_restart_clicked()
{
    restart();
}
*/
/*void result::restart()
{
    newgame = new game;
    this->close();
    newgame->show();
}
*/


void result::on_back_clicked()
{
    this->close();
}
