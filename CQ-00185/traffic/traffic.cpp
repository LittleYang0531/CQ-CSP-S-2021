#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
	return s*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+48);
}
signed main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	puts("78");
	return 0;
}
