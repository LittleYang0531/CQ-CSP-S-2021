#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 100005,M = N*2;
class Ayaka{
	public:
		int l,r;
		Ayaka(int l_=0,int r_=0):l(l_),r(r_){}
}airin[N],airout[N];
vector<int> ha;
int hamaxm;
int d[M];
int din[M];
vector<int> dout[M];
int b[M];
int n,m1,m2;

inline int h(int x){
	return lower_bound(ha.begin(),ha.end(),x)-ha.begin()+1;
}

inline void init(){
	sort(ha.begin(),ha.end());
	ha.erase(unique(ha.begin(),ha.end()),ha.end());
	hamaxm = ha.size();
	for(int k=1;k<=m1;k++){
		airin[k].l = h(airin[k].l);
		airin[k].r = h(airin[k].r);
	}
	for(int k=1;k<=m2;k++){
		airout[k].l = h(airout[k].l);
		airout[k].r = h(airout[k].r);
	}
}

inline int findmax(Ayaka *airall,int len){
	memset(d,0,sizeof(d));
	for(int k=1;k<=len;k++){
		d[airall[k].l]++;
		d[airall[k].r]--;
	}
	int ans = 0,tmp = 0;
	for(int k=1;k<=hamaxm;k++){
		tmp += d[k];
		ans = max(ans,tmp);
	}
	return ans;
}

inline int check(Ayaka *airall,int wei,int len){
	ll tmpans = 0;
	memset(din,0,sizeof(din));
	for(int k=1;k<=hamaxm;k++)
		dout[k].clear();
	memset(b,false,sizeof(b));
	for(int k=1;k<=wei;k++){
		din[airall[k].l]++;
		dout[airall[k].r].push_back(k);
	}
	int tmp = 0;
	for(int k=1;k<=hamaxm;k++){
		if(dout[k].size())
			for(auto x:dout[k])
				if(b[airall[x].l]){
					tmp--;
					b[airall[x].l]--;
				}
		int tmpc = min(len-tmp,din[k]);
		tmp += tmpc;
		b[k] += tmpc;
		if(tmp==len)
			tmpans += din[k]-tmpc;
	}
	return tmpans;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int k=1;k<=m1;k++){
		scanf("%d%d",&airin[k].l,&airin[k].r);
		ha.push_back(airin[k].l);
		ha.push_back(airin[k].r);
	}
	for(int k=1;k<=m2;k++){
		scanf("%d%d",&airout[k].l,&airout[k].r);
		ha.push_back(airout[k].l);
		ha.push_back(airout[k].r);
	}
	init();
	if(n<=5000){
		int ans = 0;
		for(int k=0;k<=n;k++)
			ans = max(ans,m1+m2-check(airin,m1,k)-check(airout,m2,n-k));
		printf("%d",ans);
		return 0;
	}
	int len1 = findmax(airin,m1);
	len1 = min(len1,n);
	int len2 = findmax(airout,m2);
	len2 = min(len2,n);
	int ans = 0;
	ans = max(ans,m1+m2-check(airin,m1,len1)-check(airout,m2,n-len1));
	ans = max(ans,m1+m2-check(airin,m1,n-len2)-check(airout,m2,len2));
	if(n&1){
		ans = max(ans,m1+m2-check(airin,m1,n>>1)-check(airout,m2,(n>>1)+1));
		ans = max(ans,m1+m2-check(airin,m1,(n>>1)+1)-check(airout,m2,n>>1));
	}
	else
		ans = max(ans,m1+m2-check(airin,m1,n>>1)-check(airout,m2,n>>1));
	printf("%d",ans);
	return 0;
}
/*
3 5 4 
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16

2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10


*/
