#include <iostream>
#include <stdio.h>
#include <fstream>
#include <ctype.h>
#include <string>
#include <vector>

std::vector<std::string> vec;
std::string token = "";

void setToken(std::string t, std::string type){
	vec.push_back(t);
	vec.push_back(type);
	token = "";
}

bool isVariable(const char s){
	std::cout << token << std::endl;
	if (isalpha(s)){
		if (isupper(s) || islower(s)){
			token = token + s;
		}
	}
	else if (isdigit(s) && token.length() > 0){
		token = token + s;
	}
	else if (s == '_' && token.length() > 0){
		token = token + s;
	}
	else{
		if (token.length() > 0){
			setToken(token, "Variable");
			return true;
		} else {
			return false;
		}
	}
}

bool isOperation(const char s){
	bool res = false;
	switch (s){
	case '=':
		token = '=';
		setToken(token, "Asignacion");
		res = true;
		break;
	case '+':
		token = '+';
		setToken(token, "Suma");
		res = true;
		break;
	case '-':
		token = '-';
		setToken(token, "Resta");
		res = true;
		break;
	case '*':
		token = '*';
		setToken(token, "Multiplicacion");
		res = true;
		break;
	case '/':
		token = '/';
		setToken(token, "Division");
		res = true;
		break;
	case '^':
		token = '^';
		setToken(token, "Exponente");
		res = true;
		break;
	default:
		break;
	}
	return res;
}

int main(){
	std::string str;
	std::ifstream inputFile;
	inputFile.open("input.txt");
	if (!inputFile){
		std::cout << "Unable to open file";
		exit(1); // terminate with error
	}
	while (getline(inputFile, str)){
		for (char const &s : str){
			// Variables
			isVariable(s);
			// Operadores
			isOperation(s);
		}
	}
	for (int i = 0; i < vec.size(); i = i + 2){
		std::cout << vec[i] << " " << vec[i + 1] << std::endl;
	}

	inputFile.close();
	return 0;
}
