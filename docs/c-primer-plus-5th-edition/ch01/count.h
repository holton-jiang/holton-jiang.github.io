#ifndef COUNT_H
#define COUNT_H

#include <math.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h> // 补充缺失的标准输入输出头文件
#include <stdlib.h> // 补充缺失的标准库头文件

// 仅保留实际使用的 China Post 专用计算函数声明
float calcListedPrice_ChinaPost(float procurement, float logistics, float commission_rate, float withdraw_rate);
float calcListedPriceZero_ChinaPost(float procurement, float logistics, float commission_rate, float withdraw_rate);

// 仅保留实际使用的 China Post 价格表宏
#define CHINA_POST_E "\n\
 50g\t3.2元\t 100g\t4.5元\n\
 150g\t5.8元\t 200g\t7.1元\n\
 250g\t8.4元\t 300g\t9.7元\n\
 350g\t11元\t 400g\t12.3元\n\
 450g\t13.6元\t 500g\t15元\n"

#define LINE "----------------------------------------------------------"

// 保留实际使用的表达式解析相关函数声明
float calculateExpression(const char *expr);
int isOperator(char c);
int getPriority(char op);
float calculatePostfix(char *postfix);

#endif