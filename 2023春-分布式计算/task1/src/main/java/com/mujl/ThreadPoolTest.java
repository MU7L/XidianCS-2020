package com.mujl;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingDeque;
import java.util.concurrent.RejectedExecutionHandler;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

public class ThreadPoolTest {
    public static void main(String[] args) {
        ThreadPoolExecutor executor = new ThreadPoolExecutor(
                5,
                10,
                200,
                TimeUnit.MILLISECONDS,
                new ArrayBlockingQueue<Runnable>(5)
        );  // 创建线程池
        System.out.println("[executor] start");

        for (int i = 0; i < 15; i++) {
            MyTask myTask = new MyTask(i);  // 创建任务
            executor.execute(myTask);  // 任务入队
            System.out.println("[executor] (task " + i + ") in queue");
            System.out.println("[executor] pool size: " + executor.getPoolSize());
            System.out.println("          queue size: " + executor.getQueue().size());
            System.out.println("           completed: " + executor.getCompletedTaskCount());
        }
        executor.shutdown();
        System.out.println("[executor] end");
    }
}

class MyTask implements Runnable {
    private int taskId;

    public MyTask(int id) {
        this.taskId = id;
    }

    @Override
    public void run() {
        int sum = 0;
        System.out.println(String.format("(task %d) is running", taskId));
        try {
            for (int i = 0; i < 15; i++) {
                sum += i;
            }
            Thread.currentThread().sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println(String.format("(task %d) done", taskId));
    }
}