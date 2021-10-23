#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,ans,f1[2][100005],f2[2][100005],c1=1,c2=1,sum=0,b;
pair<int,int> a1[100005],a2[100005];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1; i<=m1; ++i) scanf("%d%d",&a1[i].first,&a1[i].second);
	for(int i=1; i<=m2; ++i) scanf("%d%d",&a2[i].first,&a2[i].second);
	sort(a1+1,a1+1+m1),sort(a2+1,a2+1+m2);
	for(int i=1; i<=m1; ++i)
		for(int j=1; j<=c1+1; ++j)
		{
			if(f1[0][j]<a1[i].first)
			{
				++f1[1][j],f1[0][j]=a1[i].second;
				if(j==c1+1) c1+=1;
				break;
			}
		}
	for(int i=1; i<=m2; ++i)
		for(int j=1; j<=c2+1; ++j)
		{
			if(f2[0][j]<a2[i].first)
			{
				++f2[1][j],f2[0][j]=a2[i].second;
				if(j==c2+1) c2+=1;
				break;
			}
		}
	for(int i=1; i<=n; ++i) sum+=f1[1][i];
	ans=sum;
	for(int i=n,j=1; i>0; ++j,--i) sum=sum-f1[1][i]+f2[1][j],ans=max(ans,sum);
	printf("%d",ans);
	return 0;
}
