#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<queue>
#include<iterator>
using namespace std;
#define FOR(i,s,e) for(int i = (s); i < (e); i++)
#define FOE(i,s,e) for(int i = (s); i <= (e); i++)
#define FOD(i,s,e) for(int i = (s); i >= (e); i--)
#define CLR(a) memset(a,0,sizeof(a))
#define ll long long
#include<ctime>
#include<cmath>
#include<vector>

int n, m, x, y, z, k, w, a, b;
int LINK[600004], ed[600004], l[300005];
int dp[300005], A[300005], S[300005], path[300005], cut[300005];
int high, low, mid;
int ANS[300005], ans;

void build(int x, int y) {
	LINK[w] = l[x]; l[x] = w; ed[w] = y; w++;
}

void find(int x, int y)
{
	S[k++] = x;
	if (x == b) { FOR(i, 0, k) path[i] = S[i]; w = k; }
	for (int i = l[x]; i != -1; i = LINK[i]) if (ed[i] != y) find(ed[i], x);
	k--;
}

void DFS(int x, int y, int cutedge)
{
	bool ok = 0; 
	for (int i = l[x]; i != -1; i = LINK[i])
	{
		if (ed[i] != y && i != cutedge && (i ^ 1) != cutedge) 
			DFS(ed[i], x, cutedge);
	}
	
	int k = 0;
	for (int i = l[x]; i != -1; i = LINK[i])
		if (ed[i] != y && i != cutedge && (i ^ 1) != cutedge) A[k++] = dp[ed[i]];
	
	sort(A, A + k);
	FOR(i, 0, k) if (A[i] + k - i > dp[x]) dp[x] = A[i] + k - i;
}

int main ()
{
	memset(l, -1, sizeof(l));
	
	scanf("%d %d %d", &n, &a, &b);
	FOR(i, 0, n - 1)
	{
		scanf("%d %d", &x, &y);
		build(x, y);
		build(y, x);
	}
	
	k = 0;
	find(a, -1);
	k = w;
	
	FOR(i, 0, k - 1)
	{
		x = path[i]; y = path[i + 1];
		for (int j = l[x]; j != -1; j = LINK[j]) if (ed[j] == y) { z = j; break; }
		cut[i] = z;
	}
	
	high = k - 2; low = 0;
	ans = 1000000000;
	
//	printf("%d %d\n", high, low);
	
	while (high - low > 1)
	{
		mid = (high + low) / 2;
		
		memset(dp, 0, sizeof(dp));
		
		DFS(a, -1, cut[mid]);
		DFS(b, -1, cut[mid]);
		
		ans = min(ans, max(dp[a], dp[b]));
		
		if (dp[a] > dp[b]) high = mid;
		else low = mid;
	}
	
//	printf("%d %d %d\n", high, low, cut[low]);
		
	memset(dp, 0, sizeof(dp));
	DFS(a, -1, cut[low]);
	DFS(b, -1, cut[low]);
	ans = min(ans, max(dp[a], dp[b]));
	
	memset(dp, 0, sizeof(dp));
	DFS(a, -1, cut[high]);
	DFS(b, -1, cut[high]);
	ans = min(ans, max(dp[a], dp[b]));
	
	printf("%d\n", ans);
	return 0;
}
	
	
