#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore>
#include <mythread.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	// initilize the thread.
	myThread = new MyThread();
	myThread->threadName = "Thread - 1";

	// connect thread to the mainwindow.
	connect(myThread, SIGNAL(sendSignal(int)), this, SLOT(onSignalChange(int)));

	// initilze another thread.
	myThread2 = new MyThread();
	myThread2->threadName = "Thread - 2";

	// connect another thread to the mainwindow.
	connect(myThread2, SIGNAL(sendSignal(int)), this, SLOT(onSignalChange(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_start_thread1_clicked()
{

	qDebug() << myThread->threadName + " start\n";
	myThread->stop = false;

	myThread->start();
}

void MainWindow::on_btn_stop_thread1_clicked()
{
	qDebug() << myThread->threadName + " stoped\n";
	myThread->stop = true;
}

void MainWindow::onSignalChange(int number)
{
	if(number % 2 == 0) {
		// set number on line edit
		if(myThread->isRunning()) {
			ui->le_thread1->setText(QString::number(number));
		}
		if(myThread2->isRunning()) {
			ui->le_thread2->setText(QString::number(number));
		}
	}
}

void MainWindow::on_btn_thread2_start_clicked()
{
	qDebug() << myThread2->threadName + " Start.\n";

	myThread2->stop = false;
	myThread2->start();
}

void MainWindow::on_btn_thread2_stop_clicked()
{
	qDebug() << myThread2->threadName + " Stoped.";

	myThread2->stop = true;
}
