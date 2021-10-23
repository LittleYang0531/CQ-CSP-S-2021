#include <bits/stdc++.h>
using namespace std ;
const int N = 1e5+5 ;
struct ww{int s,t,id ;}a[N],b[N] ;
struct www{int w,f,id ;}li1[2*N],li2[2*N]; 
int n,m1,m2,cnt1,cnt2,ans,ce1[N],ce2[N] ;
int t[N],cf1[N],vis[N],cf2[N],tfk,ffk ;
vector<int>pl ; 
int cmp(www x,www y){
	return x.w < y.w ;
}
int van(ww x,ww y){
	return x.s < y.s ;
}
void check(int x){
	int user = 0,now1 = 0,now2 = 0,ff = 0  ;
	memset(t,0,sizeof(t)) ;
	for(int i = 1 ; i <= 2*m1 ; ++i ){
		if(cf1[i] > 0)ff++,ce1[ff]++ ;
		else ff-- ;
		if(user < x && cf1[i] > 0) t[cf1[i]] = 1,user++,now1++ ;
		if(cf1[i] < 0 && t[-cf1[i]]) t[-cf1[i]] = 0,user-- ;
	}
	memset(t,0,sizeof(t)) ; 
	user = 0,x = n-x ;
	ff = 0 ;
	for(int i = 1 ; i <= 2*m2 ; ++i ){
		if(cf2[i] > 0)ff++,ce2[ff]++ ;
		if(user < x && cf2[i] > 0) t[cf2[i]] = 1,user++,now2++ ;
		if(cf2[i] < 0 && t[-cf2[i]]) t[-cf2[i]] = 0,user-- ;
	}
	tfk = now1,ffk = now2 ;
	ans = max(ans,now1+now2) ;
}
int main(){
	freopen("airport.in","r",stdin) ;
	freopen("airport.out","w",stdout) ;
	scanf("%d%d%d",&n,&m1,&m2) ;
	for(int i = 1 ; i <= m1 ; ++i ) scanf("%d%d",&a[i].s,&a[i].t),a[i].id = i,li1[++cnt1] = (www){a[i].s,0,i},li1[++cnt1] = (www){a[i].t,1,i} ;
	for(int i = 1 ; i <= m2 ; ++i ) scanf("%d%d",&b[i].s,&b[i].t),b[i].id = i,li2[++cnt2] = (www){b[i].s,0,i},li2[++cnt2] = (www){b[i].t,1,i} ;
	sort(li1+1,li1+1+cnt1,cmp) ;
	sort(li2+1,li2+1+cnt2,cmp) ;
	for(int i = 1 ; i <= cnt1 ; ++i )
		if(!li1[i].f)a[li1[i].id].s = i ;
		else a[li1[i].id].t = i ;
	for(int i = 1 ; i <= cnt2 ; ++i )
		if(!li2[i].f)b[li2[i].id].s = i ;
		else b[li2[i].id].t = i ;
	sort(a+1,a+1+m1,van) ;
	sort(b+1,b+1+m2,van) ;
	for(int i = 1 ; i <= m1 ; ++i ) cf1[a[i].s] = i,cf1[a[i].t] = -i ;
	for(int i = 1 ; i <= m2 ; ++i ) cf2[b[i].s] = i,cf2[b[i].t] = -i ;
	if(n <= 5000)
	for(int i = 0 ; i <= min(m1,n) ; ++i ) check(i) ;
	else {
		check(0) ;
		for(int i = 1 ; i <= min(m1,n) ; ++i ){
			tfk += ce1[i],ffk -= ce2[n-i] ;
			ans = max(ans,tfk+ffk) ;
		}
	}
	printf("%d",ans) ;
	return 0 ;
}
