# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 60
int a[N],buc[N];
void _() {  
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) buc[i]=0;
    for(i=1;i<=n;i++) scanf("%d",a+i), buc[a[i]]++;
    for(i=n;i>=1 && buc[i]%2==0;i--);
    if(i<1) puts("NO");
    else puts("YES");
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
