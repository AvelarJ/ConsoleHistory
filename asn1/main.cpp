//Created by Jordan Avelar
//Main method to create the QT MainWindow
//October 5, 2021

#include "command.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	//Create a new instance of the main window
	QApplication app(argc, argv);
	MainWindow mainwindow;
	mainwindow.resize(320, 500);
	mainwindow.show();
	mainwindow.update();
	return app.exec();

}
