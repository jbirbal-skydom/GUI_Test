#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <QObject>
#include <QQuickPaintedItem>
#include <QImage>
#include <QPainter>

#include <opencv2/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include<opencv2/core/mat.hpp>

using namespace cv;

class ViewWindow : public QQuickPaintedItem
{

    Q_OBJECT

    Q_PROPERTY(QImage viewFrame READ getViewFrame WRITE setViewFrame NOTIFY frameChanged FINAL)

    cv::Mat rawFrame;
    QImage viewFrame;


public:
    ViewWindow(QQuickItem *parent = 0);

    void paint(QPainter *painter);

    Mat getRawFrame() const;
    Q_INVOKABLE void setRawFrame(const Mat &newRawFrame);
    QImage getViewFrame() const;
    void setViewFrame(const QImage &newViewFrame);

    Q_INVOKABLE void openImage(QUrl url);
    Q_INVOKABLE bool smoothImage();

signals:
    void frameChanged();

public slots:
    void convert2QImage();


};

#endif // VIEWWINDOW_H
