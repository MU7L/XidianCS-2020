grammar MyParser;
import MyLexer;

statements: (sql ';')+ ;

sql: CREATE TABLE ID '(' createFields ')' # create
    | SHOW TABLES # show
    | DROP TABLE ID # drop
    | INSERT INTO ID ('(' fields ')')? VALUES '(' values ')' # insert
    | SELECT fields FROM ID (WHERE conditions)? # select
    | UPDATE ID SET updateFields (WHERE conditions)? # update
    | DELETE ('*')? FROM ID (WHERE conditions)? # delete
    ;

createFields: createField (',' createField)* ;

createField: ID INT # createNumberField
    | ID CHAR '(' NUMBER ')' # createStringField
    ;

fields: '*' # allFields
    | ID (',' ID)* # someFields
    ;


values: value (',' value)* ;

value: NUMBER | STRING ;

conditions: conditions op=AND conditions
    | conditions op=OR conditions
    | '(' conditions ')'
    | condition
    ;

condition: ID cmp value ;

cmp: '=' | '<' | '<=' | '=>' | '>' | '!=' ;

updateFields: updateField (',' updateField)* ;

updateField: ID '=' value ;
