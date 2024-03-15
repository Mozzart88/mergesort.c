#include <mergesort.h>

static void	_bzero(void *pointer, size_t size)
{
	char	*tmp;

	if (!pointer)
		return;
	tmp = (char*)pointer;
	while (size--)
		*(tmp + size) = 0;
}

static void	_swap(int *dst)
{
	int	i;

	i = *dst;
	*dst = *(dst + 1);
	*(dst + 1) = i;
}

static void _memcpy(int *src, int *dst, size_t size)
{
	if (!src || !dst)
		return;
	while (size--)
		*(dst + size) = *(src + size);
}

static unsigned int	_getSemiSize(int size)
{
	return size % 2 + size / 2;
}

static void	_merge(int *arr, int size, mergesort_callback cb)
{
	const int		*breakPointer;
	int const		tmp[size];
	int const		*firstSubArrayPointer;
	int const		*secondSubArrayPointer;
	int			i;

	_memcpy(arr, (int*)tmp, size);
	firstSubArrayPointer = &(tmp[0]);
	breakPointer = &(tmp[_getSemiSize(size)]);
	secondSubArrayPointer = breakPointer;
	--size;
	i = 0;
	while (i++ <= size)
	{
		if (firstSubArrayPointer >= breakPointer)
			*arr = *(secondSubArrayPointer++);
		else if (secondSubArrayPointer > &(tmp[size]))
			*arr = *(firstSubArrayPointer++);
		else if (cb(*firstSubArrayPointer, *secondSubArrayPointer))
			*arr = *(secondSubArrayPointer++);
		else if (!cb(*firstSubArrayPointer, *secondSubArrayPointer))
			*arr = *(firstSubArrayPointer++);
		++arr;
	}
}

static void	_sort(int *src, int *dst, size_t size, mergesort_callback cb)
{
	unsigned int	firstSubArraySize;
	unsigned int	secondSubArraySize;

	if (size <= 2)
	{
		_memcpy(src, dst, size);
		if (size > 1 &&  cb(*dst, *(dst + 1)))
			_swap(dst);
		return;
	}
	firstSubArraySize = _getSemiSize(size);
	secondSubArraySize = size / 2;
	_sort(src, dst, firstSubArraySize, cb);
	_sort(src + firstSubArraySize, dst + firstSubArraySize, secondSubArraySize, cb);
	_merge(dst, size, cb);
}

int 		*my_mergesort(int *arr, size_t size, mergesort_callback cb)
{
	int	*res;

	if ((res = (int*)malloc((sizeof (int)) * size)) == NULL)
		return NULL;
	_bzero(res, size);
	_sort(arr, res, size, cb);
	
	return res;
}
