// 多项式求和msh

#include<bits/stdc++.h>
using namespace std;

typedef struct LNode{
    int coef;
    int exp;
    struct LNode* next;
}List;

void create_list(List*& p){
    int m, coef, exp;
    cin >> m;
    p = (List*) malloc(sizeof(List));
    List*s = p;
    while(m --){
        s->next = (List*) malloc(sizeof(List));
        s = s->next;
        cin >> s->coef >> s->exp;
        s->next = NULL;
    }
}

void print_list(List* head){
    while((head = head->next) != NULL){
        cout << head->coef << "\t" << head->exp << endl;
    }
}

void list_sum_print(List* p, List* q){
    // List* L = (List*) malloc(sizeof(List));
    List* l = p;
    List* sum = p;
    p = p->next;
    q = q->next;
    while((p != NULL) && (q != NULL)){
        if(p->exp < q->exp){
            l = p;
            p = p->next;
        }
        else if(p->exp > q->exp){
            l->next = q;
            l = q;
            q = q->next;
            l->next = p;
            /* 插入当前链表q的某一结点到p中时，一定要谨慎不要把q中这一结点的后一结点的地址给丢掉 */
        }
        else{//指数相等的情况下
            p->coef += q->coef;
            q = q->next;
            l = p;
            p = p->next;
        }
    }
    if(p == NULL) l->next = q;

    while((sum = sum->next) != NULL){
        printf(" %dx^%d ", sum->coef, sum->exp);
        if(sum->next != NULL) cout << "+";
    }
}

void sort_list(List* p){
    List*s = p;
    while((s = s->next) != NULL){
        List* L=s;
        while((L = L->next) != NULL){
            if(L->exp < s->exp){
                swap(L->exp, s->exp);
                swap(L->coef, s->coef);
            }
        }
    }
}

//传递某一节点的next给其它指针时，前提必须该next有具体的地址
//head空间不使用时和使用时
int main(){
    freopen("2.txt", "r", stdin);
    List *p = NULL, *q = NULL;
    create_list(p);
    create_list(q);
    sort_list(p);
    sort_list(q);
    
    list_sum_print(p, q);
}