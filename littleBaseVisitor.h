
// Generated from little.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "littleVisitor.h"


/**
 * This class provides an empty implementation of littleVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  littleBaseVisitor : public littleVisitor {
public:

  virtual std::any visitProgram(littleParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(littleParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment(littleParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStatement(littleParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParens(littleParser::ParensContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariable(littleParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInteger(littleParser::IntegerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinaryExpr(littleParser::BinaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperator(littleParser::OperatorContext *ctx) override {
    return visitChildren(ctx);
  }


};

