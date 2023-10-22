import java.io.*;
import java.net.Socket;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class Client {

    // 数据节点代理类
    static class NodeProxy {
        int port;
        Socket socket;
        BufferedReader in;
        PrintWriter out;

        NodeProxy(int port) throws IOException {
            this.port = port;
            this.socket = new Socket("localhost", port);
            InputStream inputStream = this.socket.getInputStream();
            OutputStream outputStream = this.socket.getOutputStream();
            this.in = new BufferedReader(new InputStreamReader(inputStream));
            this.out = new PrintWriter(outputStream);
        }

        void put(String key, String value) {
            out.println(String.format("put %s %s", key, value));
            out.flush();
        }

        String get(String key) throws IOException {
            out.println(String.format("get %s", key));
            out.flush();
            return in.readLine();
        }

        // 取出节点全部键值对 用于移除节点操作
        Map<String, String> getAll() throws IOException {
            Map<String, String> data = new HashMap<>();
            out.println("get all");
            out.flush();
            String line;
            while ((line = in.readLine()) != null) { // TODO: 循环无法退出？
                if (line.equals("")) break;
                System.out.println(line);
                String[] args = line.split(" ");
                data.put(args[0], args[1]);
            }
            return data;
        }

        void close() throws IOException {
            in.close();
            out.close();
            socket.close();
        }
    }

    // 节点表
    TreeMap<Integer, NodeProxy> nodes;

    Client() {
        nodes = new TreeMap<>();
    }

    // 根据键值寻找所在下一个节点
    NodeProxy locateNode(String key) {
        if (nodes.size() == 0) {
            System.out.println("没有 DataNode");
            return null;
        }
        int hashKey = MyHash.hash(key);
        Integer nodeHash = nodes.ceilingKey(hashKey);
        if (nodeHash == null) {
            return nodes.firstEntry().getValue();
        } else return nodes.get(nodeHash);
    }

    // 增加节点
    void addNode(int port, boolean init) throws IOException {
        String _port = String.valueOf(port);
        int portHash = MyHash.hash(_port);
        if (nodes.containsKey(portHash)) {
            System.out.println("该 DataNode 已存在");
        }
        NodeProxy node = new NodeProxy(port);
        System.out.println("连接到 DataNode@" + port);

        // 数据迁移
        if (!init) {
            NodeProxy source = locateNode(_port);
            System.out.println(String.format("数据迁移 DataNode@%d -> DataNode@%d", source.port, node.port));
            Map<String, String> data = source.getAll();
            for (Map.Entry<String, String> entry : data.entrySet()) {
                String key = entry.getKey();
                String value = entry.getValue();
                int keyHash = MyHash.hash(key);
                // 需要迁移
                if (keyHash < portHash) node.put(key, value);
                    // 不需要迁移
                else source.put(key, value);
            }
        }

        nodes.put(portHash, node);
    }

    // 移除节点
    void removeNode(int port) throws IOException {
        if (nodes.size() == 1) {
            System.out.println("不能删除最后一个 DataNode");
            return;
        }
        String _port = String.valueOf(port);
        int portHash = MyHash.hash(_port);
        NodeProxy node = nodes.get(portHash);
        if (node == null) {
            System.out.println("不存在该 DataNode");
            return;
        }
        NodeProxy dest = locateNode(String.valueOf(port + 1));
        System.out.println(String.format("数据迁移 DataNode@%d -> DataNode@%d", node.port, dest.port));
        Map<String, String> data = node.getAll();
        for (Map.Entry<String, String> entry : data.entrySet()) {
            String key = entry.getKey();
            String value = entry.getValue();
            dest.put(key, value);
        }
        node.close();
        nodes.remove(portHash);
        System.out.println("移除 DataNode@" + port);
    }

    void put(String key, String value) {
        NodeProxy node = locateNode(key);
        node.put(key, value);
    }

    String get(String key) throws IOException {
        NodeProxy node = locateNode(key);
        return node.get(key);
    }

    /*
     * 命令
     * put key value
     * get key 返回 value
     * add <port>
     * remove <port>
     * quit
     */
    void repl() throws NumberFormatException, IOException {
        System.out.println("命令：\n" +
                "put <key：7位字符> <value>\n" +
                "get <key：7位字符>\n" +
                "add <port>\n" +
                "remove <port>\n" +
                "quit");
        Scanner sc = new Scanner(System.in);
        String line;
        REPL:
        while (true) {
            System.out.print("> ");
            line = sc.nextLine();
            String[] args = line.split(" ");
            if (line.equals("quit")) break;
            switch (args[0]) {
                case "quit":
                    break REPL;
                case "put":
                    if (args[1].length() > 7) {
                        System.out.println("输入无效");
                    } else {
                        put(args[1], args[2]);
                    }
                    break;
                case "get":
                    if (args[1].length() > 7) {
                        System.out.println("输入无效");
                    } else {
                        line = get(args[1]);
                        System.out.println(line);
                    }
                    break;
                case "add": {
                    int _port = Integer.parseInt(args[1]);
                    addNode(_port, false);
                    break;
                }
                case "remove": {
                    int _port = Integer.parseInt(args[1]);
                    removeNode(_port);
                    break;
                }
                default:
                    System.out.println("无效命令");
                    break;
            }
        }
    }

    void close() throws IOException {
        for (NodeProxy node : nodes.values()) {
            node.close();
        }
        nodes.clear();
    }

    /*
     * 命令
     * Client 8000
     */
    public static void main(String[] args) throws NumberFormatException, IOException {
        if (args.length == 0) {
            System.out.println("用法：Client <DataNode端口号> ...");
            return;
        }
        Client client = new Client();
        for (String port : args) {
            int _port = Integer.parseInt(port);
            client.addNode(_port, true);
        }
        client.repl();
        client.close();
        System.out.println("close");
    }
}
