#include<iostream>
using namespace std;
int n;
int nums[3][5000];
int mins = 0x7fffffff;
int abs(int a) {
    if (a < 0) {
        return 0 - a;
    }
    return a;
}
void DFS(int idx, int sum, int prev){
    if (idx == n) {
        if (sum < mins) {
            mins = sum;
        }
        return;
    }
    if (sum > mins) {
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (idx == 0) {
            DFS(1, 0, nums[i][0]);
        }
        else {
            DFS(idx+1, sum + abs(nums[i][idx] - prev), nums[i][idx]);
        }
    }
}
int main() {
    while(cin >> n) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                cin >> nums[i][j];
            }
        }
        DFS(0, 0, 0);
        cout << mins << endl;
        mins = 0x7fffffff;
    }
    return 0;
}
