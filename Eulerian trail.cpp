#include <bits/stdc++.h>
std::ifstream fin ("input.txt" );
std::ofstream fout("output.txt");
#define e5  100000
#define e6  1000000
#define e9  1000000000
#define mod %1000000007
#define e18 1000000000000000000
#define ll long long
#define loop(b) for (int i=0;i<b;i++)
#define hmap unordered_map
#define hset unordered_set
#define get cin>>
#define put cout<<
#define str string
#define v vector
using namespace std;

const str alphabetLower ="abcdefghijklmnopqrstuvwxyz";
const str alphabetHigher="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const str digits="0123456789";
deque<int>cycles[3*e5];
int bw=0;
stack<int>ans;
void foo(int cur){
	cout<<cur+1<<" ";
	bool k=!cycles[cur].empty();
	while (!cycles[cur].empty()){
	    int a=cycles[cur].front();
	    cycles[cur].pop_front();
	    foo(a);
	}
	if (k&&cur!=bw)cout<<cur+1<<" ";
}
void run(){
	int n,m;get n>>m;
	multiset<int>gr[n],gw[n];
	for (;m>0;m--){
		int x,y;
		str a;
		get x>>y;//>>a;
		/*if (a=="white"){
			gw[--x].insert(--y);
			gw[y].insert(x);
		} else {
			gr[--x].insert--y);
			gr[y].insert(x);
		}*/
		gw[--x].insert(--y);
		gw[y].insert(x);
	}
	v<int>odd;
	for (int i=0;i<n;i++){
		if (gw[i].size()%2)odd.push_back(i);
	}
	if (odd.size()==0||odd.size()==2){
		if (odd.size()){
			gw[odd[0]].insert(odd[1]);
			gw[odd[1]].insert(odd[0]);
			bw=odd[0];
		}
		for (int i=bw;i!=(bw-1==-1?n-1:bw-1);i=(i+1)%n){
			int te=i,p=i;
			//cerr<<i<<endl;
			for (int j:gw[te]){
				if (j!=p){te=j;break;}
			}
			if (i==bw&&odd.size())te=odd[1];
			while (te!=i){
				gw[te].erase(p);
				gw[p].erase(te);
				if (i==bw&&odd.size())cycles[i].push_front(te);
				else cycles[i].push_back(te);
				for (int j:gw[te])if (j!=p){p=te;te=j;break;}
			}
			gw[te].erase(p);
			gw[p].erase(te);
		}
		foo(bw);
	} else put "NONE";
}

int main() {ios::sync_with_stdio(0);cin.tie(0);run();return 0;}