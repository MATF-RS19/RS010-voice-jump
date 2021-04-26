#ifndef PLAYER_H
#define PLAYER_H

#include "flower.h"
#include "game_over.h"
#include "obstacle.h"
#include "recorder.h"
#include <QDebug>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>

#define VIEW_WIDTH 1000

extern Recorder* recorder;
//extern QGraphicsScene scene;

class Player : public QGraphicsRectItem {
public:
    Player(QGraphicsView* view, QGraphicsScene* scene);
    void keyPressEvent(QKeyEvent* event);
    void drawObsticles(int count);
    void drawFlowers(int count);
    void drawBackground(int count);
    //void keyReleaseEvent(QKeyEvent *event);

private:
    QGraphicsView* m_view;
    QGraphicsScene* m_scene;
    int new_obsticales_group_count = 0;

    std::vector<QPoint> movementLine; // linija kretanja
    //std::vector<QPoint> testTmp; // linija kretanja posle prve
    int sizeOfTest; //velicina kretanja
    int currentPosition = 0; //treutna pozicija kretanja
    int recordingStartPosition = 0;
    int skip = 20; // preskacemo prvih 20 zbog loseg ucitavanja zvuka
    //bool startDots = true; // za ucitavanje kretanja
    int position = 0;
    bool gameOverBool = true;
};

#endif // PLAYER_H
