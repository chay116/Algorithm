#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
char visit[876543211];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a;
	string target = "123456780";
	string st = "";
	for (int i = 0; i < 9; i++)
	{
		cin >> a;
		st += a + '0';
	}
	queue<pair<string, int> > q;
	visit[stoi(st)] = 1;
	q.push({st, 0});
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		if (cur.first == target)
		{
			cout << cur.second << '\n';
			return 0;
		}
		for (int i = 0; i < 9; i++)
		{
			if (cur.first[i] == '0')
			{
				if (i + 1 < 9)
				{
					string ori = "";
					ori += cur.first;
					swap(ori[i], ori[i + 1]);
					if (!visit[stoi(ori)])
					{
						q.push({ori, cur.second + 1});
						visit[stoi(ori)] = 1;
					}
				}
				if (i - 1 >= 0)
				{
					string ori = "";
					ori += cur.first;
					swap(ori[i], ori[i - 1]);
					if (!visit[stoi(ori)])
					{
						q.push({ori, cur.second + 1});
						visit[stoi(ori)] = 1;
					}
				}
				if (i + 3 < 9)
				{
					string ori = "";
					ori += cur.first;
					swap(ori[i], ori[i + 3]);
					if (!visit[stoi(ori)])
					{
						q.push({ori, cur.second + 1});
						visit[stoi(ori)] = 1;
					}
				}
				if (i - 3 >= 0)
				{
					string ori = "";
					ori += cur.first;
					swap(ori[i], ori[i - 3]);
					if (!visit[stoi(ori)])
					{
						q.push({ori, cur.second + 1});
						visit[stoi(ori)] = 1;
					}
				}
			}
		}
	}
	cout << -1 << '\n';
	return 0;
}