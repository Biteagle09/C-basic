#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void say(struct Person p);
void showTime(struct DT *dte);

typedef struct DT {
	int year;
	unsigned short month;
	unsigned short day;
	unsigned short hour;
	unsigned short minute;
	unsigned short second;
}DateTime;


//����һ���ṹ��
struct  Person{
	char name[30];
	char sex[4];
	unsigned short age;
	unsigned int height;
	float weight;
	struct DT birthday;
};


//�ṹ�����
struct A {
	int nums;
	struct A *a;
};


int main() {

	struct Person p1 = { "����","��",43,176,66.783456f,{1982,12,31,18,23,51} };
	struct Person p2 = {"��С��","��",54,177,69.23456f};
	DT t1 = {2019,11,5};

	showTime(&t1);

	//p1.weight = 1346;
	//say(p1);
	//printf_s("****************************************\n");
	//say(p2);

	return 0;
}


void say(struct Person p) {
	printf_s("������%s\n", p.name);
	printf_s("�Ա�%s\n", p.sex);
	printf_s("���䣺%d\n", p.age);
	printf_s("���أ�%0.2f\n", p.weight);
	printf_s("����: %04d-%02d-%02d  %02d:%02d:%02d\n", p.birthday.year, p.birthday.month, p.birthday.day, p.birthday.hour, p.birthday.minute, p.birthday.second);
}


void showTime(struct DT *dte) {
	printf_s("%04d-%02d-%02d  %02d:%02d:%02d\n", dte->year, dte->month, dte->day, dte->hour, dte->minute, dte->second);
}