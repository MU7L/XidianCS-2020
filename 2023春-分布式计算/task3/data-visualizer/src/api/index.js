import Stomp from 'stompjs';
import { useDatasetStore } from '../store';

const MQ_SERVICE = 'ws://localhost:61614/stomp';  // mq服务地址
const MQ_USERNAME = 'admin';  // mq连接用户名
const MQ_PASSWORD = 'admin';  // mq连接密码
const MQ_QUEUE = 'mom';  // mq连接队列

export function connect(callback) {
    const client = Stomp.client(MQ_SERVICE);
    const store = useDatasetStore();

    // 监听失败的回调
    function onFailed(frame) {
        console.log('Failed: ', frame);
    }

    function onConnected(frame) {
        console.log('connected: ', frame);
        client.subscribe(MQ_QUEUE, responseCallback, onFailed)
    }

    // 监听成功的回调，获取消息
    function responseCallback(frame) {
        console.log('responseCallback: ' + frame.body)
        // 他这里获取的是字符串型的json数据，需要用JSON.parse转一下
        let data = JSON.parse(frame.body)
        console.log('data: ', data);
        // {mean: 0.05287209042687589, variance: 0.8934929325621668, max: 2.4384659821058055, min: -1.8242468309859514}
        store.load(data);
        callback();
    }

    let headers = {
        'login': MQ_USERNAME,
        'passcode': MQ_PASSWORD
    };
    client.connect(headers, onConnected, onFailed);
}
