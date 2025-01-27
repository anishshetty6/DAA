// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	void shortest_distance(vector<vector<int>> &m)
	{
		// Code here
		int n = m.size();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (m[i][j] == -1)
					m[i][j] = 1e9;
				if (i == j)
					m[i][j] = 0;
			}
		}
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (m[i][j] == 1e9)
					m[i][j] = -1;
			}
		}
	}
};
int main()
{

	int n;
	cin >> n;
	vector<vector<int>> matrix(n, vector<int>(n, -1));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
	Solution obj;
	obj.shortest_distance(matrix);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}