<template>
    <div id="container"></div>
</template>

<script setup>
import * as THREE from 'three';
import { onMounted, ref, watch } from 'vue';
import { useDirection } from '../hooks/useDirection';
import campus from '/pic/campus.png';

const config = {
    width: window.innerWidth,
    height: window.innerHeight,
    VIEW_HEIGHT: 100,
    SCENE_SIZE: 1000
}

// 场景
const scene = new THREE.Scene();

// 相机
const camera = new THREE.PerspectiveCamera(75, config.width / config.height, 0.1, 1000);
camera.position.set(0, config.VIEW_HEIGHT, 0);

// 渲染器
const renderer = new THREE.WebGLRenderer();
renderer.setSize(config.width, config.height);

// 动态窗口
// https://juejin.cn/post/7101207945387442212
window.addEventListener("resize", () => {
    config.width = window.innerWidth;
    config.height = window.innerHeight;
    camera.aspect = config.width / config.height;
    camera.updateProjectionMatrix();
    renderer.setSize(config.width, config.height);
    // renderer.render(scene, camera);
});

// 坐标系和网格 1格为10
const axesHelper = new THREE.AxesHelper(config.SCENE_SIZE);
scene.add(axesHelper);
const gridHelper = new THREE.GridHelper(config.SCENE_SIZE, 100);
scene.add(gridHelper);

// 地面
const plane = new THREE.Mesh(
    new THREE.PlaneGeometry(config.SCENE_SIZE, config.SCENE_SIZE),
    new THREE.MeshStandardMaterial({
        color: 0xbbbbbb,
        side: THREE.DoubleSide
    })
);
plane.rotateX(Math.PI / 2);
plane.receiveShadow = true;
scene.add(plane);

// 圆柱 顶部半径 底部半径 高度 开顶
const cylinder = new THREE.Mesh(
    new THREE.CylinderGeometry(100, 100, config.VIEW_HEIGHT * 2, 64, 1, true),
    new THREE.MeshStandardMaterial({
        // color: 0xffff00,
        side: THREE.BackSide,
        map: new THREE.TextureLoader().load(campus)
    })
);
cylinder.translateY(25);
scene.add(cylinder);

// 动态加载模型
// onMounted(async () => {
//     const cylinder = await cylinderLoader();
//     console.log(cylinder);
//     scene.add(cylinder);
//     renderer.render(scene, camera);
// })

// 环境光
const ambientLight = new THREE.AmbientLight(0x404040); // soft white light
scene.add(ambientLight);

// 点光源
const pointLight = new THREE.PointLight(0xffffff, 1, config.SCENE_SIZE);
pointLight.position.set(0, 100, 0);
scene.add(pointLight);
// pointLight.castShadow = true;
// pointLight.shadow.mapSize.width = 512; // default
// pointLight.shadow.mapSize.height = 512; // default
// pointLight.shadow.camera.near = 0.5; // default
// pointLight.shadow.camera.far = 500; // default

// 传感器 
const direction = useDirection();
watch(direction, () => {
    // lookat方法
    // BUG: 传感器参数绑定有问题
    let alpha = direction.alpha * Math.PI / 180; // 0 - 2pi
    let beta = (direction.beta - 90) * Math.PI / 180; // -0.5pi - 0.5pi
    if (direction.beta - 90 < -90) {
        beta = - Math.PI / 2;
    } else if (direction.beta - 90 > 90) {
        beta = Math.PI / 2;
    }
    camera.lookAt(
        Math.cos(beta) * Math.sin(alpha),
        Math.sin(beta) + config.VIEW_HEIGHT,
        Math.cos(beta) * Math.cos(alpha)
    );
    // 欧拉角赋值
    // camera.setRotationFromEuler(new THREE.Euler(
    //     (direction.beta - 90) * Math.PI / 180,
    //     direction.gamma * Math.PI / 180,
    //     direction.alpha * Math.PI / 180,
    //     'ZXY'
    // ));
})

// 持续渲染
const renderSeitch = ref(false);
function animate() {
    if (renderSeitch.value) {
        requestAnimationFrame(animate);
    }
    renderer.render(scene, camera);
};
function start() {
    renderSeitch.value = true;
    animate();
}

onMounted(() => {
    const container = document.querySelector("#container");
    container.appendChild(renderer.domElement);
    // renderer.render(scene, camera);
    start();
});
</script>