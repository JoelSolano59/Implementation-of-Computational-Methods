// Inluimos las librerias necesarias.
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <ctype.h>
#include <string>
#include <vector>
#include <cstring>

// Declaramos nuestras variables globales.
std::vector<std::string> vec;	// Vector donde guardaremos nuestra salida.
std::string token = "";			// String donde guardaremos el token.
int qg = 0; 					// Entero que estara al tanto de los estados del DFA.
int line = 1;					// Entero que estara al tanto de las lineas del texto.
bool error = false;				// Booleano para detectar errores.

// Funcion para agregar el token y su tipo al vector.
void setToken(std::string t, std::string type){
	vec.push_back(std::to_string(line));
	vec.push_back(t);
	vec.push_back(type);
}

// Funcion para cambiar el estado de qg y agregar el caracter actual al token.
void setState(int q, char const t){
	qg = q;
	token = token + t;
}

// Funcion para asignar el valor de qg a 0 y el token a "".
void resetState(){
	qg = 0;
	token = "";
}

// Funcion para asignar el tipo de operador segun el caracter.
void setOperation(char const s){
	switch (s){		// Switch para asignar el tipo de operador en base al parametro.
	case '=':		// Si es asignacion.
		setToken("=", "Asignacion");
		break;
	case '+':		// Si es suma.
		setToken("+", "Suma");
		break;
	case '-':		// Si es resta.
		setToken("-", "Resta");
		break;
	case '*':		// Si es multiplicacion.
		setToken("*", "Multiplicacion");
		break;
	case '/':		// Si es division.
		setToken("/", "Division");
		break;
	case '^':		// Si es exponente.
		setToken("^", "Exponente");
		break;
	case '(':		// Si es simbolo especial.
		setToken("(", "Parentesis que abre");
		break;
	case ')':		// Si es simbolo especial.
		setToken(")", "Parentesis que cierra");
		break;
	default:		// Ninguna de las anteriores.
		break;
	}
}

