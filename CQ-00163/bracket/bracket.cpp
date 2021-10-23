#include<cstdio>
#include<iostream>
#include<algorithm>
#define maxn 1005005
const long long  UM=1000000007;
using namespace std;
char c[505];
int zuo,you,wen[505];
int n,k,num=0;
long long ans=0;

bool  ch(int x,int y){ 
    bool a=false,flag=true;
    int b=0;
    if(c[x+1]=='*'&&c[y-1]=='*') a=true;
    for(int i=x+1;i<y;i++)
    {
    	if(c[i]=='*'){
    		int num=0;
    		while(c[i]!='*') i++,num++;
    		if(num>k) return false;
    		i--;
		}
		else if(c[i]=='('){
		b++;if(b>=3) return false;
		int zu=1,yo=0,j=i;
	     do{ ++j;
	    if(c[j]=='(') zu++;
	    else if(c[j]==')') yo++;
	     }while(yo>zu&&c[j]==')');
	     if(!ch(i,j)) return false;	
		}
    	
	}
	if(a&&!b) return false;
	return true;
}
void check(){
    bool flag=true;
    for(int i=1;i<=n&&flag;i++)
	 if(c[i]=='(')
	 { int zu=1,yo=0,j=i;
	 do{ ++j;
	 if(c[j]=='(') zu++;
	 else if(c[j]==')') yo++;
	 }while(yo>zu&&c[j]==')');
	  flag=ch(i,j);
	  i=j;
     }
     if(flag) ans++,ans%=UM;
}
void dfs(int d){
	//printf("%d",d);
	if(d>num) {if(zuo==you)check();return;}
	if(wen[d]==1){
		c[1]='('; zuo++;
		dfs(d+1);
		zuo--;
	}
	else{
		c[wen[d]]='(';zuo++;dfs(d+1);zuo--;
		c[wen[d]]=')';you++;dfs(d+1);you--;
		c[wen[d]]='*';dfs(d+1);
	}
}
int re(){ int temp;scanf("%d",&temp);return temp;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=re(),k=re();
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
    {
	 	c[i]=s[i-1];
	 	if(c[i]=='?') wen[++num]=i;
	 	else if(c[i]=='(') zuo++;
	 	else if(c[i]==')') you++;
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}
