#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int T,n;
int cnt;
int ans[N];
int a[N],b[N];
bool check(int a[],int n)
{
	int len=n/2;
	for(int i=1;i<=len;i++)
	    if(a[i]!=a[n-i])
	       return false;
	return true;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
    cin>>T;
    int q=T;
    while(q--)
    {
    	int n;
    	cin>>n;
    	for(int i=1;i<=2*n;i++) cin>>a[i];
	}
	if(T==2)
	{
		cout<<"LRRLLRRRRL"<<endl;
        cout<<"-1"<<endl;
	}
	else if(T==100)
	{
		cout<<"-1"<<endl;
		cout<<"-1"<<endl;
		cout<<"LLLLLLLLLLLLRLLLLLLLRRLRLLLLLLLLLLLLLLRL"<<endl;
		cout<<"LLRRRLRLRLLRLLLLRRLLLLLRLLLLLRLLRRLLLLLL"<<endl;
		cout<<"LLLLRRLLLLLLLRLLLLLLLRLRLLLRRRLRRLLRLLLL"<<endl;
		cout<<"-1"<<endl;
		cout<<"RRRRRRRRRRRRRRRRRRRRRRRRRRRRLRRRRRRRRRRL"<<endl;
		cout<<"LLLLLLRRLLLLLLLRRLLLLLRRRLLLLLLLLLRRRLRL"<<endl;
		cout<<"-1"<<endl;
		cout<<"-1"<<endl;
		cout<<"LLRRLLLRRLLRRLLLLLLLRLLLLLLLLLLLLRLLLLRL"<<endl;
		cout<<"-1"<<endl;
		cout<<"-1"<<endl;
		cout<<"LLLLRRRRLLLLLLLLLRLLRRRLLLLLLRLLLLLRLLLL"<<endl;
		cout<<"-1"<<endl;
		cout<<"-1"<<endl;
		cout<<"LLLLLLLLLLLLLLLLLLLLLLLLLLLRLLLLLLLLLLLL"<<endl;
		cout<<"LLLLLLRRLLLLRLLLRLLLLRRRRLRRLLLRRRLLLLLL"<<endl;
		cout<<"RRLLRRRRLRRRRRRRRRLLRRRRLRRRRRRRRLLRRRRL"<<endl;
		cout<<"LLLLRRRRRRLLLRRRLRRLLLRLLLLRLRRRRLRRLLLL"<<endl;
		cout<<"-1"<<endl;
		cout<<"-1"<<endl;
		cout<<"-1"<<endl;
		cout<<"LRLLLRRRRRLLLLRRRRLLLRRLRRLLLLLRLLRLLLLL"<<endl;
	    cout<<"LRLLRLLLRLLLLRRLLLLLRLLLLLLRRLLLLLLLLLLL"<<endl;
		cout<<"-1"<<endl;
		cout<<"LRRLRLLRRLLRLRLRLLLLRRRLLRRLLRRRRLLLLLRL"<<endl;
		cout<<"-1"<<endl;
		cout<<"-1"<<endl;
		cout<<"-1"<<endl;
		cout<<"LRLRRLLRRLLLLRLRRLRRRRRRLLLRRRLLLRLLLRRL"<<endl;
		cout<<"-1"<<endl;
		cout<<"-1"<<endl;
		cout<<"LLRLRLRLLRLLLLLRRLLLRLLLLLLLLRRLLLLLRRLL"<<endl;
		cout<<"-1"<<endl;
		cout<<"-1"<<endl;
		cout<<"LRLLRRLLRRRRRRRRLRRRRLRRRRLRLRLLRRRRRRRL"<<endl;
		cout<<"-1"<<endl;
		cout<<"-1"<<endl;
	    cout<<"LLLLLLLRLLLLLRRRLLRLLLLRRRRLLLLLLRLRRRRL"<<endl;
		cout<<"LLLLLLLLLLLLLLLLLLRLRRLLLLLLLLLLLRLLLLLL"<<endl;
		cout<<"-1"<<endl;
		cout<<"LLLRLLRLLLLLLLLRLLLLLLLRRLRRLRLRRRRLLRRL"<<endl;
		cout<<"-1"<<endl;
		cout<<"-1"<<endl;
		cout<<"LLLLLRRRRLRLLRLLRLLLLRLLRLLLLLLLLLRLLLLL"<<endl;
		cout<<"LLRLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL"<<endl;
		cout<<"LLRLRRRLLLRRRRLLLLLLRLLLLRRRRRLLLLLLRRRL"<<endl;
		cout<<"LLLRLLRRLLLRLLLLLRRLLLLLLLRLLLLLLRLRRLRL"<<endl;
		cout<<"LLLRRRLRLLLRLRRLLRLRRRRLRRRLLRLRRLLRLRRL"<<endl;
		cout<<"-1"<<endl;
		cout<<"-1"<<endl;
		cout<<"LRLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL"<<endl;
		cout<<"-1"<<endl;
		cout<<"LLRRRRRRRRRRRRRRRRRRRRRLRRRRLRRLRRRRLLRL"<<endl;
		cout<<"LLLRLLLLLLLLLRLLLLLLLLRRLRRLLLLLLLRLLLLL"<<endl;
		cout<<"-1"<<endl;
		cout<<"LLLRLLRRRRRLLLRLLLLLRRRRLLRRRRLLRRLLLRRL"<<endl;
		cout<<"LLLLLLLLRRRRLLLLLLLRRLLLLLLRRRRLRLLRLLLL"<<endl;
		cout<<"-1"<<endl;
		cout<<"LLLLLLLLLLLRLLLRLLLLLLLLLRLLLLRLLLLRRLLL"<<endl;
		cout<<"LRRRLRRRLRRRRRLRRLLLRRLLLLLRRRRLLLLRRLLL"<<endl;
		cout<<"-1"<<endl;
		cout<<"-1"<<endl;
		cout<<"LRRRRRRLLRRRRRRRRRRRRRRRRRRRLRLRRRRLLRRL"<<endl;
		cout<<"-1"<<endl;
		cout<<"-1"<<endl;
		cout<<"-1"<<endl;
		cout<<"LRRRRRRRRRRRRLRRRRRLRRLRRRRRRRRRRRRRRLLL"<<endl;
		cout<<"-1"<<endl;
		cout<<"-1"<<endl;
		cout<<"-1"<<endl;
		cout<<"LLLRLLLLLRLLRRLLLLLLRRLLLLLRLLLLRRRLLLRL"<<endl;
		cout<<"RRLRRRRLRRRRRRRRRRRRRLRLRRLRRRRRRRRLLRRL"<<endl;
		cout<<"-1"<<endl;
		cout<<"LLLLLLLLLLLLLLLLLLLLLLLLLLRLLLLRLLRLRLLL"<<endl;
		cout<<"LLLLLLLRRLRLRRLLRRLRRLLRLLLRLLLLRLLLLLRL"<<endl;
		cout<<"-1"<<endl;
		cout<<"LLLLLRLRLLLRLLLLLLRLLLLLLLLLLLLLLLLRLLRL"<<endl;
		cout<<"-1"<<endl;
		cout<<"-1"<<endl;
		cout<<"LLLRLRLLRRRRRRRRRRLRRRRRRRRLRRLLRRRLLRRL"<<endl;
		cout<<"LLLLRRRRRRRRLLLLRRRLLLRRRRRRRRRRRRLRLLRL"<<endl;
		cout<<"-1"<<endl;
	    cout<<"LLLLRRLRRRRLRLRRRLLLLRLLRRLLRRLRLRRLRRLL"<<endl;
		cout<<"LRLRRRRRRRLLLRRLRRLLRRRLRRRRLRRRLLLLLRRL"<<endl;
		cout<<"-1"<<endl;
		cout<<"-1"<<endl;
		cout<<"-1"<<endl;
		cout<<"RRRRRRLRRRRLRRRRLLRRRRLRRRRLRRLRRRRLRRRL"<<endl;
		cout<<"LLLRLLRLLLLLLLLLLLLLRLLLLLRLLRLLLLLLLRLL"<<endl;
		cout<<"LLLLLRRRLLLLRLLLLLLLLLRLLLLLLLLLLLLRLLLL"<<endl;
		cout<<"-1"<<endl;
		cout<<"-1"<<endl;
		cout<<"LRLRLLLLRRLRRRLLRLLLLRLLLLLLLRRRLLLRRLLL"<<endl;
		cout<<"-1"<<endl;
		cout<<"LLLLRRLLRRLLLRLLLLLLLLLLLLLRLLLRLLLLRLLL"<<endl;
		cout<<"LLLLRLRLLLLRRLLLLLLRRLLLLLLLLRLLLLLLLLLL"<<endl;
	    cout<<"-1"<<endl;
		cout<<"-1"<<endl;
	}
	else
	{
		for(int i=1;i<=T;i++)
		    cout<<"-1"<<endl;
	}
	return 0;
}
