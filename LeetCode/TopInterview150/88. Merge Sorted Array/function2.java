class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if (n == 0) return;
        int backM = m-1;
        int backN = n-1;

        int back = m+n-1;

        while(back >= 0) {
            if(backN < 0 || (backM >= 0 && nums1[backM] > nums2[backN])) {
                nums1[back--] = nums1[backM--];
            } else {
                nums1[back--] = nums2[backN--];
            }
        }
    }
}
