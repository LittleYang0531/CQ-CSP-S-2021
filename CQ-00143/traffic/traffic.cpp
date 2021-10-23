#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &n){
	T w=1;n=0;
	char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF){n=(n<<1)+(n<<3)+(ch&15);ch=getchar();}
	n*=w;
}
int T;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	srand((unsigned)(time(NULL)));
	read(T);read(T);read(T);
	while(T--){
		int t=rand();
		printf("%d\n",t);
	}
	return 0;
}
