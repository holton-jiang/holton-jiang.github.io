#ifdef _WIN32
#include <windows.h>
#endif
#include "count.h"

#ifdef _WIN32
// Windows 下定义 sleep
#define sleep(seconds) Sleep((unsigned int)((seconds) * 1000.0))
#else
#include <unistd.h>
#endif

// --- 全局变量定义 ---
// 用于存储 China Post 推荐售价下的成本
float cost_of_the_listed_price_china;

// UTF-8 判断中文全角符号
int isChineseSymbol(const char *p) {
    // 第一种：标准中文标点 ，。（） → E3 80 XX
    if ((unsigned char)p[0] == 0xE3 && (unsigned char)p[1] == 0x80) {
        switch ((unsigned char)p[2]) {
            case 0x81: return 3; // ，
            case 0x82: return 4; // 。
            case 0x88: return 1; // （
            case 0x89: return 2; // ）
            default: return 0;
        }
    }
    // 第二种：全角标点 ，。（） → EF BC XX
    if ((unsigned char)p[0] == 0xEF && (unsigned char)p[1] == 0xBC) {
        switch ((unsigned char)p[2]) {
            case 0x8C: return 3; // ，
            case 0x8E: return 4; // 。
            case 0x88: return 1; // （
            case 0x89: return 2; // ）
            default: return 0;
        }
    }
    return 0;
}

