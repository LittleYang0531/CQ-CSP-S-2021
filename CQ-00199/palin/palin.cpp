#include<bits/stdc++.h>
using namespace std;
int T,n,tot=1;
int a[500005];
int shunxu[500005];
vector<char> ans;
char anss[500005];
vector<int> hasaa;
vector<char> tmpaa;
vector<char> ansaa;
int laa,raa;
bool check(){
	for(register int i=1;i<=n;i++)
		if(hasaa[i]!=hasaa[n+1-i]) return false;
	if(ansaa.size()==1) return true;
	for(register int i=1;i<=n;i++){
		if(ansaa[i]>tmpaa[i]) return true;
		if(ansaa[i]<tmpaa[i]) return false;
	}
	return false;
}
void change_ans(){
	ansaa.clear(); ansaa.push_back('H');
	for(register int i=1;i<=n;i++){
		ansaa.push_back(tmpaa[i]);
	}
}
void dfs(int sum){
	if(sum==n){
		if(check()) change_ans();
		return;
	}
	if(laa>raa) return;
	hasaa.push_back(a[laa]);
	laa++;
	tmpaa.push_back('L');
	dfs(sum+1);
	hasaa.pop_back();
	tmpaa.pop_back();
	laa--;
	hasaa.push_back(a[raa]);
	tmpaa.push_back('R');
	raa--;
	dfs(sum+1);
	hasaa.pop_back();
	raa++;
	tmpaa.pop_back();
}
bool check_ans(int pos){
	int rlpos=pos,rrpos=pos,llpos=pos-n/2,lrpos=pos-n/2;
	while(rrpos-rlpos+lrpos-llpos+2!=n){
		if(a[rrpos+1]==a[rlpos-1]){
			tot++;
			rrpos++,rlpos--;
			shunxu[tot]=a[rrpos];
		}
		else if(a[rrpos+1]==a[lrpos+1]){
			tot++;
			rrpos++,lrpos++;
			shunxu[tot]=a[rrpos];
		}
		else if(a[rlpos-1]==a[llpos-1]){
			tot++;
			rlpos--,llpos--;
			shunxu[tot]=a[rlpos];
		}
		else if(a[llpos-1]==a[lrpos+1]){
			tot++;
			llpos--,lrpos++;
			shunxu[tot]=a[llpos];
		}
		else return false;
	}
	int lpos=1,rpos=n;
	n/=2;
	for(register int i=n;i>=1;i--){
		if(a[lpos]==shunxu[i]) {
			ans.push_back('L');
			lpos++;
		}
		else {
			ans.push_back('R');
			rpos--;
		}
	}
	for(register int i=1;i<=n;i++){
		if(a[lpos]==shunxu[i]) {
			ans.push_back('L');
			lpos++;
		}
		else {
			ans.push_back('R');
			rpos--;
		}
	}
	return true;
}
int tmplen;
bool check_two(int i){
	for(register int j=i+2;j<tmplen;j++)
		if(a[j]==a[j+1]){
			if(j-i!=tmplen/2) return false;
			else return true;
		}
	return false;
}
int main(){
	ifstream rosein("palin.in");
	ofstream roseout("palin.out");
	//#define rosein rosein
	//#define roseout roseout
	rosein>>T;
	while(T--){
		hasaa.clear();
		ansaa.clear();
		tmpaa.clear();
		tmpaa.push_back('H');
		ansaa.push_back('H');
		hasaa.push_back(0);
		rosein>>n;
		if(n<=10){
			n*=2;
			for(register int i=1;i<=n;i++) rosein>>a[i];
			laa=1,raa=n;
			hasaa.push_back(a[laa]);
			tmpaa.push_back('L');
			laa++;
			dfs(1);
			hasaa.pop_back();
			tmpaa.pop_back();
			laa--;
			hasaa.push_back(a[raa]);
			tmpaa.push_back('R');
			raa--;
			dfs(1);
			if(ansaa.size()==1) roseout<<"-1\n";
			else {
				for(register int i=1;i<=n;i++)
					roseout<<ansaa[i];
				roseout<<"\n";
			}
		}
		else {
			int flag=0;
			tmplen=n*2;
			n*=2;
			for(register int i=n;i>=n/2+1;i--){
				if(a[i]==a[i-n/2]){
					flag=0;
					memset(shunxu,0,sizeof shunxu);
					shunxu[1]=a[i];
					tot=1;
					ans.clear();
					if(check_ans(i)){
						flag=1;
						//roseout<<ans<<"\n";
						int len=ans.size();
						for(register int i=0;i<len;i++)
							roseout<<ans[i];
						roseout<<"\n";
						break;
					}
				}
			}
			if(!flag){
				memset(shunxu,0,sizeof shunxu);
				for(register int i=1;i<tmplen;i++){
					if(a[i]==a[i+1]){
						int flag_two=0;
						for(register int j=i+2;j<tmplen;j++)
							if(a[j]==a[j+1]){
								flag_two++;
							}
						if(flag_two==1){
							if(check_two(i)){
								for(register int j=1;j<=i;j++)
									roseout<<'L';
								for(register int j=1;j<=tmplen/2-i;j++)
									roseout<<'R';
								for(register int j=1;j<=tmplen/2-i;j++)
									roseout<<'R';
								for(register int j=1;j<=i;j++)
									roseout<<'L';
								roseout<<"\n";
								flag=1;
							}
							else break;
						}
						else if(!flag_two){
							if(i!=tmplen/2) {
								int tmpl=i,tmpr=i+1;
								while(a[tmpl]==a[tmpr]){
									tmpl--; tmpr++;
								}
								int tmppos=tmplen/2;
								for(register int i=1;i<=(tmpr-tmpl)/2;i++){
									anss[tmppos]='L'; anss[tmppos+i*2-1]='L';
								}
								for(register int k=1;k<=tmplen;k++)
									roseout<<'L';
								roseout<<"\n";
								flag=1;
								//rnm ccf
							}
							else {
								for(register int j=1;j<=tmplen;j++)
									roseout<<'L';
								roseout<<"\n";
								flag=1;
							}
						}
					}
				}
			}
			if(!flag) roseout<<"-1\n";
		}
	}
	return 0;
}
