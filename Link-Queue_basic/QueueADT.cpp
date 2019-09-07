#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct Node* createNode(int data);
struct Queue* createQueue();
void push(struct Queue* theQueue, int data);
void push(struct Queue* theQueue, int data);
void pop(struct Queue* theQueue);
int getFornt(struct Queue* theQueue);
int isEmpty(struct Queue* theQueue);


//��ʽ�ṹ��������
struct Node {
	int data;
	struct Node* next;
};

//���еĽṹ��
struct Queue {
	struct Node* frontNode;
	struct Node* tailNode;
	int size;
};



int main() {

	struct Queue* myQueue = createQueue();
	for (int i = 0; i < 10; i++) {
		push(myQueue, i);
	}
	while (myQueue->frontNode->next) {
		printf_s("%d-->", getFornt(myQueue));
		pop(myQueue);
	}
	printf_s("%d\n", getFornt(myQueue));
	return 0;
}


//1������һ������
struct Queue* createQueue() {
	struct Queue* newQueue = (struct Queue*)malloc(sizeof(struct Queue));
	newQueue->frontNode = newQueue->tailNode = NULL;
	newQueue->size = 0;
	return newQueue;
}


//2�����
void push(struct Queue* theQueue, int data) {
	struct Node* newNode = createNode(data);
	if (theQueue->size == 0) {
		theQueue->frontNode = theQueue->tailNode = newNode;
	}
	else {
		theQueue->tailNode->next = newNode;
		theQueue->tailNode = newNode;
	}
	theQueue->size++;
}



//3������
void pop(struct Queue* theQueue) {
	if (theQueue->size == 0) {
		printf("The Queue is null!!!");
		return;
	}
	else {
		struct Node* nextNode = theQueue->frontNode->next;
		free(theQueue->frontNode);
		theQueue->frontNode = nextNode;
		theQueue->size--;
	}
}



//4����ȡ��ͷԪ��
int getFornt(struct Queue* theQueue) {
	if (theQueue->size == 0) {
		printf("The Queue is null!!!");
		return theQueue->size;
	}
	else {
		return theQueue->frontNode->data;
	}
}



//5���ж϶����Ƿ�Ϊ��
/*
return 1��ջ��Ϊ��
	   0��ջΪ��
*/
int isEmpty(struct Queue* theQueue) {
	return theQueue->size ? 1 : 0;
}


//...n�������ڵ�
struct Node* createNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}