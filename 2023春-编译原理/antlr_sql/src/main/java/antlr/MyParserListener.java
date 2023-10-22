// Generated from java-escape by ANTLR 4.11.1
package antlr;
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link MyParserParser}.
 */
public interface MyParserListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link MyParserParser#statements}.
	 * @param ctx the parse tree
	 */
	void enterStatements(MyParserParser.StatementsContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyParserParser#statements}.
	 * @param ctx the parse tree
	 */
	void exitStatements(MyParserParser.StatementsContext ctx);
	/**
	 * Enter a parse tree produced by the {@code create}
	 * labeled alternative in {@link MyParserParser#sql}.
	 * @param ctx the parse tree
	 */
	void enterCreate(MyParserParser.CreateContext ctx);
	/**
	 * Exit a parse tree produced by the {@code create}
	 * labeled alternative in {@link MyParserParser#sql}.
	 * @param ctx the parse tree
	 */
	void exitCreate(MyParserParser.CreateContext ctx);
	/**
	 * Enter a parse tree produced by the {@code show}
	 * labeled alternative in {@link MyParserParser#sql}.
	 * @param ctx the parse tree
	 */
	void enterShow(MyParserParser.ShowContext ctx);
	/**
	 * Exit a parse tree produced by the {@code show}
	 * labeled alternative in {@link MyParserParser#sql}.
	 * @param ctx the parse tree
	 */
	void exitShow(MyParserParser.ShowContext ctx);
	/**
	 * Enter a parse tree produced by the {@code drop}
	 * labeled alternative in {@link MyParserParser#sql}.
	 * @param ctx the parse tree
	 */
	void enterDrop(MyParserParser.DropContext ctx);
	/**
	 * Exit a parse tree produced by the {@code drop}
	 * labeled alternative in {@link MyParserParser#sql}.
	 * @param ctx the parse tree
	 */
	void exitDrop(MyParserParser.DropContext ctx);
	/**
	 * Enter a parse tree produced by the {@code insert}
	 * labeled alternative in {@link MyParserParser#sql}.
	 * @param ctx the parse tree
	 */
	void enterInsert(MyParserParser.InsertContext ctx);
	/**
	 * Exit a parse tree produced by the {@code insert}
	 * labeled alternative in {@link MyParserParser#sql}.
	 * @param ctx the parse tree
	 */
	void exitInsert(MyParserParser.InsertContext ctx);
	/**
	 * Enter a parse tree produced by the {@code select}
	 * labeled alternative in {@link MyParserParser#sql}.
	 * @param ctx the parse tree
	 */
	void enterSelect(MyParserParser.SelectContext ctx);
	/**
	 * Exit a parse tree produced by the {@code select}
	 * labeled alternative in {@link MyParserParser#sql}.
	 * @param ctx the parse tree
	 */
	void exitSelect(MyParserParser.SelectContext ctx);
	/**
	 * Enter a parse tree produced by the {@code update}
	 * labeled alternative in {@link MyParserParser#sql}.
	 * @param ctx the parse tree
	 */
	void enterUpdate(MyParserParser.UpdateContext ctx);
	/**
	 * Exit a parse tree produced by the {@code update}
	 * labeled alternative in {@link MyParserParser#sql}.
	 * @param ctx the parse tree
	 */
	void exitUpdate(MyParserParser.UpdateContext ctx);
	/**
	 * Enter a parse tree produced by the {@code delete}
	 * labeled alternative in {@link MyParserParser#sql}.
	 * @param ctx the parse tree
	 */
	void enterDelete(MyParserParser.DeleteContext ctx);
	/**
	 * Exit a parse tree produced by the {@code delete}
	 * labeled alternative in {@link MyParserParser#sql}.
	 * @param ctx the parse tree
	 */
	void exitDelete(MyParserParser.DeleteContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyParserParser#createFields}.
	 * @param ctx the parse tree
	 */
	void enterCreateFields(MyParserParser.CreateFieldsContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyParserParser#createFields}.
	 * @param ctx the parse tree
	 */
	void exitCreateFields(MyParserParser.CreateFieldsContext ctx);
	/**
	 * Enter a parse tree produced by the {@code createNumberField}
	 * labeled alternative in {@link MyParserParser#createField}.
	 * @param ctx the parse tree
	 */
	void enterCreateNumberField(MyParserParser.CreateNumberFieldContext ctx);
	/**
	 * Exit a parse tree produced by the {@code createNumberField}
	 * labeled alternative in {@link MyParserParser#createField}.
	 * @param ctx the parse tree
	 */
	void exitCreateNumberField(MyParserParser.CreateNumberFieldContext ctx);
	/**
	 * Enter a parse tree produced by the {@code createStringField}
	 * labeled alternative in {@link MyParserParser#createField}.
	 * @param ctx the parse tree
	 */
	void enterCreateStringField(MyParserParser.CreateStringFieldContext ctx);
	/**
	 * Exit a parse tree produced by the {@code createStringField}
	 * labeled alternative in {@link MyParserParser#createField}.
	 * @param ctx the parse tree
	 */
	void exitCreateStringField(MyParserParser.CreateStringFieldContext ctx);
	/**
	 * Enter a parse tree produced by the {@code allFields}
	 * labeled alternative in {@link MyParserParser#fields}.
	 * @param ctx the parse tree
	 */
	void enterAllFields(MyParserParser.AllFieldsContext ctx);
	/**
	 * Exit a parse tree produced by the {@code allFields}
	 * labeled alternative in {@link MyParserParser#fields}.
	 * @param ctx the parse tree
	 */
	void exitAllFields(MyParserParser.AllFieldsContext ctx);
	/**
	 * Enter a parse tree produced by the {@code someFields}
	 * labeled alternative in {@link MyParserParser#fields}.
	 * @param ctx the parse tree
	 */
	void enterSomeFields(MyParserParser.SomeFieldsContext ctx);
	/**
	 * Exit a parse tree produced by the {@code someFields}
	 * labeled alternative in {@link MyParserParser#fields}.
	 * @param ctx the parse tree
	 */
	void exitSomeFields(MyParserParser.SomeFieldsContext ctx);
	/**
	 * Enter a parse tree produced by the {@code values}
	 * labeled alternative in {@link MyParserParser#sqlsqlsqlsqlsqlsqlsqlcreateFieldcreateFieldfieldsfields}.
	 * @param ctx the parse tree
	 */
	void enterValues(MyParserParser.ValuesContext ctx);
	/**
	 * Exit a parse tree produced by the {@code values}
	 * labeled alternative in {@link MyParserParser#sqlsqlsqlsqlsqlsqlsqlcreateFieldcreateFieldfieldsfields}.
	 * @param ctx the parse tree
	 */
	void exitValues(MyParserParser.ValuesContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyParserParser#value}.
	 * @param ctx the parse tree
	 */
	void enterValue(MyParserParser.ValueContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyParserParser#value}.
	 * @param ctx the parse tree
	 */
	void exitValue(MyParserParser.ValueContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyParserParser#conditions}.
	 * @param ctx the parse tree
	 */
	void enterConditions(MyParserParser.ConditionsContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyParserParser#conditions}.
	 * @param ctx the parse tree
	 */
	void exitConditions(MyParserParser.ConditionsContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyParserParser#condition}.
	 * @param ctx the parse tree
	 */
	void enterCondition(MyParserParser.ConditionContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyParserParser#condition}.
	 * @param ctx the parse tree
	 */
	void exitCondition(MyParserParser.ConditionContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyParserParser#cmp}.
	 * @param ctx the parse tree
	 */
	void enterCmp(MyParserParser.CmpContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyParserParser#cmp}.
	 * @param ctx the parse tree
	 */
	void exitCmp(MyParserParser.CmpContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyParserParser#updateFields}.
	 * @param ctx the parse tree
	 */
	void enterUpdateFields(MyParserParser.UpdateFieldsContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyParserParser#updateFields}.
	 * @param ctx the parse tree
	 */
	void exitUpdateFields(MyParserParser.UpdateFieldsContext ctx);
	/**
	 * Enter a parse tree produced by {@link MyParserParser#updateField}.
	 * @param ctx the parse tree
	 */
	void enterUpdateField(MyParserParser.UpdateFieldContext ctx);
	/**
	 * Exit a parse tree produced by {@link MyParserParser#updateField}.
	 * @param ctx the parse tree
	 */
	void exitUpdateField(MyParserParser.UpdateFieldContext ctx);
}