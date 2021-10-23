#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 1000005
using namespace std;
priority_queue<int> q;
struct FJ{int luo,fei;
}N[maxn],W[maxn];
int n,m1,m2,ans=0,ne[maxn];
bool cmp(FJ a,FJ b){ return a.luo<b.luo;
}
int re(){ int temp;scanf("%d",&temp); return temp;
}
int main(){
	freopen("airport.in","r",stdin);
    freopen("airport.out","w",stdout);
	n=re();m1=re();m2=re();
	for(int i=1;i<=m1;i++)
	 {
	     N[i].luo=re();
	     N[i].fei=re();}
    sort(N+1,N+m1+1,cmp);
    for(int i=1;i<=m2;i++)
     {
     	W[i].luo=re();
     	W[i].fei=re();
	 }
	sort(W+1,W+m2+1,cmp);
	int topa,topb,num;
	for(int i=0;i<=n;i++)
    {
     	num=0;
    	if(i!=0) 
    	{
		while(!q.empty()) q.pop(); 
		q.push(0);
		for(int j=1;j<=m1;j++)
        {
        	
    	    if(-q.top()<N[j].luo) {q.pop();q.push(-N[j].fei);num++;/*cout<<" "<<num<<" "<<-q.top()<<endl;*/}
    	    else if(q.size()<i){q.push(-N[j].fei);num++;/*cout<<" "<<num<<" "<<-q.top()<<endl;*/
			}
    	 }}
    	if(n!=i)
		{while(!q.empty()) q.pop();q.push(0); 
    	for(int j=1;j<=m1;j++)
        {
    	    if(-q.top()<W[j].luo) {q.pop();q.push(-W[j].fei);num++;/*cout<<" "<<num<<" "<<-q.top()<<endl;*/}
    	    else if(q.size()<n-i){q.push(-W[j].fei);num++;/*cout<<" "<<num<<" "<<-q.top()<<endl;*/
			}
    	 }}
		ans=max(ans,num);
    }
    printf("%d",ans);
	return 0;
}
