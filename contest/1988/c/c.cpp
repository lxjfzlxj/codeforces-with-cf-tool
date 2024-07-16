# include <bits/stdc++.h>
# define report (args...) return printf(args), void()

void _() {
    long long n;
    int i;
    scanf("%lld",&n);
    std::vector<int> vec;
    for(i=60;i>=0;i--) {
        if((n>>i)&1) vec.push_back(i);
    }
    int siz=vec.size();
    if(siz==1) {
        puts("1");
        printf("%lld\n",n);
    } else {
        printf("%d\n",siz+1);
        for(i=0;i<siz;i++) {
            long long tp=0;
            for(int j=0;j<siz;j++) if(i!=j) tp|=1ll<<vec[j];
            printf("%lld ",tp);
        }
        printf("%lld\n",n);
    }
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
