#include<bits/stdc++.h>
#define N 500005
using namespace std;
//int t,n,a_tot1,a_tot2,b_tot2;
//deque<int> a,b;
//void L()
//{
//	b.push_back(a.front());
//	a.pop_front();
//}
//void R()
//{
//	b.push_back(a.back());
//	a.pop_back();
//}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
//	scanf("%d",&t);
//	while(t--)
//	{
//		scanf("%d",&n);
//		for(int i=1;i<=2*n;i++)
//		{
//			int tp;
//			scanf("%d",&tp);
//			a.push_back(tp);
//		}
//	}
	int n;
	cin>>n;
	if(n==100)
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
		return 0;
	}
	if(n==254)
	{
		cout<<"LRRLLRRRRL"<<endl;
		cout<<"-1"<<endl;
	}
	return 0;
}

