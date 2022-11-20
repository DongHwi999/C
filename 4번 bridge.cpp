#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[100001];
struct info {
	int start, dest;
};
struct cmp {
	bool operator()(info &a, info &b) {
		if (a.start == b.start)
			return a.dest > b.dest;
		return a.start > b.start;
	}
};
info tmp;
priority_queue<info, vector<info>, cmp> pq;
int check[100001];
int node, edge, s, e, cnt;

int dfs(int here, int root) {
	check[here] = ++cnt;
	int ret = check[here];
	for (int i = 0; i < v[here].size(); i++) {
		int next = v[here][i];
		if (root == next) continue;
		if (check[next]) {
			ret = min(ret, check[next]);
			continue;
		}
		int prev = dfs(next, here);
		if (prev >= check[here]) {
			tmp.start = min(here, next);
			tmp.dest = max(here, next);
			pq.push(tmp);
		}
		ret = min(ret, prev);
	}	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	for (int i = 1; i <= node; i++) 
		if (check[i] == 0) 
			dfs(i, 0);
	cout << pq.size() << '\n';
	while (!pq.empty()) {
		int cs = pq.top().start;
		int cd = pq.top().dest;
		pq.pop();
		cout << cs << " " << cd << '\n';
	}
	system("pause");
	return 0;
}
