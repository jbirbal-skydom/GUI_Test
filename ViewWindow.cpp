#include "ViewWindow.h"
#include <QUrl>

cv::Mat ViewWindow::getRawFrame() const
{
    return rawFrame;
}

void ViewWindow::setRawFrame(const Mat &newRawFrame)
{
    rawFrame = newRawFrame;
    convert2QImage();

}

QImage ViewWindow::getViewFrame() const
{
    return viewFrame;
}

void ViewWindow::setViewFrame(const QImage &newViewFrame)
{
    viewFrame = newViewFrame;
    ViewWindow::update();
    emit(frameChanged());

}

void ViewWindow::openImage(QUrl url)
{
    QString myurl = url.toLocalFile();
    //qDebug() << myurl;
    rawFrame = cv::imread(myurl.toStdString());
    convert2QImage();
}

void ViewWindow::convert2QImage()
{
    cv::Mat tempMat;
    cv::cvtColor(rawFrame,tempMat, cv::COLOR_RGB2BGR);
    QImage tempImage((uchar*) tempMat.data, tempMat.cols,tempMat.rows, tempMat.step, QImage::Format_RGB888);
    viewFrame = tempImage;
    viewFrame.detach();
    ViewWindow::update();
    emit(frameChanged());
}

ViewWindow::ViewWindow(QQuickItem *parent) : QQuickPaintedItem(parent)
{

}

void ViewWindow::paint(QPainter *painter)
{
    //viewFrame.scaled(640,480, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    painter->drawImage(0,0, viewFrame, 0,0, -1,-1, Qt::AutoColor);
}

bool ViewWindow::smoothImage() {
    if(!rawFrame.empty()){
        Mat temp;
        GaussianBlur(rawFrame, temp, Size (31,31), 0, 0);
        setRawFrame(temp);
        return true;

    }
    return false;
}
