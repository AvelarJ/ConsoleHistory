//Created by Jordan Avelar
//Header for the mainwindow class
//October 5, 2021

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPushButton>
#include <QMainWindow>
#include <QtWidgets>
#include <iostream>
#include "command.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = nullptr);
private slots:	//These functions handle what happens after certain actions
	void handleExecButton();
	void handleHistoryClick(QListWidgetItem *currItem);
private:	//All QT window objects/widgets
	QPushButton *execButton;
	QLineEdit *cmdIn;
	QLabel *execLabel;
	QLabel *historyLabel;
	QLabel *returnLabel;
	QPlainTextEdit *cmdOut;
	QListWidget *historyOut;
};
#endif
