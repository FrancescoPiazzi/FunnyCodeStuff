#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i1 = m-1, i2=n-1, k=m+n-1;
    while(k >= 0){
        if(i2<0 || i1>=0 && nums1[i1] > nums2[i2]){
            nums1[k] = nums1[i1];
            i1--;
        } else {
            nums1[k] = nums2[i2];
            i2--;
        }
        k--;
    }
}


void rotate(vector<int>& nums, int j) {
    int size = nums.size();

    j = j%nums.size();

    int *tmp = new int[size];

    for(int i=0; i<size; i++){
        tmp[(i+j)%nums.size()] = nums[i];
    }
    for(int i=0; i<size; i++){
        nums[i] = tmp[i];
    }

    delete[] tmp;

}


int maxProduct(vector<int>& nums) {
    int mx = nums[0];
    bool leftmost_negative = false;
    bool zero = false;
    int sofar1 = 1;     // cumulative product
    int sofar2 = 1;     // cumulative product after the first negative

    for(int i=0; i<nums.size(); i++){
        if(nums[i]==0){
            zero = true;
            if(i>0 && nums[i-1]!=0){   // we just ended a section
                leftmost_negative = false;
                sofar1 = 1;
                sofar2 = 1;
            }
            continue;
        }

        sofar1*=nums[i];
        if(leftmost_negative){
            sofar2*=nums[i];
        }

        if(nums[i]<0){
            leftmost_negative = true;
        }
        mx = leftmost_negative ? max(mx, max(sofar1, sofar2)) : max(mx, sofar1);
    }
    return zero ? max(mx, 0) : mx;
}


void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> temp(m);
    for(int i = 0; i < m; i++){
        temp[i] = nums1[i];
    }
    int i1 = 0, i2 = 0, j=0;
    while(i1<m && i2<n){
        if(temp[i1] < nums2[i2]){
            nums1[j] = temp[i1];
            i1++;
        } else {
            nums1[j] = nums2[i2];
            i2++;
        }
        j++;
    }
    while(i1<m){
        nums1[j] = temp[i1];
        i1++;
        j++;
    }
    while(i2<n){
        nums1[j] = nums2[i2];
        i2++;
        j++;
    }
}


int main(){
    vector<int> nums1 = {0};
    vector<int> nums2 = {1};
    merge(nums1, 0, nums2, 1);

    vector<int> nums3 = {-2, 0, -1};
    maxProduct(nums3);

    int x;
}