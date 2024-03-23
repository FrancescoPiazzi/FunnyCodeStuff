#include <iostream>
#include <vector>

using namespace std;


// removes duplicates from a sorted array
int removeDuplicates(vector<int>& nums) {
    int res = nums.size();
    int ii=0;
    for(int i=0; i<nums.size()-1; i++){
        if(nums[i]==nums[i+1]){
            res--;
        } else{
            nums[ii] = nums[i];
            ii++;
        }
    }

    return res;
}