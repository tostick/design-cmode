#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _DATA
{
	int basic_val;
	struct _DATA* (*copy)(struct _DATA* pData);
}DATA;


struct _DATA *data_copy_A(struct _DATA* pData)
{
	DATA *pResult = NULL;

	pResult = (DATA *)malloc(sizeof(DATA));
	assert(NULL != pResult);
	memmove(pResult, pData, sizeof(DATA));
	return pResult;
}


struct _DATA *clone(struct _DATA *pData)
{
	return pData->copy(pData);
}


int main(int argc, char **argv)
{
	DATA p = {101, data_copy_A}; // 初始化值和函数
	DATA *p1 = NULL;
	DATA *p2 = NULL;

	p1 = clone(&p); // 生子结构
	p2 = clone(p1); // 生子结构
	p2->basic_val = 102; // 修改子结构的内容

	printf("p1 val:%d\n", p1->basic_val);
	printf("p2 val:%d\n", p2->basic_val);

	return 0;
}
