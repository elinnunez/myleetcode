class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        if(n <= 1) {
            return count;
        }
        
        vector<bool> sieve(n,true);
        sieve[0] = false;
        sieve[1] = false;
        
        // Sieve of Eratosthenes
        for(int i = 2; i*i < n; i++) { // O(n)
            if(sieve[i] == true) {
                for(int j = i*i; j < n; j+=i) { // Harmonic Series: O(logn)
                    sieve[j] = false;
                }
            }
        }
        
        // Count all numbers that are prime
        for(int i = 2; i < sieve.size(); i++) { // O(n)
            if(sieve[i] == true) {
                count++;
            }
        }
        
        return count;
    }
};

// Time Complexity: O(n) + O(nlogn) = O(nlogn)