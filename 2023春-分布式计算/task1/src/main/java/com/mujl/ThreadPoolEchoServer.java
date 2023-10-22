package com.mujl;

import java.net.*;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

public class ThreadPoolEchoServer {
    public static void main(String[] args) throws Exception {
        System.out.println("[pool-server] start");

        // 监听
        ServerSocket poolListenSocket = new ServerSocket(8189);
        System.out.println("[pool-server] listening at 8189");

        // 线程池
        ThreadPoolExecutor poolExecutor = new ThreadPoolExecutor(
                5,
                10,
                200,
                TimeUnit.MILLISECONDS,
                new ArrayBlockingQueue<Runnable>(5)
        );

        // 接收
        Socket poolSocket = null;
        int poolCount = 0;
        while (true) {
            System.out.println("[pool-server] ready");
            poolSocket = poolListenSocket.accept();
            System.out.println("[pool-server] new connection");
            poolCount++;
            System.out.println("[pool-server] total clients: " + poolCount);
            ServerThread poolServerThread = new ServerThread(poolSocket);
            poolExecutor.execute(poolServerThread);
            System.out.println("[pool-server] state");
            System.out.println("\t pool size: " + poolExecutor.getPoolSize());
            System.out.println("\tqueue size: " + poolExecutor.getQueue().size());
            System.out.println("\t completed: " + poolExecutor.getCompletedTaskCount());
        }

        // 关闭
//        poolExecutor.shutdown();
//        System.out.println("[pool-server] close");
    }
}
