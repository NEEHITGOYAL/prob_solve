//write a func that takes inp an array of distinct integer and returns the
//length of highest mountain (adjacent integers that are strictly increasing until 
//reach  a peak,at which become strictly decreasing)
#include<bits/stdc++.h>
using namespace std;
int mountain(vector<int> arr)
{
    int result = 0;
    int cnt = 0;
    for(int i=1;i<arr.size()-1;)
    {
        int prev = i-1;
        int curr = i;
        int next = i+1;
        //check if its peak
        if(arr[prev]<arr[i] && arr[i]>arr[next])
        {
            cnt = 1;
            //count backward
            while(curr>=1 && arr[curr] > arr[prev])
            {
                cnt++;
                curr--;
                prev--;
            }
            //count forward
            while (i<arr.size()-1 && arr[i]> arr[i+1])
            {
                i++;
                cnt++;
            }
        }
        //if its not
        else
            i++;
        result = max(result,cnt);
    }
    return result;
}
int main(){
    vector<int> inp = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    int result = mountain(inp);
    cout<< result<<endl;;
}