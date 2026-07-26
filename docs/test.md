---

lastUpdated: true
date: 2025-12-19 08:09

---

# 美化测试页面

<update />

::: code-group

```sh [pnpm]
#查询pnpm版本
pnpm -v
```

```sh [yarn]
#查询yarn版本
yarn -v
```

:::


::: code-group

```shell [git]
git -v
```

```shell [gcc]
gcc -v
```

```md:img [cmd 控制台]
![](https://gcc.gnu.org/img/gccegg-65.png)
```
:::

<Linkcard url="https://space.bilibili.com/391801687?tagid=447775" title="蒋小霕的哔哩哔哩" description="https://space.bilibili.com/391801687?tagid=447775" logo="https://ts4.tc.mm.bing.net/th/id/ODLS.1e67f861-d980-4c01-ba66-9450f90172f4?w=32&h=32&qlt=90&pcl=fffffc&r=0&o=6&pid=1.2"/>

---

<xgplayer url="https://www.bilibili.com/video/BV1WoKwzyEyb?t=3.5" poster="https://ts4.tc.mm.bing.net/th/id/ODLS.1e67f861-d980-4c01-ba66-9450f90172f4?w=32&h=32&qlt=90&pcl=fffffc&r=0&o=6&pid=1.2" />


::: info
This is an info box.
:::

::: tip
This is a tip.
:::

::: warning
This is a warning.
:::

::: danger
This is a dangerous warning.
:::

::: details
这是一个详情块。
:::


### 本站代码标注
```c:line-numbers {1,2-3}
#include <stdio.h>
int main(void)
{
    printf("新增标注 // [!code ++]\n"); // [!code ++]
    printf("删除标注 // [!code --]\n"); // [!code --]
    printf("警告标注 // [!code warning]\n"); // [!code warning]
    printf("错误标注 // [!code error]\n"); // [!code error]
    return 0;
}
```
