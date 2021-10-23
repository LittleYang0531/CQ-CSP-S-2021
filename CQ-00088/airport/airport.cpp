#include<bits/stdc++.h>
using namespace std;
struct times{
	int a,g;
};
bool cmp(times a,times b)
{
	return a.a<b.a;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int ld,gn,gw;
	cin>>ld>>gn>>gw;
	times p[gn],p1[gw];
	int dl[100000]={0},last[100000]={-1},t1=0,t2=0,lasts[100000]={-1},dl1[100000]={0},tot=0;
	for(int a=0;a<gn;a++)
	{
		cin>>p[a].a>>p[a].g;
	}
	sort(p,p+gn,cmp);
	for(int a=0;a<gw;a++)
	{
		cin>>p1[a].a>>p1[a].g;
	}
	sort(p1,p1+gw,cmp);
	for(int g=0;g<gn;g++)
	{
		int a=p[g].a,b=p[g].g,tag=0;
		for(int c=0;c<=t1;c++)
		{
			if(last[c]<a)
			{
				tag=1;
				last[c]=b;
				dl[c]++;
				if(c<ld)
				{
					tot++;
				}
				break;
			}
		}
		if(!tag)
		{
			if(t1>=ld-1)
			{
				continue;
			}
			t1++;
			dl[t1]=1;
			last[t1]=b;
			tot++;
		}
	}
	for(int g=0;g<gw;g++)
	{
		int a=p1[g].a,b=p1[g].g,tag=0;
		for(int c=0;c<=t2;c++)
		{
			if(lasts[c]<a)
			{
				tag=1;
				lasts[c]=b;
				dl1[c]++;
				break;
			}
		}
		if(!tag)
		{
			t2++;
			dl1[t2]=1;
			lasts[t2]=b;
		}
	}
	int m=-1;
	for(int a=0;a<ld;a++)
	{
		if(tot>m)
		{
			m=tot;
		}
		if(t1>=ld-1)tot-=dl[t1-a];
		else t1++;
		tot+=dl1[a];
	}
	cout<<m;
	return 0;
}
