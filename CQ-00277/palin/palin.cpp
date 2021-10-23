#include<bits/stdc++.h>
using namespace std;
bool flag;
int _,n,P,p,pos,Pos,A[200005],Nxt[100005],Lst[100005],top,Q[100005],head,s[100005],Head,S[100005];
inline void L()
{
	P=Lst[A[1]];
	for(register int i=2;i<P;++i)
	{
		if(Lst[A[i]]==i) continue;
		if(Lst[A[i]]<P)
			if(Pos<Lst[A[i]]) {flag=1;break;}
			else Pos=Lst[A[i]];
		else if(pos>Lst[A[i]]) {flag=1;break;}
		else pos=Lst[A[i]];
	}
	if(flag) return;
	Pos=n;
	for(register int i=P+1;i<=n;++i)
	{
		if(Nxt[A[i]]<P) {Q[++top]=i;continue;}
		if(Lst[A[i]]==i) continue;
		if(Pos<Lst[A[i]]) {flag=1;break;}
		else Pos=Lst[A[i]];
	}
	if(flag) return;
	s[++head]=1,S[++Head]=1,pos=P+1,Pos=n;
	for(register int i=2;i<P;++i)
	{
		if(Lst[A[i]]<P)
		{
			while(top&&Lst[A[i]]<Nxt[Q[top]])
			{
				while(Q[head]<=Pos) s[++head]=2,--Pos;
				--top;
			}
			s[++head]=1;continue;
		}
		while(A[i]!=A[pos]) s[++head]=2,S[++Head]=2,++pos;
		s[++head]=1,S[++Head]=2,++pos;
	}
	if(head+Head>n) {flag=1;return;}
	for(register int i=1;i<=head;++i)
		if(s[i]&1) printf("L");
		else printf("R");
	for(register int i=Head;i;--i)
		if(S[i]&1) printf("L");
		else printf("R");
	printf("\n");
}
inline void R()
{
	flag=head=Head=0,P=Nxt[A[n]],pos=0,Pos=P-1;
	for(register int i=1;i<P;++i)
	{
		if(Lst[A[i]]==i) continue;
		if(Lst[A[i]]<P)
			if(Pos<Lst[A[i]]) {flag=1;break;}
			else Pos=Lst[A[i]];
		else if(pos>Lst[A[i]]) {flag=1;break;}
		else pos=Lst[A[i]];
	}
	if(flag) return;
	Pos=n;
	for(register int i=P+1;i<n;++i)
	{
		if(Nxt[A[i]]<P) Q[++top]=i;
		if(Lst[A[i]]==i) continue;
		if(Pos<Lst[A[i]]) {flag=1;break;}
		else Pos=Lst[A[i]];
	}
	if(flag) return;
	s[++head]=2,S[++Head]=1,pos=P+1,Pos=n;
	for(register int i=2;i<P;++i)
	{
		if(Lst[A[i]]<P)
		{
			while(top&&Lst[A[i]]<Nxt[Q[top]])
			{
				while(Q[head]<=Pos) s[++head]=2,--Pos;
				--top;
			}
			s[++head]=1;continue;
		}
		while(A[i]!=A[pos]) s[++head]=2,S[++Head]=2,++pos;
		s[++head]=1,S[++Head]=2,++pos;
	}
	if(head+Head>n) {flag=1;return;}
	for(register int i=1;i<=head;++i)
		if(s[i]&1) printf("L");
		else printf("R");
	for(register int i=Head;i;--i)
		if(S[i]&1) printf("L");
		else printf("R");
	printf("\n");
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&_);
	for(register int __=1;__<=_;++__)
	{
		scanf("%d",&n);for(register int i=1;i<=n;++i) Nxt[i]=Lst[i]=0;n*=2,Pos=n,flag=head=Head=0;
		for(register int i=1;i<=n;++i)
		{
			scanf("%d",&A[i]);
			if(!Nxt[A[i]]) Nxt[A[i]]=i;
			else Lst[A[i]]=i;
		}
		L();if(!flag) continue;
		R();if(!flag) continue;
		printf("-1\n");
	}
	return 0;
}
