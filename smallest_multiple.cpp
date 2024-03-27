#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int gcd(int a, int b){
    // replace (a, b) with (b, a mod b) repeatedly until the pair is (d, 0), where d is the greatest common divisor. 
    while(b==0){
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}

int lcm(int a, int b){
    return a*b/gcd(a, b);
}


int main() {
    int N;
    cin >> N;
    int n;
    
    for(int i=0; i<N; i++){
        cin >> n;
        if(n<3){
            cout << n << endl;
            continue;
        }
        int res=lcm(1, 2);
        for(int j=3; j<=n; j++){
            res = lcm(res, j);
        }
        cout << res << endl;
    }
    
    return 0;
}
