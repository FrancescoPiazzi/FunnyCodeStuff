// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <cassert>


using namespace std;


long long sum(int n, int k){
    if (k>n)
        return 0;
    n--;    // exclude n from the sum
    n-=n%k; // round down to the nearest multiple of k
    long long terms = n/k;    // number of terms in the sum
    long long s = n+k;        // value of each pair of terms
    if(terms%2==0){
        return s*terms/2;
    }else{
        return s*(terms-1)/2+s/2;
    }
}


long long f(int n){
    return sum(n, 3)+sum(n, 5)-sum(n, 15);
}


int main()
{
    assert(f(10)==23 && "Test 1 failed");
    assert(f(100)==2318 && "Test 2 failed");
    assert(f(0)==0 && "Test 3 failed");
    assert(f(1)==0 && "Test 4 failed");
}

