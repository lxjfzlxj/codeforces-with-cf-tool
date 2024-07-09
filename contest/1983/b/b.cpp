# include <bits/stdc++.h>
# define N 510
char s[N][N],t[N][N];
void _() {
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(i=1;i<=n;i++) scanf("%s",t[i]+1);
	for(i=1;i<=n;i++) {
		int s1=0,s2=0;
		for(j=1;j<=m;j++) {
			s1=(s1+(s[i][j]-'0'))%3;
			s2=(s2+(t[i][j]-'0'))%3;
		}
		if(s1!=s2) return puts("NO"), void();
	}
	for(j=1;j<=m;j++) {
		int s1=0,s2=0;
		for(i=1;i<=n;i++) {
			s1=(s1+(s[i][j]-'0'))%3;
			s2=(s2+(t[i][j]-'0'))%3;
		}
		if(s1!=s2) return puts("NO"), void();
	}
	puts("YES");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}