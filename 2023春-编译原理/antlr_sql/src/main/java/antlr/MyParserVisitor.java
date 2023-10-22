// Generated from java-escape by ANTLR 4.11.1
package antlr;
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link MyParserParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface MyParserVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link MyParserParser#statements}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStatements(MyParserParser.StatementsContext ctx);
	/**
	 * Visit a parse tree produced by the {@code create}
	 * labeled alternative in {@link MyParserParser#sql}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCreate(MyParserParser.CreateContext ctx);
	/**
	 * Visit a parse tree produced by the {@code show}
	 * labeled alternative in {@link MyParserParser#sql}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitShow(MyParserParser.ShowContext ctx);
	/**
	 * Visit a parse tree produced by the {@code drop}
	 * labeled alternative in {@link MyParserParser#sql}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDrop(MyParserParser.DropContext ctx);
	/**
	 * Visit a parse tree produced by the {@code insert}
	 * labeled alternative in {@link MyParserParser#sql}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInsert(MyParserParser.InsertContext ctx);
	/**
	 * Visit a parse tree produced by the {@code select}
	 * labeled alternative in {@link MyParserParser#sql}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSelect(MyParserParser.SelectContext ctx);
	/**
	 * Visit a parse tree produced by the {@code update}
	 * labeled alternative in {@link MyParserParser#sql}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitUpdate(MyParserParser.UpdateContext ctx);
	/**
	 * Visit a parse tree produced by the {@code delete}
	 * labeled alternative in {@link MyParserParser#sql}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDelete(MyParserParser.DeleteContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyParserParser#createFields}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCreateFields(MyParserParser.CreateFieldsContext ctx);
	/**
	 * Visit a parse tree produced by the {@code createNumberField}
	 * labeled alternative in {@link MyParserParser#createField}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCreateNumberField(MyParserParser.CreateNumberFieldContext ctx);
	/**
	 * Visit a parse tree produced by the {@code createStringField}
	 * labeled alternative in {@link MyParserParser#createField}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCreateStringField(MyParserParser.CreateStringFieldContext ctx);
	/**
	 * Visit a parse tree produced by the {@code allFields}
	 * labeled alternative in {@link MyParserParser#fields}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAllFields(MyParserParser.AllFieldsContext ctx);
	/**
	 * Visit a parse tree produced by the {@code someFields}
	 * labeled alternative in {@link MyParserParser#fields}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSomeFields(MyParserParser.SomeFieldsContext ctx);
	/**
	 * Visit a parse tree produced by the {@code values}
	 * labeled alternative in {@link MyParserParser#sqlsqlsqlsqlsqlsqlsqlcreateFieldcreateFieldfieldsfields}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitValues(MyParserParser.ValuesContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyParserParser#value}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitValue(MyParserParser.ValueContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyParserParser#conditions}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConditions(MyParserParser.ConditionsContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyParserParser#condition}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCondition(MyParserParser.ConditionContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyParserParser#cmp}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCmp(MyParserParser.CmpContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyParserParser#updateFields}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitUpdateFields(MyParserParser.UpdateFieldsContext ctx);
	/**
	 * Visit a parse tree produced by {@link MyParserParser#updateField}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitUpdateField(MyParserParser.UpdateFieldContext ctx);
}