#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<cstdlib>
#include<stack>
#include<climits>
#include<vector>
#include<string>
#include<map>
using namespace std;
typedef long long ll;
const int mod = 1e6+7;
struct node{
    int step;
    int p[10][10];
};
node t, tt;
int aim[4][8];
bool vis[mod];
long long gethash(node &t){
    int has[70], k = 0;
    for(int i = 0; i < 4; i ++){
        for(int j = 0; j <= 8; j ++){
            has[k++] = t.p[i][j]/10;
            has[k++] = t.p[i][j]%10;
        }
    }
    ll ans = 0;
    for(int i = 0; i < k; i++)
        ans = ans*7+has[i];
    ans = (ans & 0x7fffffff)%mod;
    //ans %= mod;
    return ans;
}

bool judge(node &t){ //---------
    /*for(int i = 0; i < 4; i ++){
        for(int j = 0; j<8; j++)
            printf("%d",t.p[i][j]);
        printf("\n");
    }
    for(int i = 0; i < 4; i ++){
        for(int j = 0; j<8; j++)
            printf("%d",aim[i][j]);
        printf("\n");
    }*/
    for(int i = 0; i < 4; i ++)
        for(int j = 0; j < 8; j++)
            if(t.p[i][j] != aim[i][j])
                return false;
    return true;
}

void change(node &t, int num){
    for(int i = 0; i < 4; i ++)
    for(int j = 0; j < 8; j ++)
        if(t.p[i][j] == num+1){
            t.p[i][j] = 0;
            return ;
        }
}

void bfs(){
    memset(vis, false, sizeof(vis));
    queue<node> q;
    t.p[0][0]=11; t.p[1][0]=21; t.p[2][0]=31; t.p[3][0]=41; t.step=0;
    int has_t = gethash(t); //cout << has_t << endl;
    vis[has_t] = true;
    q.push(t);
    while(!q.empty()){
        node t = q.front(); q.pop();
        if(judge(t)){printf("%d\n", t.step); return ;}
        for(int i=0; i<4; i++){
            for(int j=1; j<8; j++){
                if(t.p[i][j]==0 && t.p[i][j-1]%10!=7 && t.p[i][j-1]!=0){
                    node cur = t;
                    change(cur, cur.p[i][j-1]);
                    cur.p[i][j] = cur.p[i][j-1]+1;
                    cur.step ++;
                    int has_cur = gethash(cur); //cout << has_cur << endl;
                    if(vis[has_cur]) continue;
                    vis[has_cur] = true;
                    q.push(cur);
                }
            }
        }
    }
    printf("-1\n");
}

int main(){
    int ts;
    scanf("%d", &ts);
    memset(aim, 0, sizeof(aim));
    for(int i = 0; i < 4; i ++){
        for(int j = 0; j <= 7; j ++){
            aim[i][j] = (i+1)*10+j+1;
            if(j == 7) aim[i][j] = 0;
            //cout << (i+1)*10+j+1 << " ";
        }
        //cout << endl;
    }
    while(ts --){
        memset(t.p, 0, sizeof(t.p));
        for(int i = 0; i < 4; i ++){
            for(int j = 1; j <= 7; j ++){
                scanf("%d",&t.p[i][j]);
                if(t.p[i][j]%10 == 1){
                    t.p[i][j] = 0;
                }
            }
        }
        bfs();
    }
    return 0;
}
