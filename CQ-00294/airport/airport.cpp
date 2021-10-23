#include<bits/stdc++.h>
#define van long long
using namespace std;

//bool ppppp;time_t st=clock();
ifstream ywhin("airport.in");
ofstream ywhout("airport.out");
const van MaxN=1e5+10;
struct node {
	van st,en;
}Nation[MaxN],Abroad[MaxN];
map<van,pair<van,van> > Tk;
van n,m1,m2;bool Used[MaxN];
van sum1[MaxN],sum2[MaxN];
//bool pppppp;

//void Output_Runner_Information() {
//	cout<<"Memory Usage: "<<(&pppppp-&ppppp)/1024.0/1024.0<<"MB"<<endl;
//	cout<<"Time Usage: "<<(clock()-st)/1000.0<<"s"<<endl;
//}
bool cmp(node a,node b) {
	if (a.st==b.st) return a.en<b.en;
	return a.st<b.st;
}

int main() {
	ywhin>>n>>m1>>m2;
	for (int i=1;i<=m1;i++) 
		ywhin>>Nation[i].st>>Nation[i].en;
	for (int i=1;i<=m2;i++) 
		ywhin>>Abroad[i].st>>Abroad[i].en;
	sort(Nation+1,Nation+m1+1,cmp);
	sort(Abroad+1,Abroad+m2+1,cmp);
	for (int i=1;i<=m1;i++) {
		Tk.insert(make_pair(Nation[i].st,make_pair(i,Nation[i].en)));
	}van cnt=1;
	for (int i=1;i<=m1;i++) {
		if (!Used[i]) {
			Used[i]=1;sum1[cnt]=1;
			van nowt=Nation[i].en;
			map<van,pair<van,van> >::iterator it=Tk.begin();
			do {
				it=Tk.lower_bound(nowt);
				if (it!=Tk.end()) {
					van id=(*it).second.first;
					Used[id]=1;
					nowt=(*it).second.second;
					sum1[cnt]++;
					Tk.erase(it);
				}
			}while (it!=Tk.end());
			cnt++;
		}
	}
	while (!Tk.empty()) Tk.erase(Tk.begin());
	for (int i=1;i<=m2;i++) {
		Tk.insert(make_pair(Abroad[i].st,make_pair(i,Abroad[i].en)));
	}cnt=1;memset(Used,0,sizeof Used);
	for (int i=1;i<=m2;i++) {
		if (!Used[i]) {
			Used[i]=1;sum2[cnt]=1;
			van nowt=Abroad[i].en;
			map<van,pair<van,van> >::iterator it=Tk.begin();
			do {
				it=Tk.lower_bound(nowt);
				if (it!=Tk.end()) {
					van id=(*it).second.first;
					Used[id]=1;
					nowt=(*it).second.second;
					sum2[cnt]++;
					Tk.erase(it);
				}
			}while (it!=Tk.end());
			cnt++;
		}
	}
//	for (int i=1;i<=n;i++) cout<<sum1[i]<<" ";cout<<endl;
//	for (int i=1;i<=n;i++) cout<<sum2[i]<<" ";cout<<endl;
	for (int i=1;i<=n;i++) sum1[i]+=sum1[i-1],sum2[i]+=sum2[i-1];
	van ans=0;for (int i=0;i<=n;i++) {
		ans=max(ans,sum1[i]+sum2[n-i]);
	}
	ywhout<<ans<<endl;
//	Output_Runner_Information();
	return 0;
}
