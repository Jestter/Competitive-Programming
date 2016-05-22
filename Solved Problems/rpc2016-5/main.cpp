#include <bits/stdc++.h>
using namespace std;
int main (int argc, char const *argv[]){
	long n;
	scanf("%ld", &n);
	for(int i = 0; i < n; i++){
		int A, B;
		scanf("%d %d" , &A, &B); //A: candidates, B:states
		long *total = (long *)malloc(sizeof(long)*A);
		long total_voters = 0;
		for (int k = 0; k < A; ++k) total[k] = 0;
		double *percentages = (double *)malloc(sizeof(double)*A);
		for (int j = 0; j < B; ++j){
			for (int k = 0; k < A; ++k)
				scanf("%lf", &percentages[k]);
			long voters = 0;
			scanf("%ld",&voters);
			total_voters += voters;
			long sum = 0;
			for (int k = 0; k < A; ++k)
				total[k] += (voters * (percentages[k]*100));
		}
		vector< pair<long,long> > votes;
		for (int k = 0; k < A; ++k){
			votes.push_back({k+1, total[k]});
			if(2*total[k] > ((total_voters)*10000)){
				printf("%ld %ld\n", k,  total[k]/10000);
				break;
			}
		}
		if(votes.size() == A){
			sort(votes.begin(), votes.end(), [](const pair<long, long>& a, const pair<long, long>& b){
				if(a.second == b.second){
					return (a.first) < (b.first);
				}
				return (a.second) > (b.second);
	       	});
			for (int k = 0; k < 2; ++k){
				printf("%ld %ld\n", votes[k].first, votes[k].second/10000 );
			}
		}
		if(i < n-1) printf("\n");
	}
	return 0;
}