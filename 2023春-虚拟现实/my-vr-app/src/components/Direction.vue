<template>
    <div class="banner">
        <div>alpha: {{ direction.alpha }} deg</div>
        <div>beta: {{ direction.beta }} deg</div>
        <div>gamma: {{ direction.gamma }} deg</div>
    </div>
</template>

<script setup>
import { useDirection } from '../hooks/useDirection';
const direction = useDirection();
</script>

<style scoped>
.banner {
    position: fixed;
    margin: 1rem;
    padding: 1rem;
    color: white;
    background-color: rgba(0, 0, 0, 0.7);
}
</style>