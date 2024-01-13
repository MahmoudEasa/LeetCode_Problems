double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int mid_all = (nums1Size + nums2Size) / 2;
    int num1, num2;
    double mid;


    if (nums1Size == 1 && nums2Size == 1)
        return ((double)(nums1[0] + nums2[0]) / 2);

    if (!nums1Size && nums2Size)
    {
        if (nums2Size % 2 == 0)
            mid = (double)((nums2[(nums2Size / 2)]) + (nums2[((nums2Size / 2) - 1)])) / 2;
        else
            mid = (double)nums2[(nums2Size / 2)];

        return (mid);
    }

    if (!nums2Size && nums1Size)
    {
        if (nums1Size % 2 == 0)
            mid = (double)((nums1[(nums1Size / 2)]) + (nums1[((nums1Size / 2) - 1)])) / 2;
        else
            mid = (double)nums1[(nums1Size / 2)];

        return (mid);
    }

    if (nums1[nums1Size - 1] < nums2[0])
    {
        if ((nums1Size + nums2Size) % 2 != 0)
            if (nums1Size <= mid_all)
                return (nums2[(mid_all - nums1Size)]);
            else
                return (nums1[(mid_all)]);

        if (nums1Size > mid_all)
        {
            num1 = nums1[mid_all];
            num2 = nums1[mid_all - 1];
        }
        else if (nums1Size == mid_all)
        {
            num1 = nums1[mid_all - 1];
            num2 = nums2[(mid_all - nums1Size)];
        }
        else
        {
            num1 = nums2[(mid_all - nums1Size)];
            num2 = nums2[(mid_all - nums1Size) - 1];
        }
        
        double sum = (double)(num1 + num2) / 2;
        return (sum);
    }
    else
    {
        int arr[((nums1Size + nums2Size))];
        int i = 0, j = 0, k = 0;

        while (i < nums1Size && j < nums2Size)
        {
            if (nums1[i] <= nums2[j])
            {
                arr[k++] = nums1[i];
                i++;
            }
            else
            {
                arr[k++] = nums2[j];
                j++;
            }
        }

        if ((nums1Size >= mid_all) && (i < mid_all))
            for (i; i < nums1Size - 1; i++)
                arr[k++] = nums1[i];

        if ((nums2Size >= mid_all) && (j < mid_all))
            for (j; j < nums2Size - 1; j++)
                arr[k++] = nums2[j];

        if ((nums1Size + nums2Size) % 2 == 0)
            return ((double)(arr[mid_all] + arr[mid_all - 1]) / 2);
            
        if (!arr[mid_all])
            return (0);

        return (arr[mid_all]);
    }

    return (0);
}
