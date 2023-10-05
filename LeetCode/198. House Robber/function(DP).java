class Solution {
    public int rob(int[] nums) {
        if (nums.length == 1) return nums[0];
        
        int[] dp = new int[nums.length];

        for (int i=0; i<nums.length; i++)
                if(i<2)
                    dp[i] = nums[i];
                else {
                    dp[i] = -1;
                }

        for (int i=2; i<nums.length; i++) {
            if (i >= 3)
                dp[i] = Math.max(dp[i-2],dp[i-3]) + nums[i]; 
            else {
                dp[i] = nums[i] + dp[i-2];
            }
        }
        return Math.max(dp[nums.length-1], dp[nums.length-2]);
    }
}

//Time complexity: O(n)
//Space complexity: O(n)
