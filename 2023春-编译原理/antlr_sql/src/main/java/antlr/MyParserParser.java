// Generated from java-escape by ANTLR 4.11.1
package antlr;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class MyParserParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.11.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, CREATE=12, SHOW=13, DROP=14, TABLE=15, TABLES=16, SELECT=17, 
		FROM=18, WHERE=19, INSERT=20, INTO=21, VALUES=22, DELETE=23, UPDATE=24, 
		SET=25, AND=26, OR=27, QUIT=28, CHAR=29, INT=30, ID=31, NUMBER=32, STRING=33, 
		WS=34;
	public static final int
		RULE_statements = 0, RULE_sql = 1, RULE_createFields = 2, RULE_createField = 3, 
		RULE_fields = 4, RULE_values = 5, RULE_value = 6, RULE_conditions = 7, 
		RULE_condition = 8, RULE_cmp = 9, RULE_updateFields = 10, RULE_updateField = 11;
	private static String[] makeRuleNames() {
		return new String[] {
			"statements", "sql", "createFields", "createField", "fields", "values", 
			"value", "conditions", "condition", "cmp", "updateFields", "updateField"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "';'", "'('", "')'", "'*'", "','", "'='", "'<'", "'<='", "'=>'", 
			"'>'", "'!='"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			"CREATE", "SHOW", "DROP", "TABLE", "TABLES", "SELECT", "FROM", "WHERE", 
			"INSERT", "INTO", "VALUES", "DELETE", "UPDATE", "SET", "AND", "OR", "QUIT", 
			"CHAR", "INT", "ID", "NUMBER", "STRING", "WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "java-escape"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public MyParserParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StatementsContext extends ParserRuleContext {
		public List<SqlContext> sql() {
			return getRuleContexts(SqlContext.class);
		}
		public SqlContext sql(int i) {
			return getRuleContext(SqlContext.class,i);
		}
		public StatementsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statements; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterStatements(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitStatements(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MyParserVisitor ) return ((MyParserVisitor<? extends T>)visitor).visitStatements(this);
			else return visitor.visitChildren(this);
		}
	}

	public final StatementsContext statements() throws RecognitionException {
		StatementsContext _localctx = new StatementsContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_statements);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(27); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(24);
				sql();
				setState(25);
				match(T__0);
				}
				}
				setState(29); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( ((_la) & ~0x3f) == 0 && ((1L << _la) & 26374144L) != 0 );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class SqlContext extends ParserRuleContext {
		public SqlContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sql; }
	 
		public SqlContext() { }
		public void copyFrom(SqlContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class DropContext extends SqlContext {
		public TerminalNode DROP() { return getToken(MyParserParser.DROP, 0); }
		public TerminalNode TABLE() { return getToken(MyParserParser.TABLE, 0); }
		public TerminalNode ID() { return getToken(MyParserParser.ID, 0); }
		public DropContext(SqlContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterDrop(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitDrop(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MyParserVisitor ) return ((MyParserVisitor<? extends T>)visitor).visitDrop(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class SelectContext extends SqlContext {
		public TerminalNode SELECT() { return getToken(MyParserParser.SELECT, 0); }
		public FieldsContext fields() {
			return getRuleContext(FieldsContext.class,0);
		}
		public TerminalNode FROM() { return getToken(MyParserParser.FROM, 0); }
		public TerminalNode ID() { return getToken(MyParserParser.ID, 0); }
		public TerminalNode WHERE() { return getToken(MyParserParser.WHERE, 0); }
		public ConditionsContext conditions() {
			return getRuleContext(ConditionsContext.class,0);
		}
		public SelectContext(SqlContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterSelect(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitSelect(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MyParserVisitor ) return ((MyParserVisitor<? extends T>)visitor).visitSelect(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ShowContext extends SqlContext {
		public TerminalNode SHOW() { return getToken(MyParserParser.SHOW, 0); }
		public TerminalNode TABLES() { return getToken(MyParserParser.TABLES, 0); }
		public ShowContext(SqlContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterShow(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitShow(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MyParserVisitor ) return ((MyParserVisitor<? extends T>)visitor).visitShow(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class CreateContext extends SqlContext {
		public TerminalNode CREATE() { return getToken(MyParserParser.CREATE, 0); }
		public TerminalNode TABLE() { return getToken(MyParserParser.TABLE, 0); }
		public TerminalNode ID() { return getToken(MyParserParser.ID, 0); }
		public CreateFieldsContext createFields() {
			return getRuleContext(CreateFieldsContext.class,0);
		}
		public CreateContext(SqlContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterCreate(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitCreate(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MyParserVisitor ) return ((MyParserVisitor<? extends T>)visitor).visitCreate(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class InsertContext extends SqlContext {
		public TerminalNode INSERT() { return getToken(MyParserParser.INSERT, 0); }
		public TerminalNode INTO() { return getToken(MyParserParser.INTO, 0); }
		public TerminalNode ID() { return getToken(MyParserParser.ID, 0); }
		public TerminalNode VALUES() { return getToken(MyParserParser.VALUES, 0); }
		public ValuesContext values() {
			return getRuleContext(ValuesContext.class,0);
		}
		public FieldsContext fields() {
			return getRuleContext(FieldsContext.class,0);
		}
		public InsertContext(SqlContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterInsert(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitInsert(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MyParserVisitor ) return ((MyParserVisitor<? extends T>)visitor).visitInsert(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class UpdateContext extends SqlContext {
		public TerminalNode UPDATE() { return getToken(MyParserParser.UPDATE, 0); }
		public TerminalNode ID() { return getToken(MyParserParser.ID, 0); }
		public TerminalNode SET() { return getToken(MyParserParser.SET, 0); }
		public UpdateFieldsContext updateFields() {
			return getRuleContext(UpdateFieldsContext.class,0);
		}
		public TerminalNode WHERE() { return getToken(MyParserParser.WHERE, 0); }
		public ConditionsContext conditions() {
			return getRuleContext(ConditionsContext.class,0);
		}
		public UpdateContext(SqlContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterUpdate(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitUpdate(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MyParserVisitor ) return ((MyParserVisitor<? extends T>)visitor).visitUpdate(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class DeleteContext extends SqlContext {
		public TerminalNode DELETE() { return getToken(MyParserParser.DELETE, 0); }
		public TerminalNode FROM() { return getToken(MyParserParser.FROM, 0); }
		public TerminalNode ID() { return getToken(MyParserParser.ID, 0); }
		public TerminalNode WHERE() { return getToken(MyParserParser.WHERE, 0); }
		public ConditionsContext conditions() {
			return getRuleContext(ConditionsContext.class,0);
		}
		public DeleteContext(SqlContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterDelete(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitDelete(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MyParserVisitor ) return ((MyParserVisitor<? extends T>)visitor).visitDelete(this);
			else return visitor.visitChildren(this);
		}
	}

	public final SqlContext sql() throws RecognitionException {
		SqlContext _localctx = new SqlContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_sql);
		int _la;
		try {
			setState(83);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case CREATE:
				_localctx = new CreateContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(31);
				match(CREATE);
				setState(32);
				match(TABLE);
				setState(33);
				match(ID);
				setState(34);
				match(T__1);
				setState(35);
				createFields();
				setState(36);
				match(T__2);
				}
				break;
			case SHOW:
				_localctx = new ShowContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(38);
				match(SHOW);
				setState(39);
				match(TABLES);
				}
				break;
			case DROP:
				_localctx = new DropContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(40);
				match(DROP);
				setState(41);
				match(TABLE);
				setState(42);
				match(ID);
				}
				break;
			case INSERT:
				_localctx = new InsertContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(43);
				match(INSERT);
				setState(44);
				match(INTO);
				setState(45);
				match(ID);
				setState(50);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==T__1) {
					{
					setState(46);
					match(T__1);
					setState(47);
					fields();
					setState(48);
					match(T__2);
					}
				}

				setState(52);
				match(VALUES);
				setState(53);
				match(T__1);
				setState(54);
				values();
				setState(55);
				match(T__2);
				}
				break;
			case SELECT:
				_localctx = new SelectContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(57);
				match(SELECT);
				setState(58);
				fields();
				setState(59);
				match(FROM);
				setState(60);
				match(ID);
				setState(63);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WHERE) {
					{
					setState(61);
					match(WHERE);
					setState(62);
					conditions(0);
					}
				}

				}
				break;
			case UPDATE:
				_localctx = new UpdateContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(65);
				match(UPDATE);
				setState(66);
				match(ID);
				setState(67);
				match(SET);
				setState(68);
				updateFields();
				setState(71);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WHERE) {
					{
					setState(69);
					match(WHERE);
					setState(70);
					conditions(0);
					}
				}

				}
				break;
			case DELETE:
				_localctx = new DeleteContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(73);
				match(DELETE);
				setState(75);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==T__3) {
					{
					setState(74);
					match(T__3);
					}
				}

				setState(77);
				match(FROM);
				setState(78);
				match(ID);
				setState(81);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WHERE) {
					{
					setState(79);
					match(WHERE);
					setState(80);
					conditions(0);
					}
				}

				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CreateFieldsContext extends ParserRuleContext {
		public List<CreateFieldContext> createField() {
			return getRuleContexts(CreateFieldContext.class);
		}
		public CreateFieldContext createField(int i) {
			return getRuleContext(CreateFieldContext.class,i);
		}
		public CreateFieldsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_createFields; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterCreateFields(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitCreateFields(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MyParserVisitor ) return ((MyParserVisitor<? extends T>)visitor).visitCreateFields(this);
			else return visitor.visitChildren(this);
		}
	}

	public final CreateFieldsContext createFields() throws RecognitionException {
		CreateFieldsContext _localctx = new CreateFieldsContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_createFields);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(85);
			createField();
			setState(90);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(86);
				match(T__4);
				setState(87);
				createField();
				}
				}
				setState(92);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CreateFieldContext extends ParserRuleContext {
		public CreateFieldContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_createField; }
	 
		public CreateFieldContext() { }
		public void copyFrom(CreateFieldContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class CreateNumberFieldContext extends CreateFieldContext {
		public TerminalNode ID() { return getToken(MyParserParser.ID, 0); }
		public TerminalNode INT() { return getToken(MyParserParser.INT, 0); }
		public CreateNumberFieldContext(CreateFieldContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterCreateNumberField(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitCreateNumberField(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MyParserVisitor ) return ((MyParserVisitor<? extends T>)visitor).visitCreateNumberField(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class CreateStringFieldContext extends CreateFieldContext {
		public TerminalNode ID() { return getToken(MyParserParser.ID, 0); }
		public TerminalNode CHAR() { return getToken(MyParserParser.CHAR, 0); }
		public TerminalNode NUMBER() { return getToken(MyParserParser.NUMBER, 0); }
		public CreateStringFieldContext(CreateFieldContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterCreateStringField(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitCreateStringField(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MyParserVisitor ) return ((MyParserVisitor<? extends T>)visitor).visitCreateStringField(this);
			else return visitor.visitChildren(this);
		}
	}

	public final CreateFieldContext createField() throws RecognitionException {
		CreateFieldContext _localctx = new CreateFieldContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_createField);
		try {
			setState(100);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				_localctx = new CreateNumberFieldContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(93);
				match(ID);
				setState(94);
				match(INT);
				}
				break;
			case 2:
				_localctx = new CreateStringFieldContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(95);
				match(ID);
				setState(96);
				match(CHAR);
				setState(97);
				match(T__1);
				setState(98);
				match(NUMBER);
				setState(99);
				match(T__2);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FieldsContext extends ParserRuleContext {
		public FieldsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fields; }
	 
		public FieldsContext() { }
		public void copyFrom(FieldsContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class AllFieldsContext extends FieldsContext {
		public AllFieldsContext(FieldsContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterAllFields(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitAllFields(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MyParserVisitor ) return ((MyParserVisitor<? extends T>)visitor).visitAllFields(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class SomeFieldsContext extends FieldsContext {
		public List<TerminalNode> ID() { return getTokens(MyParserParser.ID); }
		public TerminalNode ID(int i) {
			return getToken(MyParserParser.ID, i);
		}
		public SomeFieldsContext(FieldsContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterSomeFields(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitSomeFields(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MyParserVisitor ) return ((MyParserVisitor<? extends T>)visitor).visitSomeFields(this);
			else return visitor.visitChildren(this);
		}
	}

	public final FieldsContext fields() throws RecognitionException {
		FieldsContext _localctx = new FieldsContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_fields);
		int _la;
		try {
			setState(111);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__3:
				_localctx = new AllFieldsContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(102);
				match(T__3);
				}
				break;
			case ID:
				_localctx = new SomeFieldsContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(103);
				match(ID);
				setState(108);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__4) {
					{
					{
					setState(104);
					match(T__4);
					setState(105);
					match(ID);
					}
					}
					setState(110);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ValuesContext extends ParserRuleContext {
		public List<ValueContext> value() {
			return getRuleContexts(ValueContext.class);
		}
		public ValueContext value(int i) {
			return getRuleContext(ValueContext.class,i);
		}
		public ValuesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_values; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterValues(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitValues(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MyParserVisitor ) return ((MyParserVisitor<? extends T>)visitor).visitValues(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ValuesContext values() throws RecognitionException {
		ValuesContext _localctx = new ValuesContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_values);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(113);
			value();
			setState(118);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(114);
				match(T__4);
				setState(115);
				value();
				}
				}
				setState(120);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ValueContext extends ParserRuleContext {
		public TerminalNode NUMBER() { return getToken(MyParserParser.NUMBER, 0); }
		public TerminalNode STRING() { return getToken(MyParserParser.STRING, 0); }
		public ValueContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_value; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterValue(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitValue(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MyParserVisitor ) return ((MyParserVisitor<? extends T>)visitor).visitValue(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ValueContext value() throws RecognitionException {
		ValueContext _localctx = new ValueContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_value);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(121);
			_la = _input.LA(1);
			if ( !(_la==NUMBER || _la==STRING) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ConditionsContext extends ParserRuleContext {
		public Token op;
		public List<ConditionsContext> conditions() {
			return getRuleContexts(ConditionsContext.class);
		}
		public ConditionsContext conditions(int i) {
			return getRuleContext(ConditionsContext.class,i);
		}
		public ConditionContext condition() {
			return getRuleContext(ConditionContext.class,0);
		}
		public TerminalNode AND() { return getToken(MyParserParser.AND, 0); }
		public TerminalNode OR() { return getToken(MyParserParser.OR, 0); }
		public ConditionsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_conditions; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterConditions(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitConditions(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MyParserVisitor ) return ((MyParserVisitor<? extends T>)visitor).visitConditions(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ConditionsContext conditions() throws RecognitionException {
		return conditions(0);
	}

	private ConditionsContext conditions(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ConditionsContext _localctx = new ConditionsContext(_ctx, _parentState);
		ConditionsContext _prevctx = _localctx;
		int _startState = 14;
		enterRecursionRule(_localctx, 14, RULE_conditions, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(129);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__1:
				{
				setState(124);
				match(T__1);
				setState(125);
				conditions(0);
				setState(126);
				match(T__2);
				}
				break;
			case ID:
				{
				setState(128);
				condition();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(139);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(137);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
					case 1:
						{
						_localctx = new ConditionsContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_conditions);
						setState(131);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(132);
						((ConditionsContext)_localctx).op = match(AND);
						setState(133);
						conditions(5);
						}
						break;
					case 2:
						{
						_localctx = new ConditionsContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_conditions);
						setState(134);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(135);
						((ConditionsContext)_localctx).op = match(OR);
						setState(136);
						conditions(4);
						}
						break;
					}
					} 
				}
				setState(141);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ConditionContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(MyParserParser.ID, 0); }
		public CmpContext cmp() {
			return getRuleContext(CmpContext.class,0);
		}
		public ValueContext value() {
			return getRuleContext(ValueContext.class,0);
		}
		public ConditionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_condition; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterCondition(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitCondition(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MyParserVisitor ) return ((MyParserVisitor<? extends T>)visitor).visitCondition(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ConditionContext condition() throws RecognitionException {
		ConditionContext _localctx = new ConditionContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_condition);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(142);
			match(ID);
			setState(143);
			cmp();
			setState(144);
			value();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CmpContext extends ParserRuleContext {
		public CmpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_cmp; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterCmp(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitCmp(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MyParserVisitor ) return ((MyParserVisitor<? extends T>)visitor).visitCmp(this);
			else return visitor.visitChildren(this);
		}
	}

	public final CmpContext cmp() throws RecognitionException {
		CmpContext _localctx = new CmpContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_cmp);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(146);
			_la = _input.LA(1);
			if ( !(((_la) & ~0x3f) == 0 && ((1L << _la) & 4032L) != 0) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class UpdateFieldsContext extends ParserRuleContext {
		public List<UpdateFieldContext> updateField() {
			return getRuleContexts(UpdateFieldContext.class);
		}
		public UpdateFieldContext updateField(int i) {
			return getRuleContext(UpdateFieldContext.class,i);
		}
		public UpdateFieldsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_updateFields; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterUpdateFields(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitUpdateFields(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MyParserVisitor ) return ((MyParserVisitor<? extends T>)visitor).visitUpdateFields(this);
			else return visitor.visitChildren(this);
		}
	}

	public final UpdateFieldsContext updateFields() throws RecognitionException {
		UpdateFieldsContext _localctx = new UpdateFieldsContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_updateFields);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(148);
			updateField();
			setState(153);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__4) {
				{
				{
				setState(149);
				match(T__4);
				setState(150);
				updateField();
				}
				}
				setState(155);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class UpdateFieldContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(MyParserParser.ID, 0); }
		public ValueContext value() {
			return getRuleContext(ValueContext.class,0);
		}
		public UpdateFieldContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_updateField; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).enterUpdateField(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MyParserListener ) ((MyParserListener)listener).exitUpdateField(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MyParserVisitor ) return ((MyParserVisitor<? extends T>)visitor).visitUpdateField(this);
			else return visitor.visitChildren(this);
		}
	}

	public final UpdateFieldContext updateField() throws RecognitionException {
		UpdateFieldContext _localctx = new UpdateFieldContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_updateField);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(156);
			match(ID);
			setState(157);
			match(T__5);
			setState(158);
			value();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 7:
			return conditions_sempred((ConditionsContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean conditions_sempred(ConditionsContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 4);
		case 1:
			return precpred(_ctx, 3);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001\"\u00a1\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0001"+
		"\u0000\u0001\u0000\u0001\u0000\u0004\u0000\u001c\b\u0000\u000b\u0000\f"+
		"\u0000\u001d\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0003\u00013\b\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0003\u0001@\b\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0003\u0001"+
		"H\b\u0001\u0001\u0001\u0001\u0001\u0003\u0001L\b\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0003\u0001R\b\u0001\u0003\u0001T\b\u0001"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0005\u0002Y\b\u0002\n\u0002\f\u0002"+
		"\\\t\u0002\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0003\u0003e\b\u0003\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0005\u0004k\b\u0004\n\u0004\f\u0004n\t\u0004"+
		"\u0003\u0004p\b\u0004\u0001\u0005\u0001\u0005\u0001\u0005\u0005\u0005"+
		"u\b\u0005\n\u0005\f\u0005x\t\u0005\u0001\u0006\u0001\u0006\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0003\u0007"+
		"\u0082\b\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007"+
		"\u0001\u0007\u0005\u0007\u008a\b\u0007\n\u0007\f\u0007\u008d\t\u0007\u0001"+
		"\b\u0001\b\u0001\b\u0001\b\u0001\t\u0001\t\u0001\n\u0001\n\u0001\n\u0005"+
		"\n\u0098\b\n\n\n\f\n\u009b\t\n\u0001\u000b\u0001\u000b\u0001\u000b\u0001"+
		"\u000b\u0001\u000b\u0000\u0001\u000e\f\u0000\u0002\u0004\u0006\b\n\f\u000e"+
		"\u0010\u0012\u0014\u0016\u0000\u0002\u0001\u0000 !\u0001\u0000\u0006\u000b"+
		"\u00a9\u0000\u001b\u0001\u0000\u0000\u0000\u0002S\u0001\u0000\u0000\u0000"+
		"\u0004U\u0001\u0000\u0000\u0000\u0006d\u0001\u0000\u0000\u0000\bo\u0001"+
		"\u0000\u0000\u0000\nq\u0001\u0000\u0000\u0000\fy\u0001\u0000\u0000\u0000"+
		"\u000e\u0081\u0001\u0000\u0000\u0000\u0010\u008e\u0001\u0000\u0000\u0000"+
		"\u0012\u0092\u0001\u0000\u0000\u0000\u0014\u0094\u0001\u0000\u0000\u0000"+
		"\u0016\u009c\u0001\u0000\u0000\u0000\u0018\u0019\u0003\u0002\u0001\u0000"+
		"\u0019\u001a\u0005\u0001\u0000\u0000\u001a\u001c\u0001\u0000\u0000\u0000"+
		"\u001b\u0018\u0001\u0000\u0000\u0000\u001c\u001d\u0001\u0000\u0000\u0000"+
		"\u001d\u001b\u0001\u0000\u0000\u0000\u001d\u001e\u0001\u0000\u0000\u0000"+
		"\u001e\u0001\u0001\u0000\u0000\u0000\u001f \u0005\f\u0000\u0000 !\u0005"+
		"\u000f\u0000\u0000!\"\u0005\u001f\u0000\u0000\"#\u0005\u0002\u0000\u0000"+
		"#$\u0003\u0004\u0002\u0000$%\u0005\u0003\u0000\u0000%T\u0001\u0000\u0000"+
		"\u0000&\'\u0005\r\u0000\u0000\'T\u0005\u0010\u0000\u0000()\u0005\u000e"+
		"\u0000\u0000)*\u0005\u000f\u0000\u0000*T\u0005\u001f\u0000\u0000+,\u0005"+
		"\u0014\u0000\u0000,-\u0005\u0015\u0000\u0000-2\u0005\u001f\u0000\u0000"+
		"./\u0005\u0002\u0000\u0000/0\u0003\b\u0004\u000001\u0005\u0003\u0000\u0000"+
		"13\u0001\u0000\u0000\u00002.\u0001\u0000\u0000\u000023\u0001\u0000\u0000"+
		"\u000034\u0001\u0000\u0000\u000045\u0005\u0016\u0000\u000056\u0005\u0002"+
		"\u0000\u000067\u0003\n\u0005\u000078\u0005\u0003\u0000\u00008T\u0001\u0000"+
		"\u0000\u00009:\u0005\u0011\u0000\u0000:;\u0003\b\u0004\u0000;<\u0005\u0012"+
		"\u0000\u0000<?\u0005\u001f\u0000\u0000=>\u0005\u0013\u0000\u0000>@\u0003"+
		"\u000e\u0007\u0000?=\u0001\u0000\u0000\u0000?@\u0001\u0000\u0000\u0000"+
		"@T\u0001\u0000\u0000\u0000AB\u0005\u0018\u0000\u0000BC\u0005\u001f\u0000"+
		"\u0000CD\u0005\u0019\u0000\u0000DG\u0003\u0014\n\u0000EF\u0005\u0013\u0000"+
		"\u0000FH\u0003\u000e\u0007\u0000GE\u0001\u0000\u0000\u0000GH\u0001\u0000"+
		"\u0000\u0000HT\u0001\u0000\u0000\u0000IK\u0005\u0017\u0000\u0000JL\u0005"+
		"\u0004\u0000\u0000KJ\u0001\u0000\u0000\u0000KL\u0001\u0000\u0000\u0000"+
		"LM\u0001\u0000\u0000\u0000MN\u0005\u0012\u0000\u0000NQ\u0005\u001f\u0000"+
		"\u0000OP\u0005\u0013\u0000\u0000PR\u0003\u000e\u0007\u0000QO\u0001\u0000"+
		"\u0000\u0000QR\u0001\u0000\u0000\u0000RT\u0001\u0000\u0000\u0000S\u001f"+
		"\u0001\u0000\u0000\u0000S&\u0001\u0000\u0000\u0000S(\u0001\u0000\u0000"+
		"\u0000S+\u0001\u0000\u0000\u0000S9\u0001\u0000\u0000\u0000SA\u0001\u0000"+
		"\u0000\u0000SI\u0001\u0000\u0000\u0000T\u0003\u0001\u0000\u0000\u0000"+
		"UZ\u0003\u0006\u0003\u0000VW\u0005\u0005\u0000\u0000WY\u0003\u0006\u0003"+
		"\u0000XV\u0001\u0000\u0000\u0000Y\\\u0001\u0000\u0000\u0000ZX\u0001\u0000"+
		"\u0000\u0000Z[\u0001\u0000\u0000\u0000[\u0005\u0001\u0000\u0000\u0000"+
		"\\Z\u0001\u0000\u0000\u0000]^\u0005\u001f\u0000\u0000^e\u0005\u001e\u0000"+
		"\u0000_`\u0005\u001f\u0000\u0000`a\u0005\u001d\u0000\u0000ab\u0005\u0002"+
		"\u0000\u0000bc\u0005 \u0000\u0000ce\u0005\u0003\u0000\u0000d]\u0001\u0000"+
		"\u0000\u0000d_\u0001\u0000\u0000\u0000e\u0007\u0001\u0000\u0000\u0000"+
		"fp\u0005\u0004\u0000\u0000gl\u0005\u001f\u0000\u0000hi\u0005\u0005\u0000"+
		"\u0000ik\u0005\u001f\u0000\u0000jh\u0001\u0000\u0000\u0000kn\u0001\u0000"+
		"\u0000\u0000lj\u0001\u0000\u0000\u0000lm\u0001\u0000\u0000\u0000mp\u0001"+
		"\u0000\u0000\u0000nl\u0001\u0000\u0000\u0000of\u0001\u0000\u0000\u0000"+
		"og\u0001\u0000\u0000\u0000p\t\u0001\u0000\u0000\u0000qv\u0003\f\u0006"+
		"\u0000rs\u0005\u0005\u0000\u0000su\u0003\f\u0006\u0000tr\u0001\u0000\u0000"+
		"\u0000ux\u0001\u0000\u0000\u0000vt\u0001\u0000\u0000\u0000vw\u0001\u0000"+
		"\u0000\u0000w\u000b\u0001\u0000\u0000\u0000xv\u0001\u0000\u0000\u0000"+
		"yz\u0007\u0000\u0000\u0000z\r\u0001\u0000\u0000\u0000{|\u0006\u0007\uffff"+
		"\uffff\u0000|}\u0005\u0002\u0000\u0000}~\u0003\u000e\u0007\u0000~\u007f"+
		"\u0005\u0003\u0000\u0000\u007f\u0082\u0001\u0000\u0000\u0000\u0080\u0082"+
		"\u0003\u0010\b\u0000\u0081{\u0001\u0000\u0000\u0000\u0081\u0080\u0001"+
		"\u0000\u0000\u0000\u0082\u008b\u0001\u0000\u0000\u0000\u0083\u0084\n\u0004"+
		"\u0000\u0000\u0084\u0085\u0005\u001a\u0000\u0000\u0085\u008a\u0003\u000e"+
		"\u0007\u0005\u0086\u0087\n\u0003\u0000\u0000\u0087\u0088\u0005\u001b\u0000"+
		"\u0000\u0088\u008a\u0003\u000e\u0007\u0004\u0089\u0083\u0001\u0000\u0000"+
		"\u0000\u0089\u0086\u0001\u0000\u0000\u0000\u008a\u008d\u0001\u0000\u0000"+
		"\u0000\u008b\u0089\u0001\u0000\u0000\u0000\u008b\u008c\u0001\u0000\u0000"+
		"\u0000\u008c\u000f\u0001\u0000\u0000\u0000\u008d\u008b\u0001\u0000\u0000"+
		"\u0000\u008e\u008f\u0005\u001f\u0000\u0000\u008f\u0090\u0003\u0012\t\u0000"+
		"\u0090\u0091\u0003\f\u0006\u0000\u0091\u0011\u0001\u0000\u0000\u0000\u0092"+
		"\u0093\u0007\u0001\u0000\u0000\u0093\u0013\u0001\u0000\u0000\u0000\u0094"+
		"\u0099\u0003\u0016\u000b\u0000\u0095\u0096\u0005\u0005\u0000\u0000\u0096"+
		"\u0098\u0003\u0016\u000b\u0000\u0097\u0095\u0001\u0000\u0000\u0000\u0098"+
		"\u009b\u0001\u0000\u0000\u0000\u0099\u0097\u0001\u0000\u0000\u0000\u0099"+
		"\u009a\u0001\u0000\u0000\u0000\u009a\u0015\u0001\u0000\u0000\u0000\u009b"+
		"\u0099\u0001\u0000\u0000\u0000\u009c\u009d\u0005\u001f\u0000\u0000\u009d"+
		"\u009e\u0005\u0006\u0000\u0000\u009e\u009f\u0003\f\u0006\u0000\u009f\u0017"+
		"\u0001\u0000\u0000\u0000\u0010\u001d2?GKQSZdlov\u0081\u0089\u008b\u0099";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}