grammar little;

program: statement+;

statement: assignment | ifStatement;

assignment: ID '=' expression ';';

ifStatement: 'if' expression 'then' program ('else' program)?;

expression: '(' expression ')'              # parens
         | ID                              # variable
         | INT                             # integer
         | op=operator e1=expression e2=expression   # binaryExpr
         ;

operator: '+' | '-' | '*' | '/';

ID: [a-zA-Z]+;
INT: [0-9]+;
WS: [ \t\r\n]+ -> skip;
