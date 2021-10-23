#include<bits/stdc++.h>

using namespace std;
int T,N;
int flag;
int a[1000100];
int ans[101000];
void dfs(int m,int head,int tail){
	if(m>2*N){
//		ans[m]=a[head];
//		for(int i=1;i<=N;i++){
//			if(ans[i]!=ans[2*N+1-i]){
//				return;
//			}	
//		}

		flag=1;
		int l=1;
		for(int i=1;i<=2*N;i++){
			if(ans[i]==a[l]){
				cout<<"L";
				l++;
				continue;
			}
			
			else cout<<"R";
		}
		cout<<endl;
		return;
	}
	
	int f=1;
	ans[m]=a[head];
	if(m>N){
		if(ans[m]!=ans[2*N+1-m]){
			f=0;
		}
	}
	if(f) dfs(m+1,head+1,tail);
	if(flag) return;

	f=1;
	ans[m]=a[tail];
	if(m>N){
		if(ans[m]!=ans[2*N+1-m]){
			f=0;
		}
	}
	if(f) dfs(m+1,head,tail-1);
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>N;
		flag=0;
		for(int i=1;i<=2*N;i++){
			cin>>a[i];
		}
		
		if(N>1000){
			for(int i=1;i<=N;i++){
			cout<<"LL";	
			}
			cout<<endl;
			continue;
		}	
		
		dfs(1,1,2*N);
		if(!flag) cout<<-1<<endl;
	}
	
	return 0;
}
