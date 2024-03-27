#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// would have made more sense to sum directly into n1 but oh well
vector<short> sum(vector<short> n1, vector<short> n2){
    vector<short> res(max(n1.size(), n2.size()), 0);
    short carry=0;
    for(int i=0; i<min(n1.size(), n2.size()); i++){
        int tmp = n1[i]+n2[i]+carry;
        res[i] = tmp%10;
        carry = tmp/10;
    }
    if(n1.size()>n2.size()){
        for(int i=n2.size(); i<n1.size(); i++){
            int tmp = n1[i]+carry;
            res[i] = tmp%10;
            carry = tmp/10;
        }
    }
    if(n2.size()>n1.size()){
        for(int i=n1.size(); i<n2.size(); i++){
            int tmp = n2[i]+carry;
            res[i] = tmp%10;
            carry = tmp/10;
        }
    }
    
    if(carry>0){
        res.push_back(carry);
    }
    
    return res;
}

vector<short> s_to_vec(string s){
    vector<short> res;
    for(char c : s){
        res.push_back(c-'0');
    }
    // reversse so all numbers have theyr least significant digit at index 0
    reverse(res.begin(), res.end());
    return res;
}

string to_str_10(vector<short> n){
    string s;
    int i=0;
    for(short x : n){
        if(i==10){
            break;
        }
        s.push_back('0'+x);
        i++;
    }
    return s;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string n;
    vector<short> s;
    vector<short> nn;
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> n;
        nn = s_to_vec(n);
        s = sum(s, nn);
    }
    
    cout << to_str_10(s);
    
    return 0;
}
