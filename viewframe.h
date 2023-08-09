#ifndef VIEWFRAME_H
#define VIEWFRAME_H



#include <QObject>
#include <QQuickPaintedItem>
#include <QImage>
#include <QPainter>

#include <opencv2/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


using namespace cv;


class ViewFrame : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QImage proFrame READ getProFrame WRITE setProFrame NOTIFY proFrameChanged)

private:
    Mat rawFrame;
    QImage proFrame;

public:
    ViewFrame(QQuickItem *parent = 0);

    void paint(QPainter *painter);


    Mat getRawFrame() const;
    Q_INVOKABLE void setRawFrame(const Mat &newRawFrame);


    QImage getProFrame() const;
    void setProFrame(const QImage &newProFrame);


    Q_INVOKABLE void openImage(QString url);



signals:
    void proFrameChanged();

public slots:
    void convert2Qimage();

};

#endif // VIEWFRAME_H
