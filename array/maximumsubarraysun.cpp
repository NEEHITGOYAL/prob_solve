#include<vector>
#include<iostream>
#include<algorithm>
#include<iostream>

using namespace std;

int maxSubarraySum(vector<int> arr){
    //Complete this function, your function should return the maximum subarray sum
    int n = arr.size();
    int result =0;
    int maximum = 0;
    for(int i=0;i<n;i++)
    {
        result += arr[i];
        if(result<0)
            result =0;
        maximum = max(maximum,result);
    }
    return maximum;
}
int main()
{
    vector<int> arr = {1,3,4,-43,56,7,8,-5,6};
    cout<<maxSubarraySum(arr)<<endl;
}