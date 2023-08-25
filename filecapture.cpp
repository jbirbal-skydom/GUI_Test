#include "filecapture.h"

FileCapture::FileCapture(QObject *parent): QObject{parent}
{
    stopVideo = false;

}


void FileCapture::openVideo()
{
    Mat rawFrame;
    videoCaptured = new VideoCapture;
    // qDebug() << url;
    videoCaptured->open(url.toStdString());
    if(!videoCaptured->isOpened()){
        std::cout<<"not opened" << std::endl;
    }
    int i = 0;
    std::cout<< "opened" << std::endl;


    while(videoCaptured->read(rawFrame) && !stopVideo){
        i++;
        std::cout<<i<<" seconds " << this << std::endl;
        //QThread::sleep(1);
        emit(newFrameCapture(rawFrame));


    }
    std::cout << "deleting object"  << std::endl;
    videoCaptured->release();


    delete videoCaptured;
    emit(completedVideo());






}



//void FileCapture::completedVideo()
//{

//    std::cout << "completed"  << std::endl;




//}


void FileCapture::setUrl(QUrl &newUrl)
{
    QString myurl = newUrl.toLocalFile();
    //newUrl.remove("file:///");
    url = myurl;
}
