import { defineConfig } from 'vite'
import { readFileSync } from 'fs';
import vue from '@vitejs/plugin-vue'

// https://vitejs.dev/config/
export default defineConfig({
    plugins: [vue()],
    base: '/my-vr-app/',
    // https://blog.csdn.net/Liuer_Qin/article/details/129046599?spm=1001.2014.3001.5502
    // server: {
    //     host: true,
    //     port: 3001,
    //     open: true,
    //     https: {
    //         key: readFileSync("keys/localhost+3-key.pem"),  // 读取我们上面生成的公钥
    //         cert: readFileSync("keys/localhost+3.pem"),	// 读取我们上面生成的证书
    //     },
    // }
})
