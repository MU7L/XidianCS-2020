import { reactive } from 'vue';

const direction = reactive({
    alpha: 0, // -180 - 180
    beta: 0, // -180 - 180
    gamma: 0, // -90 - 90
});

// 节流
let flag = false;
// https://juejin.cn/post/6844903457384562701
window.addEventListener('deviceorientation', ({ alpha, beta, gamma }) => {
    console.log({ alpha, beta, gamma });
    if (!flag) {
        flag = true;
        setTimeout(() => {
            direction.alpha = alpha;
            direction.beta = beta;
            direction.gamma = gamma;
            flag = false;
        }, 10);
    }
}, false);

export function useDirection() {
    return direction;
}