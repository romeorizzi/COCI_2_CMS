#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a;
int b;
vector<int> e[300001];
vector<int> f[300001];
int t[300001];
int pa[300001];
int pdb;
int u;
int v;
int atilt;
int btilt;
int x;
int y;
int lj;

bool keres(int p, int apa)
{
	if (p == b)
	{
		pdb = 1;
		pa[1] = b;
		return true;
	}
	for (vector<int>::iterator it = e[p].begin(); it != e[p].end(); it++)
	{
		if (apa != *it)
		{
			if (keres(*it, p))
			{
				pdb++;
				pa[pdb] = p;
				//cerr << ' ' << p;
				return true;
			}
		}
	}
	return false;
}

int megold(int p, int tilt, int apa)
{
	t[p] = 1;
	f[p].clear();
	for (vector<int>::iterator it = e[p].begin(); it != e[p].end(); it++)
	{
		if ((*it != apa) && (*it != tilt))
		{
			f[p].push_back(megold(*it, tilt, p) + 1);
		}
	}
	sort(f[p].begin(), f[p].end());
	for (vector<int>::iterator it = f[p].begin(); it != f[p].end(); it++)
	{
		t[p] = max(t[p] + 1, *it);
	}
	//cerr << p << ' ' << t[p] << endl;
	return t[p];
}

int main()
{
  //	ios_base::sync_with_stdio(false);
	cin >> n >> a >> b;
	for (int i = 1; i < n; i++)
	{
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	keres(a, 0);
	//cerr << endl;
	u = 1;
	v = pdb - 1;
	lj = n;
	while (u <= v)
	{
		atilt = pa[(u + v) / 2];
		btilt = pa[(u + v) / 2 + 1];
		//cerr << atilt << ' ' << btilt << ':' << endl;
		x = megold(a, atilt, 0);
		y = megold(b, btilt, 0);
		lj = min(lj, max(x, y));
		if (x < y)
		{
			v = (u + v) / 2 - 1;
		}
		else
		{
			u = (u + v) / 2 + 1;
		}
	}
	cout << lj - 1 << endl;
	return 0;
}

