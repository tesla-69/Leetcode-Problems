class Solution {
public:
    bool isPrime(int num) {
        if (num < 2) return false; // Fix: Ensure numbers < 2 are handled
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        
        // Collect all prime numbers in the range
        for (int i = left; i <= right; i++) {
            if (isPrime(i)) primes.push_back(i);
        }

        if (primes.size() < 2) return {-1, -1}; // No pair found

        int minDiff = INT_MAX;
        int n1 = -1, n2 = -1;

        for (int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                n1 = primes[i - 1];
                n2 = primes[i];
            }
        }

        return {n1, n2};
    }
};
