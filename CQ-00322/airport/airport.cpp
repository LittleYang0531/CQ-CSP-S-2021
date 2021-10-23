#include<bits/stdc++.h>
using namespace std;

struct node{
	int x,y;
};

const int N = 100005;

int n , m1 , m2;
node a[N] , b[N] , q[N*2];

int geta(int x){
	int hd = 1 , tl = 0 , ans = m1;
	for(int i=1;i<=m1;i++){
		while(q[hd].y < a[i].x && hd <= tl) hd ++;
		if(tl - hd + 1 < x) q[++tl] = a[i];
		else ans --;
	}
	return ans;
}

int getb(int x){
	int hd = 1 , tl = 0 , ans = m2;
	for(int i=1;i<=m2;i++){
		while(q[hd].y < b[i].x && hd <= tl) hd ++;
		if(tl - hd + 1 < x) q[++tl] = b[i];
		else ans --;
	}
	return ans;
}

bool cmpx(node A,node B){
	if(A.x == B.x) return A.y < B.y;
	return A.x < B.x;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	scanf("%d %d %d",&n,&m1,&m2);
	
	for(int i=1;i<=m1;i++)
		scanf("%d %d",&a[i].x,&a[i].y);
	
	for(int i=1;i<=m2;i++)
		scanf("%d %d",&b[i].x,&b[i].y);
	
	sort(a+1 , a+1+m1 , cmpx);
	sort(b+1 , b+1+m2 , cmpx);
	
	int ans = 0;
	
	if(m1 < m2){
		for(int i=0;i<=min(n , m1);i++){
			ans = max( ans , geta( i ) + getb( n - i ) );
		}
	}
	else{
		for(int i=0;i<=min(n , m2);i++){
			ans = max( ans , getb( i ) + geta( n - i ) );
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}

//3 5 4
//1 5
//3 8
//6 10
//9 14
//13 18
//2 11
//4 15
//7 17
//12 16
//
//2 4 6
//20 30
//40 50
//21 22
//41 42
//1 19
//2 18
//3 4
//5 6
//7 8
//9 10
