package shell;

import antlr.MyParserBaseVisitor;
import antlr.MyParserParser;
import core.Database;
import core.Meta;
import org.antlr.v4.runtime.tree.TerminalNode;

import java.util.ArrayList;
import java.util.List;

// 访问器 TODO: 深浅拷贝问题
public class MyVisitor extends MyParserBaseVisitor<String> {
    Database db;

    public MyVisitor(Database db) {
        this.db = db;
    }

    @Override
    public String visitStatements(MyParserParser.StatementsContext ctx) {
        StringBuilder sb = new StringBuilder();
        for (MyParserParser.SqlContext sql : ctx.sql()) {
            sb.append(visit(sql)).append('\n');
            // createFields.clear();
            // createTypes.clear();
            // values.clear();
            // fields.clear();
        }
        sb.append(String.format("执行 %d 条语句", ctx.sql().size()));
        return sb.toString();
    }

    // 新建表
    // create table t1(f1 int, f2 char(111));
    @Override
    public String visitCreate(MyParserParser.CreateContext ctx) {
        // 表名
        String tableName = ctx.ID().getText(); // getText 返回字面量
        // 字段
        String err = visit(ctx.createFields()); // visitXXX 返回计算量
        if (err != null) return err;
        return db.create(tableName, createFields, createTypes);
    }

    List<String> createFields;
    List<Meta.Type> createTypes;

    @Override
    public String visitCreateFields(MyParserParser.CreateFieldsContext ctx) {
        createFields = new ArrayList<>();
        createTypes = new ArrayList<>();
        String err;
        for (MyParserParser.CreateFieldContext createFieldContext : ctx.createField()) {
            err = visit(createFieldContext);
            if (err != null) {
                return err;
            }
        }
        return null;
    }

    @Override
    public String visitCreateNumberField(MyParserParser.CreateNumberFieldContext ctx) {
        String field = ctx.ID().getText();
        createFields.add(field);
        createTypes.add(Meta.Type.NUMBER);
        return null;
    }

    @Override
    public String visitCreateStringField(MyParserParser.CreateStringFieldContext ctx) {
        String field = ctx.ID().getText();
        createFields.add(field);
        createTypes.add(Meta.Type.STRING);
        return null;
    }

    // 显示所有表
    @Override
    public String visitShow(MyParserParser.ShowContext ctx) {
        return db.show();
    }

    // 删除表
    @Override
    public String visitDrop(MyParserParser.DropContext ctx) {
        String tableName = ctx.ID().getText();
        return db.drop(tableName);
    }

    // 插入
    @Override
    public String visitInsert(MyParserParser.InsertContext ctx) {
        // 表名
        String tableName = ctx.ID().getText();
        // 数据
        visit(ctx.values());
        // 字段
        MyParserParser.FieldsContext fieldsContext = ctx.fields();
        if (fieldsContext == null) {
            // 全部插入
            return db.insert(tableName, values);
        } else {
            // 部分插入
            if (visit(fieldsContext) == null) {
                return db.insert(tableName, values, fields);
            } else {
                return db.insert(tableName, values);
            }
        }
    }

    List<String> values;

    @Override
    public String visitValues(MyParserParser.ValuesContext ctx) {
        values = new ArrayList<>();
        for (MyParserParser.ValueContext valueContext : ctx.value()) {
            visit(valueContext);
        }
        return null;
    }

    @Override
    public String visitValue(MyParserParser.ValueContext ctx) {
        values.add(ctx.getText().replace('\'', '"'));
        return null;
    }

    @Override
    public String visitAllFields(MyParserParser.AllFieldsContext ctx) {
        return "*";
    }

    List<String> fields;

    @Override
    public String visitSomeFields(MyParserParser.SomeFieldsContext ctx) {
        fields = new ArrayList<>();
        for (TerminalNode id : ctx.ID()) {
            fields.add(id.getText());
        }
        return null;
    }

    // 查询
    @Override
    public String visitSelect(MyParserParser.SelectContext ctx) {
        // 表名
        String tableName = ctx.ID().getText();
        // 字段
        if (visit(ctx.fields()).equals("*")) {
            return db.select(tableName);
        } else {
            return db.select(tableName, fields);
        }
    }

    // 更新
    // UPDATE Person SET Address = 'Zhongshan 23', City = 'Nanjing';
    @Override
    public String visitUpdate(MyParserParser.UpdateContext ctx) {
        String tableName = ctx.ID().getText();
        visit(ctx.updateFields());
        return db.update(tableName, values, fields);
        // TODO: conditions如何实现?
    }

    @Override
    public String visitUpdateFields(MyParserParser.UpdateFieldsContext ctx) {
        values = new ArrayList<>();
        fields = new ArrayList<>();
        for (MyParserParser.UpdateFieldContext updateFieldContext : ctx.updateField()) {
            visit(updateFieldContext);
        }
        return null;
    }

    @Override
    public String visitUpdateField(MyParserParser.UpdateFieldContext ctx) {
        fields.add(ctx.ID().getText());
        visit(ctx.value()); // values.add
        return null;
    }

    // 删除
    // DELETE FROM table_name;
    @Override
    public String visitDelete(MyParserParser.DeleteContext ctx) {
        String tableName = ctx.ID().getText();
        return db.delete(tableName);
    }

    @Override
    public String visitConditions(MyParserParser.ConditionsContext ctx) {
        return null;
    }

    @Override
    public String visitCondition(MyParserParser.ConditionContext ctx) {
        return null;
    }

    @Override
    public String visitCmp(MyParserParser.CmpContext ctx) {
        return null;
    }
}
