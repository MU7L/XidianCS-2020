package com.mujl;

import java.net.*;

public class MultiThreadEchoServer {
    public static void main(String[] args) throws Exception {
        ServerSocket listenSocket = new ServerSocket(8189);  // 监听socket
        Socket socket = null;

        int count = 0;
        System.out.println("[multi-server] listening at 8189");

        while (true) {
            socket = listenSocket.accept();
            count++;
            System.out.println("[multi-server] total client is " + count);
            ServerThread serverThread = new ServerThread(socket);
            serverThread.start();
        }

    }
}
