#include<bits/stdc++.h>
#define N 2001
using namespace std;
int T,n,a[N],b[N],ansb[N];
char cz[N],anscz[N];
bool hw()
{
	for(int i=1;i<=n;i++)
	if(b[i]!=b[2*n-i+1])return 0;
	return 1;
}
bool fla;
void zz()
{
	if(hw())
	{
		fla=1;
		for(int i=1;i<=2*n;i++)
		ansb[i]=b[i],anscz[i]=cz[i];
	}
}
int l,r;
void dfs(int k)
{
	if(k>2*n)
	{
		zz();
		return;
	}
	cz[k]='L';
	b[k]=a[l++];
	if(!fla||b[k]<=ansb[k])
	dfs(k+1);
	l--;
	
	cz[k]='R';
	b[k]=a[r--];
	if(!fla||b[k]<=ansb[k])
	dfs(k+1);
	r++;
}
int main()
{
freopen("palin.in","r",stdin);
freopen("palin.out","w",stdout);
scanf("%d",&T);
while(T--)
{
fla=0;
scanf("%d",&n);
for(int i=1;i<=2*n;i++)
	scanf("%d",&a[i]);
l=1;r=2*n;
dfs(1);
if(!fla)printf("-1\n");
else
{
	for(int i=1;i<=2*n;i++)printf("%c",anscz[i]);
	printf("\n");
}


}
return 0;
}
