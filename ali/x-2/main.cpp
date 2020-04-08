#include <iostream>
using namespace std;
int n, m, q;
int nums[501][501];
int isComplete;

void modifyRow(int row) {
    int i = 0;
    for (; i < m && nums[row][i] == 0; i++) {}
    int j = i + 1;
    for (; j < m && nums[row][j] == 0; j++) {}
    if (i == m || j == m) {
        return;
    }
    isComplete++;
    int step = (nums[row][j] - nums[row][i]) / (j - i);
    for (int i = 0; i < m; i++) {
        nums[row][i] = (nums[row][j] - j * step) + i * step;
    }
}
void modifyCol(int col) {
    int i = 0, j = 0;
    for (; i < n && nums[i][col] == 0; i++) {}
    for (j = i+1; j < n && nums[j][col] == 0; j++) {}
    if (i == n || j == n) {
        return;
    }
    int step = (nums[j][col] - nums[i][col]) / (j - i);
    for (int i = 0; i < m; i++) {
        nums[i][col] = (nums[j][col] - j * step) + i * step;
    }
}
void fillTheNums() {
    for (int i = 0; i < n; i++) {
        modifyRow(i);
    }
    for (int j = 0; j < m; j++) {
        modifyCol(j);
    }
    for (int i = 0; i < n; i++) {
        modifyRow(i);
    }
}
int main(){
    while(cin >> n >> m >> q) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> nums[i][j];
            }
        }
        isComplete = 0;
        fillTheNums();
        int x, y;
        while(q--) {
            cin >> x >> y;
            if (isComplete > 2) {
                cout << nums[x][y] << endl;
            }
            else {
                if (nums[x][y] == 0)
                    cout << "Unknown" << endl;
                else cout << nums[x][y] << endl;
            }
        }
    }
    return 0;
}
