import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

public class DataNode {
    // 数据表
    Map<String, String> data;
    Socket clientSocket;
    BufferedReader in;
    PrintWriter out;

    DataNode(int port) throws IOException {
        this.data = new HashMap<>();

        // 创建监听对象
        ServerSocket listenSocket = new ServerSocket(port);
        System.out.println("DataNode@" + port);
        // 从连接队列中取出一个记录并创建新的通信socket
        clientSocket = listenSocket.accept();
        System.out.println(new Date() + "\t连接到 Client");

        InputStream inputStream = clientSocket.getInputStream();
        OutputStream outputStream = clientSocket.getOutputStream();
        in = new BufferedReader(new InputStreamReader(inputStream));
        out = new PrintWriter(outputStream);

        listenSocket.close();
    }

    /*
     * 命令
     * put key value 返回 ok
     * get key 返回 value
     * add <port>
     * remove <port>
     * quit
     */
    void run() throws IOException {
        String line;
        REPL:
        while ((line = in.readLine()) != null) {
            System.out.println(new Date() + "\t[client] " + line);
            String[] args = line.split(" ");
            switch (args[0]) {
                case "put":
                    data.put(args[1], args[2]);
                    break;
                case "get":
                    if (args[1].equals("all")) {
                        StringBuilder sb = new StringBuilder();
                        for (Map.Entry<String, String> entry : data.entrySet()) {
                            sb.append(String.format("%s %s\n", entry.getKey(), entry.getValue()));
                        }
                        // sb.deleteCharAt(sb.length() - 1);
                        line = sb.toString();
                        data.clear();
                    } else {
                        line = data.get(args[1]);
                    }
                    System.out.println(new Date() + "\tsend: " + line);
                    out.println(line);
                    out.flush();
                    break;
                case "quit":
                    break REPL;
                default:
                    System.out.println('?');
                    break;
            }
            System.out.println(new Date() + "\tdatabase: " + data.toString());
        }
    }

    void close() throws IOException {
        in.close();
        out.close();
        clientSocket.close();
    }

    /*
     * 命令
     * DataNode 8000
     */
    public static void main(String[] args) throws NumberFormatException, IOException {
        if (args.length == 0) {
            System.out.println("用法：DataNode <端口号>");
            return;
        }
        int port = Integer.parseInt(args[0]);
        DataNode dataNode = new DataNode(port);
        dataNode.run();
        dataNode.close();
        System.out.println("close");
    }
}
