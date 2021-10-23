#include<bits/stdc++.h>
using namespace std;
const int M=1000000007;
int n,k,ans;
char s[505],sn[505];

void f(int j,int b,int c){
	if(j>n){
		if(b==0&&c==0&&s[1]!='*'){
			for(int i=1;i<=n;i++){
				sn[i]=s[i];
			}
			int z[100],zh=0,cnt=0,snum=0;
			for(int i=1;i<=n;i++){
				if(sn[i]=='('){
					++zh;
					z[zh]=i;
				}
				if(sn[i]==')'){
					for(int j=z[zh]+1;j<i;j++){
						if(sn[j]=='*'&&sn[j-1]!='*'){
//							cout<<j<<"!"<<endl;
							snum++;
						}
					}
					if(snum>cnt&&cnt!=0){
//						for(int i=1;i<=n;i++)
//							cout<<sn[i];
//						cout<<snum<<" "<<cnt<<endl;
						return ;
					}
					for(int j=z[zh]+1;j<i;j++){
						if(sn[j]=='*') sn[j]='%';
					}
					snum=0;// cnt=0;
					cnt++,zh--;
				}
			}
			
			ans++;
//			for(int i=1;i<=n;i++)
//				cout<<s[i];
//			cout<<endl;
			
			return ;
		}
		else {
			return ;
		}
	}
	if(s[j]=='('){
		c=0;
		b++;
	}
	if(s[j]==')'){
		c=0;
		b--;
		if(b<0) return;
	}
	if(s[j]=='*'){
		c++;
		if(c>k) return;
	}
	if(s[j]=='?'){
		s[j]='(';f(j,b,c);
		s[j]='*';f(j,b,c);
		s[j]=')';f(j,b,c);
		s[j]='?';
		return ;
	}
	f(++j,b,c);
}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	f(1,0,0);
	cout<<ans%M;
	return 0;
}
/*
7 3
(*??*??
10 2
???(*??(?)
10 2
(**(*)*())
(**(**)())
(**(*))(*)
*/
