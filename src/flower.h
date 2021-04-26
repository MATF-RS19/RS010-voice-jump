#ifndef FLOWER_H
#define FLOWER_H

#include <QDebug>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>

#define MIN_WIDTH_SIZE 50
#define MAX_WIDTH_SIZE 120

#define MIN_HEIGHT_SIZE 50
#define MAX_HEIGHT_SIZE 160

class Flower : public QGraphicsRectItem {
public:
    Flower(int x, int y);
};

#endif // FLOWER_H
