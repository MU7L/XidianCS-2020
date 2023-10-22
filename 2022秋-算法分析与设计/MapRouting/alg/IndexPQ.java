package MapRouting.alg;

public class IndexPQ {
    private int N;  // 队列长度
    private int[] pq;  // 二叉堆 pq[index]=id
    private int[] qp;  // qp[id]=index 在二叉堆中由id定位index
    private double[] priority;  // 优先度 priority[id]=value

    public IndexPQ(int maxN) {
        pq = new int[maxN + 1];
        qp = new int[maxN + 1];
        priority = new double[maxN];
        N = 0;
    }

    public boolean isEmpty() {
        return N == 0;
    }

    public void insert(int id, double value) {
        N++;  // pq[0]不用
        pq[N] = id;  // id插入队尾
        qp[id] = N;
        priority[id] = value;
        swim(N);
    }

    public int delMin() {
        int id = pq[1];
        exch(1, N);
        N--;
        sink(1);
        return id;
    }
    
    public double getPriority(int id) {
        return priority[id];
    }

    public void update(int id, double value) {
        priority[id] = value;
        // int idIndex = 0;
        // // TODO 查找太慢：引入qp
        // for (int i = 1; i <= N; i++) {
        //     if (pq[i] == id) {
        //         idIndex = i;
        //         break;
        //     }
        // }
        swim(qp[id]);
        sink(qp[id]);
    }

    private boolean greater(int i1, int i2) {
        return priority[pq[i1]] > priority[pq[i2]];
    }

    private void exch(int i1, int i2) {
        // pq[i1] = id1  pq[i2] = id2  交换
        int tmpId = pq[i1];
        pq[i1] = pq[i2];
        pq[i2] = tmpId;
        // qp[id1] = i1  qp[id2] = i2  交换
        qp[pq[i2]] = i2;
        qp[pq[i1]] = i1;
    }

    private void swim(int i) {  // pq[i] = id
        // i不是根节点 && i比父节点小
        while (i > 1 && greater(i / 2, i)) {
            exch(i / 2, i);
            i = i / 2;
        }
    }

    private void sink(int i) {  // pq[i] = id
        while (2 * i <= N) {
            int child = 2 * i;
            if (child < N && greater(child, child + 1)) child = child + 1;
            if (!greater(i, child)) break;
            exch(i, child);
            i = child;
        }
    }

    public void print() {
        System.out.println("pq:");
        for (int i = 1; i <= N; i++) {
            if (priority[pq[i]] == EuclideanGraph.MAX_DISTANCE) continue;
            System.out.println(String.format("\tto id[%d]: %f", pq[i], priority[pq[i]]));
        }
        System.out.println();
    }

}