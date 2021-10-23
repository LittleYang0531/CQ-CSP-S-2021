# include<iostream>
# include<cstdio>
# include<map>
# include<algorithm>
//# define _DEBUG
# ifdef _DEBUG
# include<windows.h>
# endif
# define _INOUT
# ifdef _INOUT
# endif
using namespace std;
const int N=100001;
struct node{
	int val,num;
}x[200001],y[200001];
int d1[100001]={0},d2[100001]={0};
bool v[100001]={0};
map<int,int> a,b;
bool cmp(node aa,node bb)
{
	return aa.val<bb.val;
}
int main()
{
	register int n=0,m1=0,m2=0,ans=0;
 	# ifdef _INOUT
 	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	# endif
	scanf(" %d %d %d",&n,&m1,&m2);
	for(register int i=2;i<=m1*2;i+=2)
	{
		scanf(" %d %d",&x[i-1].val,&x[i].val);
		x[i-1].num=i>>1,x[i].num=i>>1;
	}
	sort(x+1,x+m1*2+1,cmp);

	# ifdef _DEBUG
	cout<<endl;
	for(register int i=1;i<=m1*2;i++)
		cout<<x[i].val<<" "<<x[i].num<<endl;
	cout<<endl;
	# endif

	for(register int i=2;i<=m2*2;i+=2)
	{
		scanf(" %d %d",&y[i-1].val,&y[i].val);
		y[i-1].num=i>>1,y[i].num=i>>1;
	}
	sort(y+1,y+m2*2+1,cmp);

	# ifdef _DEBUG
	cout<<endl;
	for(register int i=1;i<=m2*2;i++)
		cout<<y[i].val<<" "<<y[i].num<<endl;
	cout<<endl;
	# endif

	for(register int i=1,NOW=1;i<=m1*2;i++)
	{
		if(!d1[x[i].num])
		{
			d1[x[i].num]=NOW;
			++a[NOW];
			v[NOW]=1;
			for(register int j=NOW+1;j<=N;++j)
				if(!v[j])
				{
					NOW=j;
					break;
				}
			# ifdef _DEBUG
			cout<<"001 "<<x[i].val<<" "<<x[i].num<<" "<<d1[x[i].num]<<" "<<NOW<<endl;
			# endif
		}
		else if(d1[x[i].num])
		{
			v[d1[x[i].num]]=0;
			NOW= d1[x[i].num]<NOW ? d1[x[i].num] : NOW;
			# ifdef _DEBUG
			cout<<"002 "<<x[i].val<<" "<<x[i].num<<" "<<d1[x[i].num]<<" "<<NOW<<endl;
			# endif
		}
	}

	# ifdef _DEBUG
	cout<<endl;
	# endif

	for(register int i=1,NOW=1;i<=m2*2;i++)
	{
		if(!d2[y[i].num])
		{
			d2[y[i].num]=NOW;
			++b[NOW];
			v[NOW]=1;
			for(register int j=NOW+1;j<=N;++j)
				if(!v[j])
				{
					NOW=j;
					break;
				}
			# ifdef _DEBUG
			cout<<"001 "<<y[i].val<<" "<<y[i].num<<" "<<d2[y[i].num]<<" "<<NOW<<endl;
			# endif
		}
		else if(d2[y[i].num])
		{
			v[d2[y[i].num]]=0;
			NOW= d2[y[i].num]<NOW ? d2[y[i].num] : NOW;
			# ifdef _DEBUG
			cout<<"002 "<<y[i].val<<" "<<y[i].num<<" "<<d2[y[i].num]<<" "<<NOW<<endl;
			# endif
		}
	}
	for(register int i=1;i<=n;i++)
		a[i]+=a[i-1],b[i]+=b[i-1];
	
	# ifdef _DEBUG
	cout<<endl;
	for(register int i=1;i<=m1;i++)
		cout<<d1[i]<<" ";
	cout<<endl;
	for(register int i=1;i<=m2;i++)
		cout<<d2[i]<<" ";
	cout<<endl;
	for(register int i=0;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	for(register int i=0;i<=n;i++)
		cout<<b[i]<<" ";
	cout<<endl;
	# endif

	for(register int i=0;i<=n;i++)
		ans= ans>a[i]+b[n-i] ? ans : a[i]+b[n-i];
	printf("%d\n",ans);
	# ifdef _DEBUG
	system("pause");
	# endif
	return 0;
}

