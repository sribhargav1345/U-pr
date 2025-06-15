#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    int dec = 0;
    for(int i=0;i<s.size();i++){
        dec = dec*2 + (s[i]-'0');
    }

    string ans = "";
    while(dec>0){
        ans += ((dec%6) + '0');
        dec /= 6;
    }

    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}