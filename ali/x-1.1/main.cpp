#include<iostream>
using namespace std;
int n;
int nums[3][5000];
int dp[3][5000];
const int mins = 0x7fffffff;
int abs(int a) {
    if (a < 0) {
        return 0 - a;
    }
    return a;
}
int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}
int main() {
    while(cin >> n) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                cin >> nums[i][j];
            }
        }
        dp[0][0], dp[1][0], dp[2][0] = 0, 0, 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                dp[j][i] = mins;
                for (int k = 0; k < 3; k++) {
                    if ( (dp[k][i-1] + abs(nums[j][i] - nums[k][i-1])) < dp[j][i]) {
                        dp[j][i] = dp[k][i-1] + abs(nums[j][i] - nums[k][i-1]);
                    }
                }
            }
        }
        cout << min(min(dp[0][n-1], dp[1][n-1]), dp[2][n-1]) << endl;
    }
    return 0;
}
