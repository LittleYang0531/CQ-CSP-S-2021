/*
��������
��Ҫ�ֵ�����С��������
sub1:���ѡ�

�������֪������жϿ����ԣ���ôӦ�û�����ܶࡣ
��ô���ǿ�������ж��� 

����ѡ����һ��������ô���ǵ����һ����Ҳȷ���ˡ�
���б��ֳ������Σ�ǰ���Ƕ��Ǵ�ǰ��ɾ�������Ƕ��ǴӺ���ɾ��
Ȼ��������ѡһ���������ֵ����ڶ���ȷ���ˣ�����Ҫô�Ǻ����Ƕεĵ�һ����Ҫô��ǰ���Ƕε����һ����
Ȼ�����ǰ������ܳ�����С��2.
ǰ���Ƕε�һ��Ϊa,���һ��Ϊb�������Ƕε�һ��Ϊc,���һ��Ϊd�� 
���ǿ�ÿ��ѡ��ǰ�����һ������ʱ�����û���κ�ѡ�����������Ҳ����a!=b,a!=c,d!=b,d!=cʱ���޽�
���ֻ��һ��ѡ���Ǿ�ֻ��ѡ�����
���������ѡ����������Ҫ�ֲ��ǰɣ�
������������������
a=b,c=dʱ�����ǿ϶�ѡa=b�����Ϊ��'L'<'R'��Ȼ����Ӱ�죬��Ϊc=d��Ȼ��ѡ�� 
a=c,b=dʱ�����ǿ϶���Ȼ��ѡa=c����
��ô���Ƿ���ֻ��һ��ѡ��
ֻ�п�ͷѡL����R�ķֲ档 
�����������һ����ѡL�ðɡ� 

2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
#include<cstdio>
void read(int &hhh)
{
	int x=0;
	char c=getchar();
	while((c>'9'||c<'0')&&c!='-')	c=getchar();
	if(c!='-')	x=c^'0';
	char d=getchar();
	while(d>='0'&&d<='9')
	{
		x=(x<<1)+(x<<3)+(d^'0');
		d=getchar();
	}
	if(c!='-')	hhh=x;
	else	hhh=-x;
} 
int t,n,a[1000010],ans[1000010]; 
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	read(t);
	while(t--)
	{
		read(n);
		for(int i=1;i<=n*2;++i)	read(a[i]);
		if(n==1)
		{
			printf("LL\n");
			continue;
		}
		bool suc=1;
		ans[1]=1;
		ans[n*2]=1;
		int onel=2,oner=0,anol=0,anor=n*2;
		for(int i=2;i<=n*2;++i)
		{
			if(a[i]==a[1])
			{
				oner=i-1;
				anol=i+1;
				break;
			}
		}
		for(int i=1;i<n;++i)
		{
			if(oner>onel&&a[oner]==a[onel])
			{
				++onel;
				--oner;
				ans[i+1]=1;
				ans[n*2-i]=1;
				continue;
			}
			if(oner>=onel&&anor>=anol)
			{
				if(a[onel]==a[anol])
				{
					++onel;
					++anol;
					ans[i+1]=1;
					ans[n*2-i]=2;
					continue;
				}
				if(a[oner]==a[anor])
				{
					--oner;
					--anor;
					ans[i+1]=2;
					ans[n*2-i]=1;
					continue;
				}
			}
			if(anor>anol&&a[anor]==a[anol])
			{
				--anor;
				++anol;
				ans[i+1]=2;
				ans[n*2-i]=2;
				continue;
			}
			suc=0;
			break;
		}
		if(suc)
		{
			for(int i=1;i<=n*2;++i)	putchar(ans[i]==1?'L':'R');
			printf("\n");
		}
		else
		{
			suc=1;
			ans[1]=2;
			ans[n*2]=1;
			int onel=1,oner=0,anol=0,anor=n*2-1;
			for(int i=1;i<n*2;++i)
			{
				if(a[i]==a[n*2])
				{ 
					oner=i-1;
					anol=i+1;
					break;
				}
			}
			for(int i=1;i<n;++i)
			{
				if(oner>onel&&a[oner]==a[onel])
				{
					++onel;
					--oner;
					ans[i+1]=1;
					ans[n*2-i]=1;
					continue;
				}
				if(oner>=onel&&anor>=anol)
				{
					if(a[onel]==a[anol])
					{
						++onel;
						++anol;
						ans[i+1]=1;
						ans[n*2-i]=2;
						continue;
					}
					if(a[oner]==a[anor])
					{
						--oner;
						--anor;
						ans[i+1]=2;
						ans[n*2-i]=1;
						continue;
					}
				}
				if(anor>anol&&a[anor]==a[anol])
				{
					--anor;
					++anol;
					ans[i+1]=2;
					ans[n*2-i]=2;
					continue;
				}
				suc=0;
				break;
			}
			if(suc)
			{
				for(int i=1;i<=n*2;++i)	putchar(ans[i]==1?'L':'R');
				printf("\n");
			}
			else	printf("-1\n");
		}
	}
	return 0;
}
