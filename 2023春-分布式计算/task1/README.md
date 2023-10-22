# 第一次作业

#### 环境

``` powershell
Apache Maven 3.5.4 (1edded0938998edf8bf061f1ceb3cfdeccf443fe; 2018-06-18T02:33:14+08:00)
java version "1.8.0_361"
```

#### 执行命令

``` powershell
mvn clean
mvn compile
```

在server终端上执行

``` powershell
java -cp target/classes com.mujl.ThreadPoolEchoServer
```

在client终端上执行

``` powershell
java -cp target/classes com.mujl.EchoClient
```

可以创建多个client终端