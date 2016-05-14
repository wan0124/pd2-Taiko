#include "drum.h"


drum::drum(int type)
{
    style=type;

    set_drum();
    move_time = new QTimer(this);
    move_time->start(10);
    connect(move_time,SIGNAL(timeout()),this,SLOT(move()));

}

void drum:: set_drum()
{
    if(style)
    {
        QPixmap red_drum;
        red.load(":/taiko/reddrum.png");
        setPixmap(red_drum);
        setPos(511,2)
        break;
    }
    else
    {
        QPixmap blue_drum;
        red.load(":/taiko/bluedrum.png");
        setPixmap(blue_drum);
        setPos(511,2)
        break;
    }
}

void drum::move()
{
    if(x()>86)
        setPos(x()-1,y());
    else
    {
        emit delete_note;
        delete this;
    }
}

int drum::get_drum()
{
    return style;
}

void drum::set_start(int drum_time)
{
    start = drum_time+1;
}

int drum::get_start()
{
    return start;
}

