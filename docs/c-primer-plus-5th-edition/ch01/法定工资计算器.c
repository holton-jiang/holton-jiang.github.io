#include <stdio.h>
char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);

#define CALCULATOR "\n\n\
本工具仅仅只有计算工资功能，为了方便小白能够看懂，计算结果做了解释，\
我尽可能用大白话来讲，不过周一到周五工作日里加班的工资需要你自己另外计算。\n\n\
首先计算日薪，日薪是用你的基本工资，就是在扣税和扣社保之前的应发工资除以21.75才算出来的。\
然后，日薪乘以工作日，也就周一到周五的工资，这是你实际的工资。\n\
至于大小周、单休这种是另算的，\033[0m\033[1;31m因为法律不允许大小周、单休、月休两天。。。意思就是说，如果你周六周日上班，\
且公司没有安排你在工作日里补休，那天就算加班\033[0m，2倍的工资（2倍的加班费）。\n\
也就是说，不管你们公司的规章制度规定是大小周、单休、还是全月无休，只要有加班，加班的费用是另算的。\n\n\
举个例子：\n\
陈先生于2025年9月10日入职一家公司上班，工资是5000元/月，每天上班8小时，由于公司是单休制，\n\
导致陈先生在9月份里，周一到周五工作日中上了15天除外，双休日中额外上了3天班，且公司没有安排他在周一至周五的工作日里休3天。\n\n\
日 一 二 三 四 五 六\n\
    1  2  3  4  5  6\n\
 7  8  9 10 11 12 13\n\
14 15 16 17 18 19 20\n\
21 22 23 24 25 26 27\n\
28 29 30\n\n\
那么他的工资如下：\n\
先把周末加班没有补休的情况和正常工作日的情况分开来，然后用应发工资除以21.75算出来日薪\n\
\033[0m\033[1;31m日薪：5000 ÷ 21.75 = 299.88 元\033[0m\n\
然后日薪乘以工作日的上班天数，得到你工作日的工资。\n\
\033[0m\033[1;31m应发工资：299.88 × 15天 = 3448.27 元\n\
双休日里上班的工资：299.88 × 3天 × 2 = 1799.28 元。\033[0m\n\n"

#define LINE "-----------------------------------------------------------------------------"
#define INFO "--------------------------------\033[0m\033[1;32m使用说明\033[0m----------------------------------------"

int main(void){

	int choice;
	void count(void);
	printf("该程序输入字符“q”可结束本程序\n");


	while ( (choice = get_choice()) != 'q')
    {
        switch (choice)
        {
            case 'a' :  count();
                        break;
            case 'b' :  printf("%s %s\n",INFO,CALCULATOR);
                        break;
            default  :  printf("程序错误!\n");
                        break;
        }
    } 

	printf("\n退出程序\n");
	return 0;
}

char get_choice(void)
{
    int ch;

    printf("a. 计算工资           b. 使用说明\n");
    printf("q. 退出(Quit)\n");
    printf("输入您的选择:_\b");
    ch = get_first();
    while (  (ch < 'a' || ch > 'b') && ch != 'q')
    {
        printf("请输入对应字符a、b 或 q :_\b");
        ch = get_first();
    }
    
    return ch;
}

char get_first(void)
{
    int ch;

    ch = getchar();
    while (getchar() != '\n')
        continue;
        
    return ch;
}

void count(void)
{

    float wage;//约定每月工资
	float fiveone;//个人缴纳的五险一金的金额
	int workday;//实际工作日出勤天数（剔除双休日里上班且未安排补休的天数）
	float workday_wage;//周一到周五工作日的工资
	float daily_wage;//日薪
	float time_wage;//时薪
	float hourly;//小时
	int weekend;//双休日里上班且未安排补休天数
	float weekend_wage;//双休日上班且未安排补休的工资
	int legal_holidays;//法定节假日天数
    float legal_holidays_wage;//法定节假日工资
    float all_workday_wage = 0L;//周一到周五工作日的工资累计
    float all_weekend_wage = 0L;//双休日上班且未安排补休的工资累计
    float all_legal_holidays_wage = 0L;//法定节假日工资累计
	float month_total;//当月到手工资统计

    long num;
    float all_total = 0L; /* 将总和初始化为零 */
    int status;

        printf("输入约定每天上班多少个小时:");
        scanf("%f",&hourly);

    	printf("输入第一个要计算的月份（阿拉伯数字1-12）:");

    status = scanf("%ld", &num);
    //num = get_int();

    while (status == 1) /* == 表示“等于" */
    {
        printf("***------------------------------%ld月分割线--------------------------------***\n",num);

        printf("输入约定每月工资为:_____\b\b\b\b\b");
		scanf("%f",&wage);

		printf("输入个人缴纳的五险一金的金额:______\b\b\b\b\b\b");
		scanf("%f",&fiveone);

		printf("输入实际工作日出勤天数（剔除双休日在上班的天数）:__\b\b");
		scanf("%d",&workday);

		printf("输入双休日上班且未安排补休的天数:_\b");
		scanf("%d",&weekend);

		printf("输入法定节假日在上班的天数:_\b");
		scanf("%d",&legal_holidays);

	daily_wage = wage / 21.75;
		printf("\n\t日薪为：约定每月工资%.2f ÷ 21.75 =\033[0m\033[1;32m %.2f 元 \033[0m\n",wage,daily_wage);
	time_wage = daily_wage / hourly;
		printf("\t时薪为：日薪%.2f ÷ 每天上%.1f小时 =\033[0m\033[1;32m %.2f 元 \033[0m\n\n",daily_wage,hourly,time_wage);

	workday_wage = daily_wage * workday;
		printf("周一到周五工作日的工资为：日薪%.2f元 × 实际工作日出勤%d天 =\033[0m\033[1;34m %.2f 元\033[0m\n",daily_wage,workday,workday_wage);

	weekend_wage = daily_wage * weekend * 2;
		printf("双休日在上班且未安排补休的工资为：(日薪%.2f元 × 双休日里上班且未安排补休%d天) × 2倍 =\033[0m\033[1;34m %.2f 元 \033[0m\n",daily_wage,weekend,weekend_wage);

    legal_holidays_wage = daily_wage * legal_holidays * 3;
        printf("法定节假日上班在上班的工资为：日薪%.2f元 × 法定节假日在上班%d天 × 3倍 =\033[0m\033[1;34m %.2f 元 \033[0m\n",daily_wage,legal_holidays,legal_holidays_wage);

	month_total = workday_wage + weekend_wage - fiveone;
		printf("%ld月应发到手工资为：工作日工资%.2f + 双休日里上班且未安排补休的工资%.2f - 个人缴纳的五险一金金额%.2f元 =\033[0m\033[1;34m %.2f 元 \033[0m\n",num,workday_wage,weekend_wage,fiveone,month_total);

		printf("%s\n",LINE);
		putchar('\a');//Di一声

    all_workday_wage = all_workday_wage + workday_wage;
    all_weekend_wage = all_weekend_wage + weekend_wage;
    all_legal_holidays_wage = all_legal_holidays_wage + legal_holidays_wage;
    all_total = all_total + month_total;

        printf("请输入下一个要计算的月份（阿拉伯数字1-12）:__\b\b");
        status = scanf("%ld", &num);
    }

    printf("\n\t周一到周五工作日的工资累计为:\033[0m\033[1;31m %.2f 元。 \033[0m\n", all_workday_wage);
    printf("\t双休日在上班且未安排补休的工资累计为:\033[0m\033[1;31m %.2f 元。 \033[0m\n", all_weekend_wage);
    printf("\t法定节假日在上班工资累计为:\033[0m\033[1;31m %.2f 元。 \033[0m\n", all_legal_holidays_wage);
    printf("\t每个月应发到手工资累计为:\033[0m\033[1;31m %.2f 元。 \033[0m\n\n\n", all_total);

}
