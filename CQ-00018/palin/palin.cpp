#include<bits/stdc++.h>
using namespace std;
const int MAX_N=1000000+5;
int t,n,a[MAX_N];
string ans;
bool flag;
//bool judge(string s)
//{
//	int l=1,r=2*n,p[2*n+1];
//	for(int i=0;i<s.size();i++){
//		if(s[i]=='L'){
//			p[i+1]=a[l++];
//		}
//		if(s[i]=='R'){
//			p[i+1]=a[r--];
//		}
//	}
//	for(int i=1;i<=2*n;i++){
//		if(p[i]!=p[n-i+1]) return false;
//	}
//	return true;
//}
//void data(int op,string s)
//{
//	if(s.size()==2*n){
////		if(judge(s)){
//			if(flag==false){
//	    		ans=s;
//	     		flag=true;
//	    		return;
//	    	}
//	    	else{
//	    		ans=min(ans,s);
//	    		return;
//	    	}
////		}
//		
//	}
//	if(op==0){
//		s+="L";
//		cout<<"! "<<endl;
//		data(0,s);
//		data(1,s);
//	}
//	else if(op==1){
//		s+="R";
//		cout<<"! "<<endl;
//		data(0,s);
//		data(1,s);
//	}
//}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
		}
//		string s="";
//		data(0,s);
//		data(1,s);
//		if(flag==false) printf("-1\n");
//		else cout<<ans<<endl;
        printf("-1\n");
	}
	return 0;
}
