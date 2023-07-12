#ifndef TYPES_HPP
# define TYPES_HPP
# include "includes.hpp"
# define SORT_MAXLEN 2

template<typename Iterator>
void it_advance(Iterator& it, size_t amount)
{
	for (size_t x = 0; x < amount; x++)
		++it;
}

template<typename Iterator>
Iterator& it_previous(Iterator& it, Iterator& prev)
{
	//static Iterator prev = it;
	prev = it;
	--prev;
	if (prev != Iterator())
		return(it);
	else
		return (prev);
}

// template <typename Iterator>
// void insertionSort(Iterator begin, Iterator end) {
//	 for (Iterator i = begin + 1; i != end; ++i) {
//		 typename Iterator::value_type key = *i;
//		 Iterator j = i - 1;
//		 while (j >= begin && *j > key) {
//			 *(j + 1) = *j;
//			 --j;
//		 }
//		 *(j + 1) = key;
//	 }
// }

// template<typename Iterator>
// void insertionSort(Iterator begin, Iterator end)
// {
//	 for (Iterator i = begin; i != end; ++i)
//	 {
//		 Iterator j = i;
//		 while (j != begin && *j < *(std::prev(j)))
//		 {
//			 std::iter_swap(j, std::prev(j));
//			 --j;
//		 }
//	 }
// }


// template<typename Iterator>
// void insertionSort(Iterator begin, Iterator end)
// {
//	 if (begin == end)
//		 return;

//	 Iterator i = begin;
//	 ++i;

//	 while (i != end)
//	 {
//		 typename std::iterator_traits<Iterator>::value_type value = *i;
//		 Iterator j = i;

//		 while (j != begin && value < *(--j))
//		 {
//			 Iterator next = j;
//			 ++next;
//			 *next = *j;
//		 }

//		 Iterator next = j;
//		 ++next;
//		 *next = value;

//		 ++i;
//	 }
// 	if (*i < *end)
// 		std::iter_swap(i, end);
// }

// template<typename Iterator>
// void insertionSort(Iterator begin, Iterator end)
// {
// 	if (begin == end)
// 		return;

// 	for (Iterator i = begin; i != end; ++i)
// 	{
// 		typename std::iterator_traits<Iterator>::value_type value = *i;
// 		Iterator j = i;
// 		Iterator prev = j;
// 		--prev;

// 		while (j != begin && value < *prev)
// 		{
// 			*j = *prev;
// 			--j;
// 			--prev;
// 		}

// 		*j = value;
// 	}
// }

template<typename Iterator>
void insertionSort(Iterator begin, Iterator end)
{
    if (begin == end)
        return;

    typedef typename Iterator::value_type value_type;

    for (Iterator i = begin; i != end; ++i)
    {
        value_type value = *i;
        Iterator j = i;
        Iterator prev = j;
        --prev;

        while (j != begin && value < *prev)
        {
            *j = *prev;
            --j;
            --prev;
        }

        *j = value;
    }
}


template<typename Iterator>
void mergeInsertSort(Iterator begin, Iterator end, size_t targetSize)
{
	const size_t distance = std::distance(begin, end);
	if (distance <= targetSize)
	{
		insertionSort(begin, end);
	}
	else
	{
		Iterator mid = begin;
		std::advance(mid, distance / 2);

		mergeInsertSort(begin, mid, targetSize);
		mergeInsertSort(mid, end, targetSize);

		std::inplace_merge(begin, mid, end);
	}
}


// template <typename Iterator>
// void mergeInsertSort(Iterator begin, Iterator end, size_t targetSize) {
//	 size_t containerSize = std::distance(begin, end);
//	 if (containerSize <= targetSize) {
//		 insertionSort(begin, end);
//	 } else {
//		 Iterator middle = begin + containerSize / 2;
//		 mergeInsertSort(begin, middle, targetSize);
//		 mergeInsertSort(middle, end, targetSize);
//		 std::inplace_merge(begin, middle, end);
//	 }
// }

// template <typename Container>
// void mergeInsertionSort(Container& container, size_t targetSize) {
//	 mergeInsertSort(container.begin(), container.end(), targetSize);
// }


