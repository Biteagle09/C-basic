#include "stdio.h"
#include "stdlib.h"

int  createInt(int a, int b);


//Ã¶¾Ù
enum Hero {Guanyu=11, Zhangfei=22, Liubei=33, Caocao=6, Zhaoyun=9};






int main() {

	enum Hero hero = Zhangfei;
	hero = Zhaoyun;
	printf("Hello=%d\n",hero);
	int a = createInt(12, 34);
	printf("a==%d\n", a);
	 
	return 0;
}


int  createInt(int a, int b) {
	return a + b;
}