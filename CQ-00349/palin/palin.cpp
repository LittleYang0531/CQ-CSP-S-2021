# include<iostream>
# include<cstdio>
//# define _DEBUG
# ifdef _DEBUG
# include<windows.h>
# endif
# define _INOUT
# ifdef _INOUT
# endif
using namespace std;
int n=0,a[1000005]={0};
int k[1000005]={0},num=1;
string ans,Empty;
bool anspd=1;
bool pd(int pdd[])
{
	for(register int i=1;i<=n;i++)
		if(pdd[i]!=pdd[n*2-i+1])
			return 0;
	return 1;
}
void BLS(string h,int m,int l,int r)
{
	/*# ifdef _DEBUG
	cout<<h<<" "<<m<<" "<<l<<" "<<r<<endl;
	# endif*/
	/*# ifdef _DEBUG
	for(register int i=1;i<=n*2;i++)
		cout<<k[i]<<" ";
	cout<<endl;
	cout<<h<<endl<<m<<" "<<l<<" "<<r<<endl;
	Sleep(50);
	# endif*/
	if(m==n*2)
	{
		/*# ifdef _DEBUG
		cout<<"Yes1"<<endl;
		# endif*/
		if(pd(k))
		{
			/*# ifdef _DEBUG
			cout<<"Yes2"<<endl;
			for(register int i=1;i<=n*2;i++)
				cout<<k[i]<<" ";
			cout<<endl;
			cout<<h<<endl<<m<<" "<<l<<" "<<r<<endl;
			system("pause");
			# endif*/
			if(anspd)
				ans=h,anspd=0;
			else
				ans=ans<h ? ans : h;
		}
		return;
	}
	num++;
	k[num-1]=a[l];
	BLS(h+"L",m+1,l+1,r);
	k[num-1]=a[r];
	BLS(h+"R",m+1,l,r-1);
	k[num-1]=0;
	num--;
	return;
}
int main()
{
	register short T=0;
 	# ifdef _INOUT
 	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	# endif
	scanf(" %d",&T);
	while(T--)
	{
		scanf(" %d",&n);
		for(register int i=1;i<=n*2;i++)
			scanf(" %d",&a[i]);
		if(pd(a))
		{
			for(register int i=1;i<=n*2;i++)
				printf("L");
			printf("\n");
		}
		else if(a[1]==a[n]*2)
			printf("-1\n");
		BLS(Empty,0,1,n*2);
		if(anspd)
			printf("-1\n");
		else
			cout<<ans<<endl;
		for(register int i=1;i<=n*2;i++)
			a[i]=0;
		ans=Empty;
		anspd=1;
	}
	# ifdef _DEBUG
	system("pause");
	# endif
	return 0;
}

