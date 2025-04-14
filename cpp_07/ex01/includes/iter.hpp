#pragma once

template <typename T>
void iter(T *array, int length, void (*f)(T &))
{
	for (int i = 0; i < length; ++i)
	{
		f(array[i]);
	}
}
template <typename T>
void iter(const T *array, int length, void (*f)(const T &))
{
	for (int i = 0; i < length; ++i)
	{
		f(array[i]);
	}
}