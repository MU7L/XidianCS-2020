package MapRouting.alg;

import java.io.IOException;

public class EuclideanGraph {
    public int V;
    public int E;
    public Point[] g;
    public int start;  // 起点
    public int end;  // 终点
    public static final double MAX_DISTANCE = Double.MAX_VALUE;

    public EuclideanGraph(String initFile) {
        try {
            ReadTxt txt = new ReadTxt(initFile);

            // 取出点数与边数
            String firstLine = txt.nextLine();  // 第一行是顶点数和边数
            String[] firstInfo = firstLine.split(" ");
            this.V = Integer.parseInt(firstInfo[0]);
            this.E = Integer.parseInt(firstInfo[1]);
            this.g = new Point[this.V];

            // 取出点信息
            System.out.println("points: " + this.V);
            for (int p = 0; p < this.V; p++) {
                String pointLine = txt.nextLine();
                String[] pointInfo = pointLine.split(" ");
                int id = Integer.parseInt(pointInfo[0]);
                int x = Integer.parseInt(pointInfo[1]);
                int y = Integer.parseInt(pointInfo[2]);
                this.g[id] = new Point(id, x, y);
                System.out.println(String.format("id[%d] (%d, %d)", id, x, y));
            }

            // 取出边信息
            System.out.println("edges: " + this.E);
            for (int e = 0; e < this.E; e++) {
                String edgeLine = txt.nextLine();
                String[] edgeInfo = edgeLine.split(" ");
                int p1 = Integer.parseInt(edgeInfo[0]);
                int p2 = Integer.parseInt(edgeInfo[1]);
                this.g[p1].neighbor.add(p2);
                this.g[p2].neighbor.add(p1);
                System.out.println(String.format("%d - %d", p1, p2));
            }

            // 取出起点终点
            String endLine = txt.nextLine();
            String[] endInfo = endLine.split(" ");
            this.start = Integer.parseInt(endInfo[0]);
            this.end = Integer.parseInt(endInfo[1]);
            System.out.println("start: id[" + this.start + "]");
            System.out.println("end: id[" + this.end + "]");

            txt.close();
            System.out.println();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // 求p1与p2的距离 没有直接连接返回MAX_DISTANCE
    public double getDistance(int p1, int p2) {
        Point pp1 = g[p1];
        Point pp2 = g[p2];
        if (pp1.neighbor.contains(p2)) {
            return Point.distance(pp1, pp2);
        } else if (p1 == p2) {
            return 0.0;
        } else {
            return MAX_DISTANCE;
        }
    }

    // 测试
    public static void main(String[] args) {
        EuclideanGraph G = new EuclideanGraph("D:\\single\\Algorithms\\test.txt");
        for (Point p : G.g) {
            System.out.print(p.id + ": ");
            for (Integer id : p.neighbor) {
                System.out.print(G.g[id].id + " ");
            }
            System.out.println();
        }
        System.out.println(G.getDistance(1,3));
    }
}
