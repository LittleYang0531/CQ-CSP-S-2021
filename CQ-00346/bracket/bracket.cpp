#include <bits/stdc++.h>
using namespace std;
int n,k,cnt=0,ans=0;
int pos[501],g[501];//*0,(1,)2
string s;
bool pd(string x){
	while(1){
		int f=0;
		for(int i=0;i<=n-1;i++){
			if(x[i]=='('&&x[i+1]==')'){//()
				string t;for(int j=0;j<i;j++)t+=x[j];
				t+='@';for(int j=i+2;j<n;j++)t+=x[j];
				x=t;f=1;
			}
			if(x[i]=='('&&x[i+1]=='*'){//(S)
				int now=i+1;
				while(x[now]=='*')now++;
				if(i+k+1<now)return 0;
				if(x[now]==')'){
					string t;for(int j=0;j<i;j++)t+=x[j];
					t+='@';for(int j=now+1;j<x.length();j++)t+=x[j];
					x=t;f=1;
				}
			}
			if(x[i]=='('&&x[i+1]=='@'&&x[i+2]==')'){//(A)
				string t;for(int j=0;j<i;j++)t+=x[j];
				t+='@';for(int j=i+3;j<n;j++)t+=x[j];
				x=t;f=1;
			}
			if(x[i]=='('&&x[i+1]=='*'){//(SA)
				int now;
				for(now=i+1;x[now]=='*';now++);
				if(i+k+1<now)return 0;
				if(x[now]=='@'&&x[now+1]==')'){
					string t;for(int j=0;j<i;j++)t+=x[j];
					t+='@';for(int j=now+2;j<n;j++)t+=x[j];
					x=t;f=1;
				}
			}
			if(x[i]=='('&&x[i+1]=='@'){//(AS)
				int now;
				for(now=i+2;x[now]=='*';now++);
				if(i+k+1<now)return 0;
				if(x[now]==')'){
					string t;for(int j=0;j<i;j++)t+=x[j];
					t+='@';for(int j=now+1;j<n;j++)t+=x[j];
					x=t;f=1;
				}
			}
			if(x[i]=='@'&&x[i+1]=='*'){//(S)
				int now=i+1;
				while(x[now]=='*')now++;
				if(i+k+1<now)return 0;
				if(x[now]=='@'){
					string t;for(int j=0;j<i;j++)t+=x[j];
					t+='@';for(int j=now+1;j<x.length();j++)t+=x[j];
					x=t;f=1;
				}
			}
			if(x[i]=='@'&&x[i+1]=='@'){//()
				string t;for(int j=0;j<i;j++)t+=x[j];
				t+='@';for(int j=i+2;j<n;j++)t+=x[j];
				x=t;f=1;
			}
			if(n==1&&x=="@")return 1;
			if(!f)return 0;
		}
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s;
	memset(g,0,sizeof(g));
	for(int i=0;i<n;i++)if(s[i]=='?')pos[++cnt]=i;
	while(1){
		for(int i=1;i<=cnt;i++)s[pos[i]]=(g[i]==0?'*':(g[i]==1?'(':')'));
		if(pd(s))ans++;g[cnt]++;
		for(int i=cnt;i>=2;i--)if(g[i]==3){g[i]=0;g[i-1]++;}
		if(g[1]==3)break;
	}
	printf("%d",ans);
	return 0;
}
