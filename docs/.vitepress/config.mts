import { defineConfig } from 'vitepress'
import { createRequire } from 'module'

import { nav } from './configs'; //导入导航栏
import { sidebar } from './configs'; //导入侧边栏
import { vitepressDemoPlugin } from 'vitepress-demo-plugin'; 
//代码组图标
import { groupIconMdPlugin, groupIconVitePlugin } from 'vitepress-plugin-group-icons';


export default defineConfig({

  base: '/',

  title: "蒋小霕的编程笔记",
  description: "蒋小霕日常学习编程",

  cleanUrls: true,
  // 是否忽略死链
  ignoreDeadLinks: false,
  //页面底部显示最后更新时间
  lastUpdated: true,
  // 切换主题
  colorModeSwitch: true,
  //页面底部显示文档贡献者列表
  contributors: true,

  markdown: {
		math: true,
		lineNumbers: true,
		codeCopyButtonTitle: '复制代码',
		container: {
			tipLabel: '小提示',
			warningLabel: '注意',
			dangerLabel: '警告',
			infoLabel: '信息',
			detailsLabel: '详情内容',
		},
	config(md) { 
	      md.use(vitepressDemoPlugin); // 代码组中添加图片
	      md.use((md) => {
	      md.use(groupIconMdPlugin)// 代码组中添加图片
	      const defaultRender = md.render
	      md.render = (...args) => {
	      const [content, env] = args
	      const currentLang = env?.localeIndex || 'root'
	      const isHomePage = env?.path === '/' || env?.relativePath === 'index.md'  // 判断是否是首页

	if (isHomePage) {
            return defaultRender.apply(md, args) // 如果是首页，直接渲染内容
          }
          // 调用原始渲染
          let defaultContent = defaultRender.apply(md, args)
          // 替换内容
          if (currentLang === 'root') {
            defaultContent = defaultContent.replace(/提醒/g, '提醒')
              .replace(/建议/g, '建议')
              .replace(/重要/g, '重要')
              .replace(/警告/g, '警告')
              .replace(/注意/g, '注意')
          } else if (currentLang === 'en') {
            // 英文替换
            defaultContent = defaultContent.replace(/提醒/g, 'remind')
              .replace(/建议/g, 'suggestion')
              .replace(/重要/g, 'important')
              .replace(/警告/g, 'warning')
              .replace(/注意/g, 'attention')
          }
          // 返回渲染的内容
          return defaultContent
        }

        // 获取原始的 fence 渲染规则
        const defaultFence = md.renderer.rules.fence?.bind(md.renderer.rules) ?? ((...args) => args[0][args[1]].content);

        // 重写 fence 渲染规则
        md.renderer.rules.fence = (tokens, idx, options, env, self) => {
          const token = tokens[idx];
          const info = token.info.trim();

          // 判断是否为 md:img 类型的代码块
          if (info.includes('md:img')) {
            // 只渲染图片，不再渲染为代码块
            return `<div class="rendered-md">${md.render(token.content)}</div>`;
          }

          // 其他代码块按默认规则渲染（如 java, js 等）
          return defaultFence(tokens, idx, options, env, self);
        };
      })

	    }, 
	image: {
	// 开启图片懒加载
		lazyLoading: true
		},
  	},//markdown代码结束

        // 404 page
        notFound: {
        	title: '这是一个 404 页面',
        	quote:
		  '但如果你持之以恒，并且继续寻找，你可能最终会抵达你所前往的地方。',
		linkLabel: '前往首页',
		linkText: '带我回首页'
        },

        vite: { 
	plugins: [
	groupIconVitePlugin() ],//代码组图标
		},


  themeConfig: {

    logo: { src: '/flop.svg', width: 24, height: 24 },

    darkModeSwitchLabel: '主题',
    langMenuLabel: '多语言',
    lightModeSwitchTitle: '切换到浅色模式',
    darkModeSwitchTitle: '切换到深色模式',
    skipToContentLabel: '跳转到内容',
    sidebarMenuLabel: '总目录',
    returnToTopLabel: '回到顶部',
    outlineTitle: '本页的章节',
    // 显示层级
    outline: { level: 'deep', label: '本页的章节' },
    // aside: false,
    //outline: false,
    siteTitle: '蒋小霕的编程笔记',

    externalLinkIcon: true,

    //设置标签页图标
  	head:[
  		['link', { rel: 'icon', type: 'image/svg+xml', href: '/favicon.svg' }],
		['link', { rel: 'icon', type: 'image/png', href: '/favicon.png' }],
		['meta', { name: 'theme-color', content: '#2f44bb' }],
		['meta', { name: 'og:type', content: 'website' }],
    	],

    // 每个页面页脚的编辑此页  :path  为当前路由
	editLink: {
		text: '在 GitHub 中改进此页面的内容',
		pattern: 'https://github.com/holton-jiang/holton-jiang.github.io/edit/main/docs/:path',
	},

	footer: {
		message: '基于 <a href="https://mit-license.org">MIT</a> 许可证下发布',
		copyright: '© 2025-<a href="https://github.com/holton-jiang">蒋小霕</a>的编程笔记',
	},

	search: {
	provider: 'local',
	options: {
		translations: {
			button: {
				buttonText: '搜索篇章',
				buttonAriaLabel: '搜索篇章',
				},
			modal: {
				noResultsText: '没有寻找到相关结果',
				resetButtonTitle: '清除查询条件',
				footer: {
					selectText: '选择',
					navigateText: '切换',
					closeText: '关闭搜索',
					},
				},
				},
		 },
	}, //search:语句结束

    lastUpdated: {
    	text: '最后更新时间',
    	dateStyle: 'short',
    	timeStyle: 'medium',
    		 },

    // siteTitle: false, // 不显示标题
    // 上一页下一页文本
    docFooter: {
        prev: '上一页',
	next: '下一页',
    },

    //导航栏
    nav,

    //侧边栏
    sidebar,

    socialLinks: [
      { icon: 'github', link: 'https://github.com/holton-jiang' },
      { icon: 'facebook', link: 'https://www.facebook.com/Holton.Jiang' },
      { icon: 'twitter', link: 'https://twitter.com/holton_jiang' }
    ]


  }
})
