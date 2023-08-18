#ifndef FILECAPTURE_H
#define FILECAPTURE_H

#include <QObject>
#include <opencv2/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include<opencv2/core/mat.hpp>

#include <QUrl>
#include <qdebug.h>
#include <iostream>
#include <QThread>


using namespace cv;



class FileCapture : public QObject
{
    Q_OBJECT

    VideoCapture *videoCaptured;
    QString url;
    bool stopVideo;

public:
    explicit FileCapture(QObject *parent = nullptr);

    void setUrl(QString &newUrl);

signals:
    void newFrameCapture (Mat rawFrame);
    void completedVideo ();


public slots:

    void openVideo();



};

#endif // FILECAPTURE_H
