#include <bits/stdc++.h>

using namespace std;

typedef vector<long long> vi;

#define MAX (1+(1<<6)) // Why? :D
#define inf 9223372036854775807

class SegmentTreeMin
{
private:
	int N;
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
		
		tree[node] = min(tree[node*2], tree[node*2+1]); // Init root value
	}

	/**
	 * Increment elements within range [i, j] with value value
	 */
	void update_tree(long long node, long long a, long long b, long long i, long long j, long long value) {
	  
	  	if(lazy[node] != 0) { // This node needs to be updated
	   		tree[node] += lazy[node]; // Update it

			if(a != b) {
				lazy[node*2] += lazy[node]; // Mark child as lazy
	    			lazy[node*2+1] += lazy[node]; // Mark child as lazy
			}

	   		lazy[node] = 0; // Reset it
	  	}
	  
		if(a > b || a > j || b < i) // Current segment is not within range [i, j]
			return;
	    
	  	if(a >= i && b <= j) { // Segment is fully within range
	    		tree[node] += value;

			if(a != b) { // Not leaf node
				lazy[node*2] += value;
				lazy[node*2+1] += value;
			}

	    		return;
		}

		update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
		update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

		tree[node] = min(tree[node*2], tree[node*2+1]); // Updating root with max value
	}

	/**
	 * Query tree to get max element value within range [i, j]
	 */
	long long query_tree(long long node, long long a, long long b, long long i, long long j) {
		
		if(a > b || a > j || b < i) return inf; // Out of range

		if(lazy[node] != 0) { // This node needs to be updated
			tree[node] += lazy[node]; // Update it

			if(a != b) {
				lazy[node*2] += lazy[node]; // Mark child as lazy
				lazy[node*2+1] += lazy[node]; // Mark child as lazy
			}

			lazy[node] = 0; // Reset it
		}

		if(a >= i && b <= j) // Current segment is totally within range [i, j]
			return tree[node];

		long long q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
		long long q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

		long long res = min(q1, q2); // Return final result
		
		return res;
	}
public:
	
	SegmentTreeMin(vi A):N(A.size())
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



class SegmentTreeSum
{
private:
	int N;
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
		
		tree[node] = tree[node*2] + tree[node*2+1]; // Init root value
	}

	/**
	 * Increment elements within range [i, j] with value value
	 */
	void update_tree(long long node, long long a, long long b, long long i, long long j, long long value) {
	  
	  	if(lazy[node] != 0) { // This node needs to be updated
	   		tree[node] += (b-a+1)*lazy[node]; // Update it

			if(a != b) {
				lazy[node*2] += lazy[node]; // Mark child as lazy
	    			lazy[node*2+1] += lazy[node]; // Mark child as lazy
			}

	   		lazy[node] = 0; // Reset it
	  	}
	  
		if(a > b || a > j || b < i) // Current segment is not within range [i, j]
			return;
	    
	  	if(a >= i && b <= j) { // Segment is fully within range
	    		tree[node] += (b-a+1)*value;

			if(a != b) { // Not leaf node
				lazy[node*2] += value;
				lazy[node*2+1] += value;
			}

	    		return;
		}

		update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
		update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

		tree[node] = (tree[node*2] + tree[node*2+1]); // Updating root with max value
	}

	/**
	 * Query tree to get max element value within range [i, j]
	 */
	long long query_tree(long long node, long long a, long long b, long long i, long long j) {
		
		if(a > b || a > j || b < i) return 0; // Out of range

		if(lazy[node] != 0) { // This node needs to be updated
			tree[node] += (b-a+1)*lazy[node]; // Update it

			if(a != b) {
				lazy[node*2] += lazy[node]; // Mark child as lazy
				lazy[node*2+1] += lazy[node]; // Mark child as lazy
			}

			lazy[node] = 0; // Reset it
		}

		if(a >= i && b <= j) // Current segment is totally within range [i, j]
			return tree[node];

		long long q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
		long long q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

		long long res = (q1 + q2); // Return final result
		
		return res;
	}
public:
	
	SegmentTreeSum(vi A):N(A.size())
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

	long long rsq(long long i,long long j)
	{
		return query_tree(1, 0, N-1, i, j);
	}
};


vector<vi > adj;
vi IDS;
vi invIDS;
vi nchilds;
long long curr_id;


void dfs(long long s)
{
	stack<long long> S;S.push(s);
	while(!S.empty())
	{
		long long u = S.top();S.pop();
		invIDS[(curr_id)] = u;
		IDS[u]=curr_id++;

		for (long long j:adj[u])
		{
			if(IDS[j]==0)
			{
				S.push(j);
			}
		}
	}

	vi maxID(curr_id,0);
	for (int i = curr_id-1; i >=1; --i)
	{
		maxID[i] = i;
		for (long long j:adj[invIDS[i]])
		{
			maxID[i] = max(maxID[i],maxID[IDS[j]]);
		}
		nchilds[invIDS[i]] = maxID[i] - i;
		
	}
	
 }

int main()
{
	int tc;
	scanf("%d",&tc);
	//tc = 3;
	for (int iii = 1; iii <= tc; ++iii)
	{
		printf("Case %d:\n",iii);
		long long nodes,queries;
		
		scanf("%lld %lld",&nodes,&queries);
		//nodes = 1e5;queries = 50*1e3;
		adj.clear();
		adj.assign(nodes+1,vi());
		IDS.clear();
		IDS.assign(nodes+1,0);
		invIDS.clear();
		invIDS.assign(nodes+1,0);
		nchilds.clear();
		nchilds.assign(nodes+1,0);
		
		
		curr_id = 1;
		long long salaries[nodes+1]; memset(salaries,0,sizeof salaries);
		//cout << "reseteo weas" << endl;
		for (int i = 1; i <= nodes; ++i)
		{
			long long parent,salary;
			scanf("%lld %lld",&parent,&salary);
			//parent = i-1;salary = 500;
			salaries[i] = salary;
			if(i>1)
			{
				//adj[i].push_back(parent);
				adj[parent].push_back(i);
			}
		}

		dfs(1);

		vi invSal(nodes+1,0);
		for (int i = 1; i <= nodes; ++i)
		{
			invSal[IDS[i]]= salaries[i];
		}

		SegmentTreeMin mins(invSal);
		SegmentTreeSum sums(invSal);
		while(queries--)
		{
			int type;long long vid;
			scanf("%d %lld",&type,&vid);
			//type = rand()%2+1;
			//vid = rand()%(nodes)+1;
			//cout << "Q entre " << IDS[vid] << " y " << IDS[vid]+nchilds[vid] << endl;
			if(type == 2)
			{
				long long minim = mins.rmq(IDS[vid],IDS[vid]+nchilds[vid]);
				mins.update(IDS[vid],IDS[vid]+nchilds[vid], min(minim,(long long)1000));
				sums.update(IDS[vid],IDS[vid]+nchilds[vid], min(minim,(long long)1000));
			}
			else
			{
				long long res = sums.rsq(IDS[vid],IDS[vid]+nchilds[vid]);
				printf("%lld\n",res);
			}
		}
	}
	return 0;
}