#include "game.h"
#include "mainwindow.h"
#include "ui_game.h"

game::game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    srand(time(NULL));
    resultbox = new result;
    score = 0;
    time_end = 30*1000;//30 sec
    time_speed = 10;
    now_time = 0;
    ui->bluedrum->move(QPoint(511,110));
    ui->bluedrum_2->move(QPoint(698,110));
    ui->reddrum->move(QPoint(578,110));
    ui->reddrum_2->move(QPoint(658,110));
    timer1 = new QTimer(this);
    timer1->start(time_speed);
    drum_speed = 10;
    timer2 = new QTimer(this);
    timer2->start(drum_speed);
    connect(timer1,SIGNAL(timeout()),this,SLOT(time_count()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(move()));


}

game::~game()
{
    delete ui;
}

void game::time_count()
{
    now_time += time_speed;
    if(now_time <= time_end)
    {
        ui->count->display((time_end - now_time)/1000+1);
    }
    else
    {
        timer1->stop();
        resultbox->show_result(score);
        this->close();

    }
}

void game::move()
{
    if(now_time == 30)
    {
        ui->bluedrum->close();
        ui->reddrum->close();
        ui->reddrum_2->close();
        ui->bluedrum_2->close();
    }

    int x1 = ui->bluedrum->x();
    int x2 = ui->reddrum->x();
    int x3 = ui->reddrum_2->x();
    int x4 = ui->bluedrum_2->x();
    int y1 = ui->bluedrum->y();
    int next1 = rand()%150;
    int next2 = rand()%150;
    int next3 = rand()%150;
    int next4 = rand()%150;


    ui->bluedrum->move(QPoint(x1-1,y1));
    ui->bluedrum_2->move(QPoint(x1-1,y1));
    ui->reddrum->move(QPoint(x2-1,y1));
    ui->reddrum_2->move(QPoint(x3-1,y1));
    if(x1 <= 60)
    {
        ui->bluedrum->move(QPoint(511+next1,y1));
    }

    if(x2 <= 60)
    {
        ui->reddrum->move(QPoint(511+next2,y1));
    }

    if(x3 <= 60)
    {
        ui->reddrum_2->move(QPoint(511+next3,y1));
    }

    if(x4 <= 60)
    {
        ui->bluedrum_2->move(QPoint(511+next4,y1));
    }


}

    void game::keyPressEvent(QKeyEvent *event)
    {
        int x1 = ui->bluedrum->x();
        int x2 = ui->reddrum->x();
        int x3 = ui->reddrum_2->x();
        int x4 = ui->bluedrum_2->x();

        int test = rand()%150;
        int test2 = rand()%150;
        int test3 = rand()%150;
        int test4 = rand()%150;
        int y1 = ui->bluedrum->y();


        if(event->key() == Qt::Key_A)
        {
            if(x1>=60 && x1<=110)
            {
                ui->bluedrum->move(QPoint(511+test,y1));
                score++;
                ui->score->display(score);
            }
            if(x4>=60 && x4<=110)
            {
                ui->bluedrum_2->move(QPoint(511+test4,y1));
                score++;
                ui->score->display(score);
            }


        }
        if(event->key() == Qt::Key_L)
        {
            if(x2>=60 && x2<=110)
            {
                ui->reddrum->move(QPoint(511+test2,y1));
                score++;
                ui->score->display(score);
            }
            if(x3>=60 && x3<=110)
            {
                ui->reddrum_2->move(QPoint(511+test3,y1));
                score++;
                ui->score->display(score);
            }
        }
    }
