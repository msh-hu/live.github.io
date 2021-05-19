#include<iostream>
using namespace std;

const int N = 100;
int n, m;
int stk[N], ne[N], p;

int main(){
    freopen("1.txt", "r", stdin);
	puts("输入n和m：");
	scanf("%d %d", &n, &m);
	for(int i=1; i <= n; i++){
		stk[i] = i;
		ne[i] = i + 1;
	}
	
	ne[n] = 1;
	ne[0] = 1;
	p = 0;
	cout << "n = " << n << "\tm = " << m << "\n\n" << endl;
	
	
	while(n --){
		// 由于单链表只能获取下一个元素的值，
		// 不能去获取上一个元素，
		// 所以需要提前一位停止所有要 - 1
		int idx = m - 1;
		while(idx --){
			p = ne[p];
		}
		printf("p = %d ; stk[p] = %d \n", p, stk[ne[p]]);
		ne[p] = ne[ne[p]];
	}
}