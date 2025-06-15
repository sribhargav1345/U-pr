#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int maxPossibleK(string s) {
    int n = s.size();
    deque<int> dq;

    // Step 1: Convert string to segments of same characters
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && s[j] == s[i]) j++;
        dq.push_back(j - i);
        i = j;
    }

    int ans = n;

    while (dq.size() > 1) {
        if (dq.front() < dq.back()) {
            int val = dq.front();
            dq.pop_front();
            dq.front() += val;
            ans = min(ans, n - val);
        } else {
            int val = dq.back();
            dq.pop_back();
            dq.back() += val;
            ans = min(ans, n - val);
        }
    }

    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << maxPossibleK(s) << endl;
    return 0;
}
