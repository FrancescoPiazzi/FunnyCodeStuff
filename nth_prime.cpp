#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

string ltrim(const string &);
string rtrim(const string &);

vector<long long> primes;

bool isPrime(long long n){
    for(long long p : primes){
        if(n%p==0){
            return false;
        }
    }
    for(long long i=primes[primes.size()-1]+1; i<n/2; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(t_temp);
    
    primes.push_back(2);
    primes.push_back(3);
    primes.shrink_to_fit();

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(n_temp);
        if(n<primes.size()){
            cout << primes[n-1] << endl;
        } else {
            while(primes.size()<n){
                long long nextPrime = primes[primes.size()-1]+2;
                while(!isPrime(nextPrime)){
                    nextPrime+=2;
                }
                primes.push_back(nextPrime);
            }
            cout << primes[n-1] << endl;
        }
        primes.shrink_to_fit();
    }

    return 0;
}
