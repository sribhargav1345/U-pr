#include<bits/stdc++.h>
using namespace std;

int main()
{
    int hr,minu;
    cin>>hr>>minu;

    // Assuming 24 hr clock

    hr = hr % 12;

    float min_angle = minu*6;  // 360/6
    float hr_angle = hr*30 + (min_angle / 360)*30; //348

    cout<<min(abs(hr_angle-min_angle),abs(360-min_angle+hr_angle))<<endl;
}