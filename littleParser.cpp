
// Generated from little.g4 by ANTLR 4.13.1


#include "littleVisitor.h"

#include "littleParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct LittleParserStaticData final {
  LittleParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LittleParserStaticData(const LittleParserStaticData&) = delete;
  LittleParserStaticData(LittleParserStaticData&&) = delete;
  LittleParserStaticData& operator=(const LittleParserStaticData&) = delete;
  LittleParserStaticData& operator=(LittleParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag littleParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
LittleParserStaticData *littleParserStaticData = nullptr;

void littleParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (littleParserStaticData != nullptr) {
    return;
  }
#else
  assert(littleParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LittleParserStaticData>(
    std::vector<std::string>{
      "program", "statement", "assignment", "ifStatement", "expression", 
      "operator"
    },
    std::vector<std::string>{
      "", "'='", "';'", "'if'", "'then'", "'else'", "'('", "')'", "'+'", 
      "'-'", "'*'", "'/'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "ID", "INT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,14,49,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,1,0,4,0,14,
  	8,0,11,0,12,0,15,1,1,1,1,3,1,20,8,1,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,
  	3,1,3,1,3,3,3,33,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,45,8,
  	4,1,5,1,5,1,5,0,0,6,0,2,4,6,8,10,0,1,1,0,8,11,48,0,13,1,0,0,0,2,19,1,
  	0,0,0,4,21,1,0,0,0,6,26,1,0,0,0,8,44,1,0,0,0,10,46,1,0,0,0,12,14,3,2,
  	1,0,13,12,1,0,0,0,14,15,1,0,0,0,15,13,1,0,0,0,15,16,1,0,0,0,16,1,1,0,
  	0,0,17,20,3,4,2,0,18,20,3,6,3,0,19,17,1,0,0,0,19,18,1,0,0,0,20,3,1,0,
  	0,0,21,22,5,12,0,0,22,23,5,1,0,0,23,24,3,8,4,0,24,25,5,2,0,0,25,5,1,0,
  	0,0,26,27,5,3,0,0,27,28,3,8,4,0,28,29,5,4,0,0,29,32,3,0,0,0,30,31,5,5,
  	0,0,31,33,3,0,0,0,32,30,1,0,0,0,32,33,1,0,0,0,33,7,1,0,0,0,34,35,5,6,
  	0,0,35,36,3,8,4,0,36,37,5,7,0,0,37,45,1,0,0,0,38,45,5,12,0,0,39,45,5,
  	13,0,0,40,41,3,10,5,0,41,42,3,8,4,0,42,43,3,8,4,0,43,45,1,0,0,0,44,34,
  	1,0,0,0,44,38,1,0,0,0,44,39,1,0,0,0,44,40,1,0,0,0,45,9,1,0,0,0,46,47,
  	7,0,0,0,47,11,1,0,0,0,4,15,19,32,44
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  littleParserStaticData = staticData.release();
}

}

littleParser::littleParser(TokenStream *input) : littleParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

littleParser::littleParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  littleParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *littleParserStaticData->atn, littleParserStaticData->decisionToDFA, littleParserStaticData->sharedContextCache, options);
}

littleParser::~littleParser() {
  delete _interpreter;
}

const atn::ATN& littleParser::getATN() const {
  return *littleParserStaticData->atn;
}

std::string littleParser::getGrammarFileName() const {
  return "little.g4";
}

const std::vector<std::string>& littleParser::getRuleNames() const {
  return littleParserStaticData->ruleNames;
}

