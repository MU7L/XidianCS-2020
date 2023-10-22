package org.example.client;

import org.example.Book;
import org.example.LibController;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.List;

public class Client {
    private LibController lib;
    public boolean isOnline;

    Client(String host, int port) throws RemoteException, NotBoundException {
        // 连接到服务器localhost，端口1099:
        Registry registry = LocateRegistry.getRegistry(host, port);
        // 查找名称为"LibController"的服务并强制转型为LibController接口:
        lib = (LibController) registry.lookup("LibController");
        isOnline = true;
    }

    String exec(String[] args) throws RemoteException {
        if (args[0].equals("help")) {
            return "add <ID号> <书名>\t添加一个书籍对象" +
                    "\nqueryByID <ID号>\t查询指定ID号的书籍对象" +
                    "\nqueryByName <书名>\t按书名查询符合条件的书籍对象列表，支持模糊查询" +
                    "\ndelete <ID号>\t\t删除指定ID号的书籍对象" +
                    "\nexit\t\t\t\t退出";

        } else if (args[0].equals("add") && args.length >= 3) {
            int bookID = Integer.parseInt(args[1]);
            String name = args[2];
            boolean flag = lib.add(new Book(bookID, name));
            return flag ? "成功添加书籍：" + name : "添加书籍失败";

        } else if (args[0].equals("queryByID") && args.length >= 2) {
            int bookID = Integer.parseInt(args[1]);
            Book ret = lib.queryByID(bookID);
            if (ret == null) return "没有该书籍";
            return ret.toString();

        } else if (args[0].equals("queryByName") && args.length >= 2) {
            String name = args[1];
            List<Book> l = lib.queryByName(name);
            if (l == null || l.size() == 0) return "没有该书籍";
            return l.toString();

        } else if (args[0].equals("delete") && args.length >= 2) {
            int bookID = Integer.parseInt(args[1]);
            boolean flag = lib.delete(bookID);
            return flag ? "成功删除书籍" + bookID : "删除书籍失败";

        } else if (args[0].equals("exit")) {
            this.isOnline = false;
            return "[client] closed.";

        } else {
            return args[0] + "不是有效命令或参数错误";
        }
    }

    public static void main(String[] args) throws IOException, NotBoundException {
        // System.setProperty("java.rmi.server.hostname", "localhost");
        // 连接到服务器localhost，端口1099:
        Client client = new Client("localhost", 1099);
        System.out.println("[Client] ready.");
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        while (client.isOnline) {
            System.out.print("> ");
            String[] cmd = input.readLine().split(" ");
            System.out.println(client.exec(cmd));
        }
    }
}
