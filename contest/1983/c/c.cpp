# include <bits/stdc++.h>
# define N 200010
int a[N],b[N],c[N],la,lb,lc,ra,rb,rc;
long long sa[N],sb[N],sc[N];
void _() {
	int n,i;
	long long key;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i), sa[i]=sa[i-1]+a[i];
	for(i=1;i<=n;i++) scanf("%d",b+i), sb[i]=sb[i-1]+b[i];
	for(i=1;i<=n;i++) scanf("%d",c+i), sc[i]=sc[i-1]+c[i];
	key=(sa[n]+2)/3;
	for(i=1;i<=n && sa[i]<key;i++);
	la=i;
	for(i=1;i<=n && sb[i]<key;i++);
	lb=i;
	for(i=1;i<=n && sc[i]<key;i++);
	lc=i;
	for(i=n;i>=1 && sa[n]-sa[i-1]<key;i--);
	ra=i;
	for(i=n;i>=1 && sb[n]-sb[i-1]<key;i--);
	rb=i;
	for(i=n;i>=1 && sc[n]-sc[i-1]<key;i--);
	rc=i;
	if(la<rb && sc[rb-1]-sc[la]>=key) return printf("%d %d %d %d %d %d\n",1,la,rb,n,la+1,rb-1), void();
	if(la<rc && sb[rc-1]-sb[la]>=key) return printf("%d %d %d %d %d %d\n",1,la,la+1,rc-1,rc,n), void();
	if(lb<ra && sc[ra-1]-sc[lb]>=key) return printf("%d %d %d %d %d %d\n",ra,n,1,lb,lb+1,ra-1), void();
	if(lb<rc && sa[rc-1]-sa[lb]>=key) return printf("%d %d %d %d %d %d\n",lb+1,rc-1,1,lb,rc,n), void();
	if(lc<ra && sb[ra-1]-sb[lc]>=key) return printf("%d %d %d %d %d %d\n",ra,n,lc+1,ra-1,1,lc), void();
	if(lc<rb && sa[rb-1]-sa[lc]>=key) return printf("%d %d %d %d %d %d\n",lc+1,rb-1,rb,n,1,lc), void();
	puts("-1");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}   