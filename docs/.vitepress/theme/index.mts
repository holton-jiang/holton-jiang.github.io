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

// 组件-更新日期
import tags from "./components/tags.vue";

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
	app.component('xgplayer' , xgplayer),
	// 注册全局组件
	app.component('Linkcard' , Linkcard) },

	// 切换亮色暗色主题动画
	Layout() {
		return h(Layout, null, {
			'doc-before': () => h(tags),// 指定组件使用doc-before插槽
		})
	},
}
