package com.mujl;

import java.io.*;
import java.net.*;

public class EchoClient {
    public static void main(String[] args) throws Exception {
        String userInput = null;  // 待发送消息
        String echoMessage = null;  // server返回消息

        BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));  // 标准输入

        System.out.println("[client] start");
        // 向服务器 127.0.0.1 发出连接请求
        Socket socket = new Socket("127.0.0.1", 8189);
        System.out.println("[client] connected to server (127.0.0.1:8189)");

        InputStream inputStream = socket.getInputStream();
        OutputStream outputStream = socket.getOutputStream();
        BufferedReader in = new BufferedReader(new InputStreamReader(inputStream));
        PrintWriter out = new PrintWriter(outputStream);
        System.out.println("[client] ready");

        while (!(userInput = stdIn.readLine()).equals("exit")) {
            out.println(userInput);
            out.flush();
            echoMessage = in.readLine();
            System.out.println("[server] return: " + echoMessage);
        }

        socket.close();
        System.out.println("[client] close");
    }
}
