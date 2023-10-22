import org.apache.activemq.ActiveMQConnectionFactory;

import javax.jms.*;

public class Producer {
    //定义链接工厂
    static ConnectionFactory connectionFactory;
    //定义链接
    Connection connection;
    //定义会话
    Session session;
    //定义消息目的地
    Destination destination;
    //定义消息生产者
    MessageProducer producer;
    //定义消息对象
    Message message;

    public Producer(String queue) throws JMSException {
        /*
         * 创建连接工厂，由 ActiveMQ 实现。构造方法参数
         * userName 用户名
         * password 密码
         * brokerURL 访问 ActiveMQ 服务的路径地址，结构为: 协议名://主机地址:端口号
         */
        connectionFactory = new ActiveMQConnectionFactory("admin", "admin", "tcp://localhost:61616");
        //创建连接对象
        connection = connectionFactory.createConnection();
        //启动连接
        connection.start();
        /*
         * 创建会话，参数含义:
         * 1.transacted - 是否使用事务
         * 2.acknowledgeMode - 消息确认机制，可选机制为：
         *  1）Session.AUTO_ACKNOWLEDGE - 自动确认消息
         *  2）Session.CLIENT_ACKNOWLEDGE - 客户端确认消息机制
         *  3）Session.DUPS_OK_ACKNOWLEDGE - 有副本的客户端确认消息机制
         */
        session = connection.createSession(false, Session.AUTO_ACKNOWLEDGE);
        //创建目的地，也就是队列名
        destination = session.createQueue(queue);
        //创建消息生成者，该生成者与目的地绑定
        producer = session.createProducer(destination);
        // System.out.println("[producer] init");
    }

    public void send(String msg) throws JMSException {
        //创建消息
        message = session.createTextMessage(msg);
        //发送消息
        producer.send(message);
        // System.out.println("[producer] send: " + msg);
    }

    public void close() {
        //关闭消息生产者资源
        try {
            if (null != producer) {
                producer.close();
            }
        } catch (JMSException e) {
            e.printStackTrace();
        } finally {
            //关闭会话资源
            try {
                if (null != session) {
                    session.close();
                }
            } catch (JMSException e) {
                e.printStackTrace();
            } finally {
                //关闭连接资源
                try {
                    if (null != connection) {
                        connection.close();
                    }
                } catch (JMSException e) {
                    e.printStackTrace();
                } finally {
                    // System.out.println("[producer] close");
                }
            }
        }
    }

    public static void main(String[] args) throws JMSException {
        System.out.println("test Producer");
        Producer p = new Producer("test");
        p.send("test");
        p.close();
    }
}