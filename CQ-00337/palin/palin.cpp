#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e6+50;

int T,n;
vector<int>a;
int b[MAXN];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
	//	cout<<n<<endl;
		for(int i=1;i<=2*n;i++)
		{
			scanf("%d",&b[i]);
		}
		bool Can=0;
		for(long long i=0;i<(1ll<<(2*n));i++)
		{
		//	cout<<i<<endl;
			bool flag=false;
			a.clear();
			for(int j=2*n-1,l=1,r=2*n;j>=0;j--)
			{
				if((i>>j)&1)
				{
					a.push_back(b[r]);
					r--;
				}
				else
				{
					a.push_back(b[l]);
					l++;
				}
			}
//			for(int i=0;i<40;i++)
//			cout<<a[i]<<" ";
//			cout<<endl; 
			//cout<<a.size()<<endl;
			for(int l=0,r=2*n-1;l<r;l++,r--)
			{
				if(a[l]!=a[r])
				{ 
					flag=true;
					break;
				}
			}
			if(flag==false)
			{
				for(int j=2*n-1;j>=0;j--)
				{
					if((i>>j)&1)
					putchar('R');
					else
					putchar('L');
				}
				Can=true;
				putchar('\n');
				break;
			}
		}
		if(Can==false)
		{
			printf("-1\n");
		}
	
	}
	return 0;
}
