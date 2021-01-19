#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n, add, nums[10000];
    cin >> n >> add;
    for(int i = 0; i < n; i++){
        cin >> nums[i]; 
    }
    for(int j = 0; j < add; j++){
        next_permutation(nums, nums + n);
    }
    for(int i = 0; i < n; i++){
        cout << nums[i];
        if (i != n - 1) cout << ' ';
    }
    //system("pause");
    return 0;
}