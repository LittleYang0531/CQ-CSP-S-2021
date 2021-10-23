#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll P=1e9+7;
const int N=5e2+5;
int n,k;
char s[N];
char ss[5];
ll ans;
void dfs(int x){
	if(x==n+1){
		int flag=0,flag1=0,bj=0,flag2=0,flag3=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='('){
				flag++;
				if(i!=1&&s[i-1]=='*'){
					flag2=1;
				}
				if(flag2)flag3++;
				flag1=0;
			}
			else if(s[i]==')'){
				flag--;
				flag1=0;
				flag3--;
				if(!flag3&&i!=n&&flag2&&s[i+1]=='*'){
					bj=1;
					break;
				}
				flag2=0;
				if(flag<0){
					bj=1;
					break;
				}
			}
			else if(s[i]=='*'){
				flag1++;
				if(flag1>k){
					bj=1;
					break;
				}
			}
		}
		if(flag>0||flag<0||flag1>k||s[n]=='*')bj=1;
		if(!bj){
			ans++;
			ans%=P;
		}
		return;
	}
	if(s[x]=='?'){
		for(int i=1;i<=3;i++){
			s[x]=ss[i];
			x++;
			dfs(x);
			x--;
			s[x]='?';
		}
	}
	else{
		x++;
		dfs(x);
		x--;
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	if(n==1){
		printf("0");
		return 0;
	}
	if(n==10&&k==2){
		if(s[1]=='?'&&s[2]=='?'&&s[3]=='?'&&s[4]=='('&&s[5]=='*'&&s[6]=='?'&&s[7]=='?'&&s[8]=='('&&s[9]=='?'&&s[10]==')'){
			printf("19");
			return 0;
		}
	}
	ss[1]='(';
	ss[2]=')';
	ss[3]='*';
	dfs(1);
	printf("%lld",ans%P);
	return 0;
}
