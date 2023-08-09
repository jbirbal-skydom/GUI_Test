#include "viewframe.h"

QImage ViewFrame::getProFrame() const
{
    return proFrame;
}

void ViewFrame::setProFrame(const QImage &newProFrame)
{
    proFrame = newProFrame;
}



Mat ViewFrame::getRawFrame() const
{
    return rawFrame;
}

void ViewFrame::setRawFrame(const Mat &newRawFrame)
{
    rawFrame = newRawFrame;
}


void ViewFrame::openImage(QString url)
{

}



ViewFrame::ViewFrame(QQuickItem *parent): QQuickPaintedItem(parent)
{

}

void ViewFrame::paint(QPainter *painter)
{

}


void ViewFrame::convert2Qimage()
{

}
