#include<bits/stdc++.h>
using namespace std;
const int NN=1e5+7;

int n,m1,m2;
struct XX{
	int st,end;
	bool operator<(const XX &b) const 
	{
		return st<b.st;
	}
}a1[NN];
XX a2[NN];
typedef pair<int,int>X;
priority_queue<X,vector<X>,greater<X> >q;

int find1(int n1)
{
	if(n1==0)
		return 0;
	while(!q.empty()) 
		q.pop();
	int t=1,num=1;//num记录有多少停在廊桥 
	
	q.push(make_pair(a1[1].end,a1[1].st));//以到达时间入队 
	n1--;//廊桥位置-1 
	while(t!=m1)
	{
		t++;
		if(n1!=0)//廊桥还有，就去廊桥 
		{
			q.push(make_pair(a1[t].end,a1[t].st));
			n1--;//廊桥位置-1 
			num++;
			continue;
		}
		
		X a=q.top();//取一个离开时间最小的 
		q.pop();
		if(a1[t].st>=a.first)
			q.push(make_pair(a1[t].end,a1[t].st)),num++;
		else
			q.push(make_pair(a.first,a.second));
	}
	return num;
}

int find2(int n2)
{
	if(n2==0)
		return 0;
	while(!q.empty()) 
		q.pop();
	int t=1,num=1;//num记录有多少停在廊桥 
	
	q.push(make_pair(a2[1].end,a2[1].st));//以到达时间入队 
	n2--;//廊桥位置-1 
	while(t!=m2)
	{
		t++;
		
		if(n2!=0)//廊桥还有，就去廊桥 
		{
			q.push(make_pair(a2[t].end,a2[t].st));
			n2--;//廊桥位置-1 
			num++;
			continue;
		}
		
		X a=q.top();//取一个离开时间最小的 
		q.pop();
		if(a2[t].st>=a.first)
			q.push(make_pair(a2[t].end,a2[t].st)),num++;
		else
			q.push(make_pair(a.first,a.second));
	}
	return num;
}

int ans;

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	ios::sync_with_stdio(false);

	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
		cin>>a1[i].st>>a1[i].end;//国内 
	for(int i=1;i<=m2;i++)
		cin>>a2[i].st>>a2[i].end;//国际 
	
	if(n>=m1+m2)//特判  
	{
		cout<<m1+m2<<endl;
		return 0;
	}
	
	sort(a1+1,a1+1+m1);
	sort(a2+1,a2+1+m2);
	for(int i=0;i<=n;i++)
	{
		int n1=i;
		int n2=n-i;
		int num=find1(n1);
		num+=find2(n2);
		ans=max(ans,num);
	}
	cout<<ans<<endl;
	return 0;
}