// template<typename Iterator>
// void insertionSort(Iterator begin, Iterator end)
// {
// 	std::cout << "insSort called on: " << *begin << " " << *end << std::endl;
// 	for (Iterator i = begin; i != end; i++)
// 	{
// 		Iterator j = end;
// 		Iterator prev;
// 		prev = it_previous(i, prev);
// 		while (j != begin) // && *j > *(it_previous(j)))
// 		{
// 			prev = it_previous(j, prev);
// 			if (*j < *it_previous(j, prev))
// 			{
// 				std::cout << "swapping " << *j << " " << *prev << std::endl;
// 				std::iter_swap(j, prev);
// 			}
// 			j--;
// 		}
// 	}
// }

// template<typename Iterator>
// void mergeInsertSort(Iterator begin, Iterator end)
// {
//	 if (ub - lb <= THRESHOLD)
//		 insertionSort(f, lb, ub);
//	 else
//	 {
//		 int mid = (lb+ub)/2;
//		 mergeSort(f,lb,mid);
//		 mergeSort(f,mid,ub);
//		 merge(f,lb,mid,ub);
//	 }
// }


// template<typename Iterator>
// void mergeInsertSort(Iterator begin, Iterator end, int halve_size = SORT_MAXLEN)
// {
// 	if (std::distance(begin, end) >= halve_size)
// 	// 	insertionSort(begin, end);
// 	// else
// 	{
// 		if (std::distance(begin, end) < SORT_MAXLEN)
// 		{
// 			Iterator half = begin;
// 			std::cout << "arr size: " << std::distance(begin, end) << " for b/e: " << *begin << " " << *end << std::endl;
// 			it_advance(half, std::distance(begin, end) / 2);
// 	//		std::cout << "half: " << *half;
// 			std::cout << " " << *half << std::endl;
// 			std::cout << "half size: " << std::distance(begin, half) << std::endl;
// 			mergeInsertSort(begin, half, halve_size);
// 			mergeInsertSort(half, end, halve_size);
// 			std::inplace_merge(begin, half, end);
// 		}
// 		// std::inplace_merge(begin, half, end);
// 	}
// 	//std::inplace_merge(begin, half, end);
// }

template<typename Iterator>
void mIS(Iterator begin, Iterator end)
{
	// --end;
	// std::cout << "before calling algo: begin points to " << *begin << " and end points to " << *end << std::endl;
	mergeInsertSort(begin, end, std::distance(begin, end));
}

// // template<typename Iterator>
// // void mergeInsertSort(Iterator begin, Iterator end, int cutoff = 10)
// // {
// // 	if (std::distance(begin, end) <= cutoff)
// // 		insertionSort(begin, end);
// // 	else
// // 	{
// // 		Iterator middle = begin;
// // 		std::advance(middle, std::distance(begin, end) / 2);
// // 		mergeInsertSort(begin, middle, cutoff);
// // 		mergeInsertSort(middle, end, cutoff);
// // 		std::inplace_merge(begin, middle, end);
// // 	}
// // }

template<typename Container>
void printContainer(const Container& container) {
	std::cout << "-------CONTAINER-------" << std::endl;
	typename Container::const_iterator it;
	for (it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "-----------------------" << std::endl;
}

template <typename Container>
Container createContainer(const std::vector<int>& vec) {
	Container container(vec.begin(), vec.end());
	return container;
}

class BadInputException : public std::exception {
public:
	const char* what() const throw() {
		return "Error: Bad Input";
	}
};

template <typename Container>
void benchmark(Container& container) {
	// Get the current clock time before performing the sorting operation
	clock_t start = clock();

	// Call the mergeInsertSort function or any other operation you want to measure
	mIS(container.begin(), container.end());

	// Get the current clock time after the sorting operation
	clock_t end = clock();

	// Calculate the duration in milliseconds
	double duration = (end - start) * 1000.0 / CLOCKS_PER_SEC;

	// Print the duration
	std::cout << "Sorting time: " << duration << " milliseconds" << std::endl;
	std::cout << "Result: " << std::endl;
	printContainer(container);
}

template<typename Container>
bool isAscendingOrder(const Container& container)
{
	typename Container::const_iterator prev = container.begin();
	typename Container::const_iterator current = prev;
	++current;

	while (current != container.end())
	{
		if (*current < *prev)
			return false;
		
		++prev;
		++current;
	}

	return true;
}

#endif