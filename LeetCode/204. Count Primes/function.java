class Solution {
    public int countPrimes(int n) {
        int count = 0;
        if (n<2) return count;
        boolean[] Prime = new boolean[n+1];
        // Arrays.fill(Prime, true);

        for (int i=2; i<n; i++) {
            if(Prime[i]) continue;
            count++;
            for ( long j= (long)i*i; j<n; j+=i) {
                Prime[(int)j] = true;
            }
        }
        // for ( long i=2; i<n; i++) {
        //     if (Prime[(int)i]) count++;
        // }
        return count;
    }
}

//Time complexity: O(n)*O(sqrt(n)) using Sieve of Eratosthenes Algorithm
