#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _Apple  
{  
    void (*print_apple)();  
}Apple;  
  
typedef struct _Grape  
{  
    void (*print_grape)();  
}Grape;

void print_white_apple()  
{  
    printf("white apple!\n");  
}  
  
void print_red_apple()  
{  
    printf("red apple!\n");  
}  
  
void print_white_grape()  
{  
    printf("white grape!\n");  
}  
  
void print_red_grape()  
{  
    printf("red grape!\n");  
}

typedef struct _FruitShop  
{  
    Apple* (*sell_apple)();  
    Grape* (*sell_grape)();  
}FruitShop;

Apple* sell_white_apple()  
{  
    Apple* pApple = (Apple*) malloc(sizeof(Apple));  
    assert(NULL != pApple);  
  
    pApple->print_apple = print_white_apple;  
    return pApple;  
}  
  
Grape* sell_white_grape()  
{  
    Grape* pGrape = (Grape*) malloc(sizeof(Grape));  
    assert(NULL != pGrape);  
  
    pGrape->print_grape = print_white_grape;  
    return pGrape;  
}

Apple* sell_red_apple()  
{  
    Apple* pApple = (Apple*) malloc(sizeof(Apple));  
    assert(NULL != pApple);  
  
    pApple->print_apple = print_red_apple;  
    return pApple;  
}  
  
Grape* sell_red_grape()  
{  
    Grape* pGrape = (Grape*) malloc(sizeof(Grape));  
    assert(NULL != pGrape);  
  
    pGrape->print_grape = print_red_grape;  
    return pGrape;  
}

#define WHITE 1
#define RED 2

FruitShop* create_fruit_shop(int color)  
{  
    FruitShop* pFruitShop = (FruitShop*) malloc(sizeof(FruitShop));  
    assert(NULL != pFruitShop);  
  
    if(WHITE == color) {  
        pFruitShop->sell_apple = sell_white_apple;  
        pFruitShop->sell_grape = sell_white_grape;  
    } else if(RED == color) {  
        pFruitShop->sell_apple = sell_red_apple;  
        pFruitShop->sell_grape = sell_red_grape;  
    } else {
		free(pFruitShop);
		return NULL;
	} 
  
    return pFruitShop;  
}

int main(int argc, char **argv)
{
	FruitShop *p = NULL;
	Apple *q1 = NULL;
	Grape *q2 = NULL;

	// p 为工厂
	// 工厂有两个门面。分别有n个产品
	p = create_fruit_shop(WHITE);
	if (p != NULL) {
		q1 = p->sell_apple();
		q2 = p->sell_grape();
		q1->print_apple();
		q2->print_grape();
		free(p);
	}

	p = create_fruit_shop(RED);
	if (p != NULL) {
		q1 = p->sell_apple();
		q2 = p->sell_grape();
		q1->print_apple();
		q2->print_grape();
		free(p);
	}

	return 0;
}
