/* configs/sidebar.ts */
import type { DefaultTheme } from 'vitepress'

export const sidebar: DefaultTheme.Config['sidebar'] = [
//C Primer Plus 第五版
      {
        text: 'C Primer Plus 第五版',
        collapsed: true,
        items: [
            { text: '1-1', link: '/c-primer-plus-5th-edition/ch01/1-1' },
//          { text: '1-1', link: '/c-primer-plus-5th-edition/ch02/1-1' },
//          { text: '1-1', link: '/c-primer-plus-5th-edition/ch03/1-1' },
//          { text: '1-1', link: '/c-primer-plus-5th-edition/ch04/1-1' },
//          { text: '1-1', link: '/c-primer-plus-5th-edition/ch05/1-1' },
//          { text: '1-1', link: '/c-primer-plus-5th-edition/ch06/1-1' },
//          { text: '1-1', link: '/c-primer-plus-5th-edition/ch07/1-1' },
//          { text: '1-1', link: '/c-primer-plus-5th-edition/ch08/1-1' },
//          { text: '1-1', link: '/c-primer-plus-5th-edition/ch09/1-1' },
//          { text: '1-1', link: '/c-primer-plus-5th-edition/ch10/1-1' },
//          { text: '1-1', link: '/c-primer-plus-5th-edition/ch11/1-1' },
//          { text: '1-1', link: '/c-primer-plus-5th-edition/ch12/1-1' },
//          { text: '1-1', link: '/c-primer-plus-5th-edition/ch13/1-1' },
//          { text: '1-1', link: '/c-primer-plus-5th-edition/ch14/1-1' },
//          { text: '1-1', link: '/c-primer-plus-5th-edition/ch15/1-1' },
//          { text: '1-1', link: '/c-primer-plus-5th-edition/ch16/1-1' },
//          { text: '1-1', link: '/c-primer-plus-5th-edition/ch17/1-1' },
//          { text: '1-1', link: '/c-primer-plus-5th-edition/ch18/1-1' },
        ],
      },

      //Java 2D 游戏编程入门
      {
        text: 'Java 2D 游戏编程入门',
        collapsed: true,
        items: [
          { text: '1-1', link: '/fundamental-2d-game-programming-with-java/ch01/1-1' },
        ],
      },

]
