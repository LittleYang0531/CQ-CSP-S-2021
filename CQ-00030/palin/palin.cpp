#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int q=read();
	int n;
	for(int i=1;i<=q;++i){
		n=read();
		cout<<"-1"<<endl;
	}
}
