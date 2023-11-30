#ifndef LITTLE_VISITOR_IMPL_H
#define LITTLE_VISITOR_IMPL_H

#include "littleVisitor.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"

class LittleVisitorImpl : public littleVisitor {
public:
  LittleVisitorImpl()
      : context(std::make_unique<llvm::LLVMContext>()),
        module(std::make_unique<llvm::Module>("LittleIR", *context)),
        builder(std::make_unique<llvm::IRBuilder<>>(*context)) {}

  virtual antlrcpp::Any visitProgram(littleParser::ProgramContext *context) override;
  virtual antlrcpp::Any visitStatement(littleParser::StatementContext *context) override;
  virtual antlrcpp::Any visitAssignment(littleParser::AssignmentContext *context) override;
  virtual antlrcpp::Any visitIfStatement(littleParser::IfStatementContext *context) override;
  virtual antlrcpp::Any visitParens(littleParser::ParensContext *context) override;
  virtual antlrcpp::Any visitVariable(littleParser::VariableContext *context) override;
  virtual antlrcpp::Any visitInteger(littleParser::IntegerContext *context) override;
  virtual antlrcpp::Any visitBinaryExpr(littleParser::BinaryExprContext *context) override;
  virtual antlrcpp::Any visitOperator(littleParser::OperatorContext *context) override;

  void generateIR(std::string outputFileName);
  void test();

private:
  std::unique_ptr<llvm::LLVMContext> context;
  std::unique_ptr<llvm::Module> module;
  std::unique_ptr<llvm::IRBuilder<>> builder;
  llvm::Function *currentFunction = nullptr;
  llvm::BasicBlock *currentBlock = nullptr;

  llvm::AllocaInst *CreateEntryBlockAlloca(const std::string &varName);
};

#endif // LITTLE_VISITOR_IMPL_H
