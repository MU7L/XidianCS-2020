const Koa = require('koa');
const bodyParser = require('koa-bodyparser');
const cors = require('koa2-cors');
const router = require('koa-router')();
const fs = require("fs");
const robot = require("robotjs");
const app = new Koa();

function move(dx, dy) {
    let { x, y } = robot.getMousePos();
    let xx = x + dx;
    let yy = y + dy;
    console.log(`(${x}, ${y}) -> (${xx}, ${yy})`);
    robot.moveMouse(xx, yy);
}

function click() {
    robot.mouseClick();
}

router.get('/', async ctx => {
    ctx.type = "html";
    ctx.body = fs.readFileSync("static/index.html");
    console.log('new device');
});

router.post('/api', async ctx => {
    // console.log(ctx.request.body);
    let { dx, dy, op } = ctx.request.body;
    switch (op) {
        case 'move':
            move(dx, dy);
            break;
        case 'click':
            click();
            break;
    }
});

app.use(
    cors({
        origin: function (ctx) { //设置允许来自指定域名请求
            return '*'; // 允许来自所有域名请求
        },
        allowMethods: ['GET', 'POST', 'PUT', 'DELETE', 'OPTIONS'], //设置所允许的HTTP请求方法'
        allowHeaders: ['Content-Type', 'Authorization', 'Accept'], //设置服务器支持的所有头信息字段
        exposeHeaders: ['WWW-Authenticate', 'Server-Authorization'] //设置获取其他自定义字段
    })
);

app.use(bodyParser());

app.use(router.routes(), router.allowedMethods());

app.listen(3001, () => {
    console.log('http://localhost:3001');
});
