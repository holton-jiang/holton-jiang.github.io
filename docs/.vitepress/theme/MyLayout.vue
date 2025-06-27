<!-- .vitepress/theme/MyLayout.vue -->
<script setup lang="ts">
import DefaultTheme from 'vitepress/theme'
// 组件
import tags from "./tags.vue";
</script>

<template>
  <DefaultTheme.Layout v-bind="$attrs">

    <!-- doc-before插槽 -->
    <template #doc-before>
      <tags />
    </template>

  </DefaultTheme.Layout>
</template>

<style scoped>
</style>
