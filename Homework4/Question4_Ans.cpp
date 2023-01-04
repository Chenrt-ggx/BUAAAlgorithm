#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> count(n);
    vector<vector<int>> ins(n);
    vector<vector<int>> outs(n);
    for (int s,t,i=0;i<m;i++)
    {
        scanf("%d %d",&s,&t);
        outs[s].push_back(t);
        ins[t].push_back(s);
    }
    int start=-1;
    for (int i=0;i<n;i++)
    {
        count[i]=ins[i].size(); if (count[i]==0)
        {
            if (start==-1) start=i;
            else {printf("%d\n",-1); return 0;}
        }
    }
    vector<int> order;
    while (start!=-1)
    {
        order.push_back(start),start=-1;
        for (int i : outs[order[order.size()-1]])
        {
            count[i]--; if (count[i]==0)
            {
                if (start==-1) start=i;
                else {printf("%d\n",-1); return 0;}
            }
        }
    }
    if ((int)order.size()==n) for (int i : order) printf("%d ",i);
    else printf("%d",-1); puts("");
    return 0;
}