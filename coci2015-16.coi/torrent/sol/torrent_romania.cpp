#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> g[300010],gg[300010];
int tata[300010],d[300010],v[300010],poz[300010],nr=0;
char vaz[300010];

void dfs(int nod,int t)
{
    tata[nod]=t;
    for(vector<int>::iterator it=g[nod].begin();it!=g[nod].end();it++)
        if(*it!=t) dfs(*it,nod);
}

int cmp(int a,int b)
{
    return d[a]>d[b];
}

void solve(int nod,int t)
{
    for(vector<int>::iterator it=g[nod].begin();it!=g[nod].end();it++)
        if(*it!=t) solve(*it,nod);
    int s=0;
    sort(g[nod].begin(),g[nod].end(),cmp);
    for(vector<int>::iterator it=g[nod].begin();it!=g[nod].end();it++)
        if(*it!=t)
        {
            s++;
            d[nod]=max(d[nod],s+d[*it]);
        }
}

int check(int timp)
{
    for(int i=1;i<=nr;i++) poz[i]=0;
    for(int a=1,b=nr,t=1;a<=b;t++)
    {
        if(poz[a]<gg[v[a]].size())
        {
            if(t+d[gg[v[a]][poz[a]]]>timp) return 0;
            else if(t+d[gg[v[a]][poz[a]]]==timp) poz[a]++;
            else a++;
        }
        else a++;
        if(poz[b]<gg[v[b]].size())
        {
            if(t+d[gg[v[b]][poz[b]]]>timp) return 0;
            else if(t+d[gg[v[b]][poz[b]]]==timp) poz[b]++;
            else b--;
        }
        else b--;
    }
    return 1;
}

int main()
{
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int n,a,b,x,y;
    scanf("%d%d%d",&n,&a,&b);
    if(n==2)
    {
        printf("0");
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(a,0);
    for(int nod=b;nod;nod=tata[nod])
    {
        v[++nr]=nod;
        vaz[nod]=1;
        for(vector<int>::iterator it=g[nod].begin();it!=g[nod].end();it++)
            if(!vaz[*it] && *it!=tata[nod])
            {
                solve(*it,nod);
                gg[nod].push_back(*it);
            }
        sort(gg[nod].begin(),gg[nod].end(),cmp);
        for(int i=gg[nod].size()-2;i>=0;i--)
            if(d[gg[nod][i]]<=d[gg[nod][i+1]]) d[gg[nod][i]]=d[gg[nod][i+1]]+1;
    }
    int st=1,dr=n;
    while(st<=dr)
    {
        int mid=(st+dr)/2;
        if(check(mid)) dr=mid-1;
        else st=mid+1;
    }
    printf("%d",st);
    return 0;
}
