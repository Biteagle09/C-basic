#include <stdio.h>
#include <stdlib.h>
#define NULL 0


//函数声明
struct Node* createLink();
struct Node* createNode(int data);
void insertNodeByHead(struct Node* headNode, int data);
void insertNodeByTail(struct Node* headNode, int data);
void printLink(struct Node* headNode);

//链式结构的数据与
struct Node{
	int data;
	struct Node* next;
};


int main(){
	 
	struct Node* link = createLink(); 
	for(int i = 0; i < 10; i++){
		if (i < 6) {
			insertNodeByHead(link, i);
		}else {
			insertNodeByTail(link, i);
		}
	}
	
	printLink(link);
	return 0;
}



//1、创建表（结构体变量）
struct Node* createLink(){
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
}



//2、创建节点
struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}


//3、插入节点（表头插入）
void insertNodeByHead(struct Node* headNode, int data){
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}



//4、插入节点（尾插法）
void insertNodeByTail(struct Node* headNode, int data){
	struct Node* newNode = createNode(data);
	struct Node* tailNode = headNode;
	while(tailNode->next){
		tailNode = tailNode->next;
	}
	tailNode->next = newNode;
}


//打印链表
void printLink(struct Node* headNode){
	struct Node* p = headNode->next;
	while(p->next){
		printf("%d-->",p->data);
		p = p->next;
	}
	printf("%d\n",*p);
}