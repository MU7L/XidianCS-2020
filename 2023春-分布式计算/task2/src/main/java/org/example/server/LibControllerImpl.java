package org.example.server;

import org.example.Book;
import org.example.LibController;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class LibControllerImpl implements LibController, DataBase {

    Connection connection;

    public LibControllerImpl() throws SQLException {
        connection = DriverManager.getConnection(JDBC_URL, JDBC_USER, JDBC_PASSWORD);
    }

    // 添加一个书籍对象
    public boolean add(Book b) {
        try {
            String sql = "INSERT INTO task2(book_id, name) VALUES(?,?)";
            PreparedStatement statement = connection.prepareCall(sql);
            statement.setInt(1, b.bookID);
            statement.setString(2, b.name);
            int i = statement.executeUpdate();
            return i == 1;
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
    }

    // 查询指定ID号的书籍对象
    public Book queryByID(int bookID) {
        try {
            String sql = "SELECT * FROM task2 WHERE book_id = ?";
            PreparedStatement statement = connection.prepareCall(sql);
            statement.setInt(1, bookID);
            ResultSet rs = statement.executeQuery();
            rs.next();
            return new Book(rs.getInt(1), rs.getString(2));
        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }
    }

    // 按书名查询符合条件的书籍对象列表 支持模糊查询
    public List<Book> queryByName(String name) {
        try {
            String sql = "SELECT * FROM task2 WHERE name LIKE ?";
            PreparedStatement statement = connection.prepareCall(sql);
            statement.setString(1, "%" + name + "%");
            ResultSet rs = statement.executeQuery();
            List<Book> ret = new ArrayList<>();
            while (rs.next()) {
                ret.add(new Book(rs.getInt(1), rs.getString(2)));
            }
            return ret;
        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }
    }

    // 删除指定ID号的书籍对象
    public boolean delete(int bookID) {
        try {
            String sql = "DELETE FROM task2 WHERE book_id = ?";
            PreparedStatement statement = connection.prepareCall(sql);
            statement.setInt(1, bookID);
            statement.executeUpdate();
            return true;
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
    }

}
