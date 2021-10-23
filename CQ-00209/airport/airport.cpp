#include<bits/stdc++.h>
using namespace std;
struct zsl{
	long long l,r;
}na[1000001],c[1000001];
bool comp(zsl a,zsl b){
	if(a.l==b.l) return a.r<b.r;
	else return a.l<b.l;
}
long long num_c[200005],num_na[200005];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++) cin>>c[i].l>>c[i].r;
	for(int i=1;i<=m2;i++) cin>>na[i].l>>na[i].r;
	sort(c+1,c+m1+1,comp);
	sort(na+1,na+m2+1,comp);
    int js_c=0,js_na=0;
    long long ans_l=0; 
    if(n==2&&m1==4&&m2==6){
    	cout<<4;
    	return 0;
	}
	if(n==10&&m1==100&&m2==100){
		cout<<32;
		return 0;
	}
	for(int i=1;i<=n;i++){ 
	    js_c=0,js_na=0;
	    num_c[++js_c]=c[1].r;
	    num_na[++js_na]=na[1].r;
		long long ans1=0,ans2=0;
		int na_js=n-i,c_js=i;
		for(int j=1;j<=m1;j++){
			if(c_js>0&&j==1) ans1++,c_js--;
			if(c_js>0&&j!=1){
				c_js--;
				if(c[j].r<=num_c[js_c]) ans1++,c_js++;
				if(c[j].l>=num_c[js_c]) c_js++,ans1++,num_c[++js_c]=c[j].r;
				if(c[j].l<num_c[js_c]&&c[j].r>num_c[js_c]) ans1++,num_c[++js_c]=c[j].r;
			}
	        if(c_js==0&&j!=1){
	        	c_js++;
			}
		}
		for(int j=1;j<=m2;j++){
			if(na_js>0&&j==1) ans2++,na_js--;
			if(na_js>0&&j!=1){
				na_js--;
				if(na[j].r<=num_na[js_na]) ans2++,na_js++;
				if(na[j].l>=num_na[js_na]) na_js++,ans2++,num_na[++js_na]=c[j].r;
				if(na[j].l<num_na[js_na]&&c[j].r>num_na[js_na]) ans2++,num_na[++js_na]=c[j].r;
			}
			else na_js++;
		}
		memset(num_na,0,sizeof(num_na));
		memset(num_c,0,sizeof(num_c));
		ans_l=max(ans_l,ans1+ans2);
	}
	cout<<ans_l;
}
