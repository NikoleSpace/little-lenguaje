#include "LittleVisitorImpl.h"

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
  // Implement the code generation for assignment
  // ...
  return nullptr;
}

antlrcpp::Any LittleVisitorImpl::visitIfStatement(littleParser::IfStatementContext *context) {
  // Implement the code generation for if statement
  // ...
  return nullptr;
}

antlrcpp::Any LittleVisitorImpl::visitParens(littleParser::ParensContext *context) {
  return visit(context->expression());
}

antlrcpp::Any LittleVisitorImpl::visitVariable(littleParser::VariableContext *context) {
  // Implement the code generation for variable
  // ...
  return nullptr;
}

antlrcpp::Any LittleVisitorImpl::visitInteger(littleParser::IntegerContext *context) {
  // Implement the code generation for integer
  // ...
  return nullptr;
}

antlrcpp::Any LittleVisitorImpl::visitBinaryExpr(littleParser::BinaryExprContext *context) {
  // Implement the code generation for binary expression
  // ...
  return nullptr;
}

antlrcpp::Any LittleVisitorImpl::visitOperator(littleParser::OperatorContext *context) {
  // Implement the code generation for operator
  // ...
  return nullptr;
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