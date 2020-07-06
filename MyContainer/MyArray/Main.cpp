#include "MyArray.h"
#include<ctime>//для rand()
#include<vector>

int main()
{
	srand(time(NULL));//для rand()

	MyArray<int> mass(3);
	
	mass.Add(25);
	mass.Add(23);
	mass.Add(29);
	mass.Add(32); /*mass.Add(32); mass.Add(32); mass.Add(32); mass.Add(31); mass.Add(32); mass.Add(33); mass.Add(49)*/;
	mass.Show_array();

	//                                         at(int index)
	//std::cout << mass.at(0) <<"\n";
	//std::cout << mass.at(1) << "\n";
	//std::cout << mass.at(2) << "\n";

	//                                         Remove(T element)
	//mass.Remove(23);//не так,плохо заполняет
	//mass.Show_array();

	//                                         RemoveAt(int index)
	//mass.RemoveAt(2);
	//mass.Show_array();

	//                                         operator[]
	//std::cout << mass[0];


	//                                         AddRange(T * elements)
	//int size = 25;
	//int* element = new int[size];
	//
	//for (int i = 0; i < size; i++)
	//{
	//	element[i] = 1 + rand() % 25;
	//	std::cout << element[i]<< " ";
	//}
	//std::cout << std::endl;
	//
	//mass.AddRange(element, size);
	//delete[]element;
	//mass.Show_array();

	//                                         T front   
	//mass.front();							   
	//mass.Show_array();					   
											   
	//                                         T back   
	//mass.back();
	//mass.Show_array();
	
	//                                         bool empty
	//std::cout << mass.empty()<<std::endl;

	//                                         int size
	//std::cout << mass.size()<<std::endl;

	//                                         fill(int number)
	//mass.fill(25);
	//mass.Show_array();

	//                                         fill(int min, int max)

	//mass.fill(25,150);
	//mass.Show_array();
	//                                         int* Find(T element)

	//int *tmass = mass.Find(32);
	//delete[]tmass;
	//                                         int FindFirst(T element)

	//std::cout << mass.RFindFirst(25) << std::endl;
	//                                         int RFindFirst(T element)
	//std::cout << mass.RFindFirst(23) << std::endl;
	
	//                                         operator <<
	                                      
	//std::cout << mass;//
	//                                         operator = (MyArray)
	
	//MyArray<int> tmp(4);
	//tmp = mass;
	//tmp.Show_array();
	//                                         MyArray(T * elements)

	//int size = 5;
	//int* Pmass = new int[size];
	//
	//for (int i = 0; i < size; i++)
	//{
	//	Pmass[i] = rand();
	//}
	//
	//MyArray<int> tmp2(Pmass, size);
	//
	//tmp2.Show_array();
	//
	//delete[]Pmass;
	//                                         MyArray(MyArray & arr)

	//int size = 5;
	//int* Pmass = new int[size];
	//
	//for (int i = 0; i < size; i++)
	//{
	//	Pmass[i] = rand();
	//}
	//
	//MyArray<int> tmp2(Pmass, size);
	//
	//tmp2.Show_array();
	//
	//delete[]Pmass;

	//                                         operator==
	//MyArray<int> tmp3(4);
	//if (tmp3 == mass)
	//{
	//	std::cout <<"==" << std::endl;
	//}
	//else
	//{
	//	std::cout <<"!="<<std::endl;
	//}
	//
	//
	////                                         operator!=
	//MyArray<int> tmp4(4);
	//if (tmp4 == mass)
	//{
	//	std::cout << "==" << std::endl;
	//}
	//else
	//{
	//	std::cout << "!=" << std::endl;
	//}
			
	//                                         operator<
	//MyArray<int> tmp5(4);
	//MyArray<int> tmp6(4);
	//
	//if (tmp5 != tmp6)
	//{
	//	std::cout << "!=" << std::endl;
	//}
	//else
	//{
	//	std::cout << "==" << std::endl;
	//}
	//		
	////                                         operator<=
	//MyArray<int> tmp12(4);
	//if (tmp12 <= mass)
	//{
	//	std::cout << "<=" << std::endl;
	//}
	//else
	//{
	//	std::cout << ">=" << std::endl;
	//}
	//		
	////                                         operator>
    //MyArray<int> tmp7(4);
    //if (tmp7 > mass)
    //{
    //	std::cout << ">" << std::endl;
    //}
    //else
    //{
    //	std::cout << "<" << std::endl;
    //}
    //		
    ////                                         operator>=
    //MyArray<int> tmp8(4);
    //if (tmp8 >= mass)
    //{
    //	std::cout << ">=" << std::endl;
    //}
    //else
    //{
    //	std::cout << "<=" << std::endl;
    //}
}
