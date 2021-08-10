#include<bits/stdc++.h>
using namespace std;
void housing(vector<int> plots,int sum){
    int start = 0;
    int end = 0;
    int curr_sum = 0;
    while(end<plots.size()){
        //expand
            curr_sum+=plots[end];
            end++;

        //contract
        while(curr_sum>sum and start <end){
            curr_sum -= plots[start];
            start++;
        }
        //equal
        if(curr_sum == sum){
            cout<<start<<" - "<<end-1<<endl;
        }
    }
    return;
}

int main(){
    vector<int> v ={1,3,2,1,4,1,3,2,1,1};
    int sum = 8;
    housing(v,sum);
    return 0;
}