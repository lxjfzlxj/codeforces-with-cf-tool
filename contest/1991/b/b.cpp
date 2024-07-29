# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 100010
int a[N],b[N];
void _() {
    int n,i;
    scanf("%d",&n);
    a[n]=0;
    for(i=1;i<n;i++) scanf("%d",a+i);
    for(i=1;i<=n;i++) b[i]=a[i-1]|a[i];
    for(i=1;i<n && (b[i]&b[i+1])==a[i];i++);
    if(i==n) for(i=1;i<=n;i++) printf("%d ",b[i]);
    else printf("-1");
    puts("");
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
