package com.mujl;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class EchoServer {
    public static void main(String[] args) throws Exception {
        Socket clientSocket = null;  // 通信socket
        System.out.println("[server] start");
        // 创建监听对象 在8189端口监听握手请求
        ServerSocket listenSocket = new ServerSocket(8189);  // 监听socket

        System.out.println("[server] listening at 8189");
        // 从连接队列中取出一个记录并创建新的通信socket
        clientSocket = listenSocket.accept();
        System.out.println("[server] accept connection from client");

        InputStream inputStream = clientSocket.getInputStream();
        OutputStream outputStream = clientSocket.getOutputStream();
        BufferedReader in = new BufferedReader(new InputStreamReader(inputStream));
        PrintWriter out = new PrintWriter(outputStream);

        String line = null;
        while ((line = in.readLine()) != null) {
            System.out.println("[client] message: " + line);
            out.println(line);
            out.flush();
        }
        clientSocket.close();
        listenSocket.close();
    }
}
