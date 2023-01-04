#include <queue>
#include <cstdio>
using namespace std;

struct Node
{
	int l,r,len;

	inline Node(int l,int r)
	{
		this->l=l,this->r=r;
		len=r-l+1; return;
	}

	inline bool operator<(const Node& rhs) const
	{
		if (this->len<rhs.len) return true;
		if (this->len>rhs.len) return false;
		return this->l>rhs.l;
	}

	inline bool operator>(const Node& rhs) const
	{
		if (this->len>rhs.len) return true;
		if (this->len<rhs.len) return false;
		return this->l<rhs.l;
	}
};

int a[10005];

int main()
{
	int n=10000;
	freopen("testcase.txt","w",stdout);
	printf("%d\n",n);
	priority_queue<Node> pq;
	Node node(0,n-1); pq.push(node);
	for (int i=1,l,r;i<=n;i++)
	{
		Node node=pq.top(); pq.pop();
		l=node.l,r=node.r;
		// printf("%d %d\n",l,r);
		int mid=(l+r)>>1;
		a[mid]=i;
		if (mid-1>=l) {Node newNode(l,mid-1); pq.push(newNode);}
		if (r>=mid+1) {Node newNode(mid+1,r); pq.push(newNode);}
	}
	for (int i=0;i<n;i++)
	printf("%d\n",a[i]);
	return 0;
}