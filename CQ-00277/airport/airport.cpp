#include<bits/stdc++.h>
using namespace std;
int n,m,mm,cnt,f[100005],g[100005],Ans;
struct node {int L,R;}A[100005],B[100005];
bool cp(node a,node b) {return a.L<b.L;}
struct nodden{int T,Id;}Tmp;
priority_queue<nodden>Q,QQ;
bool operator<(nodden a,nodden b) {return a.T>b.T;}
struct noddden{int T,Id;}Temp;
priority_queue<noddden>P,PP;
bool operator<(noddden a,noddden b) {return a.Id>b.Id;}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);	
	scanf("%d%d%d",&n,&m,&mm);
	for(register int i=1;i<=m;++i) scanf("%d%d",&A[i].L,&A[i].R);
	for(register int i=1;i<=mm;++i) scanf("%d%d",&B[i].L,&B[i].R);
	sort(A+1,A+m+1,cp),sort(B+1,B+mm+1,cp);
	Tmp.T=A[1].R,Tmp.Id=++cnt,++f[Tmp.Id],Q.push(Tmp);
	for(register int i=2;i<=m;++i)
	{
		while(Q.size()&&Q.top().T<=A[i].L) Temp.Id=Q.top().Id,Temp.T=Q.top().T,Q.pop(),P.push(Temp);
		if(P.size()) Tmp.Id=P.top().Id,Tmp.T=A[i].R,P.pop(),++f[Tmp.Id],Q.push(Tmp);
		else Tmp.Id=++cnt,Tmp.T=A[i].R,++f[Tmp.Id],Q.push(Tmp);
	}
	cnt=0,Tmp.T=B[1].R,Tmp.Id=++cnt,++g[Tmp.Id],QQ.push(Tmp);
	for(register int i=2;i<=mm;++i)
	{
		while(QQ.size()&&QQ.top().T<=B[i].L) Temp.Id=QQ.top().Id,Temp.T=QQ.top().T,QQ.pop(),PP.push(Temp);
		if(PP.size()) Tmp.Id=PP.top().Id,Tmp.T=B[i].R,PP.pop(),++g[Tmp.Id],QQ.push(Tmp);
		else Tmp.Id=++cnt,Tmp.T=B[i].R,++g[Tmp.Id],QQ.push(Tmp);
	}
	for(register int i=1;i<=m;++i) f[i]+=f[i-1];
	for(register int i=1;i<=mm;++i) g[i]+=g[i-1];
	for(register int i=0;i<=n;++i) Ans=max(Ans,f[i]+g[n-i]);
	printf("%d",Ans);
	return 0;
}
