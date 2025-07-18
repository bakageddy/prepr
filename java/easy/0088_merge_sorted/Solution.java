package dev.bakageddy.prepr;
public class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
		if (m == 0 && n == 0) return;
		int i = m - 1;
		int j = n - 1;
		int k = nums1.length - 1;

		while (i >= 0 && j >= 0) {
			if (nums1[i] > nums2[j]) {
				nums1[k--] = nums1[i--];
			} else {
				nums1[k--] = nums2[j--];
			}
		}

		while (i >= 0) {
			nums1[k--] = nums1[i--];
		}

		while (j >= 0) {
			nums1[k--] = nums2[j--];
		}
    }
}
