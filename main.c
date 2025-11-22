#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_LEN 1024 * 32

int calc_digit(int number)
{
	size_t digit = 0;

	if (number == 0)
		return digit;
	
	while (number != 0) {
		number /= 10;
		digit++;
	}

	return  digit;
}

void swap_int(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void shuffle_arr(int *arr, size_t arr_len)
{
	size_t rnd_idx, i;

	for (i = arr_len - 1; i > 0; i--) {
		rnd_idx = rand() % (i + 1);
		swap_int(&arr[rnd_idx], &arr[i]);
	}
}

void bubble_sort(int *arr, size_t arr_len)
{
	size_t i, j;
	char swapped;

	for (i = arr_len - 1; i > 0; i--) {
		swapped = 0;
		for (j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap_int(&arr[j], &arr[j + 1]);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
	}
}


void print_arr(int *arr, size_t arr_len, size_t width)
{
	size_t i;
	
	for (i = 0; i < arr_len; i++) {
		printf("%*d", width, arr[i]);
		putchar(i % 16 == 15 ? '\n' : ' ');
	}
	putchar('\n');
}

int main(void)
{
	int *arr;
	size_t i;

	arr = (int *)malloc(sizeof(int) * ARR_LEN);
	if (arr == NULL)
		return 1;
	for (i = 0; i < ARR_LEN; i++) 
		arr[i] = i + 1;

	srand(time(NULL));
	printf("\n=== before sort ===\n");
	shuffle_arr(arr, ARR_LEN);
	print_arr(arr, ARR_LEN, calc_digit(ARR_LEN));

	printf("\n=== after sort ===\n");
	bubble_sort(arr, ARR_LEN);	
	print_arr(arr, ARR_LEN, calc_digit(ARR_LEN));

	free(arr);
	return 0;
}
