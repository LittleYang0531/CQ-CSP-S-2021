# include<iostream>
# include<cstdio>
//# define _DEBUG
# ifdef _DEBUG
# endif
# define _INOUT
# ifdef _INOUT
# endif
using namespace std;
int n,k;
string s;
int l[501]={0},lx[501]={0},lnum=0;
int le=0,ri=0;
int ans;
int pd()
{
	for(register int i=0,j=0,lee=0,rii=0;i<=n-1;i++)
	{
		if(s[i]=='(')
			lee++;
		else if(s[i]==')')
			rii++;
		if(lee-rii<0)
			return 1;
		if(s[i]=='*')
		{
			if(lee-rii==0&&((lee==0&&rii==0)||(lee==le&&rii==ri)))
				return 2;
			j++;
		}
		else
			j=0;
		if(j>k)
			return 3;
	}
	return 0;
}
void BLS(int num)
{
	if(num>lnum)
	{
		# ifdef _DEBUG
			cout<<"00 "<<s<<" "<<pd()<<endl;
		# endif
		if(le==ri&&!pd())
		{
			ans++;
			# ifdef _DEBUG
			cout<<ans<<" "<<s<<endl;
			# endif
		}
		return;
	}
	s[l[num]]='*';
	BLS(num+1);
	s[l[num]]='(';
	le++;
	BLS(num+1);
	le--;
	s[l[num]]=')';
	ri++;
	BLS(num+1);
	ri--;
	s[l[num]]='?';
}
bool pl()
{
	for(register int i=0,j=0;i<=n-1;i++)
	{
		if(s[i]=='(')
			le++;
		if(s[i]==')')
			ri++;
		if(s[i]=='?')
			l[++lnum]=i,lx[lnum]=j;
		if(s[i]=='*')
			j++;
		else
			j=0;
		if(j>k)
			return 1;
	}
	return 0;
}
int main()
{
 	# ifdef _INOUT
 	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	# endif
	scanf(" %d %d",&n,&k);
	cin>>s;
	if(s[0]=='?')
		s[0]='(';
	if(s[n-1]=='?')
		s[n-1]=')';
	if(n==0||pl())
	{
		printf("0");
		return 0;
	}
	BLS(1);
	printf("%d",ans);
	return 0;
}

