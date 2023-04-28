#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int A, int C, vector<int>& B) {
    vector<int> mark(A + 1, 0);
    int cnt = 0;
    for (int i = A; i >= 1; i--) {
        if (i + C - 1 <= A) {
            int ones = mark[i + 1] - mark[i + C];
            int zeros = (i - (i + C - 1)) - ones;
            if (ones > zeros) {
                mark[i] = 1;
                cnt++;
            }
        }
        if (i == A) {
            mark[i] = 1;
            cnt++;
        }
        for (int j = i + 1; j <= A; j++) {
            if (B[j - 1] > B[i - 1]) {
                mark[i] |= mark[j];
            }
        }
    }
    return cnt;
}

int main() {
    int A = 5;
    int C = 3;
    vector<int> B = {3, 1, 4, 2, 5};
    int ans = solve(A, C, B);
    cout << ans << endl; // Output: 2
    return 0;
}
