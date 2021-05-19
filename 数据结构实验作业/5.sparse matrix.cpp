#include<bits/stdc++.h>
using namespace std;

// 矩阵元素个数
const int N = 110;
int idx = -1, n;
int num[10], cpot[N];

typedef struct{
    int x, y;
    int e;
}Tripe;

typedef struct{
    Tripe data[N];
    int row; // 行
    int col; // 列
    int sum;
}Matrix;

Matrix M, T;

int main(){
    freopen("5.txt", "r", stdin);
    puts("请输入矩阵行、列、稀疏元素个数");
    cin >> M.row >> M.col >> n;
    
    puts("Hello World!");
    // 对num数组初始化
    for(int i=0; i<M.col; i++) num[i] = 0;

    puts("请输入元素所在行、列、元素值");
    M.sum = n;
    // 将矩阵存储到一维数组内
    // M内是随机存的，没有什么顺序
    for(int i=0; i<M.sum; i++){
        cin >> M.data[i].x >> M.data[i].y >> M.data[i].e;
        num[M.data[i].y] ++;
    }

    // 矩阵M中每列第一个元素在一维数组中的位置
    cpot[0] = 0;
    for(int i=1; i<M.col; i++){
        cpot[i] = num[i-1] + cpot[i-1];
    }
    
    T.sum = M.sum;
    T.row = M.col;
    T.col = M.row;
    for(int i=0; i<T.sum; i++){
        int col, p;
        col = M.data[i].y;
        p = cpot[col] ++; // 当前元素的位置
        T.data[p].x = M.data[i].y;
        T.data[p].y = M.data[i].x;
        T.data[p].e = M.data[i].e;
    }

    for(int i=0; i<T.sum; i++){
        printf("%d %d %d\n",M.data[i].x, M.data[i].y, M.data[i].e);
    }
    puts("");
    for(int i=0; i<T.sum; i++){
        printf("%d %d %d\n",T.data[i].x, T.data[i].y, T.data[i].e);
    }
}

// 目前只能完成分列
// 但是同一列中的元素无法排好顺序