#include <iostream>
//#define DEBUG_STANDIO
#ifndef DEBUG_STANDIO
#include <fstream>
std::ifstream fin;
std::ofstream fout;
#else
#define fin std::cin
#define fout std::cout
#endif
#include <cstring>
void io_init(std::string path_){
#ifndef DEBUG_STANDIO
	fin.rdbuf()->pubsetbuf(nullptr, 1 << 23);
	fout.rdbuf()->pubsetbuf(nullptr, 1 << 23);
	fin.open(path_ + ".in");
	fout.open(path_ + ".out"); 
#else
	std::ios::sync_with_stdio(false);
#endif
}
#include <algorithm>
#include <map>
#include <vector>
std::vector<std::pair<int,int>> cplanes, fplanes; 
#include <queue>
int n, fm, cm;
int spendcount_c(int value){
	int res = 0, now = 0;
	std::priority_queue<int, std::vector<int>, std::greater<int>> q;
	for (auto it: cplanes){
		while(!q.empty() && q.top() < it.first){
			q.pop();
			--now;
		}
		if (now < value){
			++now, ++res;
			q.push(it.second);
		}
	}
	return res;
}
int spendcount_f(int value){
	int res = 0, now = 0;
	std::priority_queue<int, std::vector<int>, std::greater<int>> q;
	for (auto it: fplanes){
		while(!q.empty() && q.top() < it.first){
			--now;
			q.pop();
		}
		if (now < value){
			++now, ++res;
			q.push(it.second);
		}
	}
	return res;
}
int main(){
	io_init("airport");
	fin >> n >> cm >> fm;
	cplanes.resize(cm);
	fplanes.resize(fm);
	for (auto& it: cplanes)
		fin >> it.first >> it.second;
	std::sort(cplanes.begin(), cplanes.end());
	for (auto& it: fplanes)
		fin >> it.first >> it.second;
	std::sort(fplanes.begin(), fplanes.end());
	int ans = 0;
	for (int i = 0; i <= n; ++i){
		const int x = i, y = n - i;
		ans = std::max(ans, spendcount_c(x) + spendcount_f(y));
	}
	fout << ans << std::endl;
	return 0;
}
