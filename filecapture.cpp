#include "filecapture.h"
#include <QUrl>
#include <qdebug.h>

FileCapture::FileCapture(QObject *parent): QObject{parent}
{
    stopVideo = false;

}


bool FileCapture::openVideo()
{
    Mat rawFrame;
    videoCaptured = new VideoCapture;
    qDebug() << url;
    videoCaptured->open(url.toStdString());
    if(!videoCaptured->isOpened()){
        return false;
    }

    while(videoCaptured->read(rawFrame) && !stopVideo){
        emit(newFrameCapture(rawFrame));
    }


}


void FileCapture::setUrl(QString &newUrl)
{
    //QString myurl = newUrl.toLocalFile();
    newUrl.remove("file:///");
    url = newUrl;
}
