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
const int maxn = 2e5+10;
ll a[maxn];
ll n, m, k;
int main(){
    int t;
    scanf("%d", &t);
    while(t --){
        scanf("%I64d%I64d%I64d", &n, &m, &k);
        for(int i = 1; i <= n; i ++){
            scanf("%I64d", &a[i]);
            if(a[i] >= m) a[i] = 1;
            else a[i] = 0;
            a[i] += a[i-1];
        }
        int r = 1;
        ll ans = 0;
        for(int i = 1; i <= n; i ++){
            while(r <= n && a[r] - a[i-1] < k) r ++;
            ans += n-r+1;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
