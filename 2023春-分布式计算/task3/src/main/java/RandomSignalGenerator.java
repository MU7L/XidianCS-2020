import javax.jms.JMSException;
import java.util.Random;

public class RandomSignalGenerator {
    public static void main(String[] args) throws JMSException, InterruptedException {
        System.out.println("RandomSignalGenerator start.");
        Producer signalMq = new Producer("signal");
        Random r = new Random();
        double signal;
        while (true) {
            signal = r.nextGaussian();
            signalMq.send(String.valueOf(signal));
            System.out.println("RandomSignalGenerator send: " + signal);
            Thread.sleep(100);
        }
        // mq.close();
    }
}
