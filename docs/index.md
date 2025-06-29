---
layout: home

title: 蒋小霕的编程笔记
titleTemplate: 蒋小霕日常学习编程

hero:
  name: 编程笔记
  text: 蒋小霕的编程笔记
  tagline: 蒋小霕日常学习编程
  actions:
    - theme: brand
      text: C Primer Plus 第五版
      link: /c-primer-plus-5th-edition/ch01/1-1
    - theme: brand
      text: Java 2D 游戏编程入门
      link: /fundamental-2d-game-programming-with-java/ch01/1-1
    - theme: brand
      text: HTTP 权威指南
      link: /HTTP/1-1
    - theme: alt
      text: 好物分享
      link: https://docs.qq.com/sheet/DQVNpUVFMeW56U3JK?scene=67bac4d10ad095a9b618e290PXNXu1&tab=BB08J2
  image:
    light: /favicon.svg
    dark: /dark.svg
    alt: 蒋小霕的编程笔记

---
<style>
:root {
  --vp-home-hero-name-color: transparent;
  --vp-home-hero-name-background: -webkit-linear-gradient(120deg, #5367f2 30%, #41d1ff);

  --vp-home-hero-image-background-image: linear-gradient(-45deg, #5367f2 50%, #41d1ff 50%);
  --vp-home-hero-image-filter: blur(60px);
}

.dark {
  --vp-c-brand-1: #5367f2;
  --vp-c-brand-2: #5260f2;
  --vp-c-brand-3: #2f48a3;
  /* 标题渐变色 以下是官方主题色*/
  --vp-home-hero-name-color: transparent;
  --vp-home-hero-name-background: -webkit-linear-gradient(120deg, #5367f2, #41d1ff);

  /*图标背景渐变色 以下是官方主题色*/
  --vp-home-hero-image-background-image: linear-gradient(-45deg, #1b1b1f 50%, #223fc6 50%);
  --vp-home-hero-image-filter: blur(40px);
}

@media (min-width: 500px) {
  :root {
    --vp-home-hero-image-filter: blur(70px);
  }
}

@media (min-width: 700px) {
  :root {
    --vp-home-hero-image-filter: blur(85px);
  }
}
</style>
