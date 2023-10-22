package MapRouting.alg;

import edu.princeton.cs.algs4.Stopwatch;

import java.util.Arrays;

public class Dijkstra {
    public double[] dis;  // 到各点的距离
    public int[] root;  // 最小生成树 root[p] = pf
    public double time; // 运行时间
    public Dijkstra(EuclideanGraph G) {
        // dis
        dis = new double[G.V];
        Arrays.fill(dis, EuclideanGraph.MAX_DISTANCE);
        // 确认数组
        boolean[] check = new boolean[G.V];
        // root
        root = new int[G.V];
        Arrays.fill(root, -1);  // -1表示没有父节点
        // 最小优先队列
        IndexPQ pq = new IndexPQ(G.V);

        Stopwatch s = new Stopwatch();  // 计时开始
        for (int v = 0; v < G.V; v++) {
            double d = G.getDistance(G.start, v);
            if (d != EuclideanGraph.MAX_DISTANCE && d != 0.0) {
                root[v] = G.start;
            }
            pq.insert(v, d); // 到自己为0(根节点) 无法到达为MAX
        }
        System.out.println("pq init...");
        pq.print();

        // start 已确定
        int minId = pq.delMin();
        dis[minId] = pq.getPriority(minId);
        check[minId] = true;
        root[minId] = 0;
        System.out.println("id[" + minId + "] checked");
        pq.print();

        while (!pq.isEmpty()) {
            // 找出新的最小值并确定
            minId = pq.delMin();
            dis[minId] = pq.getPriority(minId);
            check[minId] = true;
            if (minId == G.end) break;  // TODO 改进1
            System.out.println("id[" + minId + "] checked");

            // 考察minId对pq的影响
            for (int v = 0; v < G.V; v++) {
                // 已确定点不考虑
                if(check[v]) continue;
                double disMinToV = G.getDistance(minId, v);  // minId到v距离
                // 与自己 || 无边时不考虑
                if (disMinToV == EuclideanGraph.MAX_DISTANCE) continue;
                double newDis = dis[minId] + disMinToV;  // start经过minId到v距离
                if (newDis < pq.getPriority(v)) {
                    System.out.println(String.format("\tupdate to id[%d]: %f", v, newDis));
                    pq.update(v, newDis);
                    root[v] = minId;
                }
            }
            pq.print();
        }
        time = s.elapsedTime();  // 计时结束
    }
}
