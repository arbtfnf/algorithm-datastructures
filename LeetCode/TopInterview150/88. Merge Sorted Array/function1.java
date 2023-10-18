class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if(n == 0) return; 
        int i=0;
        int j = 0;
        int push = m;
        
        while (n > 0) {
            if(i >= push || nums1[i] > nums2[j]) {
                for(int k = push-1; k>=i; k-- ){
                    nums1[k+1] = nums1[k];
                }
                push++;
                nums1[i] = nums2[j++];
                n--;
            } else {
                i++;
            }
        }
    }
}
