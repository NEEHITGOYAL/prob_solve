//given a arrayof n integer and number S denoting target sum find two distinct integer 
//that can oair up ti form the sum .Assume there will be only one pair
#include<bits/stdc++.h>
using namespace std;
vector<int> pairSum(vector<int> arr,int Sum)
{
    //Logic
    unordered_set<int> s;
    vector<int> result;
    for(int i =0;i<arr.size();i++)
    {
        int temp = Sum - arr[i];
        if(s.find(temp) != s.end() )
        {
            result.push_back(temp);
            result.push_back(arr[i]);
            return result;
        }
        s.insert(arr[i]);
    }
    return result;
}
int main()
{
    vector<int> arr{9,11,10,5,2,3,-6,};
    int S = 4;
    auto p = pairSum(arr,S);
    if(p.size() == 0)
        cout<<"No such pair";
    else
        cout<<p[0]<<","<<p[1]<<endl;
    return 0;    
}