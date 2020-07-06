#pragma once
#include<iostream>

template<class T>
class MyArray
{
public:
	
	MyArray(T data,int size) :MyArray(size)
	{
		Add(data);
	}
	MyArray(int size = 0);//main ctor
	
	MyArray(T* elements,int size)
	{
		AddRange(elements,size);
	}
	MyArray(MyArray& arr, int size)
	{
		AddRange(arr, size);
	}
	MyArray(const MyArray& other)//конст.копирования
	{
		operator =(other);
	}
	~MyArray()
	{
		delete []arr;
	}

	int at(int index);
	
	void Add(T element);
	
	void Remove(T element);

	void RemoveAt(int index);

	void AddRange(T* elements, int size);
	
	T front();

	T back();
	
	bool empty();

	void fill(int number);
	
	void fill(int min, int max);

	T* Find(T element);

	int FindFirst(T element);

	int RFindFirst(T element);

	void Show_array();

	int size()
	{
		return size_c;
	}

	int capacity()
	{
		return capacity_c;
	}

	MyArray& operator= (const MyArray<T>& other);

	int& operator [](int index)
	{
		return arr[index];
	}

	std::ostream& operator<< (std::ostream& out/*,const MyArray<T>& myArray2*/);//вывод всех эллементов

	bool operator==(const MyArray<T>& myArray2);

	bool operator!=(const MyArray<T>& myArray2);
		 
	bool operator<(const MyArray<T>& myArray2);
		 
	bool operator<=(const MyArray<T>& myArray2);
	
	bool operator>(const MyArray<T>& myArray2);
		 
	bool operator>=(const MyArray<T>& myArray2);

private:
	
	T* arr;
	int size_c;//колич. элементов
	int capacity_c;//колич. места для элементов

	void Create_array(int size);

	void Initialize_array();//дял заполнения пустого массива

	void Create_new_array(int& capacity, int& size);

	void Remove_ellement(int index);//часть методов Remove , RemoveAt
};

template<class T>
MyArray<T>::MyArray(int size)//main ctor
{
	this->size_c = 0;

	if (size > 3) //если пользователь ввёдёт обьем больше
	{
		this->capacity_c = size;//на 3 элемента больше
	}
	else if (size <= 3)//если меньше
	{
		this->capacity_c += 3;
	}

	Create_array(this->capacity_c);
	Initialize_array();
}

template<class T>
int MyArray<T>::at(int index)
{
	if (size_c > index)
	{
		return arr[index];
	}
	else
	{
		throw std::exception("no such element");
	}
}

template<class T>
void MyArray<T>::Add(T element)
{
	int i = 0;
	for (; i < capacity_c; i++)
	{
		if (arr[i] == 0)
		{
			arr[i] = element;
			size_c++;
			return;
		}
	}
	if (i >= capacity_c)
	{
		Create_new_array(capacity_c, size_c);
		arr[i] = element;
	}
}

template<class T>
void MyArray<T>::Remove(T element)
{
	for (int i = 0; i < capacity_c; i++)
	{
		if (arr[i] == element)
		{
			Remove_ellement(i);
			break;
		}
	}
}

template<class T>
void MyArray<T>::RemoveAt(int index)
{
	if (index > size_c)
	{
		throw std::exception("out of range!");
	}
	for (int i = 0; i < capacity_c; i++)
	{
		if (i == index)
		{
			Remove_ellement(i);
			break;
		}
	}
}

template<class T>
void MyArray<T>::Remove_ellement(int i)//часть метода RemoveAt ,Remove
{
	size_c--;
	capacity_c--;

	T* Tptr = arr;
	arr = new T[capacity_c];
	
	for (int j = i; j < capacity_c; j++) //Двигаемся слева направо с заданной позиции
	{
		Tptr[j] = Tptr[j+1];//Сдвигаем элементы,чтоб удаленый переместить в конец
	}

	for (int j = 0; j < capacity_c; j++)//присвоение
	{
		if (j < size_c)
		{
			arr[j] = Tptr[j];
		}
		else if (j >= size_c)
		{
			arr[j] = 0;
		}
	}

	delete[]Tptr;
}


template<class T>
void MyArray<T>::AddRange(T* elements,int size)
{
	int numb_el = size;//узнаём кол. элементов в массиве,который передали
	int size_temp = size_c;//нужна для цикла ниже,хранение старого количества элементов
	int free_sweep = 0;//количество свободного пространства

	for (int i = 0; i < capacity_c; i++)//подсчёт свободного пространства в коллекции
	{
		if (arr[i] == 0)
		{
			free_sweep++;
		}
	}  

	if (free_sweep >= numb_el)//если хвататет свободного места,для добавлении коллекции
	{
		for (int i = 0, j = 0; i < capacity_c; i++)
		{
			if (arr[i] == 0)
			{
				arr[i] = elements[j];
				j++;	
				size_c++;
			}
		}
	}
	else
	{
		capacity_c += numb_el + 3;
		size_c += numb_el;
		
		T* Tptr = arr;
		arr = new T[capacity_c];

		for (int j = 0; j < capacity_c; j++)//присвоение
		{
			if (j < size_temp)
			{
				arr[j] = Tptr[j];
			}
			else if (j >= size_temp && j < size_c)
			{
				arr[j] = elements[j - size_temp];
			}
			else if (j >= size_c)
			{
				arr[j] = 0;
			}
		}
		delete[]Tptr;
	}
}

