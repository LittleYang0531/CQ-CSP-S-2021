#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') w*=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
struct Brige{
	int t,num;
	friend bool operator < (const Brige &X,const Brige &Y ){
		return X.t>Y.t; //С�� 
	}
};
struct node{ int st,ed; }A[N],B[N]; 
struct Airport{ int a,b; }dp[N],sum[N];
int n,ans;
int x,y;
priority_queue<Brige> q;
priority_queue<int,vector<int>,greater<int> > id; //С���ѣ�����Ŀǰ������ 
inline bool cmp(node a,node b) { return a.st<b.st; }
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),x=read(),y=read();
	for(register int i=1;i<=x;i++){
		A[i].st=read(),A[i].ed=read();
	}
	for(register int i=1;i<=y;i++){
		B[i].st=read(),B[i].ed=read();
	}
	sort(A+1,A+x+1,cmp),sort(B+1,B+y+1,cmp);
	int cnt=0;
	for(register int i=1;i<=x;i++){
		while(q.size()){
			Brige now=q.top();
			if(now.t>A[i].st) break;
			q.pop(); //���У����� 
			id.push(now.num); //��num���ſ��� 
		}
		if(id.size()){ //���ſ��� 
			int now=id.top(); id.pop();
			dp[now].a++; //ʹ�õ�now���ŷɻ�ͣ����++ 
			q.push((Brige){A[i].ed,now});
		}
		else{ //���ſ��� 
			cnt++; //�½���һ����
			dp[cnt].a++;
			q.push((Brige){A[i].ed,cnt});
		} 
	}
	cnt=0;
	while(!q.empty()) q.pop();
	while(!id.empty()) id.pop();
	for(register int i=1;i<=y;i++){
		while(q.size()){
			Brige now=q.top();
			if(now.t>B[i].st) break;
			q.pop(); //���У����� 
			id.push(now.num); //��num���ſ��� 
		}
		if(id.size()){ //���ſ��� 
			int now=id.top(); id.pop();
			dp[now].b++; //ʹ�õ�now���ŷɻ�ͣ����++ 
			q.push((Brige){B[i].ed,now});
		}
		else{ //���ſ��� 
			cnt++; //�½���һ����
			dp[cnt].b++;
			q.push((Brige){B[i].ed,cnt});
		} 
	}
	for(register int i=1;i<=n;i++) sum[i].a=sum[i-1].a+dp[i].a;
	for(register int i=1;i<=n;i++) sum[i].b=sum[i-1].b+dp[i].b;
	for(register int i=0;i<=n;i++){
		ans=max(ans,sum[i].a+sum[n-i].b);
	}
	printf("%d\n",ans);
	return 0;
}
