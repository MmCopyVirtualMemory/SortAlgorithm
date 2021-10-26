#include <windows.h>
#include <iostream>
#include <vector>

template <typename T>
void PrintList(std::vector<T> list)
{
	for (int i = 0; i < list.size(); i++)
	{
		std::cout << "Index: " << i << " -> " << list[i] << std::endl;
	}
}

template <typename T>
void FindBiggest(std::vector<T> list, T& biggest, int& biggest_idx)
{
	biggest = list[0];
	biggest_idx = 0;
	for (int i = 0; i < list.size(); i++) 
	{
		if (list[i] > biggest) 
		{
			biggest = list[i];
			biggest_idx = i;
		}
	}
}

template <typename T>
void FindSmallest(std::vector<T> list, T& smallest, int& smallest_idx)
{
	smallest = list[0];
	smallest_idx = 0;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i] < smallest)
		{
			smallest = list[i];
			smallest_idx = i;
		}
	}
}

template <typename T>
std::vector<T> SortForward(std::vector<T> list)
{
	std::vector<T> return_list;
	int list_size = list.size();
	for (int i = 0; i < list_size; i++)
	{
		int idx;
		T current_item;
		FindSmallest<T>(list, current_item, idx);
		return_list.push_back(list[idx]);
		list.erase(list.begin() + idx);
	}
	return return_list;
}

template <typename T>
std::vector<T> SortBackward(std::vector<T> list)
{
	std::vector<T> return_list;
	int list_size = list.size();
	for (int i = 0; i < list_size; i++)
	{
		int idx;
		T current_item;
		FindBiggest<T>(list, current_item, idx);
		return_list.push_back(list[idx]);
		list.erase(list.begin() + idx);
	}
	return return_list;
}

int main() 
{
	std::vector<int> int_list = { 10, 12, 20, 9, 55, 6, 1 };	
	std::vector<int> int_list_forward = SortForward<int>(int_list);
	std::vector<int> int_list_backward = SortBackward<int>(int_list);
	PrintList<int>(int_list);
	std::cout << std::endl;
	PrintList<int>(int_list_forward);
	std::cout << std::endl;
	PrintList<int>(int_list_backward);
	Sleep(20000);
	return 0;
}