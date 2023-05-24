#include <stdio.h>
#include <string.h>

struct node {
	char* data;
	struct node *next; //자신과 동일한 구조체에 대한 포인터를 멤버로 가지는 '자기참조형 구조체'
};

typedef struct node Node;
Node *head = NULL; //첫 노드 주소를 담을 헤드

int main() {
	head = (Node*)malloc(sizeof(Node));
	head->data = "Tuesday";
	head->next = NULL;

	Node *q = (Node*)malloc(sizeof(Node));
	q->data = "Thursday";
	q->next = NULL;
	head->next = q;

	q = (Node*)malloc(sizeof(Node));
	q->data = "Monday";
	q->next = head;
	head = q;

	Node *p = head;
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}
}