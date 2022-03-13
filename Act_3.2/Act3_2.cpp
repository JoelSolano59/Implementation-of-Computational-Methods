#include <iostream>
#include <stdio.h>
#include <fstream>
#include <ctype.h>
#include <string>
#include <vector>

std::vector<std::string> vec;
std::string token = "";
std::string tv, tr = "";
int qv, qr = 0;

void setToken(std::string t, std::string type){
	vec.push_back(t);
	vec.push_back(type);
}

void setState(char dfa, int q, char const t){
	switch (dfa){
	case 'v':
		qv = q;
		tv = tv + t;
		break;
	case 'r':
		qr = q;
		tr = tr + t;
		break;
	default:
		break;
	}
}

void resetState(char dfa){
	switch (dfa){
	case 'v':
		qv = 0;
		tv = "";
		break;
	case 'r':
		qr = 0;
		tr = "";
		break;
	default:
		break;
	}
}

void isVariable(std::string str){
	for (char const &s : str){
		switch (qv){
		case 0:
			if (isalpha(s) && islower(s)){
				setState('v', 1, s);
			} else if (isalpha(s) && isupper(s)){
				setState('v', 2, s);
			} else {
				resetState('v');
			}
			break;
		case 1:
			if (s == '(' || s == ')'){
				setToken(tv, "Variable");
				resetState('v');
			} else if (isalpha(s) && islower(s)){
				setState('v', 1, s);
			} else if (isalpha(s) && isupper(s)){
				setState('v', 2, s);
			} else if (isdigit(s)){
				setState('v', 3, s);
			} else if (s == '_'){
				setState('v', 4, s);
			} else if (s == ' '){
				setToken(tv, "Variable");
				resetState('v');
			} else {
				resetState('v');
			}
			break;
		case 2:
			if (s == '(' || s == ')'){
				setToken(tv, "Variable");
				resetState('v');
			} else if (isalpha(s) && islower(s)){
				setState('v', 1, s);
			} else if (isalpha(s) && isupper(s)){
				setState('v', 2, s);
			} else if (isdigit(s)){
				setState('v', 3, s);
			} else if (s == '_'){
				setState('v', 4, s);
			} else if (s == ' '){
				setToken(tv, "Variable");
				resetState('v');
			} else {
				resetState('v');
			}
			break;
		case 3:
			if (s == '(' || s == ')'){
				setToken(tv, "Variable");
				resetState('v');
			} else if (isalpha(s) && islower(s)){
				setState('v', 1, s);
			} else if (isalpha(s) && isupper(s)){
				setState('v', 2, s);
			} else if (isdigit(s)){
				setState('v', 3, s);
			} else if (s == '_'){
				setState('v', 4, s);
			} else if (s == ' '){
				setToken(tv, "Variable");
				resetState('v');
			} else {
				resetState('v');
			}
			break;
		case 4:
			if (s == '(' || s == ')'){
				setToken(tv, "Variable");
				resetState('v');
			} else if (isalpha(s) && islower(s)){
				setState('v', 1, s);
			} else if (isalpha(s) && isupper(s)){
				setState('v', 2, s);
			} else if (isdigit(s)){
				setState('v', 3, s);
			} else if (s == '_'){
				setState('v', 4, s);
			} else if (s == ' '){
				setToken(tv, "Variable");
				resetState('v');
			} else {
				resetState('v');
			}
			break;
		default:
			break;
		}
	}
	if (tv.length() > 0 && (qv == 1 || qv == 2 || qv == 3 || qv == 4)){
		setToken(tv, "Variable");
	}
		// if (isalpha(s)){
		// 	if (isupper(s) || islower(s)){
		// 		token = token + s;
		// 	}
		// } else if (isdigit(s) && token.length() > 0){
		// 	token = token + s;
		// } else if (s == '_' && token.length() > 0){
		// 	token = token + s;
		// } else {
		// 	if (token.length() > 0){
		// 		setToken(token, "Variable");
		// 	}
		// }
}

void isInteger(std::string str){
	for (char const &s : str){
		if (isdigit(s)){
			token = token + s;
		}
		else{
			if (isdigit && token.length() > 0){
				setToken(token, "Entero");
			}
		}
	}
	if (token.length() > 0){
		setToken(token, "Entero");
	}
}

void isReal(std::string str){
	for (char const &s : str){
		switch (qr){
		case 0:
			if (isdigit(s)){
				setState('r', 1, s);
			} else if (s == '+' || s == '-'){
				setState('r', 2, s);
			} else if (s == '.'){
				setState('r', 3, s);
			} else {
				resetState('r');
			}
			break;
		case 1:
			if (isdigit(s)){
				setState('r', 1, s);
			} else if (s == '.'){
				setState('r', 3, s);
			} else {
				resetState('r');
			}
			break;
		case 2:
			if (isdigit(s)){
				setState('r', 1, s);
			} else if (s == '.'){
				setState('r', 3, s);
			} else {
				resetState('r');
			}
			break;
		case 3:
			if (isdigit(s)){
				setState('r', 4, s);
			} else if (s == ' '){
				setToken(tr, "Real");
				resetState('r');
			} else {
				resetState('r');
			}
			break;
		case 4:
			if (isdigit(s)){
				setState('r', 4, s);
			} else if (s == 'e' || s == 'E'){
				setState('r', 5, s);
			} else if (s == ' '){
				setToken(tr, "Real");
				resetState('r');
			} else {
				resetState('r');
			}
			break;
		case 5:
			if (isdigit(s)){
				setState('r', 7, s);
			} else if (s == '+' || s == '-'){
				setState('r', 6, s);
			} else {
				resetState('r');
			}
			break;
		case 6:
			if (isdigit(s)){
				setState('r', 7, s);
			} else {
				resetState('r');
			}
		case 7:
			if (s == ' '){
				setToken(tr, "Real");
				resetState('r');
			} else {
				resetState('r');
			}
			break;
		default:
			break;
		}
	}
	if (tr.length() > 0 && (qr == 4 || qr == 7)){
		setToken(tr, "Real");
	}
}

bool isComment(std::string str){
	std::string prefix1 = "/";
	std::string prefix2 = "//";
	for (char const &s : str){
		if (s == '/'){
			if (token == ""){
				token = token + s;
			} else if (token == prefix1){
				token = token + s;
			}
		} else if (prefix2 == token.substr(0, prefix2.size())){
			token = token + s;
		}
	}
	if (prefix2 == token.substr(0, prefix2.size()) && token.length() >= 2){
		setToken(token, "Comentario");
		return true;
	} else {
		token = "";
		return false;
	}
}

void isOperation(std::string str){
	for (char const &s : str){
		switch (s){
		case '=':
			setToken("=", "Asignacion");
			break;
		case '+':
			setToken("+", "Suma");
			break;
		case '-':
			setToken("-", "Resta");
			break;
		case '*':
			setToken("*", "Multiplicacion");
			break;
		case '/':
			setToken("/", "Division");
			break;
		case '^':
			setToken("^", "Exponente");
			break;
		case '(':
			setToken("(", "Parentesis que abre");
			break;
		case ')':
			setToken(")", "Parentesis que cierra");
			break;
		default:
			break;
		}
	}
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
		// bool com = isComment(str);
		isVariable(str);
		// isOperation(str);
		// isInteger(str);
		isReal(str);
	}
	for (int i = 0; i < vec.size(); i = i + 2){
		std::cout << vec[i] << " " << vec[i + 1] << std::endl;
	}

	inputFile.close();
	return 0;
}