// 预处理：中文标点转英文、过滤其他多字节 + 中文句号/逗号/英文逗号转小数点
void preprocessInput(char *input) {
    char *p = input;
    while (*p != '\0') {
        int sym = isChineseSymbol(p);
        if (sym > 0) {
            switch (sym) {
                case 1: *p = '('; break;
                case 2: *p = ')'; break;
                case 3: *p = '.'; break; // 中文逗号 → 小数点
                case 4: *p = '.'; break; // 中文句号 → 小数点
            }
            memmove(p + 1, p + 3, strlen(p + 3) + 1);
        }
        // 英文逗号 → 小数点
        else if (*p == ',') {
            *p = '.';
            p++;
        }
        // 过滤无用多字节字符（兼容 Windows GBK + Mac UTF-8）
        else if ((unsigned char)*p >= 0x80) {
            unsigned char uc = (unsigned char)*p;
            int skip = (uc >= 0xE0) ? 2 : ((uc >= 0xC0) ? 1 : 0);
            while (skip-- > 0 && *(p + 1)) {
                memmove(p, p + 1, strlen(p + 1) + 1);
            }
            p++;
        } else {
            p++;
        }
    }
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

int getPriority(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int infixToPostfix(const char *expr, char *postfix) {
    char stack[100];
    int stackTop = -1;
    int postIdx = 0;
    const char *p = expr;
    while (*p) {
        if (*p == ' ' || *p == '\t') {
            p++;
            continue;
        }
        if (isdigit(*p) || *p == '.') {
            while (isdigit(*p) || *p == '.') postfix[postIdx++] = *p++;
            postfix[postIdx++] = ' ';
        } else if (*p == '(')
            stack[++stackTop] = *p++;
        else if (*p == ')') {
            while (stackTop >= 0 && stack[stackTop] != '(') {
                postfix[postIdx++] = stack[stackTop--];
                postfix[postIdx++] = ' ';
            }
            if (stackTop < 0) return 0;
            stackTop--;
            p++;
        } else if (isOperator(*p)) {
            while (stackTop >= 0 && getPriority(stack[stackTop]) >= getPriority(*p)) {
                postfix[postIdx++] = stack[stackTop--];
                postfix[postIdx++] = ' ';
            }
            stack[++stackTop] = *p++;
        } else return 0;
    }
    while (stackTop >= 0) {
        if (stack[stackTop] == '(') return 0;
        postfix[postIdx++] = stack[stackTop--];
        postfix[postIdx++] = ' ';
    }
    if (postIdx > 0) postfix[postIdx - 1] = '\0';
    return 1;
}

float calculatePostfix(char *postfix) {
    float stack[100];
    int stackTop = -1;
    char *token = strtok(postfix, " ");
    while (token) {
        if (!isOperator(token[0]) || (token[0] == '-' && token[1])) {
            errno = 0;
            float num = strtof(token, NULL);
            if (errno) return NAN;
            stack[++stackTop] = num;
        } else {
            if (stackTop < 1) return NAN;
            float b = stack[stackTop--];
            float a = stack[stackTop--];
            float res;
            switch (token[0]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': if (b == 0) return NAN; res = a / b; break;
                default: return NAN;
            }
            stack[++stackTop] = res;
        }
        token = strtok(NULL, " ");
    }
    return (stackTop == 0) ? stack[0] : NAN;
}

float calculateExpression(const char *expr) {
    char processed[200], postfix[200];
    strncpy(processed, expr, sizeof(processed)-1);
    processed[sizeof(processed)-1] = '\0';
    preprocessInput(processed);
    if (!infixToPostfix(processed, postfix)) return NAN;
    return calculatePostfix(postfix);
}

float safeInput(const char *prompt) {
    char input[100];
    float value;
    while (1) {
        printf("%s", prompt);
        fflush(stdout);
        if (!fgets(input, sizeof(input), stdin)) continue;
        input[strcspn(input, "\n")] = '\0';
        if (strlen(input) == 0) continue;
        if (strlen(input) == 1) {
            char c = tolower(input[0]);
            if (c == 'q') {
                printf("\n正在退出程序...\n");
                sleep(1);
                exit(0);
            }
        }
        value = calculateExpression(input);
        if (!isnan(value)) return value;
        printf("输入格式错误！支持输入运算符号 + - * / \neg:直接输入 10.55 或 (1.5+2)*3.3-1\n");
    }
}

// 返回值：包含两种佣金的结构体
typedef struct {
    float sales_commission;
    float withdraw_fee;
} CommissionResult;

CommissionResult calcCommissions(float price, float commission_rate, float withdraw_rate) {
    CommissionResult res;
    res.sales_commission = price * commission_rate / 100; // 销售佣金 = 售价 × 佣金比例%
    res.withdraw_fee = price * withdraw_rate / 100;       // 提现费 = 售价 × 交付比例%
    return res;
}

// 函数功能：计算平台配送服务费（固定规则）
float calcOO(float ozon_seller) {
    float agency_commission;
    if (ozon_seller <= 75) {
        agency_commission = 1.5; // 售价≤75元，配送费固定1.5元
    } else if (ozon_seller >= 2000) {
        agency_commission = 20.0; // 售价≥2000元，配送费固定20元
    } else {
        float temp = ozon_seller * 0.02; // 其他情况：售价×2%
        temp = ceil(temp * 2) / 2; // 向上取整到0.5的倍数
        agency_commission = temp;
    }
    return agency_commission;
}

// China Post 专用计算逻辑
void count_china_post(void){
    // 变量定义
    float procurement;
    float commission_rate = 12;
    float withdraw = 1.2;
    float logistics;
    float ozon_seller;
    int list = 1;
    float rub_exchange_rate = 11.024;

    // 1. 提示输入
    while (1){
        procurement = safeInput("输入商品采购金额:_________\b\b\b\b\b\b\b\b\b");
        printf("%s\n", CHINA_POST_E); // 打印运费表
        logistics = safeInput("输入中国邮政物流费:_________\b\b\b\b\b\b\b\b\b");
        ozon_seller = safeInput("输入你的售价:_________\b\b\b\b\b\b\b\b\b");

        // ---------------- 核心计算逻辑 ----------------
        // 1. 计算基础佣金
        float custom_commission_rate = (ozon_seller > 135) ? 14.0 : 12.0;
        CommissionResult customComm = calcCommissions(ozon_seller, custom_commission_rate, withdraw);
        // 2. 计算平台配送服务费 (Ozon代理)
        float agency_commission1 = calcOO(ozon_seller);
        // 3. 计算额外交付成本 (5%)
        float extra_delivery_fee = ozon_seller * 0.05;
        // 4. 计算总成本
        float cost_statistics = procurement + logistics + agency_commission1 + customComm.sales_commission + customComm.withdraw_fee + extra_delivery_fee;

        // ---------------- 输出结果 ----------------
        printf("\n清单0%d--------固定支出成本计算结果------------------------\n", list);
        
        // 采购成本
        printf("商品采购成本: %.2f 元\n", procurement);
        // 物流
        printf("国际物流费用: %.2f 元\n", logistics);
        // 平台配送 (Ozon代理)
        printf("Ozon代理佣金: %.2f 元(2%%  15-200卢布)\n", agency_commission1);
        // 基础佣金 (销售+收单+提现)
        printf("销售代理佣金: %.2f 元(%.0f%%)\n", customComm.sales_commission, custom_commission_rate);
        printf("银行提现业务: %.2f 元(1.2%%)\n", customComm.withdraw_fee);
        // 合作交付成本 (5%)
        printf("商品交付费用: %.2f 元(约4~6%%)\n", extra_delivery_fee);
        
        printf("%s\n",LINE);
        // 总成本
        printf("固定支出成本: %.2f 元\n", cost_statistics);
        printf("%s\n",LINE);
        // 毛利
        printf("实际到手毛利:%.2f 元\n\n", ozon_seller - cost_statistics);
        
        list++;
    }
}

// --- 程序主入口 ---
int main(void) {
    // 自动判断系统
#ifdef _WIN32
    SetConsoleTitleA("计算realFBS (rFBS) 中国邮政  Version: 2026.7.26");
#else
    printf("计算realFBS (rFBS) 中国邮政\n");
#endif
    printf("欢迎使用 Ozon 中国邮政物流成本计算工具 (China Post版)\n");
    printf("开发者: 蒋小霕 (Holton Jiang) \t 版本: 2026.7.26\n");
    printf("输入 'q' 可随时退出程序\n");
    printf("--------------------------------------------------\n\n");
    count_china_post();
    return 0;
}