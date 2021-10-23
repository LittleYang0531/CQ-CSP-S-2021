#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn=1e6+10;
int a[maxn],b[maxn],bin[50];
char ch[maxn];
inline bool check(){
	int l=0,r=n-1;
	for(int i=0;i<n;++i)
	{
		if(ch[i]=='L')	b[i]=a[l++];
		else	b[i]=a[r--];
	}
	for(int i=0;i<n;++i)
	{
		if(b[i]!=b[n-i-1])	return false;
	}
	return true;
}
int flag;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out ","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(ch,0,sizeof(ch));
		flag=0;
		scanf("%d",&n);
		n*=2;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
			bin[i]=1<<i;
		}
		bin[n]=1<<n,bin[n+1]=1<<(n+1);
		for(int i=0;i<bin[n];++i)
		{
			for(int j=0;j<n;++j)
			{
				if(i&bin[j])	ch[n-j-1]='R';
				else
				{
					ch[n-j-1]='L';
				}
			}
			if(check())
			{
//				for(int i=0;i<n;++i)	cout<<b[i]<<" ";
//				puts("");
				printf("%s\n",ch);
				flag=1;
				break;
			}
		}
		if(flag==0)	printf("-1\n");
	}

	return 0;
}
