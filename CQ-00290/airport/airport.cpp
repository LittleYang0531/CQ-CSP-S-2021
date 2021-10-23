#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,d[10000];
int a1[10000],b1[10000],a2[10000],b2[10000];
int h1[10000],h2[10000];
int t;
pair<int,int>p1[10000],p2[10000];
bool cmp(pair<int,int>a,pair<int,int>b){
	return a.first<b.first;
}
int ans;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=0;i<m1;i++){
		cin>>a1[i]>>b1[i];
		p1[i].first=a1[i];
		p1[i+m1].first=b1[i];
		p1[i].second=i;		
		p1[i+m1].second=i+m1;
	}
	for(int i=0;i<m2;i++){
		cin>>a2[i]>>b2[i];
		p2[i].first=a2[i];
		p2[i+m2].first=b2[i];
		p2[i].second=i;		
		p2[i+m2].second=i+m2;
	}
	sort(p1,p1+2*m1,cmp);
	sort(p2,p2+2*m2,cmp);
	for(int k=1;k<=n;k++){
		t=0;
		for(int i=0;i<2*m1;i++){
			if(p1[i].second<m1){
				if(t==k){
					d[p1[i].second]=1;
				}else{
					d[p1[i].second]=0;
					t++;
					h1[k]++;
				}
			}else if(!d[p1[i].second-m1]){
				t--;
			}
		}
	}
	for(int k=1;k<=n;k++){
		t=0;
		for(int i=0;i<2*m2;i++){
			if(p2[i].second<m2){
				if(t==k){
					d[p2[i].second]=1;
				}else{
					d[p2[i].second]=0;
					t++;
					h2[k]++;
				}
			}else if(!d[p2[i].second-m2]){
				t--;
			}
		}
	}
	for(int i=0;i<=n;i++){
		ans=max(ans,h1[i]+h2[n-i]);
	}
	cout<<ans;
	return 0;
}
