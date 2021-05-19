#include<bits/stdc++.h>
using namespace std;

struct LNode{
	int coef;
	int exp;
	struct LNode* next;
};
typedef LNode List;

void Add_List_Tail(List*& s ,int coef, int exp){
	List*t = (LNode*) malloc(sizeof(LNode));
	t->coef = coef;
	t->exp = exp;
	t->next = NULL;

	s->next = t;
}

void CreatList(List*& p)
{
	int m, coef, exp;

	printf("输入项数：\t");
	scanf("%d", &m);
	while(m --){
		printf("\n请分别输入系数和指数:\n");
		scanf("%d %d", &coef, &exp);
		Add_List_Tail(p, coef, exp);
		p = p->next;
	}
}

void print(List* s){
	do{
		printf("%d %d\t", s->coef, s->exp);
	}while((s=s->next) != NULL);
}

int main(){
	freopen("1.txt", "r", stdin);
	List *p, *head;
	p = (List *)malloc(sizeof(List));
	head = p;
	CreatList(p);
	head = head->next;

	print(head);
}