const dfa::Vocabulary& littleParser::getVocabulary() const {
  return littleParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView littleParser::getSerializedATN() const {
  return littleParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

littleParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<littleParser::StatementContext *> littleParser::ProgramContext::statement() {
  return getRuleContexts<littleParser::StatementContext>();
}

littleParser::StatementContext* littleParser::ProgramContext::statement(size_t i) {
  return getRuleContext<littleParser::StatementContext>(i);
}


size_t littleParser::ProgramContext::getRuleIndex() const {
  return littleParser::RuleProgram;
}


std::any littleParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<littleVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

littleParser::ProgramContext* littleParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, littleParser::RuleProgram);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(13); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(12);
              statement();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(15); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

littleParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

littleParser::AssignmentContext* littleParser::StatementContext::assignment() {
  return getRuleContext<littleParser::AssignmentContext>(0);
}

littleParser::IfStatementContext* littleParser::StatementContext::ifStatement() {
  return getRuleContext<littleParser::IfStatementContext>(0);
}


size_t littleParser::StatementContext::getRuleIndex() const {
  return littleParser::RuleStatement;
}


std::any littleParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<littleVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

littleParser::StatementContext* littleParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, littleParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(19);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case littleParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(17);
        assignment();
        break;
      }

      case littleParser::T__2: {
        enterOuterAlt(_localctx, 2);
        setState(18);
        ifStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

littleParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* littleParser::AssignmentContext::ID() {
  return getToken(littleParser::ID, 0);
}

littleParser::ExpressionContext* littleParser::AssignmentContext::expression() {
  return getRuleContext<littleParser::ExpressionContext>(0);
}


size_t littleParser::AssignmentContext::getRuleIndex() const {
  return littleParser::RuleAssignment;
}


std::any littleParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<littleVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

littleParser::AssignmentContext* littleParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 4, littleParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(21);
    match(littleParser::ID);
    setState(22);
    match(littleParser::T__0);
    setState(23);
    expression();
    setState(24);
    match(littleParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

littleParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

littleParser::ExpressionContext* littleParser::IfStatementContext::expression() {
  return getRuleContext<littleParser::ExpressionContext>(0);
}

std::vector<littleParser::ProgramContext *> littleParser::IfStatementContext::program() {
  return getRuleContexts<littleParser::ProgramContext>();
}

littleParser::ProgramContext* littleParser::IfStatementContext::program(size_t i) {
  return getRuleContext<littleParser::ProgramContext>(i);
}


size_t littleParser::IfStatementContext::getRuleIndex() const {
  return littleParser::RuleIfStatement;
}


std::any littleParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<littleVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

littleParser::IfStatementContext* littleParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 6, littleParser::RuleIfStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(26);
    match(littleParser::T__2);
    setState(27);
    expression();
    setState(28);
    match(littleParser::T__3);
    setState(29);
    program();
    setState(32);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      setState(30);
      match(littleParser::T__4);
      setState(31);
      program();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

littleParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t littleParser::ExpressionContext::getRuleIndex() const {
  return littleParser::RuleExpression;
}

void littleParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParensContext ------------------------------------------------------------------

littleParser::ExpressionContext* littleParser::ParensContext::expression() {
  return getRuleContext<littleParser::ExpressionContext>(0);
}

littleParser::ParensContext::ParensContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any littleParser::ParensContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<littleVisitor*>(visitor))
    return parserVisitor->visitParens(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableContext ------------------------------------------------------------------

tree::TerminalNode* littleParser::VariableContext::ID() {
  return getToken(littleParser::ID, 0);
}

littleParser::VariableContext::VariableContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any littleParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<littleVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinaryExprContext ------------------------------------------------------------------

littleParser::OperatorContext* littleParser::BinaryExprContext::operator_() {
  return getRuleContext<littleParser::OperatorContext>(0);
}

std::vector<littleParser::ExpressionContext *> littleParser::BinaryExprContext::expression() {
  return getRuleContexts<littleParser::ExpressionContext>();
}

littleParser::ExpressionContext* littleParser::BinaryExprContext::expression(size_t i) {
  return getRuleContext<littleParser::ExpressionContext>(i);
}

littleParser::BinaryExprContext::BinaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any littleParser::BinaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<littleVisitor*>(visitor))
    return parserVisitor->visitBinaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntegerContext ------------------------------------------------------------------

tree::TerminalNode* littleParser::IntegerContext::INT() {
  return getToken(littleParser::INT, 0);
}

littleParser::IntegerContext::IntegerContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any littleParser::IntegerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<littleVisitor*>(visitor))
    return parserVisitor->visitInteger(this);
  else
    return visitor->visitChildren(this);
}
littleParser::ExpressionContext* littleParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 8, littleParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(44);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case littleParser::T__5: {
        _localctx = _tracker.createInstance<littleParser::ParensContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(34);
        match(littleParser::T__5);
        setState(35);
        expression();
        setState(36);
        match(littleParser::T__6);
        break;
      }

      case littleParser::ID: {
        _localctx = _tracker.createInstance<littleParser::VariableContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(38);
        match(littleParser::ID);
        break;
      }

      case littleParser::INT: {
        _localctx = _tracker.createInstance<littleParser::IntegerContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(39);
        match(littleParser::INT);
        break;
      }

      case littleParser::T__7:
      case littleParser::T__8:
      case littleParser::T__9:
      case littleParser::T__10: {
        _localctx = _tracker.createInstance<littleParser::BinaryExprContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(40);
        antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = operator_();
        setState(41);
        antlrcpp::downCast<BinaryExprContext *>(_localctx)->e1 = expression();
        setState(42);
        antlrcpp::downCast<BinaryExprContext *>(_localctx)->e2 = expression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperatorContext ------------------------------------------------------------------

littleParser::OperatorContext::OperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t littleParser::OperatorContext::getRuleIndex() const {
  return littleParser::RuleOperator;
}


std::any littleParser::OperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<littleVisitor*>(visitor))
    return parserVisitor->visitOperator(this);
  else
    return visitor->visitChildren(this);
}

littleParser::OperatorContext* littleParser::operator_() {
  OperatorContext *_localctx = _tracker.createInstance<OperatorContext>(_ctx, getState());
  enterRule(_localctx, 10, littleParser::RuleOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3840) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void littleParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  littleParserInitialize();
#else
  ::antlr4::internal::call_once(littleParserOnceFlag, littleParserInitialize);
#endif
}
