#include<bits/stdc++.h>
using namespace std;

typedef struct TRIPE{
	int x;
	TRIPE *lchild, *rchild;
} TriNode, Tripe;

void CreateNode(Tripe *T, int& e){
    Tripe *newNode = (Tripe*) malloc(sizeof(Tripe));
    newNode -> lchild = NULL;
    newNode -> rchild = NULL;
    newNode -> x = e;

    Tripe *p = T;
    Tripe *q = NULL;
    while(p != NULL){
        if(p -> x > e){
            q = p;
            p = p -> lchild;
            continue;
        }
        else{
            q = p;
            p = p -> rchild;
        }
    }
    p = q;
    // if(p != NULL) cout << "!!!NULL!!!" << endl;
    if(p -> x > e) p -> lchild = newNode;
    else p -> rchild = newNode;
}

// 递归先序遍历
void PrePrint(Tripe *T){
	if(T != NULL){
        printf("%d ", T -> x);
		PrePrint(T -> lchild);
		PrePrint(T -> rchild);
	}
}
// 非递归先序遍历
void PreOrder(Tripe* root){
    stack<Tripe*> s;
    while(root != NULL || !s.empty()){
        while(root != NULL){
            printf("%d ", root->x);
            s.push(root);
            root = root -> lchild;
        }
        if(!s.empty()){
            root = s.top();
            s.pop();
            root = root -> rchild;
        }
    }
}
// 递归中序遍历
void InPrint(Tripe* T){
    if(T != NULL){
        InPrint(T -> lchild);
        printf("%d ", T -> x);
        InPrint(T -> rchild);
    }
}
// 非递归中序遍历
void InOrder(Tripe* root){
    stack<Tripe*> s;
    while(root != NULL || !s.empty()){
        while(root){
            s.push(root);
            root = root -> lchild;
        }
        if(!s.empty()){
            root = s.top();
            s.pop();
            printf("%d ", root -> x);
            root = root -> rchild;
        }
    }
}
// 递归后序遍历
void PostPrint(Tripe *T){
	if(T != NULL){
		PostPrint(T -> lchild);
		PostPrint(T -> rchild);
		printf("%d ", T -> x);
	}
}
// 非递归后序遍历
void PostOrder(Tripe* root){
    stack<Tripe* > s;
    stack<int> f;
    while(root || !s.empty()){
        while(root){
            s.push(root);
            f.push(1);
            root = root -> lchild;
        }
        if(!s.empty()){
            root = s.top();
            auto flag = f.top();
            
            if(flag == 1){
                f.pop();
                f.push(2);
                // cout << s.top() -> x << " " << f.top() << "here  " << endl;
                root = root -> rchild;
            }
            else{ // 
                printf("%d ", root -> x);
                root = NULL;
                s.pop();
                // cout << s.top() -> x << "there  " << endl;
                f.pop();
            }
        }
    }
}



int main(){
    freopen("6.txt", "r", stdin);
	Tripe *root = (Tripe*) malloc(sizeof(Tripe));
	root -> x = 6;
	root -> lchild = NULL;
	root -> rchild = NULL;

    int e;
    while(cin >> e){
        CreateNode(root, e);
    }
    
    PrePrint(root);// 递归先序遍历
    puts("递归先序遍历");
    PreOrder(root);// 非递归先序遍历
    puts("非递归先序遍历");
    puts("");

    InPrint(root);// 递归中序遍历
    puts("递归中序遍历");
    InOrder(root);// 非递归中序遍历
    puts("非递归中序遍历");
    puts("");

    PostPrint(root);// 递归后序遍历
    puts("递归后序遍历");
    PostOrder(root);// 非递归后序遍历
    puts("非递归后序遍历");
}
// 二叉树回溯时一定要注意s和f两个栈的处理
// 遇到bug时把二叉树的形态给完善出来，然后耐心调试，莫急

/*
#include<bits/stdc++.h>
using namespace std;

typedef struct TRIPE{
	int x;
	TRIPE *lchild, *rchild;
} TriNode, Tripe;

void CreateNode(Tripe *T, int& e){
    Tripe *newNode = (Tripe*) malloc(sizeof(Tripe));
    newNode -> lchild = NULL;
    newNode -> rchild = NULL;
    newNode -> x = e;

    Tripe *p = T;
    Tripe *q = NULL;
    while(p != NULL){
        if(p -> x > e){
            q = p;
            p = p -> lchild;
            continue;
        }
        else{
            q = p;
            p = p -> rchild;
        }
    }
    p = q;
    // if(p != NULL) cout << "!!!NULL!!!" << endl;
    if(p -> x > e) p -> lchild = newNode;
    else p -> rchild = newNode;
}



void PrePrint(Tripe *T){
	if(T != NULL){
        printf("%d ", T -> x);
		PrePrint(T -> lchild);
		PrePrint(T -> rchild);
	}
}

void InPrint(Tripe* T){
    if(T != NULL){
        InPrint(T -> lchild);
        printf("%d ", T -> x);
        InPrint(T -> rchild);
    }
}

void PostPrint(Tripe *T){
	if(T != NULL){
		PostPrint(T -> lchild);
		PostPrint(T -> rchild);
		printf("%d ", T -> x);
	}
}

int main(){
	freopen("6.txt", "r", stdin);
	Tripe *root = (Tripe*) malloc(sizeof(Tripe));
	root -> x = 6;
	root -> lchild = NULL;
	root -> rchild = NULL;

    int e;
    while(cin >> e){
        CreateNode(root, e);
    }

    PrePrint(root);
    puts("\n-*-*-*-*-*-");
    InPrint(root);
    puts("\n-*-*-*-*-*-");
	PostPrint(root);
    puts("\n-*-*-*-*-*-");
    
}
*/
//	PreInsert(root);n
