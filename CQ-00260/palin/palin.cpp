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
#include <vector>
std::vector<int> str;
int t, n;
std::vector<int> vis;
#include <deque>
int main(){
	io_init("palin");
	fin >> t;
	while (t--){
		fin >> n;
		str.clear();
		str.resize(n << 1);
		for (auto& it: str){
			fin >> it;
			--it;
		}
		if (n > 30){
			fout << -1 << std::endl;
			continue;
		}
		std::deque<int> dq_base;
		for (auto x: str)
			dq_base.push_back(x);
		int ansx = -1,ansy = -1;
		for (int x = 0; x < 1 << n; ++x){
			auto dq = dq_base;
			std::deque<int> mem;
			vis.clear();
			vis.resize(n);
			bool flag = false;
			for (int i = n - 1; ~i; --i){
				if ((x >> i) & 1){
					if (vis[dq.back()]){
						flag = true;
						break;
					}
					vis[dq.back()] = true;
					mem.push_back(dq.back());
					dq.pop_back();
				}else{
					if (vis[dq.front()]){
						flag = true;
						break;
					}
					vis[dq.front()]= true;
					mem.push_back(dq.front());
					dq.pop_front();
				}
			}
			if (flag)
				continue;
			int y = 0;
			bool flag1 = false;
			while (!mem.empty()){
				if (mem.back() == dq.front()){
					y = y << 1;
					mem.pop_back();
					dq.pop_front();
				}else if(mem.back() == dq.back()){
					y = y << 1 | 1;
					mem.pop_back();
					dq.pop_back();
				}else{
					flag1 = true;
					break;
				}
			}
			if (flag1)
				continue;
			ansx = x, ansy = y;
			break;
		}
		if (!~ansx && !~ansy)
			fout << -1 << std::endl;
		else{
			for (int i = n - 1; ~i; --i)
				fout << (((ansx >> i) & 1)? 'R': 'L');
			for (int i = n - 1; ~i; --i)
				fout << (((ansy >> i) & 1)? 'R': 'L');
			fout << std::endl;
 		}
	}
	return 0;
}
