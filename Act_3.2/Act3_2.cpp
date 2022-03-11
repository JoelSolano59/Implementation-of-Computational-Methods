#include <iostream>
#include <stdio.h>
#include <fstream>
#include <ctype.h>
#include <string>
#include <vector>

int main(){
	std::string str;
	std::ifstream inputFile;
	inputFile.open("input.txt");
	if (!inputFile){
		std::cout << "Unable to open file";
		exit(1); // terminate with error
	}
	std::vector<std::string> vec;
	while (getline(inputFile, str)){
		std::string token = "";
		for (char& s: str){
			//Variables
			if (isalpha(s)){
				if (isupper(s) || islower(s)){
					token = token + s;
				} 
			}
			else if (isdigit(s)){
				token = token + s;
			}
			else if (s == '_'){
				token = token + s;
			}
			else{
				vec.push_back(token);
				vec.push_back("Variable");
				token = "";
			}
		}
	}
	std::cout << vec[0] << vec[1] << std::endl;
	inputFile.close();
	return 0;
}
