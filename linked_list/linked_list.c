#include <stdio.h>
#include <string.h>

struct node {
	char* data;
	struct node *next; //�ڽŰ� ������ ����ü�� ���� �����͸� ����� ������ '�ڱ������� ����ü'
};

typedef struct node Node;
Node *head = NULL; //ù ��� �ּҸ� ���� ���


//���ο� ��带 ù��°�� �����ְ� �ʹٸ�
	//1. ���ο� ��� ����� �߰��� ������ ���� \
		2-a. ���ο� ����� next�ʵ尡 ���� head��带 ����Ű���� �� \
		2-b. ���� head�� ����Ű�� ���� ���ٸ� NULL�� ����Ű���� �� \  
	//3. ���ο� ��带 ���ο� head ���� ����
void add_first(const char *item) {
	Node* tmp = (Node*)malloc(sizeof(Node)); //(1)
	tmp->data = item; //(1)
	if (head == NULL)
		tmp->next = NULL;
	else
		tmp->next = head; //(2)
	head = tmp; //(3)
}

//���� node�� ���� ���� ������ ����ƴٸ�?
void add_first_local(Node** head_ptr, const char *item) { //���� �����ͷ� �����ؾ߸� head�� ����Ű�� �ּ� ���� ����
	Node* tmp = (Node*)malloc(sizeof(Node)); //(1)
	tmp->data = item; //(1)
	if (*head_ptr == NULL)
		tmp->next = NULL;
	else
		tmp->next = *head_ptr; //(2)
	*head_ptr = tmp; //(3)
}

int main() {
	/*head = (Node*)malloc(sizeof(Node));
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
	}*/

	//part2. ���Ḯ��Ʈ �� �տ� ���ο� ��� �߰�
	head = (Node*)malloc(sizeof(Node));
	head->data = "Tom";
	head->next = NULL;

	add_first("Ann");

	Node* p = (Node*)malloc(sizeof(Node));
	p->data = "dick";
	p->next = NULL;
	head->next = p;

	Node* q = (Node*)malloc(sizeof(Node));
	q->data = "Harry";
	q->next = NULL;
	p->next = q;

	Node *x = head;
	while (x != NULL) {
		printf("%s\n", x->data);
		x = x->next;
	}
}