import org.apache.activemq.ActiveMQConnectionFactory;

import javax.jms.*;

public class Consumer {
    //定义连接工厂
    ConnectionFactory connectionFactory;
    //定义连接
    Connection connection;
    //定义会话
    Session session;
    //定义目的地
    Destination destination;
    //定义消息消费者
    MessageConsumer consumer;
    //定义消息
    Message message;

    public Consumer(String queue) throws JMSException {
        connectionFactory = new ActiveMQConnectionFactory("admin", "admin", "tcp://localhost:61616");
        connection = connectionFactory.createConnection();
        connection.start();
        session = connection.createSession(false, Session.AUTO_ACKNOWLEDGE);
        destination = session.createQueue(queue);
        consumer = session.createConsumer(destination);
        // System.out.println("[consumer] init");
    }

    public String receive() throws JMSException {
        message = consumer.receive();
        String msg = ((TextMessage) message).getText();
        // System.out.println("[consumer] receive: " + msg);
        return msg;
    }

    public void close() {
        try {
            if (null != consumer)
                consumer.close();
        } catch (JMSException e) {
            e.printStackTrace();
        } finally {
            try {
                if (null != session)
                    session.close();
            } catch (JMSException e) {
                e.printStackTrace();
            } finally {
                try {
                    if (null != connection)
                        connection.close();
                } catch (JMSException e) {
                    e.printStackTrace();
                } finally {
                    // System.out.println("[consumer] close");
                }
            }
        }
    }

    public static void main(String[] args) throws JMSException {
        System.out.println("test Consumer");
        Consumer c = new Consumer("test");
        String s = c.receive();
        System.out.println(s);
        c.close();
    }
}
