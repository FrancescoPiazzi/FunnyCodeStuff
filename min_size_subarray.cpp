#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int right=0;
    int left=0;
    int sum=0;
    int minnums;
    bool found = false;
    while(right<nums.size()){
        sum+=nums[right];
        // if we meet the target
        if(sum>=target){
            // try moving the left pointer forward, reducing the numbers used
            while(sum-nums[left]>=target){
                sum-=nums[left];
                left++;
            }
            minnums = found ? min(minnums, right-left+1) : right-left+1;
            found = true;
        }
        right++;
    }
    return found ? minnums : 0;
}


string longestCommonPrefix(vector<string>& strs) {
    string res="";
    bool valid;
    size_t shortest = strs[0].size();
    for(string s : strs){
        shortest = std::min(shortest, s.size());
    }
    for(int i=0; i<shortest; i++){
        char base = strs[0][i];
        for(const auto &s : strs){
            if(s[i]!=base){
                return res;
            }
        }
        res+=base;
    }
    return res;
}

int main() {
    vector<int> nums = {3,3,3,4,2,3};
    int target = 18;
    cout << minSubArrayLen(target, nums) << endl;
    return 0;
}