// Funcion de DFA, recibe la linea completa como parametro.
void DFA(std::string str){
	error = false;					// Booleano empieza en falso por cada linea de texto..
	for (char const &s : str){		// Ciclo for para cada caracter de la linea de texto.
		switch (qg){				// Switch para cada estado de nuestro DFA.
		case 0:						// En caso 0, tratamos de identificar primero que clase de token es.
			if ((s == '=' || s == '+' || s == '*' || s == '^' || s == '(' || s == ')') && error == false){	// Si es un operador.
				setOperation(s);
				resetState();
			} else if (s == '/' && error == false){		// Si es una division o comentario.
				setState(9, s);
			} else if (s == '-' && error == false){		// Si es una resta, real o entero.
				setState(2, s);
			} else if (isalpha(s) && (islower(s) || isupper(s)) && error == false){		// Si es una variable.
				setState(1, s);
			} else if (s == '0' && error == false) {	// Si es un octal.
				setState(12, s);
			} else if (isdigit(s) && error == false){	// Si es un entero o real.
				setState(3, s);
			} else if (s == ' ' && error == false){		// Los espacios no se asignan pero ayudan a determinar cuando un token a finalizado.
				resetState();
			} else {									// Si no se cumple ninguna condicion if, detectamos que es un error.
				error = true;
				setState(11, s);
			}
			break;
		case 1:		// En caso 1, el token es posible a ser una variable.
			if (s == '=' || s == '+' || s == '-' || s == '*' || s == '/' || s == '^' || s == '(' || s == ')'){	// Si es un operador.
				setToken(token, "Variable");	
				setOperation(s);				
				resetState();
			} else if (s == '/'){	// Si es division o comentario.
				setToken(token, "Variable");
				setState(9, s);
			} else if ((isalpha(s) && (islower(s) || isupper(s))) || isdigit(s) || s == '_'){	// Si es una variable.
				setState(1, s);
			} else if (s == ' '){	// Fin del token.
				setToken(token, "Variable");
				resetState();
			} else {				// Ninguna de las anteriores.
				resetState();
			}
			break;
		case 2:		// En el caso 2, el token puede ser un entero o real negativo.
			if (isdigit(s)){		// Si es un digito.
				setState(3, s);
			} else if (s == '.'){	// Si es real.
				setState(4, s);
			} else if (s == ' ' && token == "-"){	// Fin del token, pero teniendo en cuenta que se ingreso una resta previamente, por lo que asignamos el operador.
				setOperation('-');
				resetState();
			} else {				// Ninguna de las anteriores.
				resetState();
			}
			break;
		case 3:		// En el caso 3, sabemos que el token a evaluar es un entero o real.
			if (s == '=' || s == '+' || s == '-' || s == '*' || s == '^' || s == '(' || s == ')'){	// Si es un operador.
				setToken(token, "Entero");
				setOperation(s);
				resetState();
			} else if (s == '/'){		// Si es division o comentario.
				setState(9, s);
			} else if (isdigit(s)){		// Si es un entero.
				setState(3, s);
			} else if (s == '.') {		// Si es un real.
				setState(4, s);
			} else {					// Ninguna de las anteriores.
				resetState();
			}
			break;
		case 4:		// En el caso 4, sabemos que el token solo puede ser un real.
			if (isdigit(s)){	// Si es un real.
				setState(5, s);
			} else {			// En este estado, solo puede seguir siendo un real si se ingresa un digito, de no ser asi, se reinicia el token y el estado.
				resetState();
			}
			break;
		case 5:		// En el caso 5, sabemos que es real, positivo o negativo con notacion decimal, pero puede concluir ahi o seguir con su exponente.
			if (s == '=' || s == '+' || s == '-' || s == '*' || s == '^' || s == '(' || s == ')'){		// Si es un operador.
				setToken(token, "Real");
				setOperation(s);
				resetState();
			} else if (s == '/'){				// Si es division o comentario.
				setToken(token, "Real");
				setState(9, s);
			} else if (s == ' '){				// Fin del token.
				setToken(token, "Real");
				resetState();
			} else if (isdigit(s)){				// Si es un real.
				setState(5, s);
			} else if (s == 'e' || s == 'E'){	// Si es un real con exponente.
				setState(6, s);
			}  else {							// Ninguna de las anteriores.
				resetState();
			}
			break;
		case 6:		// En el caso 6, se ha agregado el exponente 'e' o 'E', por lo que es necesario determinar el exponente positivo o negativo.
			if (s == '-'){				// Si es un exponente negativo.
				setState(7, s);
			} else if (isdigit(s)) {	// Si es un exponente positivo.
				setState(8, s);
			} else {					// Ninguna de las anteriores.
				resetState();
			}
			break;
		case 7:		// En el caso 7, solo se puede agregar el ultimo digito del numero real que es el exponente.
			if (isdigit(s)){		// Si es un exponente positivo.
				setState(8, s);
			} else {				// En este estado, como solo puede seguir siendo un real si se ingrea un solo digito, de no ser asi, se reinicia el token y el estado.
				resetState();
			}
			break;
		case 8:		// En el caso 8, es el fin del numero real por lo que podemos agregarlo a nuestro vector, solo queda evaluar el siguiente token o si es un real valido.
			if (s == '=' || s == '+' || s == '-' || s == '*' || s == '^' || s == '(' || s == ')'){		// Si es un operador.
				setToken(token, "Real");	
				setOperation(s);
				resetState();
			} else if (s == '/'){		// Si es division o comentario.
				setToken(token, "Real");
				setState(9, s);
			} else {					// Si se reconoce otro caracter que no sea un operador, un caracter especial o comentario, entonces tenemos un real no valido.
				resetState();
			}
			break;
		case 9:		// En el caso 9, tenemos que determinar si nuestro token = "/" es una division o comentario.
			if ((s == '(' || s == ')')){			// Si es un caracter especial.
				setOperation('/');
				setOperation(s);
				resetState();
			} else if (s == ' '){					// Si hay un espacio, es una division.
				setOperation('/');
				resetState();
			} else if (s == '/' && token == "/"){	// Si s = "/" y el token = "/", es una division.
				setState(10, s);
			} else {								// Ninguna de las anteriores.
				resetState();
			}
			break;
		case 10:	// En el caso 10, sabemos que es un comentario, por lo que agregaremos cada caracter hasta terminar la linea de texto.
			setState(10, s);
			break;
		case 11:	// En el caso 11, sabemos que es un error, por lo que agregaremos cada caracter hasta terminar la linea de texto.
			setState(11, s);
			break;
		case 12:	// En el caso 12, sabemos que es un octal.
			if (s == '=' || s == '+' || s == '-' || s == '*' || s == '^' || s == '(' || s == ')'){	// Si es un operador.
				setToken(token, "Octal");	
				setOperation(s);
				resetState();
			} else if (s == '/'){								// Si es division o comentario.
				setToken(token, "Octal");
				setState(9, s);
			} else if (isdigit(s) && (s != '8' && s!= '9')) {	// Si es un numero dentro del lenguaje de los octales.
				setState(12, s);
			} else {											// Si se reconoce otro caracter que no sea un operador, un caracter especial o comentario, entonces tenemos un octal no valido.
				resetState();
			}
			break;
		default:	// Ninguno de los casos.
			break;
		}
	}
	if (token.length() > 0){	// Si al finalizar la linea de texto, pudimos evaluar algo en nuestro token, asignamos lo que posiblemente pudo haber sido dicho token.
		switch (qg){			// Como tambien cambiamos entre estados previamente de terminar la linea de texto, podemos determinar por los estados finales quye era el token.
		case 1:					// En el caso 1, es el estado final para variables.
			setToken(token, "Variable");
			break;
		case 3:					// En el caso 3, es el estado final para enteros.
			setToken(token, "Entero");
			break;
		case 5:					// En el caso 5, es el estado final para reales (sin exponente).
			setToken(token, "Real");
			break;
		case 8:					// En el caso 8, es el estado final para reales (con exponente).
			setToken(token, "Real");
			break;
		case 10:				// En el caso 10, es el estado final para comentarios.
			setToken(token, "Comentario");
			break;
		case 11:				// En el caso 11, es el estado para errores.
			setToken(token, "Error");
			break;
		case 12:				// En el caso 11, es el estado para octales.
			setToken(token, "Octal");
			break;
		default:				// Si no es ninguno de los estados anteriores, nuestro token no es valido y no lo agregamos a nuestro vector.
			resetState();
			break;
		}
	}
	resetState();	// Reiniciamos el token y el estado por cada linea de texto.
}

// Funcion principal.
int main(){
	std::string str;				// String para cada linea del texto input.txt
	std::ifstream inputFile;		// Ifstream para nuestro archivo de entrada.
	inputFile.open("input.txt");	// Abrimos el archivo input.txt
	if (!inputFile){				// Intentamos abrir el archivo, de no ser posible se sale del programa.
		std::cout << "No se puede abrir el archivo input.txt";
		exit(1);
	}
	while (getline(inputFile, str)){	// Ciclo while para mandar cada linea del texto input.txt a la funcion DFA como parametro.
		DFA(str);
		line++;
		if (error == true){				// Si encontramos un error en la ultima linea del texto, detenemos el proceso e imprimimos directamente.
			break;
		}
	}
	printf("%-10s%-50s%-20s\n", "Linea", "Token", "Tipo"); 		// Imprime fila para determinar las columnas de la salida (Token y Tipo).
	for (int i = 0; i < vec.size(); i = i+3){		// Ciclo for para imprimir el resultado de salida.
		printf("%-10s%-50s%-20s\n", vec[i].c_str(), vec[i+1].c_str(), vec[i+2].c_str());
	}
	inputFile.close();	// Cerramos el archivo input.txt
	return 0;			// Fin de la funcion principal.
}