// Prob2.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> positive, negative;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (num > 0)
            positive.push_back(num);
        else if (num < 0)
            negative.push_back(-num);
    }
    sort(positive.begin(), positive.end());
    sort(negative.begin(), negative.end());

    int grid[200'001] = { 0, };
    int arrIdx = 0, arrNum = negative.size();
    for (int i = 0; i < m; i++) {
        while (arrIdx < negative.size() && i >= negative[arrIdx]) {
            arrIdx++;
            arrNum--;
        }
        grid[i] += arrNum;
    }

    arrIdx = 0, arrNum = positive.size();
    for (int i = m; i > 0; i--) {
        while (arrIdx < positive.size() && (m - i) >= positive[arrIdx]) {
            arrIdx++;
            arrNum--;
        }
        grid[i - 1] += arrNum;
    }

    pair<int, int> ans = { 0x3f3f3f3f, 0 };
    for (int i = 0; i < m; i++) {
        if (grid[i] < ans.first)
            ans = { grid[i], 1 };
        else if (grid[i] == ans.first)
            ans.second++;
    }

    cout << ans.first << ' ' << ans.second << '\n';

    return 0;
}