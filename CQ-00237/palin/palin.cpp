//2021/10/23

#include <iostream>
#include <cstdio>
#include <climits>//need "INT_MAX","INT_MIN"
#include <cstring>
#include <ctime>
using namespace std;

const int ma=500005;
int a[ma<<1],b[ma<<1];
char str[ma<<1];
int n;

inline bool chk(){
	memset(b,0,sizeof(b));
	int idx=0,ta=0,tb=(n<<1);
	for(register int i=1;i<=(n<<1);i++){
		if(str[i]=='L'){
			b[++idx]=a[++ta];
		}else{
			b[++idx]=a[tb--];
		}
	}
	
	for(register int i=1;i<=n;i++){
		if(b[i]!=b[(n<<1)+1-i]){
			return false;
		}
	}
	
	return true;
}
bool mark;
inline void dfs(int step){
	if(step==(n<<1)+1){
		if(chk() && !mark){
			mark=true;
			for(register int i=1;i<=(n<<1);i++){
				cout<<str[i];
			}
			
			cout<<endl;
		}
		
		return;
	}
	
	str[step]='L';
	dfs(step+1);
	str[step]='R';
	dfs(step+1);
}
int main(void){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int st=clock();
	int T;
	
	scanf("%d",&T);
	
	while(T--)
	{
		scanf("%d",&n);
		
		for(register int i=1;i<=(n<<1);i++)
		{
			scanf("%d",a+i);
		}
		
		mark=false;
		dfs(1);
		if(!mark){
			cout<<-1<<endl;
		}
	}
	
//	cout<<"time = "<<clock()-st<<" ms"<<endl;
	
	return 0;
}

