//Created by Jordan Avelar
//Implementation of the command class
//October 5, 2021

#include "command.h"

using namespace boost::process;
//Constructor with the command string as param
Command::Command(std::string newCmd) {
	cmdText = newCmd;
}
//Generic destructor
Command::~Command() {};
//String of the command getter
std::string Command::getCmd() {
	return cmdText;
}
//Result getter
std::string Command::getResult() {
	return result;
}
//Return code getter
int Command::getReturnCode() {
	return returnCode;
}

//Execute function takes the command saved in cmdText
//and executes it using the boost library (Taken mainly from boost example)
std::string Command::execute() {
	try{
		returnCode = 0;	//returnCode starts as a proper command, changes if error

		ipstream pipe_stream;	//Used to execute the command
		child c(cmdText, (std_out & std_err) > pipe_stream);

		std::string line;

		while (pipe_stream && std::getline(pipe_stream, line) && !line.empty())
			result.append(line);	//Each line of the output appended to the result string

		c.wait();

		return result;
	} catch (process_error e) {
		std::cerr << "Error when executing command" << std::endl;
		returnCode = -1;	//Error causes the returnCode to reflect this error
		return "Error when executing command";
	}
}
