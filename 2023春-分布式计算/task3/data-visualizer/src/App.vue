<template>
    <div class="container">
        <div id="echarts"></div>
    </div>
</template>

<script setup>
import { onMounted } from 'vue';
import { storeToRefs } from 'pinia'
import { useDatasetStore } from './store';
import * as echarts from 'echarts';
import { connect } from './api';

const { times, means, variances, maxs, mins } = storeToRefs(useDatasetStore());
let myChart = null;
const option = {
    tooltip: {
        trigger: 'axis',
        axisPointer: { type: 'cross' }
    },
    legend: {
        orient: 'horizontal',
        top: 10,
        textStyle: {
            color: '#ccc'
        }
    },
    xAxis: {
        data: times.value
    },
    yAxis: {
        type: 'value'
    },
    series: [
        {
            name: '均值',
            data: means.value,
            type: 'line'
        }, {
            name: '方差',
            data: variances.value,
            type: 'line'
        }, {
            name: '最大值',
            data: maxs.value,
            type: 'line'
        }, {
            name: '最小值',
            data: mins.value,
            type: 'line'
        },
    ]
};

onMounted(() => {
    myChart = echarts.init(document.getElementById('echarts'));
    connect(() => {
        myChart.setOption(option);
    });
});

</script>

<style>
* {
    margin: 0;
    padding: 0;

}

.container {
    background-color: rgb(1, 4, 9);
    width: 100vw;
    height: 100vh;
    display: flex;
    justify-content: center;
    align-items: center;
}

#echarts {
    border: 3px solid rgb(48, 54, 61);
    border-radius: 10px;
    background-color: rgb(13, 17, 23);
    width: 90%;
    height: 90%;
}
</style>