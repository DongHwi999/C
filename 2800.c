#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <map> 
#include <algorithm>
#include <cmath>
#define CUNLINK ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ENDL cout << endl
#define ll long long
#define INF 987654321
#define Mod 10007
#define endl '\n'
#define pil pair<int,int>

using namespace std;

string s; 
bool visited[12];
bool chk[203];
vector<string> answer;
vector<pair<int, int>> v;

void func(int N, int depth, int start) {
	if (depth == N) {
		memset(chk, false, sizeof(chk));
		for (int i = 0; i < 11; i++) {
			if (visited[i]) {
				int fst = v[i].first;
				int scd = v[i].second;

				chk[fst] = true;
				chk[scd] = true;
			}
		}
		string Temp;
		for (int i = 0; i < s.size(); i++) {
			if (chk[i]) continue;
			Temp += s[i];
		}
		answer.push_back(Temp);
		Temp.clear();
		return;
	}

	for (int i = start; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;

			func(N, depth + 1, i + 1);

			visited[i] = false;
		}
	}
}

int main() {
	CUNLINK;
	cin >> s;
	stack<int> stk;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			stk.push(i);
		}
		else if (s[i] == ')') {
			v.push_back({ stk.top(), i });
			stk.pop();
		}
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= v.size(); i++) {
		func(i, 0, 0);
	}
	sort(answer.begin(), answer.end());
	cout << answer[0] << endl;
	string prev = answer[0];
	for (int i = 1; i < answer.size();i++) {
		if (prev == answer[i]) continue;
		cout << answer[i] << endl;
		prev = answer[i];
	}
	
	return 0;
}
