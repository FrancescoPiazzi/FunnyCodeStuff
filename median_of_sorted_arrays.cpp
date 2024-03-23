#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cassert>

using namespace std;


// THIS DOES NOT WORK
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int min1=0, max1=nums1.size(); // for choosing an element
    int min2=0, max2=nums2.size(); // for searching where to put it
    int totaln = nums1.size()+nums2.size();
    bool found = false;
    double median;
    while(!found){
        min2=0;
        max2=nums2.size();
        // using binary search choose an element vrom vector 1
        int i = (min1+max1)/2;
        // long long int n = nums1[i];
        // see where it ends up if we put it in vector 2
        int j = (min2+max2)/2;
        while(max2-min2>1){
            if(nums1[i]<=nums2[j]){
                max2 = j;
            } else {
                min2 = j;
            }
        }
        // is i the index of a median?
        if(totaln-(i+j) == 0){
            median = nums2[i];
            found = true;
        }
        if(totaln-(i+j) == 1){
            median = (nums2[i]+nums2[i+1])/2.0;
            found = true;
        }
        if(totaln-(i+j) == -1){
            median = (nums2[i]+nums2[i-1])/2.0;
            found = true;
        }
        // otherwise correct the range for i
        if((i+j)*2 > totaln){
            max1 = i;
        } else {
            min1 = i;
        }
    }
    return median; // Return the calculated median value.
}


int main(){
    vector<int> nums1, nums2;

    nums1 = {1, 3};
    nums2 = {2};
    assert(findMedianSortedArrays(nums1, nums2) == 2.0);

    return 0;
}