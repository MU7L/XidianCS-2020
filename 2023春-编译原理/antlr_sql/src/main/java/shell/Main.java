package shell;

import antlr.MyParserLexer;
import antlr.MyParserParser;
import core.Database;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;

import java.util.Scanner;

// 启动类
public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        Database db = Database.getInstance();
        //创建访问器
        MyVisitor visitor = new MyVisitor(db);

        // REPL
        while (true) {
            System.out.print("SQL> ");
            String sql = sc.nextLine();
            if (sql.equals("quit") || sql.equals("QUIT")) break;
            CharStream input = CharStreams.fromString(sql);

            //词法分析器
            MyParserLexer lexer = new MyParserLexer(input);
            //将词法分析器产生的词法符号放到缓冲区
            CommonTokenStream tokens = new CommonTokenStream(lexer);
            //将词法符号送入语法分析器
            MyParserParser parser = new MyParserParser(tokens);
            //开始分析
            ParseTree tree = parser.statements();
            // System.out.println(tree.toStringTree());

            //开始遍历分析树
            String result = visitor.visit(tree);
            System.out.println(result);
        }
        sc.close();
        System.out.println("bye.");
    }
}
