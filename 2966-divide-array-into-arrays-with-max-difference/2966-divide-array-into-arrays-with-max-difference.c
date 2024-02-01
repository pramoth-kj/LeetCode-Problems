/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
/**
 * Compares two integers for use in qsort.
 *
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 * @return -1 if a < b, 0 if a == b, 1 if a > b.
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

/**
 * Divides an array into subarrays of size 3, ensuring the difference between
 * the maximum and minimum values in each subarray is within a specified limit.
 *
 * @param nums The input array of integers.
 * @param numsSize The size of the input array.
 * @param k The maximum allowed difference between the maximum and minimum values in a subarray.
 * @param returnSize A pointer to an integer that will store the number of subarrays.
 * @param returnColumnSizes A pointer to an integer array that will store the sizes of the subarrays.
 * @return A pointer to a pointer to an integer array, where each subarray is of size 3, or NULL if the array cannot be divided.
 */
int** divideArray(int* nums, int numsSize, int k, int* returnSize, int** returnColumnSizes) {
    if (numsSize % 3 != 0) {  // Check if the size is divisible by 3
        return NULL;
    }

    // Initialize variables
    *returnSize = numsSize / 3;
    qsort(nums, numsSize, sizeof(int), cmp);  // Sort the array in ascending order

    int **result = (int **)calloc(*returnSize, sizeof(int *));  // Allocate memory for the result array
    if (result == NULL) {
        exit(-1);  // Handle memory allocation failure
    }

    int index = 0;
    for (int i = 2; i < numsSize; i += 3) {  // Iterate through the array in steps of 3
        if (nums[i] - nums[i - 2] > k) {  // Check if the difference in the subarray is within the limit
            // If not, release allocated memory and return NULL
            for (int j = 0; j < *returnSize; ++j) {
                free(result[j]);
            }
            free(result);
            *returnSize = 0;
            return NULL;
        }

        int *temp = (int *)malloc(3 * sizeof(int));  // Allocate memory for a subarray
        if (temp == NULL) {
            // Handle memory allocation failure
            for (int j = 0; j < *returnSize; ++j) {
                free(result[j]);
            }
            free(result);
            return NULL;
        }
        // Fill the subarray with values
        temp[0] = nums[i - 2];
        temp[1] = nums[i - 1];
        temp[2] = nums[i];

        result[index++] = temp;  // Add the subarray to the result
        temp = NULL;
    }

    // Allocate memory for the column size array
    (*returnColumnSizes) = (int *)malloc((*returnSize) * sizeof(int));
    if (*returnColumnSizes == NULL) {
        // Handle memory allocation failure
        for (int j = 0; j < *returnSize; ++j) {
            free(result[j]);
        }
        free(result);
        return NULL;
    }

    // Set the column sizes to 3
    for (int i = 0; i < (*returnSize); ++i) {
        (*returnColumnSizes)[i] = 3;
    }

    return result;  // Return the result and column size arrays
}