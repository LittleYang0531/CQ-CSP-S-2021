#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6+5;
int fi[MAX],fo[MAX];
pair<int,int> in[MAX],out[MAX];
int n,mi,mo;
int ans=-1;
bool vis[MAX];
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first<b.first;
}
int find(int tot){
	int cnt=tot;
	int Min=MAX,num=0;
	if(cnt==0) return 0;
	for(int i=1;i<=mi;i++){
		for(int j=1;j<=cnt;j++){
			if(in[i].first>fi[j]){
				num++;
				fi[j]=in[i].second;
				break;
			}
		}
	}
	return num;
}
int fond(int tot){
	int cnt=tot;
	int Min=MAX,num=0;
	if(cnt==0) return 0;
	for(int i=1;i<=mo;i++){
		for(int j=1;j<=cnt;j++){
			if(out[i].first>fo[j]){
				num++;
				fo[j]=out[i].second;
				break;
			}
		}
	}
	return num;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&mi,&mo);
	for(int i=1;i<=mi;i++) scanf("%d %d",&in[i].first,&in[i].second);
	for(int i=1;i<=mo;i++) scanf("%d %d",&out[i].first,&out[i].second);
	sort(in+1,in+mi+1,cmp);sort(out+1,out+mo+1,cmp);
	for(int i=0;i<=n;i++){
		memset(fi,0,sizeof(fi));memset(fo,0,sizeof(fo));
		int fin=i,fout=n-i,num=0,_1=0,_2=0;
		num=find(fin)+fond(fout);
		ans=max(ans,num);
	}
	printf("%d",ans);
	return 0;
}
