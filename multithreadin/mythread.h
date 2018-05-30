#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
	Q_OBJECT

	public:
		MyThread();
		void run();
		bool stop = false;
		QString threadName;

	signals:
		void sendSignal(int);
};

#endif // MYTHREAD_H
