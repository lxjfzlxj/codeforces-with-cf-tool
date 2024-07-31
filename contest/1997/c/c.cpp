# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
char s[N];
int n,sta[N],top;
long long ans;
long long calc() {
    top=0;
    long long ans=0;
    for(int i=1;i<=n;i++) {
        if(s[i]=='(') sta[++top]=i;
        else ans+=i-sta[top], top--;
    }
    return ans;
}
void dfs(int x,int sum) {
    if(ans!=-1) return;
    if(sum<0) return;
    if(x>n) {
        ans=calc();
        return;
    }
    if(x%2==0) {
        if(s[x]=='(') dfs(x+1,sum+1);
        else dfs(x+1,sum-1);
    } else {
        if(sum>0) s[x]=')', dfs(x+1,sum-1);
        s[x]='('; dfs(x+1,sum+1);
    }
}
void _() {
    // int i;
    scanf("%d%s",&n,s+1);
    ans=-1; dfs(1,0);
    printf("%lld\n",ans);
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
