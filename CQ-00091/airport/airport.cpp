#include<cstdio>
#include<queue>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<cmath>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+(ch-48);
		ch=getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x)write(x/10);
	putchar(x%10+48);
}
#define pp pair<int,int>
#define mp make_pair
int n,m1,m2,ans1[100005],ans2[100005];
set<pp>S1,S2;
signed main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++){
		int l=read(),r=read();
		S1.insert(mp(l,r));
	}
	for(int i=1;i<=m2;i++){
		int l=read(),r=read();
		S2.insert(mp(l,r));
	}
	for(int i=1;i<=n;i++){
		ans1[i]=ans1[i-1];
		int r=0;
		while(S1.size()){
			pp now=*S1.lower_bound(mp(r+1,r+1));
			if(S1.lower_bound(mp(r+1,r+1))!=S1.end()){
				ans1[i]++;
				S1.erase(S1.lower_bound(now));
				r=now.second;
			}else break;
		}
	}
	for(int i=1;i<=n;i++){
		ans2[i]=ans2[i-1];
		int r=0;
		while(S2.size()){
			pp now=*S2.lower_bound(mp(r+1,r+1));
			if(S2.lower_bound(mp(r+1,r+1))!=S2.end()){
				ans2[i]++;
				S2.erase(S2.lower_bound(now));
				r=now.second;
			}else break;
		}
	}
	int maxx=0;
	for(int i=0;i<=n;i++)maxx=max(maxx,ans1[i]+ans2[n-i]);
	printf("%d\n",maxx);
	return 0;
}

