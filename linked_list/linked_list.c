#include <stdio.h>
#include <string.h>

struct node {
	char* data;
	struct node *next; //자신과 동일한 구조체에 대한 포인터를 멤버로 가지는 '자기참조형 구조체'
};

typedef struct node Node;
Node *head = NULL; //첫 노드 주소를 담을 헤드


//새로운 노드를 첫번째에 끼워넣고 싶다면
	//1. 새로운 노드 만들고 추가할 데이터 저장 \
		2-a. 새로운 노드의 next필드가 현재 head노드를 가리키도록 함 \
		2-b. 만약 head가 가리키는 것이 없다면 NULL을 가리키도록 함 \  
	//3. 새로운 노드를 새로운 head 노드로 변경
void add_first(const char *item) {
	Node* tmp = (Node*)malloc(sizeof(Node)); //(1)
	tmp->data = item; //(1)
	if (head == NULL)
		tmp->next = NULL;
	else
		tmp->next = head; //(2)
	head = tmp; //(3)
}

//만약 node가 지역 변수 내에서 선언됐다면?
void add_first_local(Node** head_ptr, const char *item) { //이중 포인터로 선언해야만 head가 가리키는 주소 변경 가능
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

	//part2. 연결리스트 맨 앞에 새로운 노드 추가
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