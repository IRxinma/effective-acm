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
/*
���⣺
����n����������Ҫɾһ������ɾÿ�����ĸ�����һ���ģ���������ɾһ��ֵ�������������ֵ����������Ƕ��٣�
��Ϊ���ľ���������𰸳�n
*/
const int maxn = 1e5+10;
int a[maxn], pre[maxn], suf[maxn];
int main(){
    int t, n;
    scanf("%d", &t);
    while(t --){
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) scanf("%I64d", &a[i]);
        memset(pre,0,sizeof(pre));
        memset(suf,0,sizeof(suf));
        for(int i = 2; i <= n; i ++){
            pre[i] = abs(a[i] - a[i-1]);
            pre[i] = max(pre[i], pre[i-1]);
        }
        for(int i = n-1; i >=1; i --){
            suf[i] = abs(a[i+1] - a[i]);
            suf[i] = max(suf[i], suf[i+1]);
        }
        ll ans = 0;
        for(int i = 1; i <= n; i ++){
            if(i == 1) ans += suf[2];
            else if(i == n) ans += pre[n-1];
            else{
                ans += max(abs(a[i+1]-a[i-1]), max(pre[i-1], suf[i+1]));
            }
            //cout << ans << endl;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
