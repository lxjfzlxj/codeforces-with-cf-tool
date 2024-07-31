# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
char s[20];
void _() {
    scanf("%s",s+1);
    int n=strlen(s+1),pos=1;
    int i;
    for(i=1;i<n;i++) if(s[i]==s[i+1]) pos=i;
    for(i=1;i<=pos;i++) putchar(s[i]);
    if(s[pos]!='a' && s[pos+1]!='a') putchar('a');
    else if(s[pos]!='b' && s[pos+1]!='b') putchar('b');
    else putchar('c');
    for(int i=pos+1;s[i];i++) putchar(s[i]);
    puts("");
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
