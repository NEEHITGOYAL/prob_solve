#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string lookAndSaySequence(int n) 
{
    if(n == 1)
        return "1";
   // if(n==2)
     //   return "11";
    // Write your code here.
    n=n-1;
    string temp = "";
    string s = lookAndSaySequence(n);
    for(int i =0;i<s.length();i++){
        int count =1;
        int j=i;
        if(i != s.length()-1){
        while(s[j] == s[j+1]){
            count++;
            j++;
            i++;
        }}
        temp += to_string(count) + s[j] ;
    }
    return temp;
}
int main() {
    string s = lookAndSaySequence(2);
    cout<<s;
}