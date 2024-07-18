# include <bits/stdc++.h>
# define report (args...) return printf(args), void()
# define N 1000010
int a[N],ans[66];
void _() {
    int k,i,j,sum=0,Ans=0;
    scanf("%d",&k);
    for(i=1;i<=k;i++) {
        scanf("%d",a+i);
        sum+=a[i];
        for(int j=1;j<a[i];j++) scanf("%*d");
    }
    for(i=0;(1<<i)<=sum;i++) ans[i]=0;
    for(i=1;i<=k;i++) {
        for(j=0;(1<<j)<=sum;j++) {
            if((a[i]>>j)&1) {
                if(!ans[j]) ans[j]=1<<j;
                else ans[j]=(1<<j+1)-1;
            }
        }
    }
    for(i=0;(1<<i)<=sum;i++) Ans|=ans[i];
    printf("%d\n",Ans);
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
