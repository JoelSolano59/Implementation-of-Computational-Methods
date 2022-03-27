#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>

int main(void)
{
  //Abrimos la plantilla y obtenemos todo el documento en 2 strings
  std::ifstream infile("plantilla.html");
  std::string first, last, middle, tp;
  int i = 1;
  while(std::getline(infile, tp)){
    if ((i >= 1 && i<= 39)){
      first += tp;
    } else if (i >= 52){
      last += tp;
    }
    i++;
  }
  std::string tipo, token;
  std::ifstream in("output.txt");
  //Abrimos el archivo output y generamos nuestros token y tipos en clases y etiquetas para HTML
  middle += "<div class='col'>";
  while (std::getline(in, tipo, ' '))
  {
    std::getline(in, token);
    if (tipo != "salto"){
      middle += "<text class='text rounded "+ tipo +"'>"+ token +"</text>"+"<text class='text'> </text>";  
    } else {
      middle += "</div><div class='w-100'></div><div class='col'>";
    }
  }
  middle += "</div>";
  in.close();
  //Creamos un archivo HTML con los 3 strings
  std::ofstream MyFile("main.html");
  MyFile << first << middle << last;
}