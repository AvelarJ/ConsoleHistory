//Created by Jordan Avelar
//Implementation of all the aspects comprising of the main window
//October 5, 2021

#include "mainwindow.h"
#include "command.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	//Creating the simple text input line
	cmdIn = new QLineEdit(this);
	cmdIn->move(10,0);
	cmdIn->resize(300,30);

	execLabel = new QLabel("Output", this);
	execLabel->move(10,75);
	//Creating the text field for the command output to be displayed
	cmdOut = new QPlainTextEdit(this);
	cmdOut->resize(300,150);
	cmdOut->move(10,100);
	//Basic QLabels
	returnLabel = new QLabel("Return code: ", this);
	returnLabel->move(10, 250);
	historyLabel = new QLabel("History", this);
	historyLabel->move(10, 285);
	//Creating list holding past commands
	historyOut = new QListWidget(this);
	historyOut->resize(300, 150);
	historyOut->move(10, 310);
	//Creating the execute button
	execButton = new QPushButton("Execute", this);
	execButton->setGeometry(QRect(QPoint(100,50), QSize(75, 30)));
	//Connect is used to connect a certain signal to a method
	connect(execButton, &QPushButton::released, this, &MainWindow::handleExecButton);
	connect(historyOut, &QListWidget::itemDoubleClicked, this, &MainWindow::handleHistoryClick);
}

//Method to handle the execution and display from the given command
void MainWindow::handleExecButton()
{

	std::string input;
	input = cmdIn->text().toStdString();
	//Making new command object
	Command newCmd(input);
	std::string output = newCmd.execute();
	//QPlainTextEdit requires a QString to set as text
	QString qOut = QString::fromStdString(output);
	cmdOut->setPlainText(qOut);
	//Changes the return code displayed by the QLabel
	QString returnString = "Return code: " + QString::number(newCmd.getReturnCode());
	returnLabel->setText(returnString);

	//Creates item elements to be held in the QListWidget
	QListWidgetItem *newItem = new QListWidgetItem;
	newItem->setData(Qt::UserRole, qOut);	//Data held in the element
	newItem->setText(QString::fromStdString(input));	//Text shown in the QListWidget
	historyOut->addItem(newItem);
}
//currItem is the item that was double clicked
void MainWindow::handleHistoryClick(QListWidgetItem *currItem)
{
	//Takes data from the currently selected item
	//Then sets the string data in the plain text edit widget
	QVariant data = currItem->data(Qt::UserRole);
	QString historyString = data.toString();
	cmdOut->setPlainText(historyString);

}
