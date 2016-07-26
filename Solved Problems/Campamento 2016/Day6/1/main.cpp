#include <bits/stdc++.h>

using namespace std;

typedef vector<long long> vi;

#define inf 9223372036854775807

class SegmentTreeMax
{
private:
	long long N;
	vi arr;
	vi tree;
	vi lazy;

	/**
	 * Build and init tree
	 */
	void build_tree(long long node, long long a, long long b) {
	  	if(a > b) return; // Out of range
	  	
	  	if(a == b) { // Leaf node
	    		tree[node] = arr[a]; // Init value
			return;
		}
		
		build_tree(node*2, a, (a+b)/2); // Init left child
		build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
		
		tree[node] = max(tree[node*2], tree[node*2+1]); // Init root value
	}

	/**
	 * Increment elements within range [i, j] with value value
	 */
	void update_tree(long long node, long long a, long long b, long long i, long long j, long long value) {
	  
	  	if(lazy[node] != 0) { // This node needs to be updated
	   		tree[node] = lazy[node]; // Update it

			if(a != b) {
				lazy[node*2] = lazy[node]; // Mark child as lazy
	    			lazy[node*2+1] = lazy[node]; // Mark child as lazy
			}

	   		lazy[node] = 0; // Reset it
	  	}
	  
		if(a > b || a > j || b < i) // Current segment is not within range [i, j]
			return;
	    
	  	if(a >= i && b <= j) { // Segment is fully within range
	    		tree[node] = value;

			if(a != b) { // Not leaf node
				lazy[node*2] = value;
				lazy[node*2+1] = value;
			}

	    		return;
		}

		update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
		update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

		tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
	}

	/**
	 * Query tree to get max element value within range [i, j]
	 */
	long long query_tree(long long node, long long a, long long b, long long i, long long j) {
		
		if(a > b || a > j || b < i) return -inf; // Out of range

		if(lazy[node] != 0) { // This node needs to be updated
			tree[node] = lazy[node]; // Update it

			if(a != b) {
				lazy[node*2] = lazy[node]; // Mark child as lazy
				lazy[node*2+1] = lazy[node]; // Mark child as lazy
			}

			lazy[node] = 0; // Reset it
		}

		if(a >= i && b <= j) // Current segment is totally within range [i, j]
			return tree[node];

		long long q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
		long long q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

		long long res = max(q1, q2); // Return final result
		
		return res;
	}
public:
	
	SegmentTreeMax(vi A):N(A.size())
	{
		arr.assign(A.begin(),A.end());
		tree.assign(N*4,0);
		lazy.assign(N*4,0);
		build_tree(1, 0, N-1);
		//memset(lazy, 0, sizeof lazy);
	}
	
	void update(long long i,long long j, long long v)
	{
		update_tree(1, 0, N-1, i, j, v);
	}

	long long rmq(long long i,long long j)
	{
		return query_tree(1, 0, N-1, i, j);
	}
};


int main()
{
	long n;
	scanf("%ld",&n);
	vi A(n,0);
	for (long i = 0; i < n; ++i)
	{
		long long nasd; scanf("%I64d",&nasd);
		A[i] = nasd;
	}

	SegmentTreeMax st(A);
	long longo;
	scanf("%ld",&longo);
	while(longo--)
	{
		long long x,y;
		scanf("%I64d %I64d",&x,&y);

		long long maxo = st.rmq(0,x-1);

		printf("%I64d\n",maxo);

		st.update(0,x-1,maxo+y);
	}
	return 0;	
}