#include <iostream>
#include <stdio.h>
#include <fstream>
#include <ctype.h>
#include <string>
#include <vector>

std::vector<std::string> vec;
std::string token = "";
int qg = 0; 
//std::string tv, tr, ti = "";
//int qv, qr, qi = 0;

void setToken(std::string t, std::string type){
	vec.push_back(t);
	vec.push_back(type);
}

void setState(int q, char const t){
	// switch (dfa){
	// case 'v':
	// 	qv = q;
	// 	tv = tv + t;
	// 	break;
	// case 'r':
	// 	qr = q;
	// 	tr = tr + t;
	// 	break;
	// case 'i':
	// 	qi = q;
	// 	ti = ti + t;
	// 	break;
	// default:
	// 	break;
	// }
	qg = q;
	token = token + t;
}

void resetState(){
	// switch (dfa){
	// case 'v':
	// 	qv = 0;
	// 	tv = "";
	// 	break;
	// case 'r':
	// 	qr = 0;
	// 	tr = "";
	// 	break;
	// case 'i':
	// 	qi = 0;
	// 	ti = "";
	// 	break;
	// default:
	// 	break;
	// }
	qg = 0;
	token = "";
}

void setOperation(char const s){
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
/*
void isVariable(std::string str){
	for (char const &s : str){
		switch (qv){
		case 0:
			if (isalpha(s) && (islower(s) || isupper(s))){
				setState('v', 1, s);
			} else {
				resetState('v');
			}
			break;
		case 1:
			if (s == '=' || s == '+' || s == '-' || s == '*' || s == '/' || s == '^' || s == '(' || s == ')'){
				setToken(tv, "Variable");
				setOperation(s);
				resetState('v');
			} else if (isalpha(s) && (islower(s) || isupper(s))){
				setState('v', 1, s);
			} else if (isdigit(s)){
				setState('v', 1, s);
			} else if (s == '_'){
				setState('v', 1, s);
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
}

void isInteger(std::string str){
	for (char const &s : str){
		switch (qi){
		case 0:
			if (s == '+' || s == '-'){
				setState('i', 1, s);
			} else if (isdigit(s)){
				setState('i', 2, s);
			} else {
				resetState('i');
			}
			break;
		case 1:
			if (isdigit(s)){
				setState('i', 2, s);
			} else {
				resetState('i');
			}
			break;
		case 2:
			if (s == '.') {
				resetState('i');
			} else if (isdigit(s)){
				setState('i', 2, s);
			} else if (s == '=' || s == '+' || s == '-' || s == '*' || s == '/' || s == '^' || s == '(' || s == ')'){
				setToken(ti, "Entero");
				setOperation(s);
				resetState('i');
			} else if (s == ' '){
				setToken(ti, "Entero");
				resetState('i');
			} else {
				resetState('i');
			}
			break;
		default:
			break;
		}
	}
	if (ti.length() > 0 && (qi == 2)){
		setToken(ti, "Entero");
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
			if (s == '=' || s == '+' || s == '-' || s == '*' || s == '/' || s == '^' || s == '(' || s == ')'){
				setToken(tr, "Real");
				setOperation(s);
				resetState('r');
			} else if (s == ' '){
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
*/
void DFA(std::string str){
	bool error = false;
	for (char const &s : str){
		switch (qg){
		case 0:
			if ((s == '=' || s == '+' || s == '*' || s == '^' || s == '(' || s == ')') && error == false){
				setOperation(s);
				resetState();
			} else if (s == '/' && error == false){
				setState(9, s);
			} else if (s == '-' && error == false){
				setState(2, s);
			} else if (isalpha(s) && (islower(s) || isupper(s)) && error == false){
				setState(1, s);
			} else if (isdigit(s) && error == false){
				setState(3, s);
			} else if (s == ' ' && error == false){
				resetState();
			} else {
				error = true;
				resetState();
			}
			break;
		case 1:
			if (s == '=' || s == '+' || s == '-' || s == '*' || s == '/' || s == '^' || s == '(' || s == ')'){
				setToken(token, "Variable");
				setOperation(s);
				resetState();
			} else if (s == '/'){
				setToken(token, "Variable");
				setState(9, s);
			} else if ((isalpha(s) && (islower(s) || isupper(s))) || isdigit(s) || s == '_'){
				setState(1, s);
			} else if (s == ' '){
				setToken(token, "Variable");
				resetState();
			} else {
				resetState();
			}
			break;
		case 2:
			if (isdigit(s)){
				setState(3, s);
			} else if (s == '.'){
				setState(4, s);
			} else if (s == ' ' && token == "-"){
				setOperation('-');
				resetState();
			} else {
				resetState();
			}
			break;
		case 3:
			if (s == '=' || s == '+' || s == '-' || s == '*' || s == '^' || s == '(' || s == ')'){
				setToken(token, "Entero");
				setOperation(s);
				resetState();
			} else if (s == '/'){
				setState(9, s);
			} else if (isdigit(s)){
				setState(3, s);
			} else if (s == '.') {
				setState(4, s);
			} else {
				resetState();
			}
			break;
		case 4:
			if (isdigit(s)){
				setState(5, s);
			} else {
				resetState();
			}
			break;
		case 5:
			if (s == '=' || s == '+' || s == '-' || s == '*' || s == '^' || s == '(' || s == ')'){
				setToken(token, "Real");
				setOperation(s);
				resetState();
			} else if (s == '/'){
				setToken(token, "Real");
				setState(9, s);
			} else if (s == ' '){
				setToken(token, "Real");
				resetState();
			} else if (isdigit(s)){
				setState(5, s);
			} else if (s == 'e' || s == 'E'){
				setState(6, s);
			}  else {
				resetState();
			}
			break;
		case 6:
			if (s == '-'){
				setState(7, s);
			} else if (isdigit(s)) {
				setState(8, s);
			} else {
				resetState();
			}
			break;
		case 7:
			if (isdigit(s)){
				setState(8, s);
			} else {
				resetState();
			}
			break;
		case 8:
			if (s == '=' || s == '+' || s == '-' || s == '*' || s == '^' || s == '(' || s == ')'){
				setToken(token, "Real");
				setOperation(s);
				resetState();
			} else if (s == '/'){
				setToken(token, "Real");
				setState(9, s);
			} else {
				resetState();
			}
			break;
		case 9:
			if ((s == '(' || s == ')')){
				setOperation('/');
				setOperation(s);
				resetState();
			} else if (s == ' '){
				setOperation('/');
				resetState();
			} else if (s == '/' && token == "/"){
				setState(10, s);
			} else {
				resetState();
			}
			break;
		case 10:
			setState(10, s);
			break;
		default:
			break;
		}
	}
	if (token.length() > 0){
		switch (qg){
		case 1:
			setToken(token, "Variable");
			break;
		case 3:
			setToken(token, "Entero");
			break;
		case 5:
			setToken(token, "Real");
			break;
		case 8:
			setToken(token, "Real");
			break;
		case 10:
			setToken(token, "Comentario");
			break;
		default:
			resetState();
			break;
		}
	}
	resetState();
}

int main(){
	std::string str;
	std::ifstream inputFile;
	inputFile.open("input.txt");
	if (!inputFile){
		std::cout << "No se pueede abrir el archivo input.txt";
		exit(1);
	}
	while (getline(inputFile, str)){
		// bool com = isComment(str);
		//sVariable(str);
		// isOperation(str);
		//isReal(str);
		//isInteger(str);
		DFA(str);
	}
	for (int i = 0; i < vec.size(); i = i + 2){
		std::cout << vec[i] << "\t" << vec[i + 1] << std::endl;
	}

	inputFile.close();
	return 0;
}
