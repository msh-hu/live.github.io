#include<bits/stdc++.h>
using namespace std;

typedef queue<int> que;
typedef pair<que, int> PII;
PII h[3];
que hin, hout;
int temp, nowOut = 1, flag = 0;

const int N = 10;
PII *stk[5], *em[5];
int ids, ide;

int main(){
    freopen("4.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    while(n --){
        cin >> temp;
        hin.push(temp);
    }

    while(flag != m+1){
        flag = 0;
        if(!hin.empty() && hin.front() == nowOut){
            temp = hin.front();
            hin.pop();
            hout.push(temp);
            nowOut ++;
            continue;
        }
        if(hin.empty()) flag ++;

        // 说明入轨的队头元素不满足条件
        // 接下来判断缓冲轨的队头是否为 nowOut
        bool t = false; // 
        for(int i=1; i<=m; i++){
            if(!h[i].first.empty() && h[i].first.front() == nowOut){
                temp = h[i].first.front();
                h[i].first.pop();
                hout.push(temp);
                nowOut ++;
                t = true;
            }
            if(h[i].first.empty()) flag ++;
        }
        if(flag == m+1) break;
        if(t) continue;
        if(hin.empty()){
            printf("1. 无法重排，当前入轨元素%d\n", hin.front());
            break;
        }

        // 入缓冲轨操作
        if(hin.front() != nowOut){
            ids = ide = -1;
            for(int i=1; i<=m; i++){
                // 对将非空且满足条件的缓冲轨与空缓冲轨分离
                if(!h[i].first.empty() ){// 这里的{}不能去掉，否则else会和内部的if配对出现bug
                    if(hin.front() > h[i].second)stk[++ ids] = &h[i];
                }// else 会和上面距离其最近的if配对。
                
                else em[++ ide] = &h[i];
            }
            printf("ids = %d, ide = %d\n", ids, ide);
            // 开始对非空缓冲轨与空缓冲轨分别进行操作
            if(ids != -1){
                PII *max_tail = stk[0];
                for(int i=1; i<=ids; i++)
                    max_tail = (max_tail->second > stk[i]->second ? max_tail : stk[i]);
                temp = hin.front();
                hin.pop();
                max_tail->first.push(temp);
                max_tail->second = temp; // 标记尾巴
                continue;
            }
            else if(ide != -1){
                temp = hin.front();
                hin.pop();
                em[0]->first.push(temp);
                em[0]->second = temp;
                continue;
            }
            else{
                printf("2. 无法重排，当前入轨元素：%d\n", hin.front());
                break;
            }
        }
    }

    while(!hout.empty()){
        printf("%d ", hout.front());
        hout.pop();
    }
}
// 5 8 1 7 4 2 9 6 3