#include "mythread.h"
#include <QDebug>
#include <QtCore>
#include <QMutex>

MyThread::MyThread()
{

}

void MyThread::run()
{
	for(int i = 0; i < 10000; i++)
	{
		QMutex qMutex;

		qMutex.lock();       // gain lock so that other thread instance can't access hare untill it unlock.

		qDebug() << i;

		if(this->stop) {     // if stop = true then break;
			break;
		}
		qMutex.unlock();     // unlock. so that other thread instance can access this place.

		emit sendSignal(i);  // send signal to mainwindow.
		//this->sleep(1);    // spleep in second.
		this->msleep(100);   // sleep in msecond.
	}
}
