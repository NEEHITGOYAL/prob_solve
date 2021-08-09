#include<bits/stdc++.h>
using namespace std;



string normalize(const string &sentence) {
    string copy = sentence;
    //Make the changes in copy, and return it
    transform(copy.begin(),copy.end(),copy.begin(), ::tolower);
    int c = copy[0];
    copy[0] = toupper(c);
    for(int i=0;i<copy.length()-1;i++){
        if(copy[i] == ' '){
            c = copy[i+1];
            copy[i+1] = toupper(c);
        }
    }
    return copy;
}
int main() {
    string s = "0x71f";   
   cout << stoi(s,nullptr,16) <<endl;
}