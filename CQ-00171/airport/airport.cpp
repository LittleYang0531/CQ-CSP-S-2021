#include <bits/stdc++.h>
using namespace std;
int n,m1,m2;
struct yu {
	int va;
	bool operator < (const yu &b)const {
		return va>b.va;
	}
};
struct ae {
	int l,r;
	bool operator < (const ae &b)const {
		return l<b.l;
	}
} inp1[100010],inp2[100010];
priority_queue<yu> wa1,wa2;
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) {
		scanf("%d%d",&inp1[i].l,&inp1[i].r);
	}
	for(int i=1;i<=m2;i++) {
		scanf("%d%d",&inp2[i].l,&inp2[i].r);
	}
	sort(inp1+1,inp1+1+m1);sort(inp2+1,inp2+1+m2);
	int Ansm=0;
	for(int u=0;u<=n;u++) {
		while(!wa1.empty()) wa1.pop();
		while(!wa2.empty()) wa2.pop();
		int a=u,b=n-u,ans1=0,ans2=0;
		for(int i=1;i<=m1;i++) {
			while(!wa1.empty()) {
				if(wa1.top().va<inp1[i].l) wa1.pop();
				else break;
			}
			if(wa1.size()<a) {
				wa1.push((yu){inp1[i].r});ans1++;
			}
		}
		for(int i=1;i<=m2;i++) {
			while(!wa2.empty()) {
				if(wa2.top().va<inp2[i].l) wa2.pop();
				else break;
			}
			if(wa2.size()<b) {
				wa2.push((yu){inp2[i].r});ans2++;
			}
		}
		Ansm=max(Ansm,ans1+ans2);
	}
	printf("%d\n",Ansm);
	return 0;
}
