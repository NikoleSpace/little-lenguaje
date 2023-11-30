#include "littleVisitorImpl.h"
#include "littleParser.h"
#include <any>
#include <llvm/ADT/APFloat.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <memory>
#include <string>
antlrcpp::Any LittleVisitorImpl::visitProgram(littleParser::ProgramContext *context) {
  for (auto statement : context->statement()) {
    visit(statement);
  }
  return nullptr;
}

antlrcpp::Any LittleVisitorImpl::visitStatement(littleParser::StatementContext *context) {
  return visit(context->getChild(0));
}

antlrcpp::Any LittleVisitorImpl::visitAssignment(littleParser::AssignmentContext *context) {
  // Obtener el nombre de la variable y la expresión asignada
  std::string variableName = context->ID()->getText();
  llvm::Value *expressionValue = visit(context->expression());

  // Crear una variable en la memoria para la asignación
  llvm::AllocaInst *alloca = CreateEntryBlockAlloca(variableName);

  // Almacenar el valor de la expresión en la variable
  builder->CreateStore(expressionValue, alloca);

  // Almacenar la variable en la memoria para su uso posterior
  memory[variableName] = alloca;

  return nullptr;
}

antlrcpp::Any LittleVisitorImpl::visitIfStatement(littleParser::IfStatementContext *context) {
  // Obtener la condición y los bloques 'then' y 'else'
  llvm::Value *conditionValue = visit(context->expression());
  llvm::BasicBlock *thenBlock = llvm::BasicBlock::Create(*context->getStart()->getContext(), "then", currentFunction);
  llvm::BasicBlock *elseBlock = llvm::BasicBlock::Create(*context->getStart()->getContext(), "else");
  llvm::BasicBlock *mergeBlock = llvm::BasicBlock::Create(*context->getStart()->getContext(), "ifcont");

  // Crear una instrucción de salto condicional
  builder->CreateCondBr(conditionValue, thenBlock, elseBlock);

  // Generar código para el bloque 'then'
  builder->SetInsertPoint(thenBlock);
  visit(context->program(0)); // Visitamos el bloque 'then'
  builder->CreateBr(mergeBlock); // Salto al bloque final después del 'if'

  // Generar código para el bloque 'else'
  currentFunction->getBasicBlockList().push_back(elseBlock);
  builder->SetInsertPoint(elseBlock);
  if (context->program().size() > 1) {
    visit(context->program(1)); // Visitamos el bloque 'else'
  }
  builder->CreateBr(mergeBlock); // Salto al bloque final después del 'if'

  // Configurar el bloque de fusión como el bloque actual
  currentFunction->getBasicBlockList().push_back(mergeBlock);
  builder->SetInsertPoint(mergeBlock);

  return nullptr;
}
antlrcpp::Any LittleVisitorImpl::visitParens(littleParser::ParensContext *context) {
  return visit(context->expression());
}

antlrcpp::Any LittleVisitorImpl::visitVariable(littleParser::VariableContext *context) {
  // Obtener el nombre de la variable
  std::string variableName = context->ID()->getText();

  // Verificar si la variable existe en la memoria
  if (memory.find(variableName) != memory.end()) {
    // Cargar el valor almacenado en la variable
    return builder->CreateLoad(memory[variableName], variableName.c_str());
  } else {
    // Si la variable no existe, puedes manejar el error o realizar alguna acción apropiada.
    // Aquí simplemente imprimimos un mensaje de error y retornamos un valor nulo.
    std::cerr << "Error: Variable '" << variableName << "' not defined." << std::endl;
    return nullptr;
  }
}

antlrcpp::Any LittleVisitorImpl::visitInteger(littleParser::IntegerContext *context) {
  // Obtener el valor entero del contexto y crear una constante entera
  int intValue = std::stoi(context->getText());
  return llvm::ConstantInt::get(*context->getStart()->getContext(), llvm::APInt(32, intValue, true));
}

antlrcpp::Any LittleVisitorImpl::visitBinaryExpr(littleParser::BinaryExprContext *context) {
  // Obtener los valores de las expresiones izquierda y derecha
  llvm::Value *leftValue = visit(context->e1);
  llvm::Value *rightValue = visit(context->e2);

  if (!leftValue || !rightValue) {
    // Manejar el error si las expresiones no generan valores
    std::cerr << "Error: Failed to generate values for binary expression." << std::endl;
    return nullptr;
  }

  // Obtener el operador de la expresión
  std::string op = context->op->getText();

  // Realizar la operación según el operador
  if (op == "+") {
    return builder->CreateAdd(leftValue, rightValue, "addtmp");
  } else if (op == "-") {
    return builder->CreateSub(leftValue, rightValue, "subtmp");
  } else if (op == "*") {
    return builder->CreateMul(leftValue, rightValue, "multmp");
  } else if (op == "/") {
    return builder->CreateSDiv(leftValue, rightValue, "divtmp");
  } else {
    // Manejar el error si el operador no es compatible
    std::cerr << "Error: Unsupported operator '" << op << "'." << std::endl;
    return nullptr;
  }
}


antlrcpp::Any LittleVisitorImpl::visitOperator(littleParser::OperatorContext *context) {
  return context->getText();
}

void LittleVisitorImpl::generateIR(std::string outputFileName) {
  std::error_code error;
  llvm::raw_fd_ostream outIR(outputFileName, error, llvm::sys::fs::F_None);
  module->print(outIR, nullptr);
}
void LittleVisitorImpl::test() {
  std::error_code error;
  llvm::raw_fd_ostream outLL("test.ll", error);
  module->print(outLL, nullptr);
}