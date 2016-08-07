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
ll n, m, x;
int main(){
    int t;
    scanf("%d", &t);
    while(t --){
        scanf("%I64d%I64d", &n, &m);
        ll ans = 0;
        for(ll i = 0; i < n; i ++){
            scanf("%I64d", &x); getchar();
            ans += x; //cout << ans << endl;
        }
        while(m --){
            scanf("%I64d", &x); getchar();
            if(x > ans) printf("1");
            else printf("0");
        }
        printf("\n");
    }
    return 0;
}
