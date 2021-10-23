#include<bits/stdc++.h>
#include<queue>
using namespace std;
inline int read(){
	int sum=0,w=1;
	char ch=getchar();
	while('0'>ch||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		sum=sum*10+ch-'0';
		ch=getchar();
	}
	return sum*w;
}
int n,m1,m2;
int a1[100005],b1[100005];
int a2[100005],b2[100005];
int smax;
struct work{
	int a,b;
	bool operator <(const work &t)const{
		return a<t.a;
	}
}w[100005],d[100005];
signed main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	if(n>=m1+m2){
		cout<<m1+m2;
		return 0;
	}
	for(int i=1;i<=m1;i++){
		w[i].a=read(),w[i].b=read();
	}
	for(int i=1;i<=m2;i++){
		d[i].a=read(),d[i].b=read();
	}
	sort(w+1,w+m1+1);
	sort(d+1,d+m2+1);
	for(int i=1;i<=n;i++){
		int n1=i,n2=n-i;
		int num1=0,num2=0;
		int ans=0;
		priority_queue<int,vector<int>,greater<int> > qp1,qp2;
		if(n1<m1){
			for(int j=1;j<=m1;j++){
				if(!qp1.empty()){
					if(w[j].a>=qp1.top()){
						qp1.pop();
						num1--;
					}
				}
				//cout<<ans<<endl;
				if(num1==n1)continue;
				num1++;
				qp1.push(w[j].b);
				ans++;
			}
		}else{
			ans+=m1;
		}
		if(n2<m2){
			for(int j=1;j<=m2;j++){
				if(!qp2.empty()){
					if(d[j].a>=qp2.top()){
						qp2.pop();
						num2--;
					}
				}
				//cout<<ans<<endl;
				if(num2==n2)continue;
				num2++;
				qp2.push(d[j].b);
				ans++;
			}
		}else{
			ans+=n2;
		}
		smax=max(smax,ans);
	}
	cout<<smax;
	return 0;
}
