#include <iostream>
#include <vector>

using namespace std;


// Given n non-negative integers representing an elevation map where the width of each bar is 1, 
// compute how much water it can trap after raining.
// example: 
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
int trap(vector<int>& height) {
    if(height.size() < 3){
        return 0;
    }

    int i;
    bool is_container = true;
    int container_height;
    int last_container_capacity=0;
    int res=0;
    int start=1;
    int maxi=0;

    // I use the top point to split the problem in two
    // this allows me to assume that a drop in height marks the start of a container or its continuation
    // while it is not the case if I don't do this (i.e. 3 2 1 0)
    for(int i=1; i<height.size(); i++){
        if(height[i] > height[maxi]){
            maxi = i;
        }
    }

    // get to the first drop in height
    while(height[start]-height[start-1] > 0){
        start++;
    }
    container_height = height[start-1];
    for(i=start; i<maxi; i++){
        if(is_container){
            // container ended
            if(height[i] >= container_height){
                // res+=last_container_capacity;
                // last_container_capacity = 0;
                is_container = false;
            }
            // container keeps going
            else {
                res+=container_height-height[i];
            }
        } else {
            // container starts
            if(i>0 && height[i-1]>height[i]){
                is_container = true;
                container_height = height[i-1];
                res += height[i-1]-height[i];
            }
        }
    }

    // get to the drop in height, starting from the end
    start = height.size()-2;
    while(start >= 0 && height[start]-height[start+1] > 0){
        start--;
    }
    is_container = true;
    container_height = height[start+1];
    for(i=start; i>=maxi; i--){
        if(is_container){
            // container ended
            if(height[i] >= container_height){
                // res+=last_container_capacity;
                // last_container_capacity = 0;
                is_container = false;
            }
            // container keeps going
            else {
                res+=container_height-height[i];
            }
        } else {
            // container starts
            if(i<height.size() && height[i+1]>height[i]){
                is_container = true;
                container_height = height[i+1];
                res += height[i+1]-height[i];
            }
        }
    }
    return res;
}


int main(){
    vector<int> v = {5,4,3,2,1,0};
    cout << trap(v) << endl;
    return 0;
}