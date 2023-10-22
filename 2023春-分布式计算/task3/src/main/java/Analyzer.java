import javax.jms.JMSException;
import java.util.LinkedList;
import java.util.Queue;

public class Analyzer {
    Consumer signalMq;
    Producer dataMq;
    Queue<Double> queue;
    int queueLength;
    double mean;  // 均值 E(X)
    double mean2;  // E(X^2)
    double variance;  // 方差 D(X) = E(X^2) - E^2(X)
    double max;  // 最大值
    double min;  // 最小值

    public Analyzer(int N) throws JMSException {
        queueLength = N;
        signalMq = new Consumer("signal");
        dataMq = new Producer("mom");
        queue = new LinkedList<>();
        mean = 0.0;
        mean2 = 0.0;
        variance = 0.0;
        max = Double.MIN_VALUE;
        min = Double.MAX_VALUE;
    }

    public void receive() throws JMSException {
        double data = Double.parseDouble(signalMq.receive());
        max = Math.max(data, max);
        min = Math.min(data, min);

        int size = queue.size();
        if (queue.size() < queueLength) {
            mean = (mean * size + data) / (size + 1);
            mean2 = (mean2 * size + Math.pow(data, 2)) / (size + 1);
        } else {
            double head = queue.remove();
            mean = (mean * size - head + data) / size;
            mean2 = (mean2 * size - Math.pow(head, 2) + Math.pow(data, 2)) / size;
        }
        variance = mean2 - Math.pow(mean, 2);
        queue.add(data);
    }

    public void send() throws JMSException {
        String json = toJSON();
        dataMq.send(json);
    }

    public String toJSON() {
        return "{" +
                "\"mean\":" + mean +
                ",\"variance\":" + variance +
                ",\"max\":" + max +
                ",\"min\":" + min +
                '}';
    }

    public static void main(String[] args) throws JMSException {
        int N = 50;
        if (args.length != 0) N = Integer.parseInt(args[0]);
        System.out.println("Analyzer start");
        Analyzer analyzer = new Analyzer(N);
        long time = System.currentTimeMillis();
        while(true) {
            analyzer.receive();
            System.out.println("Analyzer receive");
            if (System.currentTimeMillis() - time >= 1000) {
                analyzer.send();
                System.out.println("Analyzer send: " + analyzer.toJSON());
                time = System.currentTimeMillis();
            }
        }
    }
}
