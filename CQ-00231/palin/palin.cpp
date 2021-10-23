#include<bits/stdc++.h>
using namespace std;
int conduct[1000005],arr[1000005],pos[500005];
int n,flag;
deque<int>que;
void function(int step){
	if(que.empty()){
		flag=1;
		return;
	}
	conduct[step]=1;
	int x=que.front();
	if(pos[x]!=0&&step!=pos[x]){
		conduct[step]=2;//х║ср
		int y=que.back();
		if(pos[y]!=0&&step!=pos[y])return;
	}
	que.pop_front();
	arr[step]=x;
	pos[x]=n*2-step;
	function(step+1);
	
	if(flag==1)return;
	que.push_front(x);
	pos[x]=0;
	conduct[step]=2;
	int y=que.back();
	if(pos[y]!=0&&step!=pos[y])return;
	que.pop_back();
	arr[step]=y;
	pos[y]=n*2-step;
	function(step+1);
}
int main(){
//	freopen("palin.in","r",stdin);
//	freopen("palin.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n*2;i++){
			int a;
			cin>>a;
			que.push_back(a);
		}
		function(1);
		if(flag==0)cout<<-1;
		else{
			for(int i=1;i<=n*2;i++){
				if(conduct[i]==1)cout<<"L";
				else cout<<"R";
			}
		}
		que.clear();
		memset(pos,0,sizeof(pos));
		flag=0;
	}
	return 0;
//	fclose(stdin);
//	fclose(stdout);
}
