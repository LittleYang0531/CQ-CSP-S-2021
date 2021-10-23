#include<bits/stdc++.h>
using namespace std;
int n,m1,m2;
int f1[100000 + 5];
int f2[100000 + 5];
int num1[10000 + 5];
int num2[10000 + 5];
int a,b;
int tim = -1;
struct bobo{
	int a;
	int b;
	
};
bobo ff1[100000 + 5];
bobo ff2[100000 + 5];
bool cmp(bobo x,bobo y){
	return x.a < y.a;
}
int sum;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i = 1;i <= m1;i ++){
		scanf("%d%d",&a,&b);
		ff1[i].a = a;
		ff1[i].b = b;
		f1[a] ++;
		f1[b + 1] --; 
		tim = max(tim,b);
	}
	sort(ff1 + 1,ff1 + m1 + 1,cmp);
	for(int i = 1;i <= tim;i ++){
		f1[i] += f1[i - 1];
	}
	for(int i = 1;i <= m2;i ++){
		scanf("%d%d",&a,&b);
		ff2[i].a = a;
		ff2[i].b = b;
		f2[a] ++;
		f2[b + 1] --; 
		tim = max(tim,b);
	}
	sort(ff2 + 1,ff2 + m2 + 1,cmp);
	for(int i = 1;i <= tim;i ++){
		f2[i] += f2[i - 1];
	}
	int ans = 0;
	for(int i = 0;i <= n;i ++){
		sum = 0;
		for(int j = 1;j <= m1;j ++){
			if(f1[ff1[j].a] < i){
				f1[ff1[j].a] ++;
				sum ++;
			}
		}
		for(int j = 1;j <= m2;j ++){
			if( f2[ff2[j].a] < n - i){
				f2[ff1[j].a] ++;
				sum ++;
			}
		}
		ans = max(ans,sum);
	}	
	printf("%d",ans + 2);
	return 0;
}
