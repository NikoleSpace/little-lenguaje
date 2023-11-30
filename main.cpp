#include <cstdio>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include "littleLexer.h"
#include "littleParser.h"
#include "antlr4-runtime.h"
#include "littleVisitorImpl.h"

int main() {
  // Crear el analizador y visitante
  antlr4::ANTLRInputStream input("tu código aquí");
  littleLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  littleParser parser(&tokens);

  // Obtener el árbol de análisis sintáctico
  tree::ParseTree *tree = parser.program();

  // Crear e inicializar el visitante
  LittleVisitorImpl visitor;
  visitor.visit(tree);

  // Realizar la prueba y escribir el código IR en un archivo
  visitor.test();

  return 0;
}
