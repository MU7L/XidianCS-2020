import { defineStore } from "pinia";
import { ref } from "vue";

// {mean: 0.05287209042687589, variance: 0.8934929325621668, max: 2.4384659821058055, min: -1.8242468309859514}
export const useDatasetStore = defineStore('dataset', () => {
    const times = ref([]);
    const means = ref([]);
    const variances = ref([]);
    const maxs = ref([]);
    const mins = ref([]);
    function load({ mean, variance, max, min }) {
        times.value.push(times.value.length + 1);
        means.value.push(mean);
        variances.value.push(variance);
        maxs.value.push(max);
        mins.value.push(min);
        console.log('load');
    }

    return { times, means, variances, maxs, mins, load }
})