#include "../includes/PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <vector>

PmergeMe::PmergeMe()
{
    std::cout << "PmergeMe: "
              << "default constructor called" << std::endl;
}

PmergeMe::~PmergeMe()
{
    std::cout << "PmergeMe: "
              << "default destructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    (void)copy;
    std::cout << "PmergeMe: "
              << "copy constructor called" << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
    (void)copy;
    std::cout << "PmergeMe: "
              << "copy assignment called" << std::endl;
    return *this;
}

/*
 * Convert a string to a positive integer
 *
 * @param str: string to be converted
 */
int PmergeMe::convert_positive_int(const std::string &str)
{
    std::stringstream ss(str);
    int value;
    ss >> value;
    if (ss.fail() || !ss.eof())
    {
        return (-1);
    }
    return (value);
}

/*
 * Create an array of integers from the input strings
 *
 * @param str_ptr: array of strings
 * @param size: size of the array
 */
int *PmergeMe::create_numbers(char **str_ptr, int size)
{
    int *array = new int[size];
    for (int i = 0; i < size; i++)
    {
        int res = PmergeMe::convert_positive_int(std::string(str_ptr[i]));
        if (res == -1)
        {
            delete[] array;
            throw PmergeMe::InvalidInput();
        }
        array[i] = res;
    }
    return array;
}

void PmergeMe::show(const std::vector<int> &arr) const
{
    std::cout << "[";
    for (std::vector<int>::const_iterator it = arr.begin(); it != arr.end(); ++it)
    {
        if (it == arr.begin())
            std::cout << *it;
        else
            std::cout << ", " << *it;
    }
    std::cout << "]" << std::endl;
}

/*
 * Merge insertion sort algorithm
 *
 * @param arr: array to be sorted
 * @param l: left index
 * @param mid: middle index
 * @param r: right index
 */
void PmergeMe::merge_insert(std::vector<int> &arr, int l, int mid, int r)
{
    std::cout << "index: [l, mid, r] = [" << l << ", " << (l + r) / 2 << ", " << r << "]"
              << " "
              << "merge-insert: [" << arr[l] << ", " << arr[mid] << ", " << arr[r] << "]" << std::endl;
}

/*
 * Merge insertion sort algorithm
 *
 * @param arr: array to be sorted
 * @param l: left index
 * @param r: right index
 */
void PmergeMe::merge_insertion_sort(std::vector<int> &arr, int l, int r)
{

    if (r - l <= 1)
    {
        return;
    }
    int mid = (l + r) / 2;
    std::cout << "index: [l, mid, r] = [" << l << ", " << (l + r) / 2 << ", " << r << "]" << std::endl;
    this->PmergeMe::merge_insertion_sort(arr, mid, r);
    this->PmergeMe::merge_insertion_sort(arr, l, mid);
    this->PmergeMe::merge_insert(arr, l, mid, r);
}

/*
 * Merge two sorted arrays
 *
 * @param arr: array to be sorted
 * @param l: left index
 * @param mid: middle index
 * @param r: right index
 */
void PmergeMe::merge(std::vector<int> &arr, int l, int mid, int r)
{
    std::vector<int> left(arr.begin() + l, arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.begin() + r);

    int i = 0, j = 0, k = l;
    while (i < (int)left.size() && j < (int)right.size())
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }

    while (i < (int)left.size())
    {
        arr[k++] = left[i++];
    }

    while (j < (int)right.size())
    {
        arr[k++] = right[j++];
    }
}

/*
 * Merge sort algorithm
 *
 * @param arr: array to be sorted
 * @param l: left index
 * @param r: right index
 */
void PmergeMe::merge_sort(std::vector<int> &arr, int l, int r)
{

    if (r - l <= 1)
    {
        return;
    }
    int mid = (l + r) / 2;
    std::cout << "index: [l, mid, r] = [" << l << ", " << (l + r) / 2 << ", " << r << "]" << std::endl;
    this->PmergeMe::merge_sort(arr, l, mid);
    this->PmergeMe::merge_sort(arr, mid, r);
    this->PmergeMe::merge(arr, l, mid, r);
}

/*
 * Execute the merge insertion sort algorithm
 *
 * @param array: array to be sorted
 * @param size: size of the array
 */
void PmergeMe::execute_sort(const int *array, const int size)
{
    int end = (size - (size % 2));
    std::vector<int> array_vec(array, array + size);
    this->show(array_vec);
    this->merge_sort(array_vec, 0, size);
    this->show(array_vec);
}

/*
 * Exception class for invalid input
 */
const char *PmergeMe::InvalidInput::what() const throw()
{
    return ("Invalid input");
}