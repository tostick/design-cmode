#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct _Leader  
{  
    struct _Leader* next;  
    int account;  
	char name[10];
      
    int (*request)(struct _Leader* pLeader, int num);   
}Leader;

void set_account(struct _Leader* pLeader, int account)  
{  
    assert(NULL != pLeader);  
       
    pLeader->account = account;  
    return;  
}   
  
void set_next_leader(struct _Leader* pLeader, struct _Leader* next)  
{  
    assert(NULL != pLeader && NULL != next);  
   
	pLeader->next = next;
	return;  
}

int request_for_manager(struct _Leader* pLeader, int num)  
{  
    assert(NULL != pLeader && 0 != num);  
  
    if(num <= pLeader->account) { 
		printf("%s\n", pLeader->name);
        return 0;  
	} else if(pLeader->next) {
        return pLeader->next->request(pLeader->next, num);
	}	
    else {   
        return 1;
	}	
}

int main(int argc, char **argv)
{
	// 创建报销规则
	// 法1
	//Leader leader1 = {NULL, 100000, "leader1", request_for_manager};
	//Leader leader2 = {&leader1, 10000, "leader2", request_for_manager};
	//Leader leader3 = {&leader2, 1000, "leader3", request_for_manager};
	// 法2 
	Leader leader1 = {NULL, 0, "leader1", request_for_manager};
	Leader leader2 = {NULL, 0, "leader2", request_for_manager};
	Leader leader3 = {NULL, 0, "leader3", request_for_manager};
	set_account(&leader3, 1000);
	set_account(&leader2, 10000);
	set_account(&leader1, 100000);
	set_next_leader(&leader3, &leader2);
	set_next_leader(&leader2, &leader1);
	

	request_for_manager(&leader3, 50000);

	return 0;
}
