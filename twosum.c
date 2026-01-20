#include <stdlib.h>
#define OFF 1000000000
#define SIZE 2000000001

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* map = (int*)calloc(SIZE, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        int need = target - nums[i];
        if (need >= -OFF && need <= OFF) {
            int idx = map[need + OFF];
            if (idx != 0) {
                int* ans = (int*)malloc(2 * sizeof(int));
                ans[0] = idx - 1;
                ans[1] = i;
                *returnSize = 2;
                free(map);
                return ans;
            }
        }

        map[nums[i] + OFF] = i + 1;
    }
    *returnSize = 0;
    free(map);
    return NULL;
}
