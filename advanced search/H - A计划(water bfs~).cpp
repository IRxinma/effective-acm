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
char p[2][11][11];
struct node{
    int x, y, h, step;
};
node s, P;
int dir[4][2] = {1,0,0,1,-1,0,0,-1};
int n, m, k;
bool vis[2][11][11];

void bfs(){
    memset(vis, false, sizeof(vis));
    queue<node> q;
    s.x=0; s.y=0; s.h=0; s.step=0;
    vis[s.h][s.x][s.y] = true;
    q.push(s);
    while(!q.empty()){
        node t = q.front(); q.pop();
        if(t.x==P.x && t.y==P.y && t.h==P.h){
            //cout << t.step << endl;
            if(t.step <= k) printf("YES\n");
            else printf("NO\n");
            return ;
        }
        if(p[t.h][t.x][t.y] == '#'){
            if(p[1-t.h][t.x][t.y] != '#'){
                t.h = 1-t.h;
                //t.step ++;
                q.push(t);
            }
            continue;
        }
        for(int i = 0; i< 4; i ++){
            node tt = t;
            tt.x += dir[i][0];
            tt.y += dir[i][1];
            if(tt.x<0 || tt.x>=n || tt.y<0 || tt.y>=m) continue;
            if(vis[tt.h][tt.x][tt.y] || p[t.h][t.x][t.y] == '*') continue;
            vis[tt.h][tt.x][tt.y] = true;
            tt.step = t.step + 1;
            q.push(tt);
        }
    }
    printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t --){
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0; i < n; i ++){
            scanf("%s", p[0][i]);
            for(int j = 0; j < m; j ++){
                if(p[0][i][j] == 'P') P.x=i,P.y=j,P.h=0;
            }
        }
        for(int i = 0; i < n; i ++){
            scanf("%s", p[1][i]);
            for(int j = 0; j < m; j ++){
                if(p[1][i][j] == 'P') P.x=i,P.y=j,P.h=1;
            }
        }
        //cout << P.h << P.x << P.y << endl;
        bfs();
    }
    return 0;
}
