#include<bits/stdc++.h>
#define R register
int n,m1,m2;
const int maxn=100005;
struct flys {
	int val,id;
	inline bool operator<(const flys &b)const {
		return val<b.val;
	} flys(int a,int b):val(a),id(b) {}
};
std::set<flys > S;
struct ph {
	int a,b;
} a1[maxn];
int ans1[maxn],ans2[maxn];
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(R int i=1; i<=m1; ++i) {
		scanf("%d%d",&a1[i].a,&a1[i].b);
		S.insert((flys) {
			a1[i].a,i
		});
	}
	for(R int i=1; i<=n; ++i) {
		ans1[i]=ans1[i-1];
		if(S.size()) {
			R int now=S.begin()->id;
			std::set<flys >::iterator Next;
			S.erase(S.begin());
			++ans1[i];
			while(1) {
				Next=S.upper_bound((flys) {
					a1[now].b,now
				});
				if(Next==S.end())break;
				++ans1[i];
				now=Next->id;
				S.erase(Next);
			}
		}
//		printf("ans1:%d %d\n",i,ans1[i]);
	}
	S.clear();
	for(R int i=1; i<=m2; ++i) {
		scanf("%d%d",&a1[i].a,&a1[i].b);
		S.insert((flys) {
			a1[i].a,i
		});
	}
	for(R int i=1; i<=n; ++i) {
		ans2[i]=ans2[i-1];
		if(S.size()) {
			R int now=S.begin()->id;
			std::set<flys >::iterator Next;
			S.erase(S.begin());
			++ans2[i];
			while(1) {
				Next=S.upper_bound((flys) {
					a1[now].b,now
				});
				if(Next==S.end())break;
				++ans2[i];
				now=Next->id;
				S.erase(Next);
			}
		}
//		printf("ans1:%d %d\n",i,ans1[i]);
	}
	int ans=0;
	for(R int i=0; i<=n; ++i) {
		ans=std::max(ans,ans1[i]+ans2[n-i]);
	}
	printf("%d",ans);
	return 0;
}

