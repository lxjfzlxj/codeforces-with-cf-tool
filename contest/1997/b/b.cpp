# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
char s[3][N];
void _() {
    int n,i,ans=0;
    scanf("%d%s%s",&n,s[1]+1,s[2]+1);
    for(i=2;i<n;i++) {
        if(s[1][i]=='.' && s[2][i]=='.' && s[1][i-1]=='.' && s[2][i-1]=='x' && s[1][i+1]=='.' && s[2][i+1]=='x') ans++;
        if(s[2][i]=='.' && s[1][i]=='.' && s[1][i-1]=='x' && s[2][i-1]=='.' && s[1][i+1]=='x' && s[2][i+1]=='.') ans++;
    }
    printf("%d\n",ans);
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
