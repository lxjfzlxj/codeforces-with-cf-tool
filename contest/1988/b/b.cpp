# include <bits/stdc++.h>
# define report (args...) return printf(args), void()
# define N 200010
char s[N];
void _() {
    int n,i,cnt1=0,cnt0=0;
    scanf("%d%s",&n,s+1);
    for(i=1;i<=n;i++) if(s[i]=='1') cnt1++;
    for(i=1;i<=n;i++) if(s[i]=='0' && (i==1 || s[i-1]=='1')) cnt0++;
    puts(cnt0>=cnt1?"No":"Yes");
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
