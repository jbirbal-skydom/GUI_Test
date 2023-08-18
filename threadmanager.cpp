#include "threadmanager.h"
#include <iostream>

threadManager::threadManager(QObject *parent)
    : QObject{parent}
{

}

void threadManager::runCaptured(QString url)
{
    capturing = new FileCapture;
    vthread = new QThread();

    capturing->setUrl(url);

    capturing->moveToThread(vthread);


//    connect(vthread, SIGNAL(finished()), vthread, SLOT(deleteLater()), Qt::DirectConnection);
//    connect(vthread, SIGNAL(finished()), this,   SLOT(myTest()),      Qt::DirectConnection);
//    connect(capturing, SIGNAL(finished()), vthread, SLOT(quit()),        Qt::DirectConnection);
//    connect(capturing, SIGNAL(finished()), capturing, SLOT(deleteLater()), Qt::DirectConnection);
//    connect(capturing, SIGNAL(finished()), this,   SLOT(deleteLater()), Qt::DirectConnection);

    connect(vthread, &QThread::started,
            capturing, &FileCapture::openVideo);

    connect(vthread, &QThread::finished,
            capturing, &FileCapture::deleteLater);


    connect(capturing, &FileCapture::newFrameCapture,
            this, &threadManager::receiveFrame);

    connect(capturing, &FileCapture::completedVideo,
            this, &threadManager::finCaptured);


    vthread->start();

}

void threadManager::finCaptured()
{
    emit(doneView());
    //QThread::sleep(5);
    std::cout<<"ending thread"<<std::endl;
    vthread->requestInterruption();
    vthread->quit();
    //delete &vthread;
    vthread->wait();

    //delete videoCaptured;


}

void threadManager::receiveFrame(Mat rawFrame)
{


    if (!rawFrame.empty()){
        std::cout<< "new frame " << this << std::endl;
        emit(updateView(rawFrame));
    }
    else std::cout<<"empty"<<std::endl;
}

void threadManager::myTest()
{
    qDebug() << "D/Tester==myTest";
}
