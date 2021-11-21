//Created by Jordan Avelar
//Header file for the Command class
//October 5, 2021

#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <boost/process.hpp>

using namespace std;

class Command{
private:
	string cmdText;
	string result;
	int returnCode;
public:
	Command(string newCmd); //Constructor takes the input command string
	~Command();	//Generic destructor
	string getCmd();
	string getResult();
	int getReturnCode();
	void setCmd(string input);	//Setter for the cmd string
	string execute();	//Main method to execute the command
};

#endif
