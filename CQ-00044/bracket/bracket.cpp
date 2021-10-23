#include<bits/stdc++.h>
using namespace std;
int d[510];
int q[510][4];
string s;
int n,k;
int cnt;
int sum1,sum2;
int ans;
int h[510];
int bh[510];
int hh[510];
bool qbh[510];
void dfs(int t){
	if(t>cnt){
		int cd=s.size();
		int l=1,r=cd-2;
		int c=0;
		if(s[0]!='('||s[cd-1]!=')') return;
		for(int i=0;i<cd;i++){
			if(s[i]=='('){
				c++;
			}	
			if(s[i]==')'){
				if(c==0) return;
				c--;
			}
		}
		if(c>0) return;
		sum1=0;
		for(int i=0;i<cd;i++){
			if(s[i]=='*'){
				sum1++;
				if(sum1>k) return;
			}
			if(s[i]!='*'){
				sum1=0;
			}
		}
		sum2=1;
		for(int i=1;i<cd;i++){
			if(s[i]=='('){
				h[i]=bh[sum2];
				sum2++;
			}
			if(s[i]==')'){
				for(int j=sum2-1;j>=1;j--){
					if(!qbh[j]){
						qbh[j]=true;
						h[i]=bh[j];
					}
				}
			}
		}
		int sum3=0;
		for(int i=0;i<cd;i++){
			if(s[i]=='('||s[i]==')'){
				hh[++sum3]=i;
			}
		}
		/*
		for(int i=1;i<=sum3;i++){
			cout<<h[hh[i]]<<" ";
		}
		
		for(int i=1;i<=sum3;i++){
			for(int j=1;j<=sum3;j++){
				if(h[hh[i]]==h[hh[j]]&&j!=i){
					cout<<hh[i]<<" "<<hh[j]<<endl;
					if((s[hh[i]]=='*')&&(s[hh[j]]=='*')){
						cout<<hh[i]<<" "<<hh[j]<<endl;
						cout<<s[hh[i]]<<" "<<s[hh[j]];
						return;
					}
				}
			}
		}
		*/
		ans++;
		//cout<<s<<endl;
		return;
	}
	s[d[t]]='*';
	dfs(t+1);
	s[d[t]]='(';
	dfs(t+1);
	s[d[t]]=')';
	dfs(t+1);
}
int main(){
	//freopen("bracket.in","r",stdin);
	//freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	int len=s.size();
	for(int i=1;i<=510;i++) bh[i]=i;
	for(int i=0;i<len;i++){
		if(s[i]=='?'){
			d[++cnt]=i;
		}
	}
	dfs(1);
	cout<<ans-1;
	return 0;
}


/*
7 3
(*??*??
*/
