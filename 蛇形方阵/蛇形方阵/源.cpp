#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int N, M;
		cin >> N >> M;
		vector<vector<int>> v(N, vector<int>(N, 0));
		v[0][0] = 1;
		vector<int> vv;
		int n = 1;
		int x = 0;
		int y = 0;
		while (n < N * N)
		{
			while (y + 1 < N && !v[x][y + 1])
			{
				v[x][y] = n;
				y += 1;
				n += 1;
			}
			while (x + 1 < N && !v[x + 1][y])
			{
				v[x][y] = n;
				x += 1;
				n += 1;
			}
			while (y - 1 >= 0 && !v[x][y - 1])
			{
				v[x][y] = n;
				y -= 1;
				n += 1;
			}
			while (x - 1 >= 0 && !v[x - 1][y])
			{
				v[x][y] = n;
				x -= 1;
				n += 1;
			}
		}
		for (int i = 0; i < M; i++)
		{
			int x, y;
			cin >> x >> y;
			if (x < N && y < N)
			{
				vv.push_back(v[x][y]);
			}
		}
		for (int i = 0; i < vv.size(); i++)
		{
			cout << vv[i] << endl;
		}
	}
	system("pause");
	return 0;
}