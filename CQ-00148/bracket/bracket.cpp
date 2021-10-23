/*
那个gmon.out是个什么？？？
为什么每次程序运行完就有一个

首先它一定是左右括号可匹配的。
然后我们看看：
若相匹配的括号中间没有别的括号，则他们中间只能是<=k个*。
否则他们往中间靠一个字符不能是*。
？
我在干嘛
设dp[i][j][k][l]表示当前字符串[i,j]左右分别为k,l时的合法方案数。
？？？
用不着后面两维了吧。
只有k='(',l='('时才可能合法。
然后我们开始乱整：
1.模拟规则，若中间没有或全是*，我们可以整一个方案。
2.再模拟规则，我们枚举哪边是哪边，然后直接dp[i][j]+=dp[i][k]*dp[k+1][j]（由于匹配的括号都不一样，方案肯定不一样）
3.再模拟规则，我们看dp[i+1][j-1]是否可行，然后dp[i][j]+=dp[k][j-1],dp[i][j]+=dp[i+1][k]（k!=i+1,k!=j-1,需要i+1~k-1/k+1~j-1全部都是*）（由于这次的括号匹配位置不一样还是不一样的方案） 
我们得到了n^3的优秀做法。 
125000000，看起来不太像跑得过的样子。 
但没办法。
7 3
(*??*??

？？？拼起来的时候漏了一种情况，就是在两个串中间插入一堆*…… 
我要是暴力看怎么拼就真的跑不过了。
for(long long k=i;k<j;++k)
{
	long long bas=dp[i][k],ano=dp[k+1][j];
	for(long long l=k+2;l<=j&&l-k-1<=K;++l)
	{
		if(!canbestar(l-1))	break;
		ano+=dp[l][j];
	}
	dp[i][j]=(dp[i][j]+bas*ano)%mod;
}
好的暴力对了呢。

10 2
???(*??(?) 
啊不暴力没对。 
看起来像是算重了的样子。 
()*()*()
()*()+*+()
()+*+()*()
算了两次…… 
dp[i][j][0/1]表示[i,j]是否为i,j匹配的合法方案数。

好现在对了，我们优化一下这个n^4. 
目的是要找到一长段可以*的。（* 名词活用作动词~） 

屑屑你，出题人。
还要卡常是吧。

我是反向卡常滴神！！！ 
O2也救不了我…… 

500个问号跑3s…… 

算了我选择相信CCF的机子开O2=_= 
*/
#include<cstdio>
const long long mod=1e9+7;
long long n,K,dp[510][510][3],hb[510],tmp[510];
bool cbl[510],cbr[510],cbs[510];
char str[510];
bool canbeleft(long long x)
{
	return str[x]=='('||str[x]=='?';
}
bool canberight(long long x)
{
	return str[x]==')'||str[x]=='?';
}
bool canbestar(long long x)
{
	return str[x]=='*'||str[x]=='?';
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%lld %lld %s",&n,&K,str+1);
	hb[n+1]=n;
	for(long long i=n;i>=1;--i)
	{
		cbl[i]=canbeleft(i);
		cbr[i]=canberight(i);
		cbs[i]=canbestar(i);
		if(cbs[i])
		{
			if(hb[i+1]!=i)	hb[i]=hb[i+1];
			else	hb[i]=i;
		}
		else	hb[i]=i-1;
	}
	for(long long len=2;len<=n;++len)
	{
		for(long long i=1;i+len-1<=n;++i)
		{
			long long j=i+len-1;
			if(!cbl[i]||!cbr[j])	continue;
			bool flag=(i==j-1);
			if(!flag&&(len-2<=K))
			{
				flag=1;
				for(long long k=i+1;k<j;++k)
				{
					if(!cbs[k])
					{
						flag=0;
						break;
					}
				}
			}
			if(flag)	dp[i][j][1]=1;
			
			tmp[i]=0;
			for(long long k=i+1;k<=j;++k)	tmp[k]=(tmp[k-1]+dp[k][j][1])%mod;
			for(long long k=i;k<j;++k)
			{
				long long bas=dp[i][k][2];
				long long l=k+1,r=hb[k+1]+1;
				if(r>j)	r=j;
				if(r-k-1>K)	r=K+k+1;
				long long ano=(tmp[r]-tmp[l-1]+mod)%mod;
				dp[i][j][0]=(dp[i][j][0]+bas*ano)%mod;
			}
			
			dp[i][j][1]=(dp[i][j][1]+dp[i+1][j-1][2])%mod;
			for(long long k=i+2;k<j-1;++k)
			{
				if(k-i-1>K||!canbestar(k-1))	break;
				dp[i][j][1]=(dp[i][j][1]+dp[k][j-1][2])%mod;
			}
			for(long long k=j-2;k>i+1;--k)
			{
				if(j-1-k>K||!canbestar(k+1))	break;
				dp[i][j][1]=(dp[i][j][1]+dp[i+1][k][2])%mod;
			}
			dp[i][j][2]=(dp[i][j][1]+dp[i][j][0])%mod; 
		}
	}
	printf("%lld\n",dp[1][n][2]);
	return 0;
}
