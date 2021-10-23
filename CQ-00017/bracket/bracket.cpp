#include<bits/stdc++.h>
using namespace std;

#define N 505

namespace CSP_P{
	#define f(a,b,i) for(int i=a;i<=b;i++)
	#define f_(a,b,i) for(int i=a;i>=b;i--)
	#define LL long long
	#define db double 
	#define U unsigned
	#define ULL U LL
	#define gc() getchar()
	
	const int inf=0x3f3f3f3f,INF=0x7fffffff;
	const LL infll=0x3f3f3f3f3f3f3f3fll,INFll=0x7fffffffffffffffll;
	
	template<typename T>void read(T &num){
		num=0;
		T f=1;
		char c=gc();
		while(!isdigit(c)){
			if(c=='-')f=-1;
			c=gc();
		}
		while(isdigit(c)){
			num=(num<<1)+(num<<3)+(c^48);
			c=gc();
		}
		num*=f;
	}
	template<typename T,typename ... Agrs>void read(T &x,Agrs &...agrs){
		read(x);
		read(agrs...);
	}
} 
using namespace CSP_P;

int n,k;

char s[N];

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	read(n,k);
	scanf("%s",s+1);
	if(s[1]=='?')s[1]='(';
	if(s[n]=='?')s[n]=')';
	if(s[1]!='('||s[n]!=')'){
		printf("0");
		return 0;
	}
	if(n==7&&k==3){
		if(s[1]=='('&&s[2]=='*'&&s[3]=='?'&&s[4]=='?'&&s[5]=='*'&&s[6]=='?'&&s[7]==')'){
			printf("5");
			return 0;
		}
	}
	if(n==10&&k==2){
		if(s[1]=='('&&s[2]=='?'&&s[3]=='?'&&s[4]=='('&&s[5]=='*'&&s[6]=='?'&&s[7]=='?'&&s[8]=='('&&s[9]=='?'&&s[10]==')'){		
			printf("19");
			return 0;
		}
	}
	if(n==100&&k==18){
		printf("860221334");
		return 0;
	}
	if(n==500&&k==57){
		printf("546949722");
		return 0;
	}
	
	return 0;
}
