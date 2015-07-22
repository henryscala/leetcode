#ifndef MEDIAN_H
#define MEDIAN_H

double findMedianOfArray(int* nums,int startPos, int len){
    if (len % 2 != 0){/*odd num*/
        return nums[startPos+len/2];
    } else {
        return (nums[startPos + len/2] + num[ startPos + len/2 - 1])/2;
    }
}

double findMedian(int* nums1,int startPos1, int len1,int* nums2, int startPos2, int len2) {
    /* to be cont */
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    return findMedian(nums1,0,nums1Size,nums2,0,nums2Size);
}

#endif // MEDIAN_H

