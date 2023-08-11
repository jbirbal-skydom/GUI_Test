#include "threadmanager.h"

threadManager::threadManager(QObject *parent)
    : QObject{parent}
{

}

void threadManager::runCaptured(QString url)
{
    capturing.setUrl(url);

    connect(&vthread, &QThread::started,
            &capturing, &FileCapture::openVideo);
    connect(&vthread, &QThread::finished,
            &capturing, &FileCapture::deleteLater);
    connect(&capturing, &FileCapture::newFrameCapture,
            this, &threadManager::receiveFrame);

    capturing.moveToThread(&vthread);
    vthread.start();

}

void threadManager::receiveFrame(Mat newrawFrame)
{
    emit(updateView(newrawFrame));
}
