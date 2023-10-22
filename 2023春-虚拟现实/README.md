# my-vr-app

#### 使用工具

- Vite 前端构建工具，提供简单的开发服务器
- Vue 渐进式前端开发脚手架
- three.js 前端3D图形库
- [mkcert](https://blog.csdn.net/Liuer_Qin/article/details/129046599?app_version=5.15.5&code=app_1562916241&csdn_share_tail={"type"%3A"blog"%2C"rType"%3A"article"%2C"rId"%3A"129046599"%2C"source"%3A"unlogin"}&uLinkId=usr1mkqgl919blen&utm_source=app) 开启https生成签名证书

#### 一些代码片段

- 初始化项目

  ```powershell
  npm create vite@latest my-vr-app -- --template vue
  ```

- 生成签名证书

  ``` powershell
  mkcert -install
  mkcert localhost 127.0.0.1
  ```
  
  将生成公钥放在 `./keys` 目录下
  
- 配置 Vite 开发环境下手机局域网访问 `vite.config.js`

  ``` javascript
  server: {
          host: true,
          port: 3001,
          open: true,
          https: {
              key: readFileSync("keys/xxx.pem"),  // 读取我们上面生成的公钥
              cert: readFileSync("keys/xxx.pem"),	// 读取我们上面生成的证书
          },
      }
  ```

  此时运行 `npm run dev` 可以看到 Network 访问路径。需要打开公共网络防火墙3001端口，手机与PC处于同一局域网下时可以访问
  
- 调用手机陀螺仪 `hooks/useDirection.js`

  ``` javascript
  window.addEventListener('deviceorientation', ({ alpha, beta, gamma }) => {
      console.log({ alpha, beta, gamma });
      // ...
  }, false);
  ```

  返回手机当前状态的欧拉角

  参考链接：https://juejin.cn/post/6844903457384562701

  由于安卓陀螺仪可能产生抖动，使用节流技术优化性能

  ``` javascript
  let flag = false;
  // ...
  if (!flag) {
      flag = true;
      setTimeout(() => {
          // ...
          flag = false;
      }, 10);
  }
  ```

- 绑定摄像机视角与陀螺仪数据

  ``` javascript
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
  ```

  考虑方法一是使用 `Object3D` 类的 `lookAt()` 方法，通过将陀螺仪数据转换到单位球上的坐标来实现。问题在于欧拉角不能直接等同于球坐标下的数据，仍存在问题

  考虑方法二是直接使用 `setRotationFromEuler` 实现，需要先理解手机陀螺仪数据是如何得到的。开发中

- 持续渲染 `animate()`

  ``` javascript
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
  ```

  `animate()` 函数会一直通过 `requestAnimationFrame` 方法调用自身，从而不断调用渲染方法

- 注意点：在 setup 生命周期下 Vue 还无法获取 dom 结点，所以渲染绑定结点需要在 onMounted 方法中实现

  ``` java
  onMounted(() => {
      const container = document.querySelector("#container");
      container.appendChild(renderer.domElement);
      // renderer.render(scene, camera);
      start();
  });
  ```

  