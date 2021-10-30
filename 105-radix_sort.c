#include "sort.h"

/**
 * recursive_radix_sort - Function to sort
 * @array: Array
 * @result: result
 * @size: Size
 * @lsd: parameter
 *
 */
void recursive_radix_sort(int *array, int *result, size_t size, int lsd)
{
	int idx_start;
	int idx_end;
	int i;
	int index[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	for (i = 0 ; i < (int)size ; i++)
		index[(array[i] / lsd) % 10] += 1;
	if (index[0] == (int)size)
		return;
	for (i = 1 ; i < 10 ; i++)
		index[i] += index[i - 1];
	for (i = 9 ; i > 0 ; i--)
		index[i] = index[i - 1];
	index[0] = 0;
	for (i = 0 ; i < (int)size ; i++)
	{
		idx_end = (array[i] / lsd) % 10;
		idx_start = index[idx_end];
		result[idx_start] = array[i];
		index[idx_end]++;
	}
	for (i = 0 ; i < (int)size ; i++)
		array[i] = result[i];
	print_array(array, size);
	recursive_radix_sort(array, result, size, lsd * 10);
}
/**
 * radix_sort - Function sort
 * @array: Array
 * @size: Size
 *
 */
void radix_sort(int *array, size_t size)
{
	int *result;

	if (!array || size <= 1)
		return;
	result = malloc(sizeof(int) * size);
	if (!result)
		return;
	recursive_radix_sort(array, result, size, 1);
	free(result);
}
