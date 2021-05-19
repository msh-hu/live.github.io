#include<bits/stdc++.h>
// #include<iostream>
// #include<stdio.h>
using namespace std;
const int N = 100010;
char str[N], expp[N], op[N], ch;
int hstr=0, hexp=-1, hop=-1, flag=0;

int main(){
    freopen("3.txt", "r", stdin);
    scanf("%s", str);

    while((ch = str[hstr ++]) != '\0'){
        if(ch == '/' || ch == '*'){
            op[++ hop] = ch;
        }
        else if(ch == '+' || ch == '-'){
            // while(op[hop] != '\0' && op[hop] != '(' && hop != -1){
            while(op[hop] != '(' && hop != -1){
                expp[++ hexp] = op[hop --];
            }
            op[++ hop] = ch;
        }
        else if(ch >= '0' && ch <= '9'){
            while(ch >= '0' && ch <= '9'){
                expp[++ hexp] = ch;
                ch = str[hstr ++];
            }
            expp[++ hexp] = '#';
            hstr --;  // ch在循环结束多 ++ 了一次，所以在 -- 回去

            // printf("str:%c  op:%c  expp:%c  \n\n", str[hstr], op[hop], expp[hexp]);
        }
        else if(ch == '('){
            op[++ hop] = '(';
        }
        else if(ch == ')'){
            do{
                ch = op[hop --];
                expp[++ hexp] = ch;
            }while(ch != '(');
            expp[hexp --] = '\0';// 上面操作的时候不小心把 '(' 传到exp的栈顶了，现在再把它删掉
        }
        // printf("str:%c  op:%s  expp:%s  \n\n", ch, op, expp);
    }
    while(hop != -1){
        expp[++ hexp] = op[hop --];
    }

    // cout << expp << endl;
    printf("%s\n%s\n", expp, str);


    int num[N], hnum=-1;
    char ch;
    int n;
    for(int i=0; i<=hexp; i++){
        ch = expp[i];
        
        if(ch >= '0' && ch <= '9'){
            n = ch - '0';
            while((ch = expp[++ i]) != '#'){
                n = n * 10 + ch - '0';
            }
            num[++ hnum] = n;
        }
        else if(ch == '+'){
            num[hnum - 1] += num[hnum];
            hnum --;
        }
        else if(ch == '-'){
            num[hnum - 1] -= num[hnum];
            hnum --;
        }
        else if(ch == '*'){
            num[hnum - 1] *= num[hnum];
            hnum --;
        }
        else if(ch == '/'){
            num[hnum - 1] /= num[hnum];
            hnum --;
        }
        for(int i=0; i<=hnum; i++) printf("%d ", num[i]);
        puts("");
    }
    printf("######  %d  #####\n", num[hnum]);

}