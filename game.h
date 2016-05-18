#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <ctime>
#include <QTimer>
#include "result.h"
#include <QLabel>
#include <QKeyEvent>
#include <QWidget>

namespace Ui {
class game;
}

class game : public QMainWindow
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = 0);
    ~game();



private:
    Ui::game *ui;
    QTimer* timer1;
    QTimer* timer2;

    int count;
    int score;
    int time_end;
    int time_speed;
    int now_time;
    int drum_speed;
    int drum_count;


    result* resultbox;

public slots:
    void time_count();
    void move();
    void keyPressEvent(QKeyEvent *event);


private slots:
    void on_reStart_clicked();
};

#endif // GAME_H
