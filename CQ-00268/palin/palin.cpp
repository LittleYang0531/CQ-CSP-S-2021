#include<cstdio>//JZM yyds!!
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<ctime>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<random>
#define ll long long
#define uns unsigned
#define MOD 
#define MAXN 1000005
#define INF 1e17
#define IF (it->first)
#define IS (it->second)
using namespace std;
inline ll read(){
	ll x=0;bool f=1;char s=getchar();
	while((s<'0'||s>'9')&&s>0){if(s=='-')f^=1;s=getchar();}
	while(s>='0'&&s<='9')x=(x<<1)+(x<<3)+(s^48),s=getchar();
	return f?x:-x;
}
inline ll lowbit(ll x){return x&-x;}
int n,a[MAXN],b[MAXN],to[MAXN];
string as1,as2;
stack<char>st;
inline void solve(string&as,stack<char>&st,int i1,int i2,int i3,int i4,bool&ok){
	while((i1<=i2||i3<=i4)&&ok){
		if(i1<i2&&a[i1]==a[i2])
			as+='L',st.push('L'),i1++,i2--;
		else if(i1<=i2&&i3<=i4&&a[i1]==a[i3])
			as+='L',st.push('R'),i1++,i3++;
		else if(i1<=i2&&i3<=i4&&a[i4]==a[i2])
			as+='R',st.push('L'),i2--,i4--;
		else if(i3<i4&&a[i4]==a[i3])
			as+='R',st.push('R'),i3++,i4--;
		else ok=0;
	}
	while(!st.empty())as+=st.top(),st.pop();
}
signed main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	for(int T=read();T--;){
		n=read();
		for(int i=1;i<=n;i++)b[i]=0;
		for(int i=1;i<=(n<<1);i++){
			a[i]=read();
			if(!b[a[i]])b[a[i]]=i;
			else to[i]=b[a[i]],to[to[i]]=i;
		}
		as1=as2="";
		while(!st.empty())st.pop();
		int i1=2,i2=to[1]-1,i3=to[1]+1,i4=(n<<1);
		as1+='L',st.push('L');
		bool ok=1;
		solve(as1,st,i1,i2,i3,i4,ok);
		i1=1,i2=to[n<<1]-1,i3=to[n<<1]+1,i4=(n<<1)-1;
		as2+='R',st.push('L'),ok=1;
		solve(as2,st,i1,i2,i3,i4,ok);
		if((int)as1.length()>=(n<<1))
			printf("%s\n",as1.c_str());
		else if((int)as2.length()>=(n<<1))
			printf("%s\n",as2.c_str());
		else printf("-1\n");
	}
	return 0;
}
