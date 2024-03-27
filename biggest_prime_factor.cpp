#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


bool isPrime(long num) {
    if (num <= 1) {
        return false;
    }
    if (num == 2) {
        return true;
    }
    if (num % 2 == 0) {
        return false;
    }
    for (long i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
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

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(n_temp);
        
        priority_queue<long> pq;
        pq.push(n);

        bool done = false;
        while(!done){
            long num = pq.top();
            pq.pop();
            
            // look for divisors of num
            for(long i = 2; i <= sqrt(num); i++){
                if(num % i == 0){
                    // if we find a divisor i, push it to the queue along with the other divisor num/i
                    pq.push(i);
                    pq.push(num / i);
                    continue;
                }
            }
            // if we get here, num is prime and it's the biggesst because we used a max priority queue
            done = true;
            cout << num << endl;
        }
    }

    return 0;
}
