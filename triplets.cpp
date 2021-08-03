//given a arrayof n integer and number S denoting target sum find two distinct integer 
//that can oair up ti form the sum .Assume there will be only one pair
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> triplets(vector<int> arr,int Sum)
{
    vector<vector<int>> result;
    vector<int> temp;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-3;i++)
    {
        int left=i+1;
        int right = arr.size()-1;
        int x = arr[i];
        while(left<right)
        {
            int curr_sum = x+arr[left]+arr[right];
            if(curr_sum == Sum)
            {
                temp = {x,arr[left],arr[right]};
                result.push_back(temp);
                left++;
                right--;
            }
            else if(curr_sum<Sum)
                left++;
            else
                right--;
        }    
    }
    return result;
}
int main()
{
    vector<int> arr{1,2,3,4,5,6,7,8,9,15};
    int S = 18;
    auto result = triplets(arr,S);
    for(auto x:result)
    {
        for(auto y:x)
            cout<<y<<" ";
        cout<<endl;
    }
    return 0;    
}