#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct _Basic  
{  
    int index;  
    void (*step1) (struct _Basic* pBasic);  
    void (*step2) (struct _Basic* pBasic);  
    void (*process) (struct _Basic* pBasic);  
}Basic;

void p1_step1(struct _Basic* pBasic)
{
	printf("p1_step1\n");
}

void p1_step2(struct _Basic* pBasic)
{
	printf("p1_step2\n");
}

void p2_step1(struct _Basic* pBasic)
{
	printf("p2_step1\n");
}

void p2_step2(struct _Basic* pBasic)
{
	printf("p2_step2\n");
}

void process(struct _Basic* pBasic)  // 公共函数
{  
    pBasic->step1(pBasic);  
    pBasic->step2(pBasic);  
}

int main(int argc, char **argv)
{
	Basic p = {0, NULL, NULL, process}; // 必须赋值后调用
	Basic p1 = {1, p1_step1, p1_step2, process}; // 初始化操作
	Basic p2 = {2, p2_step1, p2_step2, process};

	p.process(&p1); // 只需改变参数，即可执行各种类
	p.process(&p2);

	return 0;
}
