#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
//不能用fread（有scanf） 
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,k;
const int xx=505,mod=1e9+7;
char s[xx];
int f[xx][xx][2];
//表示l，r这个区间填出来合法的方案，0表示强制钦定直接最左最右拆开,1表示结合和拆开都可 
int sum[xx];
bool check(int l,int r)//l~r能否全填* 
{
	if(l>r)return 1;
//	cout<<l<<" "<<r<<"\n";
	return sum[r]-sum[l-1]==(r-l+1);
}
void add(int &a,int b){(a+=b)>=mod?a-=mod:0;}
int yc[xx];
ll suf[xx];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+(s[i]=='*'||s[i]=='?');
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(s[j]=='('||s[j]==')')break;
			yc[i]++;
		}
		yc[i]=min(yc[i],k);//不能超过k个 
	}
	//yc表示从i+1开始，最多可填几个* 
	for(int l=1;l<=n;l++)
	{
		for(int i=1,j;(j=i+l)<=n;i++)
		{
			if((s[i]=='?'||s[i]=='(')&&(s[j]=='?'||s[j]==')'))
			{
				if(j-i-1<=k&&check(i+1,j-1))f[i][j][0]++;
				add(f[i][j][0],f[i+1][j-1][1]);
				for(int w=i+2;w<min(i+2+k,j);w++)
				{
					if(check(i+1,w-1))
					add(f[i][j][0],f[w][j-1][1]);
				}
				for(int w=j-2;w>max(i,j-2-k);w--)
				{
					if(check(w+1,j-1))
					add(f[i][j][0],f[i+1][w][1]);
				}
			}
			add(f[i][j][1],f[i][j][0]);
			suf[j+1]=0;
			for(int w=j;w>=i;w--)
				suf[w]=suf[w+1]+f[w][j][1];
			for(int w=i;w<j;w++)
			{
				ll re=(suf[w+1]-suf[min(w+yc[w]+1,j)+1])%mod;
				add(f[i][j][1],f[i][w][0]*re%mod);
			}
//			cout<<i<<" sss "<<j<<" "<<s[j]<<"\n";
//				if(i==1&&j==4)
//				{
//					cout<<w<<" "<<re<<"!!\n";
//				}
//			cout<<i<<" "<<j<<" "<<f[i][j][0]<<" "<<f[i][j][1]<<"\n";
//			for(int k=i;k<j;k++)
//				add(f[i][j][1],1ll*f[i][k][0]*f[k+1][j][1]%mod);
		}
	}
	cout<<f[1][n][1]<<"\n";
	return 0;
}
/*
21!9-324@emb
*/

