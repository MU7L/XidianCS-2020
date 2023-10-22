package MapRouting.alg;

import java.util.ArrayList;

public class Point {
    public int id;
    public int x;
    public int y;
    public ArrayList<Integer> neighbor;

    public Point(int id, int x, int y) {
        this.id = id;
        this.x = x;
        this.y = y;
        neighbor = new ArrayList<Integer>();
    }

    // 计算a和b的距离
    public static double distance(Point a, Point b) {
        return Math.sqrt(Math.pow(a.x - b.x, 2) + Math.pow(a.y - b.y, 2));
    }
}
