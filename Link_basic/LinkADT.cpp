#include <stdio.h>
#include <stdlib.h>

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
	 
	//定义节点变量
	//struct Node node1 = { 1, NULL };
	//struct Node node2 = { 2, NULL };
	//struct Node node3 = { 3, NULL };
	//
	//node1.next = &node2;
	//node2.next = &node3;

	//赋予变量的地址
	//int d = 1;
	//int *p = &d;
	//d = 3;
	//(*p)++;
	//printf("d==%d\n",*p);


	//动态内存申请
	//int *p1 = (int *)malloc(sizeof(int));
	//*p1 = 5;
	//printf("p1==%d\n",*p1);



	struct Node* link = createLink(); 
	for(int i = 0; i < 10; i++){
		if(i < 6) insertNodeByHead(link, i);
		else insertNodeByTail(link,i);
		
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