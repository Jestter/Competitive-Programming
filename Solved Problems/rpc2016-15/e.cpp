#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int main(void){
    vector<int> array;
    int n = 0;
    scanf("%d\n", & n);

    while(n--){
        int temp = 0;
        scanf("%d\n", &temp);
        array.push_back(temp);
    }

    sort(array.begin(), array.end());

    vector<int> a1(array.begin(), array.begin()+ array.size()/2); 
    vector<int> a2(array.begin()+ array.size()/2, array.end());

    reverse(a2.begin(), a2.end());

    vector<int> sum;

    for(int i=0; i < a1.size(); i++){
        sum.push_back(a1[i]+a2[i]);
    }

    sort(sum.begin(), sum.end());

    printf("%d\n", sum[0]);


    return 0;
}