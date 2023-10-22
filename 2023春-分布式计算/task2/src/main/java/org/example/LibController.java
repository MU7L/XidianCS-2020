package org.example;

import org.example.Book;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.List;

public interface LibController extends Remote {
    boolean add(Book b) throws RemoteException;  // 添加一个书籍对象
    Book queryByID(int bookID) throws RemoteException;  // 查询指定ID号的书籍对象
    List<Book> queryByName(String name) throws RemoteException;  // 按书名查询符合条件的书籍对象列表 支持模糊查询
    boolean delete(int bookID) throws RemoteException;  // 删除指定ID号的书籍对象
}
