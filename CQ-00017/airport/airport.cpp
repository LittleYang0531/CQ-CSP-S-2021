#include<bits/stdc++.h>
using namespace std;

#define N 100005

namespace CSP_P{
	#define f(a,b,i) for(int i=a;i<=b;i++)
	#define f_(a,b,i) for(int i=a;i>=b;i--)
	#define LL long long
	#define db double 
	#define U unsigned
	#define ULL U LL
	#define gc() getchar()
	
	const int inf=0x3f3f3f3f,INF=0x7fffffff;
	const LL infll=0x3f3f3f3f3f3f3f3fll,INFll=0x7fffffffffffffffll;
	
	template<typename T>void read(T &num){
		num=0;
		T f=1;
		char c=gc();
		while(!isdigit(c)){
			if(c=='-')f=-1;
			c=gc();
		}
		while(isdigit(c)){
			num=(num<<1)+(num<<3)+(c^48);
			c=gc();
		}
		num*=f;
	}
	template<typename T,typename ... Agrs>void read(T &x,Agrs &...agrs){
		read(x);
		read(agrs...);
	}
} 
using namespace CSP_P;

struct node{
	int a,b;
}pl1[N],pl2[N];


int n,m1,m2;

deque<int> q1,q2;

int cmp(node x,node y){
	return x.a<y.a;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n,m1,m2);
	f(1,m1,i) read(pl1[i].a,pl1[i].b);
	f(1,m2,i) read(pl2[i].a,pl2[i].b);
	sort(pl1+1,pl1+m1+1,cmp);
	sort(pl2+1,pl2+m2+1,cmp);
	LL ans=0,maxn;
	f(0,n,n1){
	
		maxn=0;
		
		q1.clear();
		f(1,m1,i){
			while(q1.size()&&pl1[q1.front()].b<pl1[i].a)q1.pop_front();
			if(q1.size()<n1){
				q1.push_back(i);
				maxn++;
			}
		}
		
		q2.clear();
		f(1,m2,i){
			while(q2.size()&&pl2[q2.front()].b<pl2[i].a)q2.pop_front();
			if(q2.size()<n-n1){
				q2.push_back(i);
				maxn++;
			}
		}
		ans=max(ans,maxn);
	}
	cout<<ans;
	return 0;
}
