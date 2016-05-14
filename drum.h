#ifndef NOTE_H
#define NOTE_H

#include <QDebug>   //help to find position

#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>

class drum : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    drum(int type,int drum_time);

private:
    int style;
    int start;

public slots:
    void set_drum();
    void move();
    int get_drum();
    void set_start();
    int get_start();


signals:
    void delete_drum();

};

#endif // NOTE_H
