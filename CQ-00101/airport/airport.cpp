#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+10;
pii org_line[N],line[N];
#define l first
#define r second

vector<int> vec;
int find(int x)
{
	return lower_bound(vec.begin(),vec.end(),x)-vec.begin();
}

bool vis[N];
int res[2][N],n,m1,m2;
int pts[2*N];

int cal(int limit,int m)
{
	memset(vis,0,sizeof vis);
	priority_queue<int,vector<int>,greater<int> >q;
	int sz=0,res=0;
	for(int i=0;i<m;i++)
	{
		while(sz&&q.top()<line[i].l)	q.pop(),sz--;
		if(sz<limit)	res++,sz++,q.push(line[i].r);
	}
	return res;
}

void solve(int m,int f[N])
{
	vec.clear();
	for(int i=0,a,b;i<m;i++)
	{
		scanf("%d %d",&a,&b);
		org_line[i]={a,b};
		vec.push_back(a),vec.push_back(b);
	}
	sort(vec.begin(),vec.end());
	sort(org_line,org_line+m);
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for(int i=0;i<m;i++)
	{
		line[i]={find(org_line[i].l),find(org_line[i].r)};
	}
	
	for(int i=n;~i;i--)
		f[i]=cal(i,m);
}

int main()
{
	freopen("airport.in","r",stdin);
//	freopen("E:\\CSP2021 S2\\airport\\airport3.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	solve(m1,res[0]),solve(m2,res[1]);
	int ans=-1;
	for(int i=0;i<=n;i++)
		ans=max(ans,res[0][i]+res[1][n-i]);
	cout<<ans<<endl;
	return 0;
}

