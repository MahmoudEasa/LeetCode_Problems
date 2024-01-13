int search(int* nums, int numsSize, int target) {
    short left, right = (numsSize - 1), mid, i = 0;


    if (numsSize && nums[0] == target) return (0);
    if (numsSize > 1 && nums[1] == target) return (1);
    if (nums[numsSize - 1] == target) return (numsSize - 1);

    while (i < numsSize && (nums[i] > target))
        i++;

    while (right >= 0 && (nums[right] < target))
        right--;

    left = i;
    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] == target) return (mid);

        if (nums[mid] < target) left = (mid + 1);
        else right = (mid - 1);
    }

    return (-1);
}
