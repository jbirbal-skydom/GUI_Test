#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <QObject>
#include <QThread>
#include <QUrl>
#include"filecapture.h"

class threadManager : public QObject
{
    Q_OBJECT

    QThread vthread;
    FileCapture capturing;


public:
    explicit threadManager(QObject *parent = nullptr);

    Q_INVOKABLE void runCaptured(QString url);

signals:

    void updateView(Mat vFrame);

public slots:

    void receiveFrame(Mat vFrame);

};

#endif // THREADMANAGER_H