template<class T>
T MyArray<T>::front()
{
	capacity_c--;

	T* Tptr = arr;
	arr = new T[capacity_c];

	T temp = T();

	for (int j = 0; j < size_c; j++) //Двигаемся слева направо с заданной позиции
	{
		Tptr[j] = Tptr[j + 1]; //Сдвигаем элементы,чтоб удаленый переместить в конец
		temp = Tptr[j];
	}
	for (int j = 0; j < capacity_c; j++)//присвоение
	{
		arr[j] = Tptr[j];
	}
	
	size_c--;

	delete[]Tptr;

	return temp;
}

template<class T>
T MyArray<T>::back()
{
	capacity_c--;

	T* Tptr = arr;
	arr = new T[capacity_c];

	T temp = T();

	for (int j = 0; j < capacity_c; j++)//присвоение
	{
		arr[j] = Tptr[j];
	}
	size_c--;

	delete[]Tptr;

	return temp;
}

template<class T>
bool MyArray<T>::empty()
{
	int counter = 0;

	if (size_c > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
void MyArray<T>::fill(int number)
{
	for (int i = 0; i < size_c; i++)
	{
		arr[i] = number;
	}
}

template<class T>
void MyArray<T>::fill(int min, int max)
{
	for (int i = 0; i < size_c; i++)
	{
		arr[i] = min + rand() % max;
	}
}

template<class T>
T* MyArray<T>::Find(T element)
{
	T* tArray = new T[size_c];
	
	bool obj_ab = false;//чтоб узнать,есть ли такое же число в коллекции

	for (int i = 0, j = 0; i < size_c; i++)
	{
		if (arr[i] == element)
		{
			tArray[j] == arr[i];
			j++;
			obj_ab = true;
		}
	}
	if (obj_ab == true)
	{
		return tArray;
	}
	else if (obj_ab == false)
	{
		throw std::exception("no such element");
	}
}

template<class T>
int MyArray<T>::FindFirst(T element)
{
	for (int i = 0; i < size_c; i++)
	{
		if (arr[i] == element)
		{
			return i;
		}
	}
}

template<class T>
int MyArray<T>::RFindFirst(T element)
{
	for (int i = size_c - 1; i >= 0; i--)
	{
		if (arr[i] == element)
		{
			return i;
		}
	}
}

template<class T>
void MyArray<T>::Show_array()
{
	for (int i = 0; i < size_c; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template<class T>
void MyArray<T>::Create_array(int size)
{
	arr = new T[size];//создаём
}

template<class T>
void MyArray<T>::Initialize_array()//для заполнения пустого массива
{
	for (int i = 0; i < capacity_c; i++)//инициализируем
	{
		arr[i] = 0;
	}
}

template<class T>
void MyArray<T>::Create_new_array(int& capacity, int& size)
{
	T* Tptr = arr;
	arr = new T[capacity + 3];

	capacity_c = capacity + 3;

	for (int j = 0; j < capacity_c; j++)//присвоение
	{
		if (j < size)
		{
			arr[j] = Tptr[j];
		}
		else if (j >= size)
		{
			arr[j] = 0;
		}

	}
	size++;
	delete[]Tptr;
}

template<class T>
MyArray<T>& MyArray<T>:: operator= (const MyArray<T>& other)
{
	this->size_c = other.size_c;
	this->capacity_c = other.capacity_c;

	Create_array(capacity_c);//записываем в указатель новый адрес

	for (int i = 0; i < other.capacity_c; i++)//инициализ.
	{
		if (i < other.size_c)
		{
			this->arr[i] = other.arr[i];
		}
		else if (i >= other.size_c)//инициализируем пустые эл.
		{
			this->arr[i] = 0;
		}
	}
	return *this;
}

template<class T>
std::ostream& MyArray<T>::operator<< (std::ostream& out/*, const MyArray<T>& myArray2*/)
{
	for (int i = 0; i < size_c; i++)
	{
		out << arr[i] << " ";
	}
	return out;
}

template<class T>
bool MyArray<T>::operator==(const MyArray<T>& myArray2)
{
	return this->size_c == myArray2.size_c;
}

template<class T>
bool MyArray<T>::operator!=(const MyArray<T>& myArray2)
{
	return this->size_c != myArray2.size_c;
}

template<class T>
bool MyArray<T>::operator<(const MyArray<T>& myArray2)
{
	return this->size_c < myArray2.size_c;
}

template<class T>
bool MyArray<T>::operator<=(const MyArray<T>& myArray2)
{
	return this->size_c <= myArray2.size_c;
}

template<class T>
bool MyArray<T>::operator>(const MyArray<T>& myArray2)
{
	return this->size_c > myArray2.size_c;
}

template<class T>
bool MyArray<T>::operator>=(const MyArray<T>& myArray2)
{
	return this->size_c >= myArray2.size_c;
}


