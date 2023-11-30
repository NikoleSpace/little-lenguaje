
// Generated from little.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "littleParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by littleParser.
 */
class  littleVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by littleParser.
   */
    virtual std::any visitProgram(littleParser::ProgramContext *context) = 0;

    virtual std::any visitStatement(littleParser::StatementContext *context) = 0;

    virtual std::any visitAssignment(littleParser::AssignmentContext *context) = 0;

    virtual std::any visitIfStatement(littleParser::IfStatementContext *context) = 0;

    virtual std::any visitParens(littleParser::ParensContext *context) = 0;

    virtual std::any visitVariable(littleParser::VariableContext *context) = 0;

    virtual std::any visitInteger(littleParser::IntegerContext *context) = 0;

    virtual std::any visitBinaryExpr(littleParser::BinaryExprContext *context) = 0;

    virtual std::any visitOperator(littleParser::OperatorContext *context) = 0;


};

