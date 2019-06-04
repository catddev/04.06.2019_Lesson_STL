#include<iostream>
#include<vector>
using namespace std;

int main() {

	vector<int> v1(10);//10 els, emptys will be nulls
	v1.push_back(4);
	v1.push_back(8);
	v1.pop_back();
	v1.insert(v1.begin()+1, 7);//begin() return ptr to the beginning of the vector
	v1.insert(v1.end() - 3, 10);//minus 3 pos from the end
	vector<int>::iterator it;

	for (it = v1.begin(); it != v1.end(); it++)
		cout << *it << endl;// * для вывода значения под итератором (указателем) it

	//library STL has ready classes for:
	//Containers(vector, list, set, map, deque; ADT abstract data types - stack, queue),
	//Iterators (связывают контейнеры с алгоритмами, иными словами это указатели для обращения к элементам контейнеров). Functors - их объекты можно исп как функции
	//Algorithms (сортировка, поиск и тд)


	system("pause");
	return 0;
}