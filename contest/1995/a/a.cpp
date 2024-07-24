# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 110
int a[N<<1],a_n;
void _() {
    int n,k,i,sum;
    scanf("%d%d",&n,&k);
    if(!k) report("0\n");
    a_n=0;
    for(i=1;i<=n;i++) a[++a_n]=i, a[++a_n]=i;
    a_n--;
    std::sort(a+1,a+a_n+1,[](const int &i,const int &j) {return i>j;});
    for(i=1,sum=0;i<=a_n;i++) {
        sum+=a[i];
        if(sum>=k) break;
    }
    printf("%d\n",i);
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
