#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void say(struct Person p);
void showTime(struct DT* dte);
void testtu(union TestU tu);


typedef struct DT {
	int year;
	unsigned short month;
	unsigned short day;
	unsigned short hour;
	unsigned short minute;
	unsigned short second;
}DateTime;


//定义一个结构体
struct  Person {
	char name[30];
	char sex[4];
	unsigned short age;
	unsigned int height;
	float weight;
	struct DT birthday;
};

struct Node {
	int data;
	struct Node* next;
};

struct Test1 {
	double d;
	int a;
	short s;
};

struct Test3 {
	double d;
	short s;
	int a;
};

struct Test2 {
	short s;
	double d;
	int a;
};


struct Test4 {
	char c;
	int i;
	short s;
};

//结构体测试A
struct A {
	int nums;
	struct A* a;
};


//共同体
union TestU {
	short ch[3];
	int i;
	short j;
};



int main() {

	struct Person p1 = { "王坚","男",43,176,66.783456f,{1982,12,31,18,23,51} };
	struct Person p2 = { "张小龙","男",54,177,69.23456f };
	struct Person p3 = { "雷军","男",50,170,70.23456f };
	DT t1 = { 2019,11,5 };

	//showTime(&t1);

	//p1.weight = 1346;
	//say(p1);
	//printf_s("****************************************\n");
	//say(p2);



	struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
	if (n1) {
		n1->data = 1;
		n1->next = n2;
	}
	if (n2) {
		n2->data = 2;
		n2->next = n3;
	}
	if (n3) {
		n3->data = 3;
		n3->next = NULL;
	}
	
	
	

	//printf_s("Test1==%d\n", sizeof(Test1));
	//printf_s(" Test2==%d\n", sizeof(Test2));
	//printf_s("Test3==%d\n", sizeof(Test3));
	//printf_s("Test4==%d\n", sizeof(Test4));

	struct Node arr[3] = { *n1,*n2,*n3 };
	union TestU  tu = { 996 };
	printf_s("sizeof(TestU)==%d\n", sizeof(tu.i));
	testtu(tu);
	printf_s("\nHello\n");
	return 0;
}


void say(struct Person p) {
	printf_s("姓名：%s\n", p.name);
	printf_s("性别：%s\n", p.sex);
	printf_s("年龄：%d\n", p.age);
	printf_s("体重：%0.2f\n", p.weight);
	printf_s("生日: %04d-%02d-%02d  %02d:%02d:%02d\n", p.birthday.year, p.birthday.month, p.birthday.day, p.birthday.hour, p.birthday.minute, p.birthday.second);
}


void showTime(struct DT* dte) {
	printf_s("%04d-%02d-%02d  %02d:%02d:%02d\n", dte->year, dte->month, dte->day, dte->hour, dte->minute, dte->second);
}


void testtu(union TestU tu) {
	printf_s("TestU.i==%d\n", tu.i);
	printf_s("TestU.j==%d\n", tu.j);
	printf_s("tu.ch[0]==%d\n", tu.ch[0]);
	printf_s("tu.ch[1]==%d\n", tu.ch[1]);
	printf_s("tu.ch[2]==%d\n", tu.ch[2]);
	//printf_s("tu.ch[10]==%d\n", tu.ch[10]);
	//printf_s("tu.ch[9]==%d\n", tu.ch[9]);
	//printf_s("tu.ch[8]==%d\n", tu.ch[8]);
}