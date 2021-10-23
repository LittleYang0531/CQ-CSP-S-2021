#include<bits/stdc++.h>
using namespace std;
int i,j,t,n,a[105],q[105],cnt=0,flag=0,ans_cnt=0;
char s[105],ans[105];
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(q[i]!=q[2*n-i+1]) return false;
	}
	return true;
}
void work(int x)
{
	if(flag) return;
	if(x==27||i-1>j) 
	{
	return;
	}//时间要爆了 
	if(x==2*n+1&&check()) {
		for(int i=1;i<=cnt;i++)
		{
		ans[i]=s[i];
		}
		flag=1;
		ans_cnt=cnt;
		return;
	}
	q[++cnt]=a[i];i++;s[cnt]='L';
	work(x+1);
	i--;cnt--;
	q[++cnt]=a[j];j--;s[cnt]='R';
	work(x+1);
	j++;cnt--;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
	cnt=0,ans_cnt=0;
	scanf("%d",&n);
	i=1,j=2*n,flag=0;
	for(int k=1;k<=2*n;k++) scanf("%d",&a[k]);
	work(1);
	if(flag)
	{
	for(int i=1;i<=ans_cnt;i++)	cout<<ans[i];
	cout<<endl;
	}
	else cout<<-1<<endl;
	}
	return 0;
}
