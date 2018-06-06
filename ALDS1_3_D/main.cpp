#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	stack<int> S1;
	stack<pair<int, int> > S2;
	char ch;
	int sum = 0;

	for (int i = 0; cin >> ch; i++) {
		if (ch == '\\') {
			S1.push(i);
		} else if (ch == '/' && S1.size() > 0) {
			int j = S1.top(); S1.pop();
			sum += i - j;
			int a = i - j;
			while (S2.size() > 0 && S2.top().first > j) {
				a += S2.top().second; S2.pop();
			}
			S2.push(make_pair(j, a));
		}
	}

	vector<int> V;
	while (S2.size() > 0) {
		V.push_back(S2.top().second); S2.pop();
	}
	reverse(V.begin(), V.end());

	cout << sum <<endl;
	cout << V.size();
	for (int i = 0; i < V.size(); i++) {
		cout << " ";
		cout << V[i];
	}
	cout << endl;
	return 0;
}
