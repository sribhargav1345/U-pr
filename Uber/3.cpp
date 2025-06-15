#include<bits/stdc++.h>
using namespace std;

bool f(string s, int k, int n, char change_to){
    vector<int> diff(n+1, 0);
    int active = 0;

    for(int i = 0; i <= n-k; i++){
        active += diff[i];

        int cur_bit = (s[i] - '0' + active) % 2;
        if(cur_bit != (change_to - '0')){  
            active++;
            diff[i+k]--;
        }
    }

    for(int i = n-k+1; i < n; i++){
        active += diff[i];
        int cur_bit = (s[i] - '0' + active) % 2;
        
        if(cur_bit != (change_to - '0')){  
            return false;
        }
    }
    return true;
}

int main()
{
    string s;
    cin >> s;

    int n = s.size();
    int low = 1;
    int high = n;
    int ans = 0;  // Store the answer

    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(f(s, mid, n, '0') || f(s, mid, n, '1')){
            ans = mid;      // Store current working answer
            low = mid + 1;  // Try for larger K
        }
        else{
            high = mid - 1; // Try for smaller K
        }
    }
    
    cout << ans << endl;  // Output the stored answer
    return 0;
}

/*
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff(n+1,0);

        int active = 0;
        int cur = 0;
        for(int i=0;i<=n-k;i++)
        {
            active += diff[i];
            int cur_bit = (nums[i] + active) % 2;
            
            if(cur_bit == 0){
                active++;
                cur++;
                diff[i+k]--;
            }
        }

        for(int i=n-k+1;i<n;i++)
        {
            active += diff[i];
            int cur_bit = (nums[i] + active) % 2;

            if(cur_bit == 0){
                return -1;
            }
        }
        return cur;
    }
};
*/