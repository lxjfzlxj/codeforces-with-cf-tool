# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
char s[N],t[N];
void _() {
    int n,i;
    scanf("%d%s%s",&n,s+1,t+1);
    for(i=1;i<=n && s[i]=='0';i++) {
        if(t[i]!='0') report("NO\n");
    }
    puts("YES");
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
