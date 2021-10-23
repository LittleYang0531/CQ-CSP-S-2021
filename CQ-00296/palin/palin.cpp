#include <bits/stdc++.h>

int T,n,head,tail;
int A[500010],B[500010];
int V[500010];
bool vis[500010],link[500010];

std :: vector <char> Check ();

int main () {
	freopen ("palin.in","r",stdin);
	freopen ("palin.out","w",stdout);

	scanf ("%d",&T);
	
	while (T --) {
		memset (V,0,sizeof (V));
		
		scanf ("%d",&n);
		for (int i = 1;i <= (n << 1);++ i) {
			scanf ("%d",A + i);
			if(! V[A[i]]) V[A[i]] = i;
			else B[i] = V[A[i]],B[V[A[i]]] = i;
		}
		
		memset (vis,false,sizeof (vis));
		memset (link,false,sizeof (link));
		link[B[1]] = true;
		std :: vector <char> ans;
		
		ans = Check ();
		
		int siz = ans.size ();
		
		if (siz < n) {
			memset (vis,false,sizeof (vis));
			memset (link,false,sizeof (link));
			link[B[n << 1]] = true;
			
			ans = Check ();
			
			siz = ans.size ();
			if (siz < n) {
				printf ("-1\n");
				continue;
			}
		}
		
		for (int i = siz - 1,l = head,r = tail;i >= 0;-- i) {
			int num = ans[i] == 'L' ? A[-- l] : A[++ r];
			if (A[head] == num) {
				ans.push_back ('L');
				++ head;
			}
			else if (A[tail] == num) {
				ans.push_back ('R');
				-- tail;
			}
		}
		
		for (int i = 0;i < ans.size();++ i) printf ("%c",ans[i]);
		printf ("\n");
	}
	
	return 0;
}

std :: vector <char> Check () {
	head = 1,tail = n << 1;
	std :: vector <char> ans;
	while (1) {
		if (link[B[head]] && ! vis[A[head]]) {
			ans.push_back ('L');
			vis[A[head]] = true;
			link[B[head] - 1] = link[B[head] + 1] = true;
			++ head;
		}
		else if (link[B[tail]] && ! vis[A[tail]]) {
			ans.push_back ('R');
			vis[A[tail]] = true;
			link[B[tail] - 1] = link[B[tail] + 1] = true;
			-- tail;
		}
		else break;
	}
	return ans;
}
