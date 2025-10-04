"""
https://leetcode.com/problems/merge-sorted-array/description/
"""
from typing import List

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        
        ptr1 = m - 1
        ptr2 = n - 1

        ptr_avail = m + n - 1

        while ptr2 >= 0:
            if ptr1 < 0 or nums1[ptr1] < nums2[ptr2]:
                nums1[ptr_avail] = nums2[ptr2]

                ptr_avail -= 1
                ptr2 -= 1

            else:
                nums1[ptr_avail] = nums1[ptr1]

                ptr1 -= 1
                ptr_avail -= 1


def main():
    sol = Solution()

    # nums1 = [1,2,3,0,0,0]
    # m = 3
    # nums2 = [2,5,6]
    # n = 3

    nums1 = [2,0]
    m = 1
    nums2 = [1]
    n = 1

    sol.merge(nums1, m, nums2, n)

    print(nums1)


main()