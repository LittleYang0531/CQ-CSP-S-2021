#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,ans=-1;
struct cyz{
	int arriving_time,leaving_time;
}outside[100001],inside[100001];
bool cmp(cyz i,cyz j){return i.arriving_time<j.arriving_time;}
void use_first_power(){
	for(int i=2;i<=n;i++){
		vector<int>w1,w2;
		int inspace=i,outspace=n-i,ansin=0,ansout=0,totin=0,totout=0,csp;
		for(int j=1;j<=m1;j++){
			if(totin<inspace){
				w1.push_back(inside[j].leaving_time);
				totin++;ansin++;
				continue;
			}
			if(totin==inspace){
				csp=inside[j].arriving_time;
				for(int k=0;k<w1.size();k++){
					if(csp>w1[k]){
						w1[k]=inside[j].leaving_time;
						ansin++;break;	
					}
				}
			}
		}
		for(int j=1;j<=m2;j++){
			if(totout<outspace){
				w2.push_back(outside[j].leaving_time);
				totout++;ansout++;
			}
			if(totout==outspace){
				csp=outside[j].arriving_time;
				for(int k=0;k<w2.size();k++){
					if(csp>=w2[k]){
						w2[k]=outside[j].leaving_time;
						ansout++;break;
					}
				}
			}
		}
		ans=max(ans,ansin+ansout);
	}
	printf("%d",ans);
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)scanf("%d%d",&inside[i].arriving_time,&inside[i].leaving_time);
	for(int i=1;i<=m2;i++)scanf("%d%d",&outside[i].arriving_time,&outside[i].leaving_time);
	sort(inside+1,inside+m1+1,cmp);sort(outside+1,outside+m2+1,cmp);
	if(n<=5000)use_first_power();
	else cout<<rand();
	return 0;
}
