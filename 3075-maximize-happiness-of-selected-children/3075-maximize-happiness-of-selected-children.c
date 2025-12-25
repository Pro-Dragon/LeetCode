void    merge(int *nums, int l, int m, int r)
{
    int left = m - l + 1;
    int right = r - m;

    int L[left], R[right];
    int i = 0, j = 0, k = l;
    for (i = 0; i < left; i++)
        L[i] = nums[l + i];
    for (i = 0; i < right; i++)
        R[i] = nums[m + 1 + i];
    i = 0;
    while (i < left && j < right)
    {
        if (L[i] >= R[j])
            nums[k++] = L[i++];
        else
            nums[k++] = R[j++];
    }
    while (i < left)
        nums[k++] = L[i++];
    while (j < right)
        nums[k++] = R[j++];
}

void    merge_sort(int *nums, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        merge_sort(nums, l, m);
        merge_sort(nums, m + 1, r);
        merge(nums, l, m, r);
    }
}
long long int maximumHappinessSum(int* happiness, int happinessSize, int k) {
    long long int i, j, hap = 0, a = 0;
    merge_sort(happiness, 0, happinessSize - 1);
    for (i = 0; i <happinessSize; i++) {
        happiness[i] -= a;
        if (happiness[i] < 0)
            happiness[i] = 0;
        hap += happiness[i];
        k--;
        if (!k)
            return hap;
        a++;
    }
    return 0;
}