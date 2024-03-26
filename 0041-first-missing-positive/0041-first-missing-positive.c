int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a > *(int *)b) - (*(int *)a < *(int *)b);
}


int firstMissingPositive(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int ris = 1;
    for (int i = 0; i < numsSize; i++)
    {
        if (i > 0)
        {
            if (nums[i] == nums[i - 1])
            {
                continue;
            }
        }

        if (nums[i] <= 0)
        {
            continue;
        }
        else if (ris == nums[i])
        {
            ris++;
            continue;
        }
        break;
    }
    return ris;
}