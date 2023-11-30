#include <cstdio>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

#include "antlr4-runtime.h"
#include "littleLexer.h"
#include "littleParser.h"
#include "littleVisitorImpl.h"

int main(int argc, char **argv) {
  if (argc <= 1)
    return -1;

  // Abrir el archivo de entrada
  std::ifstream is;
  is.open(argv[1]);

  // Crear un flujo de entrada de ANTLR
  antlr4::ANTLRInputStream input(is);

  // Crear un lexer e inicializar los tokens
  littleLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);

  // Crear un parser y obtener el árbol de análisis sintáctico
  littleParser parser(&tokens);
  auto tree = parser.program();

  // Crear e inicializar el visitante
  LittleVisitorImpl visitor;
  visitor.visitProgram(tree);

  // Realizar la prueba y escribir el código IR en un archivo
  visitor.test();

  return 0;
}
