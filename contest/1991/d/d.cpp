# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
void _() {
    int n,i;
    scanf("%d",&n);
    if(n==1) puts("1\n1");
    else if(n==2) puts("2\n1 2");
    else if(n==3) puts("2\n1 2 2");
    else if(n==4) puts("3\n1 2 2 3");
    else if(n==5) puts("3\n1 2 2 3 3");
    else {
        puts("4");
        for(i=1;i<=n;i++) printf("%d ",(i-1)%4+1);
        puts("");
    }
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
