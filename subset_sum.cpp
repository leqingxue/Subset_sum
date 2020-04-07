//
// Created by leqin on 4/6/2020.
//
#include <stdint.h>

int subsetSum(int* a, uint32_t len, uint32_t count, uint32_t sum) {
    if(sum == 0 && count == 0){ //found a working subset sum
        return 1;
    }
    if(sum != 0 && count == 0){ //used up count and did not find the sum
        return 0;
    }
    if(len==0){ //reached the end of the array
        return 0;
    }
    int case1 = 0;
    if (sum >= a[0]){ //case 1 recursion, if can continue{
        case1 = subsetSum(a+1, len-1, count-1, sum-a[0]);
    }
    int case2  = subsetSum(a+1, len-1, count, sum); //if cannot work with the first in a
    if(case1 || case2){ //if either returns a true;
        return 1;
    }
    return 0;
}