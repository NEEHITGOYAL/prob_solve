#include<bits/stdc++.h>
using namespace std;
// 1st method not working

// int truncate(int number,int n){
//     int digits = floor(log10(number)+1);
    
//     while(digits != n){
//         int y = n-digits;
//         int z = digits-y;
//         number = number*(int)(pow(10,y)+0.5) + number/(int)(pow(10,z)+0.5);
//         digits = floor(log10(number)+1);
//     }
//     return number;
// }

// bool compare(pair<int,int> a,pair<int,int> b){
//     return a.second>b.second;
// }

// string concatenate(vector<int> numbers){
//     vector<pair<int,int>> vp;
//     int temp;
//     //returns no. of digits in largest integer present
//    int n = floor(log10(*max_element(numbers.begin(),numbers.end()))+1);
//    for(auto x:numbers){
//        temp = truncate(x,n);
//        vp.push_back({x,temp});
//    }   
//     sort(vp.begin(),vp.end(),compare);
//     string str;
//    for(auto x:vp)
//        str += to_string(x.first);
//     return str;
// }

//2nd method

bool compare(string a,string b){
    string ab = a+b;
    string ba = b+a;
    return ab>ba;
}

string concatenate(vector<int> numbers){
    //complete this method and return the largest number you can form as a string
    string str;
    vector<string> vs(numbers.size()) ;
    for(auto x:numbers)
        vs.push_back(to_string(x));
    sort(vs.begin(),vs.end(),compare);
    for(auto x:vs)
        str+=x;
    return str;
}

int main(){
    vector<int> numbers = {10,11,20,30,3};
    cout<<concatenate(numbers)<<endl;
}