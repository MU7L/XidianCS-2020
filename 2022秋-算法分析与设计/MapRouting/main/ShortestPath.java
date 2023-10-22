package MapRouting.main;

import MapRouting.alg.Dijkstra;
import MapRouting.alg.EuclideanGraph;

// 求解一个单源点最短路径问题， 并使用图形绘制结果

public class ShortestPath {
    public static void main(String[] args) {
        // 生成图
        // String initFile = args[0];
        // String initFile = "D:\\single\\Algorithms\\test.txt";
        String initFile = "D:\\single\\Algorithms\\usamap.txt";
        System.out.println("Generating EuclideanGraph...");
        EuclideanGraph G = new EuclideanGraph(initFile);
        // 计算结果
        System.out.println("Generating answer...");
        Dijkstra res = new Dijkstra(G);
        // 输出
        System.out.println("Answer:");
        // 起点到所有节点的最短路程
        for(int i = 0; i < res.dis.length; i++) {
            if (res.dis[i] == EuclideanGraph.MAX_DISTANCE) {
                System.out.println(G.start + "->" + i + ": INFINITY");
            }
            System.out.println(G.start + "->" + i + ": " + res.dis[i]);
        }
        // 起点到终点的最短路径
        int p = G.end;
        while (res.root[p] != G.start) {
            System.out.print(p + " <- ");
            p = res.root[p];
        }
        System.out.println(p + " <- " + G.start);
        System.out.println("distance: " + res.dis[G.end]);
        System.out.println("time: " + res.time + "s");
    }
}
