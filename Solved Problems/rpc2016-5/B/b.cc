#include <stdio.h>
int main (int argc, char const *argv[]){
	long m, n;
	scanf("%ld %ld",&n,&m);
	// prlongf("n=%ld, m=%ld\n",n,m);
	long matrix[300][300];
	for (long i = 0; i < n; ++i){
		for (long j = 0; j < m; ++j){
			scanf("%ld", &matrix[i][j]);
		}
	}

	long i, j, dpr_1, dpr_2, dp_v1, dp_v2, t, r;
	dpr_1 = dpr_2 = dp_v1 = dp_v2 = t = r = 0;
	for(i = 0; i < m; ++i){
		for(dp_v1=0, dp_v2=0, j = 0; j < n; ++j){
			r = matrix[i][j];
			t = dp_v1;
			dp_v1 = dp_v2 + r > dp_v1 ? dp_v2 + r : dp_v1;
			dp_v2 = t;
		}
		t = dpr_1;
		dpr_1 = dpr_2 + ((dp_v1 > dp_v2)? dp_v1 : dp_v2) > dpr_1 ? dpr_2 + ((dp_v1 > dp_v2)? dp_v1 : dp_v2) : dpr_1;
		dpr_2 = t;
		j++;
	}
	printf("%ld\n", (dpr_1 > dpr_2) ? dpr_1 : dpr_2);
	return 0;
}