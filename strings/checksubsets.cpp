#include<bits/stdc++.h>
using namespace std;

bool checksubset(string s1,string s2){
    int ptr1,ptr2;
    ptr1 = s1.length() -1;
    ptr2 = s2.length() -1;
    while (ptr1>=0){
        if(s1[ptr1]==s2[ptr2]){
            ptr1--;
            ptr2--;
        }
        else
            ptr1--;
        if(ptr2<0)
            return true;
    }
    return false;
    
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<checksubset(s1,s2)<<endl;
}

