lexer grammar MyLexer;

CREATE: 'create'|'CREATE';
SHOW: 'show'|'SHOW';
DROP: 'DROP'|'drop' ;
TABLE: 'TABLE'|'table' ;
TABLES: 'TABLES' | 'tables' ;

SELECT: 'SELECT'|'select' ;
FROM: 'FROM'|'from' ;
WHERE: 'WHERE'|'where' ;
INSERT: 'INSERT'|'insert' ;
INTO: 'INTO'|'into' ;
VALUES: 'VALUES'|'values' ;
DELETE: 'DELETE'|'delete' ;
UPDATE: 'UPDATE'|'update' ;
SET: 'SET'|'set' ;

AND: 'AND'|'and';
OR: 'OR'|'or';

QUIT: 'QUIT'|'EXIT'|'quit'|'exit';

CHAR: 'CHAR'|'char';
INT: 'INT'|'int';

// base

ID: [a-zA-Z][a-zA-Z_0-9]*;

NUMBER: '-'?[1-9][0-9]*
    | '0'
    ;

STRING: '"' (.)*? '"'
    | '\'' (.)*? '\''
    ;

// ignore

WS : [ \t\r\n]+ -> skip;
