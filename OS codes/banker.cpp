#include <iostream>
using namespace std;
int main()
{
	int n, m, i, j, k;
	cout << "Enter number of processes: ";
	cin >> n;
	cout << "Enter number of resource types: ";
	cin >> m;
	int alloc[n][m];
	int max[n][m];
	int instance[m];
	int avail_sum[m];
	int avail[m];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout << "Allocation for P" << i << " alloc[" << i << "][" << j << "]: ";
			cin >> alloc[i][j];
		}
		cout << endl;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout << "Maximum for P" << i << " max[" << i << "][" << j << "]: ";
			cin >> max[i][j];
		}
		cout << endl;
	}
	cout << endl
		 << "Enter available instances for each resource type: ";
	for (i = 0; i < m; i++)
	{
		cin >> instance[i];
	}
	int sum = 0;

	for (i = 0; i < m; i++)
	{
		sum = 0;
		for (j = 0; j < n; j++)
		{
			sum += alloc[j][i];
		}
		avail_sum[i] = sum;
	}
	for (i = 0; i < m; i++)
	{
		avail[i] = instance[i] - avail_sum[i];
	}
	cout << "Allocation :" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout << alloc[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Max :" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout << max[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl
		 << "Available instances for each resource type: ";
	for (i = 0; i < m; i++)
	{
		cout << avail[i] << " ";
	}
	cout << endl;
	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++)
	{
		f[k] = 0;
	}
	int need[n][m];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	int y = 0;
	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			if (f[i] == 0)
			{
				int flag = 0;
				for (j = 0; j < m; j++)
				{
					if (need[i][j] > avail[j])
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}
	int flag = 1;
	// To check if sequence is safe or not
	for (i = 0; i < n; i++)
	{
		if (f[i] == 0)
		{
			flag = 0;
			cout << endl
				 << "The given sequence is not safe" << endl;
			break;
		}
	}
	if (flag == 1)
	{
		cout << endl
			 << "Following is the SAFE Sequence" << endl;
		for (i = 0; i < n - 1; i++)
			cout << " P" << ans[i] << "->";
		cout << " P" << ans[n - 1] << endl;
	}
	return 0;
}