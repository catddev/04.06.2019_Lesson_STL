#include<vector>
#include<list>
#include<algorithm>
#include<iterator>
#include<fstream>
#include"Train.h"
#include"Ticket.h"
#include"Filter.h"
#include"Sort_by.h"
using namespace std;

bool asc(train t1, train t2) {
	return(t1.getNumber() < t2.getNumber());
}

int main() {

	//vector<int> v1(10);//10 els, emptys will be nulls
	//v1.push_back(4);
	//v1.push_back(8);
	//v1.pop_back();
	//v1.insert(v1.begin()+1, 7);//begin() return ptr to the beginning of the vector
	//v1.insert(v1.end() - 3, 10);//minus 3 pos from the end
	//v1.insert(v1.begin(), 500);
	//vector<int>::iterator it;

	////#include<algorithm>
	//replace(v1.begin() + 5, v1.begin() + 8, 0, 1000); //replace 0 to 1000 on positions from 5 till 8
	//*find(v1.begin(), v1.end(), 10) = 2000; //find - returns ptr to el, *find - its value

	////vector<int>::iterator it = find(v1.begin(), v1.end(), 300);
	////if (it != v1.end())//если нашел элемент=300, т.е если не дошел до конца
	////	*it = 3000;

	////to find and replace not only one but all such elements we use cycle
	//it = v1.begin();
	//while (it != v1.end()) {
	//	it = find(it++, v1.end(), 0);
	//	if (it != v1.end())
	//		*it = 4000;
	//}

	//int number;
	//cin >> number;

	//v1.erase(v1.begin());
	//v1.erase(v1.begin(), v1.begin()+5);//2 arguments
	//
	//for_each(v1.begin(), v1.end(), [number](int a) {
	//	if(a==number)
	//	cout << a << endl; });//с начала до конца примени лямбда функцию// int a - псевдоним для каждого элемента, соответсвующего типа
	//cout << endl;

	//v1.erase(remove_if(v1.begin(), v1.end(),
	//	//лямбда функция [ {condition} ] определяет по какому условию будет удалять элементы
	//	[number](int a) {
	//	return (number == a);
	//}
	//)/*first arg of erase()*/, v1.end());/*second arg of erase()*/

	//cout << "The vector without " << number << endl;
	//for_each(v1.begin(), v1.end(), [](int a) { cout << a << endl; });//print all, применяет лямбда функцию к каждому элементу вектора

	//for (it = v1.begin(); it != v1.end(); it++)
	//	cout << *it << endl;// * для вывода значения под итератором (указателем) it

	//library STL has ready classes for:
	//Containers(vector, list, set, map, deque; ADT abstract data types - stack, queue),
	//Iterators (связывают контейнеры с алгоритмами, иными словами это указатели для обращения к элементам контейнеров). Functors - их объекты можно исп как функции
	//Algorithms (сортировка, поиск и тд)

	//with list
	
	ifstream in_file("in2.txt");
	//vector<train> ts;
	list<ticket> ts;
	int n;
	string str1, str2;
	string feature;

	if (!in_file)
		cerr << "file open error" << endl;
	else {
		while (in_file >> n >> str1 >> str2) {//пока идет считывание
			ts.push_back(ticket(n, str1, str2));
		}
	}
	
	cout << "Enter feature to sort by: flight, departure, passenger" << endl;
	cin >> feature;
	ts.sort(SortBy2(feature)); //in the LIST SortBy is the inner method
	for_each(ts.begin(), ts.end(), [](ticket t) {cout << t << endl << endl; });
	
	ticket t;
	cout << "Enter the needed date" << endl;
	cin >> str1;
	t.getDeparture() = str1;
	for_each(ts.begin(), ts.end(), filter2("departure", t));
	cout << endl;

	cout << "Enter ticket to delete" << endl;
	ticket t2;
	cin >> t2;
	//cin >> n >> str1 >> str2;
	//ticket t2(n, str1, str2);
	ts.erase(remove_if(ts.begin(), ts.end(),
		[t2](ticket a) {
		return (t2 == a);
	}
	), ts.end());
	for_each(ts.begin(), ts.end(), [](ticket t) {cout << t << endl << endl; });



	////with vector

	//ifstream in_file("in.txt");
	//vector<train> ts;
	//int n;
	//string str1, str2;
	//string feature;

	//if (!in_file)
	//	cerr << "file open error" << endl;
	//else {
	//	while (in_file >> n >> str1 >> str2) {//пока идет считывание
	//		ts.push_back(train(n, str2, str1));
	//	}
	//}

	////sort by number
	//sort(ts.begin(), ts.end(), asc);//our own predicator asc

	//cin >> feature;
	////outer method SortBy
	//sort(ts.begin(), ts.end(), SortBy(feature));//functor SortBy, класс при вызове круглых скобок становится функтором
	//for_each(ts.begin(), ts.end(), [](train t){cout << t << endl;});


	////for_each(ts.begin(), ts.end(), [](train t) {cout << t << endl; });

	////or with filter!
	//
	//cout << "Enter \"number\" to search by number" << endl;
	//cout << "Enter \"dep_time\" to search by departure time" << endl;
	//cout << "Enter \"destination\" to search by destination" << endl;
	//cin >> feature;
	//train t;

	//
	//if (feature == "number") {
	//	cin >> n;
	//	t.getNumber() = n;
	//}
	//else if (feature == "dep_time") {
	//	cin >> str1;
	//	t.getDepartureTime() = str1;
	//}
	//else if (feature == "destination") {
	//	cin >> str2;
	//	t.getDestination() = str2;
	//}


	////filter is a FUNCTOR
	//for_each(ts.begin(), ts.end(), filter(feature, t));//here using operator()!!!
	////filter compares this train t to vector's objects and implements own condition
	////predicator is a functor that returns bool. Usually functors return void


	system("pause");
	return 0;
}