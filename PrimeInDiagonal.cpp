class Solution {
private:
    vector<bool> sieve(int n) {
        vector<bool> is_prime(n+1, true);
        is_prime[0] = false;
        is_prime[1] = false;
        for (int i = 2; i*i <= n; i++) {
            if (is_prime[i]) {
                for (int j = i*i; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        return is_prime;
    }
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int row=nums.size(),col=nums[0].size();
        int ans=0;
        vector<bool> isPrime=sieve(4000000);
        for(int i=0;i<row;i++)
        {
            if(nums[i][i]>ans&&isPrime[nums[i][i]])
            {
                ans=nums[i][i];
            }
            if(nums[i][col-1-i]>ans&&isPrime[nums[i][col-1-i]])
            {
                ans=nums[i][col-1-i];
            }
        }
        return ans;
    }
};