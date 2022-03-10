#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <numeric>
#include <string>
#include <vector>
#include <thread>
#include <cmath>
#include <ctime>
#include <regex>

int main(){
	std::string str;
	std::ifstream myInputFile;
	myInputFile.open("input.txt");
	if (!myInputFile){
		std::cout << "Unable to open file";
		exit(1); // terminate with error
	}
	while (getline(myInputFile, str)){
		// for (char& c: myStringLine){
		// }
		std::smatch matches;
		std::regex reg("");
	}
	myInputFile.close();
	return 0;
}
