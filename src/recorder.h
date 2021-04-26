#ifndef RECORDER_H
#define RECORDER_H

#include <QAudioBuffer>
#include <QAudioProbe>
#include <QAudioRecorder>
#include <QDebug>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QMediaRecorder>
#include <QObject>
#include <QPainter>
#include <QPoint>
#include <QStyleOption>
#include <QtMultimedia>
#include <QtMultimediaWidgets>

#include <fftw3.h>
#include <iostream>
#include <string>
#include <vector>

#define REAL 0
#define IMAG 1
#define SCALING_MAG 20

class Recorder : public QObject {
    Q_OBJECT
public:
    Recorder(QObject* parent, QGraphicsScene* scene);
    void startRecording(double x, double y);
    std::vector<QPoint> stopRecording();
    bool get_is_recording();
    void set_is_recording(bool b);
    void delete_lines();
public slots:
    void processAudioBuffer(QAudioBuffer buffer);

private:
    QAudioRecorder* recorder;
    bool is_recording = false;

    //  brojac poziva funkcije processAudioBuffer
    unsigned int buffer_count = 0;

    std::vector<double> recent_magnitudes;
    std::vector<QPoint> line_dots;

    QGraphicsScene* m_scene;
    double start_magnitude;
    double line_previous_y = 15;

    double fft_calculation(double input[], int n);

    double player_x = 0;
    double player_y = 0;
};

#endif // RECORDER_H
