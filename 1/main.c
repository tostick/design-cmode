#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// get_data函数中可产生一个示例，可在整个程序中调用访问
typedef struct DATA  
{  
    int data;  
}DATA;  
      
void* get_data()  
{  
    static DATA* pData = NULL;  
        
    if(NULL != pData)  
        return pData;  
      
    pData = (DATA*)malloc(sizeof(DATA));  
    assert(NULL != pData);  
    return (void*)pData;  
}

int main(int argc, char **argv)
{
	DATA *q = NULL;	
	void *p = NULL;	
	
	p = get_data();

	q = (DATA *)p; // 注: 不可使用p->data
	q->data = 10;

	printf("%d\n", q->data);

	return 0;
}
