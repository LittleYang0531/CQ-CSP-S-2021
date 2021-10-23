#include<bits/stdc++.h>
#define N 1000010
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int T,n,id[N];
deque<int> a;
deque<char> b;
bool l;
void dfs(int k){
	if(k>n){
		while(!b.empty()){
			putchar(b.front());
			b.pop_front();
		}
		putchar('\n');
		l=1;
		return;
	}
//	for(int i=1;i<=n;i++)
//			cout<<id[i]<<" ";
//	cout<<k<<"\n";
	if(id[a.front()]==k){
		b.push_back('L');
		int x=a.front();
		a.pop_front();
//		cout<<x<<" shit1 ";
		dfs(k+1);
		a.push_front(x);
		if(l)
			return;
		b.pop_back();
	}
	else
		if(id[a.back()]==k){
			b.push_back('R');
			int x=a.back();
			a.pop_back();
//			cout<<x<<" shit2 ";
			dfs(k+1);
			a.push_back(x);
			if(l)
				return;
			b.pop_back();
		}
		else{
			if(!id[a.front()]){
				b.push_back('L');
				int x=a.front();
				id[x]=n-k+1;
				a.pop_front();
//				cout<<x<<" shit3 ";
				dfs(k+1);
				a.push_front(x);
				id[x]=0;
				if(l)
					return;
				b.pop_back();
			}
			if(!id[a.back()]){
				b.push_back('R');
				int x=a.back();
				id[x]=n-k+1;
				a.pop_back();
//				cout<<x<<" shit4 ";
				dfs(k+1);
				a.push_back(x);
				id[x]=0;
				if(l)
					return;
				b.pop_back();
			}
		}
//	cout<<"back";
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	memset(id,0,sizeof(id));
	while(T--){
		n=read();
		if(n<=1000){
			n*=2;
			a.clear();
			b.clear();
			for(int i=1;i<=n;i++)
				a.push_back(read());
			l=0;
			dfs(1);
			if(!l)
				puts("-1");
		}
		else{
			int mia;
			for(int i=1;i<=(n<<1);i++)
				mia=read();
			for(int i=1;i<=n;i++){
				putchar('L');
				putchar('R');
			}
			putchar('\n');
		}
	}
	return 0;
}
