/* ************************************************* *
 *          Annie Wang 2016.11.30                    *
 *  Idea: Sieve of Eratosthenes                      *
 *  Remark: N/A                                      *
 * ************************************************* *
 */
class Solution {
public:
    int countPrimes(int n) {
        if(n < 3 ) return 0;
        vector<bool> prime(n, true);
        prime[0] = false;
        prime[1] = false;
        int opt = 0;
        for(int i = 2; i < n; i++){
            if(prime[i]){
                opt++;
                for(int j = 2 * i; j < n; j += i ){
                    prime[j] = false;
                }
            }
        }
        return opt;
    }
};
