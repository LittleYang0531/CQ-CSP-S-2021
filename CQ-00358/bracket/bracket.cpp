#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,ch[1000],mi[505][505],mx[505][505],ss[505][505],mod=1e9+7;
char c[1000];
bool bj[505][505],s[505][505];
long long f[505][505];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("btacket.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++){
		if(c[i]=='('){
			ch[++cnt]=-2;
		}else if(c[i]==')'){
			ch[++cnt]=-1;
		}else if(c[i]=='*'){
			int sum=1;
			while(c[i+1]=='*')i++,sum++;
			ch[++cnt]=sum;
		}else if(c[i]=='?'){
			ch[++cnt]=-3; //                   -2:(  -1:)
		}
	}
	for(int i=1;i<=cnt;i++){
		if((ch[i]==-2||ch[i]==-3)&&(ch[i+1]==-3||ch[i+1]==-1)){
			f[i][i+1]++;
		}
	}
	for(int len=1;len<=m;len++){
		for(int i=1;i<=cnt-len+1;i++){
			int j=i+len-1;
			bool flag=0;
			for(int k=i;k<=j;k++){
				if(ch[k]==-1||ch[k]==-2){
					flag=1;
					break;
				}
			}
			if(flag){
				ss[i][j]=0;
				continue;
			}
			ss[i][j]=1;
		}
	}
	for(int len=3;len<=m+2;len++){
		for(int i=1;i<=cnt-len+1;i++){
			int j=i+len-1;
			if(ch[i]>=1||ch[j]>=1)continue;
			bool flag=0;
			for(int k=i+1;k<=j-1;k++){
				if(ch[k]==-1||ch[k]==-2){
					flag=1;
					break;
				}
			}
			if(flag)continue;
			f[i][j]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(ch[i]>=1||ch[j]>=1)continue;
			for(int k=i+1;k<j;k++){
				f[i][j]=(f[i][j]+f[i][k]*f[k+1][j])%mod;
			}
			for(int k1=i+2;k1<=j-3;k1++){
				for(int k2=k1+1;k2<=j-2;k2++){
					if(!ss[k1+1][k2-1])continue;
					f[i][j]=(f[i][j]+f[i+1][k1]*f[k2][j-1])%mod;
				}
			}
			f[i][j]+=f[i+1][j-1];
			f[i][j]%=mod;
			for(int k=i+2;k<=j-2;k++){
				if(!ss[i+1][k-1])continue;
				f[i][j]=(f[i][j]+f[k][j-1])%mod;
			}
			for(int k=i+2;k<=j-2;k++){
				if(!ss[k+1][j-1]){
					f[i][j]=(f[i][j]+f[i+1][k])%mod;
				}
			}
		}
	}
	cout<<f[1][cnt];
	return 0;
}
/*
7 3
(*??*??
*/
