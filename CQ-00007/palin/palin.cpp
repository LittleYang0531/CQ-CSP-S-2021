#include<iostream>
#include<cstdio>
using namespace std;
#define N 1000012
inline int re(){int x=0;char ch=getchar();while(ch<'0')ch=getchar();while('0'<=ch)x=x*10+(ch^'0'),ch=getchar();return x;}
int T,n,a[N],ans[N],an[N];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=re();
	while(T--)
	{
		n=re();int i,l,r,pl,pr,fl;
		for(i=1;i<=(n<<1);i++)a[i]=re();
		ans[1]=2;
		for(i=1;i<(n<<1);i++)
		if(a[i]==a[n<<1])
		{
			pl=i-1;pr=i+1;l=1;r=n<<1;an[1]=1;an[n<<1]=0;--r;fl=1;
			for(i=2;i<=n;i++)
			{
				if((l<pl)&&(a[l]==a[pl])){an[i]=0;an[(n<<1)-i+1]=0;++l;--pl;continue;}
				if((l<=pl)&&(a[l]==a[pr])){an[i]=0;an[(n<<1)-i+1]=1;++l;++pr;continue;}
				if((r>=pr)&&(a[r]==a[pl])){an[i]=1;an[(n<<1)-i+1]=0;--r;--pl;continue;}
				if((r>pr)&&(a[r]==a[pr])){an[i]=1;an[(n<<1)-i+1]=1;--r;++pr;continue;}
				fl=false;break;
			}
			if(!fl)break;
			for(i=1;i<=(n<<1);i++)if(an[i]!=ans[i]){if(an[i]<ans[i])for(i=1;i<=(n<<1);i++)ans[i]=an[i];break;}
			break;
		}
		for(i=2;i<=(n<<1);i++)
		if(a[i]==a[1])
		{
			pl=i-1;pr=i+1;l=1;r=n<<1;an[1]=0;an[n<<1]=0;++l;fl=1;
			for(i=2;i<=n;i++)
			{
				if((l<pl)&&(a[l]==a[pl])){an[i]=0;an[(n<<1)-i+1]=0;++l;--pl;continue;}
				if((l<=pl)&&(a[l]==a[pr])){an[i]=0;an[(n<<1)-i+1]=1;++l;++pr;continue;}
				if((r>=pr)&&(a[r]==a[pl])){an[i]=1;an[(n<<1)-i+1]=0;--r;--pl;continue;}
				if((r>pr)&&(a[r]==a[pr])){an[i]=1;an[(n<<1)-i+1]=1;--r;++pr;continue;}
				fl=false;break;
			}
			if(!fl)break;
			for(i=1;i<=(n<<1);i++)if(an[i]!=ans[i]){if(an[i]<ans[i]){for(i=1;i<=(n<<1);i++)ans[i]=an[i];}break;}
			break;
		}
		if(ans[1]==2){putchar('-');putchar('1');putchar('\n');}else{for(i=1;i<=(n<<1);i++)putchar(ans[i]?'R':'L');putchar('\n');}
	}return 0;
}
