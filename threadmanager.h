#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <QObject>
#include <QThread>
#include <QUrl>
#include "filecapture.h"
#include <iostream>

class threadManager : public QObject
{
    Q_OBJECT

    QThread *vthread;
    FileCapture *capturing;


public:
    explicit threadManager(QObject *parent = nullptr);

    Q_INVOKABLE void runCaptured(QString url);
    Q_INVOKABLE void finCaptured();


signals:

    void updateView(Mat vFrame);
    void doneView();

public slots:

    void receiveFrame(Mat vFrame);
    void myTest();

};

#endif // THREADMANAGER_H
