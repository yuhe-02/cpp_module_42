#pragma once

#include <string>
#include <vector>
// #include <iostream>

class PmergeMe
{
  private:
    PmergeMe(const PmergeMe &copy);
    PmergeMe &operator=(const PmergeMe &copy);
    void merge_insertion_sort(std::vector<int> &arr, int l, int r);
    void merge_insert(std::vector<int> &arr, int l, int mid, int r);
    void show(const std::vector<int> &arr) const;

  public:
    PmergeMe();
    ~PmergeMe();
    static int convert_positive_int(const std::string &str);
    static int *create_numbers(char **str_ptr, int size);
    void execute_sort(const int *array, const int size);
    class PmergeMeException : public std::exception
    {
      public:
        virtual const char *what() const throw() = 0;
    };
    class InvalidInput : public PmergeMeException
    {
      public:
        virtual const char *what() const throw();
    };
};