#include <iostream>
using namespace std;


class MyArray
{
public:
	MyArray();
	int size = 4;
	int& operator [] (int i)
	{
		if (i > size)
		{
			resize(i);
		}
		return elements[i];
	}
	void print()
	{
		for (int l = 0; l < size; l++)
		{
			cout << elements[l];
		}
	}
private:
	void resize(int i)
	{
		int* the_new_array = new int[i + 1]();
		for (int k = 0; k < size; k++)
		{
			the_new_array[k] = elements[k];
		}
		size = i + 1;
		elements = the_new_array;
	}
	int* elements;

};
int main()
{
	MyArray a;
	for (int i = 0; i < 5; i++)
	{
		a[i] = 0;
	}
	a[5] = 16;
	a.print();
}
MyArray::MyArray()
{
	elements = new int[size]();
}