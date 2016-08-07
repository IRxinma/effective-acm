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
//const int maxn = 101;
struct castle{
    int x, y, period, v, dir;
};
castle cas[101];
struct node{
    int x, y, engry;
};
node girl;
int dir[][2] = {-1,0,0,-1,1,0,0,1,0,0};
bool vis[101][101][1001];
int n, m, k, engry;

void init(){
    for(int i = 0; i < k; i ++){
        int state = 0;
        int x = cas[i].x, y = cas[i].y;
        int d = cas[i].dir;
        while(1){
            ++ state;
            x += dir[d][0]; y += dir[d][1];
            if(x < 0 || x > n || y < 0 || y > m || (!vis[x][y][0])) //here is castle.
                break;
            if(!(state % cas[i].v)){
                for(int j = state/cas[i].v; j <= engry; j += cas[i].period)
                    vis[x][y][j] = false;
            }
        }
    }
}

void bfs(){
    queue<node> q;
    girl.x = 0; girl.y = 0; girl.engry = 0;
    //vis[0][0][0] = false;
    q.push(girl);
    while(!q.empty()){
        node t = q.front(); q.pop();
        if(t.x == n && t.y == m){
            printf("%d\n", t.engry);
            return ;
        }
        if(t.engry == engry){
            printf("Bad luck!\n");
            return ;
        }
        if(n-t.x+m-t.y > engry-t.engry) continue; //manhadon
        node tmp = t;
        tmp.engry ++;
        for(int i = 0; i < 5; i ++){
            //tmp.x += dir[i][0];
            //tmp.y += dir[i][1];
            tmp.x = t.x + dir[i][0];
            tmp.y = t.y + dir[i][1];
            if(tmp.x < 0 || tmp.x > n || tmp.y < 0 || tmp.y > m || (!vis[tmp.x][tmp.y][tmp.engry]))
                continue;
            vis[tmp.x][tmp.y][tmp.engry] = false;
            q.push(tmp);
        }
    }
    printf("Bad luck!\n");
    return ;
}
int main(){
    while(~scanf("%d%d%d%d", &n, &m, &k, &engry)){
        memset(vis, true, sizeof(vis));
        for(int i = 0; i < k; i ++){
            char ch;
            scanf(" %c", &ch);
            if(ch == 'N') cas[i].dir = 0;
            else if(ch == 'W') cas[i].dir = 1;
            else if(ch == 'S') cas[i].dir = 2;
            else cas[i].dir = 3;
            scanf("%d%d%d%d", &cas[i].period, &cas[i].v, &cas[i].x, &cas[i].y);
            for(int j = 0; j <= engry; j ++)
                vis[cas[i].x][cas[i].y][j] = false;
        }
        init();
        bfs();
    }
    return 0;
}
