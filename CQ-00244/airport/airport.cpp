#include<bits/stdc++.h>
using namespace std;

const int Maxn=1e5+10;
int N,M1,M2,tmp1=1,tmp2=1,f[2][Maxn],ans;
struct plane{
	int a,b;
	bool operator <(const plane &A)const{return a<A.a;}
}Home[Maxn],Broad[Maxn];
bool Vis1[Maxn],Vis2[Maxn];

int sol1(){
	int tot=0,lst=0;
	for(int i=tmp1;i<=M1;i++){
		if(Vis1[i]) continue;
		if(Home[i].a>=lst) lst=Home[i].b,Vis1[i]=true,tot++;
		else if(Vis1[tmp1]) tmp1=i;
	}
	return tot;
}

int sol2(){
	int tot=0,lst=0;
	for(int i=tmp2;i<=M2;i++){
		if(Vis2[i]) continue;
		if(Broad[i].a>=lst) lst=Broad[i].b,Vis2[i]=true,tot++;
		else if(Vis2[tmp2]) tmp2=i;
	}
	return tot;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&N,&M1,&M2);
	for(int i=1;i<=M1;i++){
		scanf("%d %d",&Home[i].a,&Home[i].b);
	}
	for(int i=1;i<=M2;i++){
		scanf("%d %d",&Broad[i].a,&Broad[i].b);
	}
	if(N>M1+M2){ printf("%d",M1+M2); return 0; }
	sort(Home+1,Home+M1+1); sort(Broad+1,Broad+M2+1);
	for(int i=1;i<=N;i++){
		f[0][i]=f[0][i-1]+sol1();
		f[1][i]=f[1][i-1]+sol2();
	}
	for(int i=1;i<=N;i++)
		ans=max(ans,f[0][i]+f[1][N-i]);
	printf("%d",ans);
	return 0;
}
