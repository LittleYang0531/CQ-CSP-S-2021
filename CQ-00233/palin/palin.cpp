#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int T,n;
int f[N],a[N],b[N];
string ch;

signed main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		ch[0]='z';
		int sn=0;
		string s;
		for(int i=1;i<=2*n;i++)
		{
			scanf("%lld",&f[i]);
		}
		if(f[1]==f[2*n])
		{
			printf("-1");
			continue;
		}
		for(int i=0;i<=1048576;i++)
		{
//			cout<<1;
			for(int j=1;j<=2*n;j++)
				a[i]=f[i];
			memset(b,0,sizeof(b));
			int an=2*n,bn=0;
			int u=i,l=1,r=an;
			while(u!=0)
			{
				int v=u&1;
				if(v==0)
				{
					b[++bn]=a[l];
					l++;
				}
				else
				{
					b[++bn]=a[r];
					r--;
				}
				u>>=1;
			}
			int flag=0;
			for(int j=1,k=bn;j<=bn;j++,k--)
			{
				if(b[j]!=b[k])
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				u=i; sn=0;
				while(u!=0)
				{
					int v=u&1;
					if(v==0)
						s[sn++]='L';
					else
						s[sn++]='R';
					u>>=1;
				}
				for(int i=sn-1;i<2*n;i++)
					s[i]='L';
				ch=min(s,ch);
			}
		}
		if(ch[0]=='z')
		{
			printf("-1\n");
			continue;
		}
		else
		{
			for(int i=0;i<2*n;i++)
			{
//				if(i>=sn) cout<<"L";
				printf("%c",s[i]);
			}
			printf("\n");
		}
	}
	return 0;
 } 
