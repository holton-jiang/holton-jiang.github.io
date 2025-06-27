import DefaultTheme from 'vitepress/theme'
import { h } from 'vue' // h函数
import './custom.css'

/* 主题美化 */
import './var.css';

/* 导航栏毛玻璃 */
import './blur.css';

/* 隐藏横条 */
import './hidden.css';

/* 容器颜色 */
import './custom-block.css';

/* 记号笔 */
import './marker.css';

/* 代码块 */
import './vp-code.css';

/* 代码块带标题 */
import './vp-code-title.css';

/* 代码组 */
import './vp-code-group.css';

/* 代码组图标 */
import 'virtual:group-icons.css';

/* 侧边栏样式美化 */
import './sidebarIcon.css';

/* 卡片样式的链接 */
import Linkcard from "./components/Linkcard.vue";

/* 视频播放样式 */
import xgplayer from "./components/xgplayer.vue"

/* 切换亮色暗色主题动画 */
import Layout from './Layout.vue';

/* 字数及阅读时间 */
import ArticleMetadata from "./components/ArticleMetadata.vue";

/* 标题下添加时间 */
import update from "./components/update.vue";

// 布局-更新日期
import tags from "./components/tags.vue";
import MyLayout from "./MyLayout.vue";

//内置的代码组常用图标
export const builtInIcons: Record<string, string> = {
  // package manager
  pnpm: 'logos:pnpm',
  npm: 'logos:npm-icon',
  yarn: 'logos:yarn',
  bun: 'logos:bun',
  // framework
  vue: 'logos:vue',
  svelte: 'logos:svelte-icon',
  angular: 'logos:angular-icon',
  react: 'logos:react',
  next: 'logos:nextjs-icon',
  nuxt: 'logos:nuxt-icon',
  solid: 'logos:solidjs-icon',
  // bundler
  rollup: 'logos:rollupjs',
  webpack: 'logos:webpack',
  vite: 'logos:vitejs',
  esbuild: 'logos:esbuild',
}


export default {
	...DefaultTheme,

	enhanceApp({app}) { 
	//字数及阅读时间
	app.component('ArticleMetadata' , ArticleMetadata),
	//标题下添加时间
	app.component('update' , update),
	//视频播放
	app.component('xgplayer' , xgplayer),
	//卡片链接 注册全局组件
	app.component('Linkcard' , Linkcard) },

	// 布局-更新日期
	MyLayout() {
		return h(DefaultTheme.Layout, null, {
		'doc-before': () => h(tags), //指定组件使用doc-before插槽
		})
	},

	// 切换亮色暗色主题动画
	Layout() {
		return h(Layout, null, {

		})
	},
}
