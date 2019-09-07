#include "stdio.h"
#include "stdlib.h"

struct Node* createNode(int data);
void insertNodeByHead(struct Node* headNode, int data);
struct stack* createStack();
void push(struct stack* theStack, int data);
void pop(struct stack* theStack);
int top(struct stack* theStack);
int isEmpty(struct stack* theStack);



//节点结构体
struct Node{
	int data;
	struct Node* next;
};


//栈结构体
struct stack{
	struct Node* stackTop;
	int size;
};




int main(){
	
	struct stack* myStack = createStack();
	for(int i = 0; i < 10; i++){
		push(myStack, i);
	}
	while(myStack->stackTop->next!=NULL){
		printf("%d-->",top(myStack));
		pop(myStack);
	}
	printf("%d\n",top(myStack));


	return 0;
}


//1、创建一个栈
struct stack* createStack(){
	struct stack* newStack = (struct stack*)malloc(sizeof(struct stack)); 
	newStack->stackTop = NULL;
	newStack->size = 0;
	return newStack;
}


//2、入栈
void push(struct stack* theStack, int data){
	struct Node* newNode = createNode(data);
	newNode->next = theStack->stackTop;
	theStack->stackTop = newNode;
	theStack->size++;
}



//3、出栈
void pop(struct stack* theStack){
	if(theStack->size == 0) {
		printf("The stack is null!!!");
		return;
	}else{
		struct Node* nextNode = theStack->stackTop->next;
		free(theStack->stackTop);
		theStack->stackTop = nextNode;
		theStack->size--;
	}
}



//4、获取栈顶元素
int top(struct stack* theStack){
	if(theStack->size == 0) {
		printf("The stack is null!!!");
		return theStack->size;
	}
	return theStack->stackTop->data;
}



//5、判断栈是否为空？
/*
return 1：栈不为空
	   0：栈为空
*/
int isEmpty(struct stack* theStack){
	return theStack->size?1:0;
}







//创建节点
struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}


//头插法 插入节点
void insertNodeByHead(struct Node* headNode, int data){
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}