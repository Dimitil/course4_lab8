#include <iostream>
#include <vector>
#include <list>
#include "MyString.h"
#include <deque>
#include "Point.h"
#include <typeinfo>

#define	  stop __asm nop

typedef std::vector<double> VectorDouble;

template <typename T>
void printConteiner(const T& cont)
{
	std::cout << typeid(cont).name() <<" :\n";
	for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it)
	{
		std::cout << *it << ' ';
	}
	std::cout << '\n';
}

template<> void printConteiner(const std::vector<Point*> &vptrPoint)
{
	for (std::vector<Point*>::const_iterator it = vptrPoint.begin(); it !=vptrPoint.end(); ++it)
	{
		std::cout << **it << " ";
	}
	std::cout << '\n';
}
template <typename T>
void vecPrintInfo(const std::vector <T>& v)
{
	std::cout << "size     = " << v.size() << '\n';
	std::cout << "capacity = " << v.capacity() << '\n';
	std::cout << "max_size = " << v.max_size() << '\n';

	printConteiner(v);
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v)
{
	
	for (int i = 0; i < v.size(); i++)
	{
		//std::cout.width(3); 
		//std::cout.adjustfield(3);
		std::cout << v[i] <<' ';
	}
	std::cout << '\n';
	return out;
}

template <typename T>
void desequence(std::vector <T>& v) //убивать кучей дубли
{
	if (v.size() < 2)	{ return; }
	typename std::vector<T>::const_iterator it1 = v.begin();
	while (it1 != v.end() )
	{
		typename std::vector<T>::const_iterator it2 = it1 + 1;
		while ((it2 != v.end()) && (*it1 == *it2))
		{
			++it2;
		}
		++it1;
		if (it2 != (it1))
		{
			it1 = v.erase(it1, it2);
		}
	}
}

template <typename T>
void myMakeUnique(std::vector <T>& v)
{
	for (typename std::vector<T>::const_iterator it1 = v.begin(); it1 != v.end() - 1; it1++)
	{
		typename std::vector<T>::const_iterator it2 = it1 + 1;
		while (it2 != v.end())
		{
			if (*it1 == *it2)
			{
				it2 = v.erase(it2);
				continue;
			}
			it2++;
		}
	}
}

bool pointIsNegative(const Point& p) { return (p.getX() < 0) || (p.getY() < 0); }

int main()
{
	std::cout << "\nTask 0.0\n";
	// Контейнер стандартной библиотеки vector 

//////////////////////////////////////////////////////////////////////
	//Создание векторов. 

	//Создайте следующие вектора:
	//---------------------------
	//пустой вектор целых чисел - vInt и проверьте с помощью функции size(),
	//что его размер нулевой. 
	
	std::vector <int> vint;
	std::cout << vint.size() << '\n';






	std::cout << "\nTask 0.1\n";
	//Раскомментируйте следующий фрагмент, подумайте - все ли корректно
	//Если есть некорректности, - исправьте

	//vint.front()=1; //cannot read empty vector

	
	vint.resize(1);
	vint.front() = 1;
	std::cout<<vint.front();






	std::cout << "\nTask 0.2\n";
	//С помощью функции push_back() в цикле заполните вектор какими-либо значениями.
	//На каждой итерации цикла следите за размером вектора с помощью методов
	//size(), capacity(), max_size() и выводите значения элементов. 
	//
	//Подсказка: так как такая проверка понадобится Вам и в следующих заданиях,
	//напишите шаблон функции, которая для вектора, содержащего элементы любого типа
	//выводит его "реквизиты" и значения элементов на консоль.

	

	for (int i = 1; i < 10; i++)
	{
		vint.push_back(i * 11);
	}
	vecPrintInfo(vint);





	std::cout << "\nTask 0.3\n";
	//вектор вещественных - vDouble1 с заданным Вами начальным размером  и
	//проверьте результат с помощью созданного Вами шаблона. Как будут
	//проинициализированы элементы вектора?

	VectorDouble vDouble1(5);
	vecPrintInfo(vDouble1);//элементы проинициализированы дефолт-конструктором






	std::cout << "\nTask 0.4\n";
	//вектор объектов типа MyString с начальным размером - 5 элементов
	//и инициализацией каждого элемента строкой "A"
	//C помощью функции at() а также с помощью оператора
	//индексирования []  измените значения каких-либо элементов.
	//Попробуйте "выйти" за границы вектора с помощью at() и
	//с помощью []. 

	std::vector<MyString> MyStrVec(5, "A");
	MyStrVec[3] = "B";
	MyStrVec.at(2) = "C";
	std::cout << MyStrVec[3] << '\n';
	std::cout << MyStrVec[2] << '\n';
	//  std::cout << MyStrVec[30]; //ничего не произошло
  //    std::cout << MyStrVec.at(30);//std::out_of_range






	std::cout << "\nTask 0.5\n";
	//вектор вещественных - vDouble3, который является копией элементов
	// [0,5) массива вещественных чисел dMas. Предворительно массив dMas 
	//нужно создать и проинициализировать!
	double dMas[10];
	for (int i = 1; i < 10; i++)
	{
		dMas[i] = static_cast<double>(i) / 10.0;
	}

	VectorDouble vDouble3(dMas, dMas + sizeof(dMas) / sizeof(double));






	std::cout << "\nTask 0.6\n";
	//вектор вещественных - vDouble4, который является копией элементов
	// [2,5) вектора vDouble3. 
	VectorDouble vDouble4(vDouble3.begin() + 1, vDouble3.begin() + 4);
	vecPrintInfo(vDouble4);






	std::cout << "\nTask 0.7\n";
	//вектор элементов типа Point - vPoint1 а) с начальным размером 3. Какой конструктор
	//будет вызван для каждого элемента?
	std::vector<Point> vPoint1(3); //будет вызван дефолт-конструктор
									//для каждого элемента
	//b) vPoint2 с начальным размером 5 и проинициализируйте каждый элемент координатами (1,1).
	std::vector<Point> vPoint2(5, Point(1, 1));// конструктор был вызван только 
												// один раз
    vecPrintInfo(vPoint2);





	std::cout << "\nTask 0.8\n";
	//вектор указателей на Point - vpPoint с начальным размером 5
	//Подумайте: как корректно заставить эти указатели "указывать" на объекты Point
	{

		//Подсказка: для вывода на печать значений скорее всего Вам понадобится
			//а) специализация Вашей шаблонной функции
			//б) или перегрузка operator<< для Point*

	}//Какие дополнительные действия нужно предпринять для такого вектора?
	std::vector<Point*> vpPoint(5);								

	for (int i = 0; i < vpPoint.size(); i++)
	{
		vpPoint[i] = new Point(3, 4);
	}

	printConteiner(vpPoint); //специализация шаблонной функции

	for (int i = 0; i < vpPoint.size(); i++)
	{
		delete vpPoint[i];
		vpPoint[i] = nullptr;
	}

	




	///////////////////////////////////////////////////////////////////////
	//Резервирование памяти.
	//Подумайте, всегда ли верны приведенные ниже проверки?
	/*
	{
	size_t n=...
	vector<int> v(n);
	v.resize(n/2);
	if(v.capacity() == n) //true?		
	}
	*/
			/*
	{
	int n=...
	size_t m=...
	vector<int> v(n);
	v.reserve(m);
	if(v.capacity() == m) //true?            
	}
	*/
	/*
	{
	vector<int> v(3,5);
	v.resize(4,10); //значения?		4 элемента со значениями 10
	v.resize(5); //значения?		5 элементов со значением 0
		
	}
	*/






	std::cout << "\nTask 0.9\n";
	//Создайте два "пустых" вектора с элементами
	//любого (но одного и того же типа) типа. 
	//В первом векторе зарезервируйте память под 5 элементов, а потом заполните
	//его значениями с помощью push_back.
	//Второй вектор просто заполните значениями посредством push_back.
	//
	//Сравните размер, емкость векторов и значения элементов

	std::vector<int> v1;
	std::vector<int> v2;

	v1.reserve(5);
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i * i);
		v2.push_back(i * i);
	}

	std::cout << "v1 :\n";
	vecPrintInfo(v1);
	std::cout << "v2 :\n";
	vecPrintInfo(v2);       //емкость векторов разная в первом сколько 
							//сделали резерв столько и осталась






	std::cout << "\nTask 0.10\n";
	//!!! shrink_to_fit - Уменьшение емкости вектора.
	//Для любого вектора из предыдущего задания требуется уменьшить емкость
	//до size.
	v2.shrink_to_fit();






	std::cout << "\nTask 0.11\n";
	//Создание "двухмерного вектора" - вектора векторов
	//Задан одномерный массив int ar[] = {11,2,4,3,5};
	//Создайте вектор векторов следующим образом:
	//вектор vv[0] - содержит 11 элементов со значением 11
	//vv[1] - содержит 2,2
	//vv[2] - содержит 4,4,4,4
	//...
	//Распечатайте содержимое такого двухмерного вектора по строкам

	int ar[] = {11, 2, 4, 3, 5};
	int numCount = sizeof(ar) / sizeof(int);

	std::vector<std::vector<int>> vv(numCount);;

	for (int i = 0; i < numCount; i++)
	{
		for (int j = 0; j < ar[i]; j++)
		{
			vv[i].push_back(ar[i]);
		}
	}

	std::cout << vv;	
	//    for (int i = 0; i<vv.size(); i++)
	//    {
	//        for( int j = 0; j<vv[i].size(); j++)
	//        {
	//            std::cout << vv[i][j] << ' ';
	//        }
	//        std::cout << '\n';
	//    }





	std::cout << "\nTask 0.12\n";
	//Вставка элемента последовательности insert().
	//В вектор vChar2 вставьте в начало вектора символ только при
	//условии, что в векторе такого еще нет.
	std::vector<char> vChar1;
	vChar1.push_back('a');
	vChar1.push_back('d');
	vChar1.push_back('s');
	vChar1.push_back('g');

	bool charFound = 0;
	char ch = 'w';
	for (std::vector<char>::const_iterator it = vChar1.begin(); it != vChar1.end(); it++)
	{
		if (*it == ch)
		{
			charFound = true;
		}
	}
	if (!charFound)
	{
		vChar1.insert(vChar1.begin(), ch);
	}
	vecPrintInfo(vChar1);






	std::cout << "\nTask 0.13\n";
	//Вставьте перед каждым элементом вектора vChar2 букву 'W'
	size_t vChar1Size = vChar1.size();

	std::vector<char>::const_iterator iter = vChar1.begin();
	for (; iter != vChar1.end(); ++iter)
	{
		iter = vChar1.insert(iter, 'W');
		++iter;
	}
	vecPrintInfo(vChar1);
	
	




	///////////////////////////////////////////////////////////////////
	std::cout << "\nTask 0.14\n";
	//Напишите функцию, которая должна удалять только повторяющиеся последовательности.
	//Например: было - "qwerrrrty12222r3", стало - "qwety1r3

	std::vector<char> vChar2 = { 'q','q','q','q','w','w','w','e','e','e',
		'r','r','t','t','y','y','q','1','1','2','2','2','3','3' };
	desequence(vChar2);
	vecPrintInfo(vChar2);






	
	///////////////////////////////////////////////////////////////////
	std::cout << "\nTask 0.15\n";
	//Удаление элемента последовательности erase()
	//Напишите функцию удаления из любого вектора всех дублей 

	myMakeUnique(vChar2);
	vecPrintInfo(vChar2);






	///////////////////////////////////////////////////////////////////
	std::cout << "\nTask 0.16\n";
	//Создайте новый вектор таким образом, чтобы его элементы стали
	//копиями элементов любого из созданных ранее векторов, но расположены
	//были бы в обратном порядке
	std::vector<char> vChar3(vChar2.rbegin(), vChar2.rend());
	vecPrintInfo(vChar3);





	///////////////////////////////////////////////////////////////////
	std::cout << "\nTask 1.0\n";
	//Задание 1. Списки. Операции, характерные для списков.
	//Создайте пустой список из элементов Point - ptList1 и наполните
	//его значениями с помощью методов push_back(),
	//push_front, insert()

	std::list <Point> ptList1;
	ptList1.push_back(Point(2, 3));
	ptList1.push_back(Point(2, 4));
	ptList1.push_back(Point(-3, 10));
	ptList1.push_back(Point(-14, 32));
	ptList1.push_back(Point(-13, -22));

	ptList1.push_front(Point(4, 2));
	ptList1.push_front(Point(5, 1));

	std::list<Point>::const_iterator it = ptList1.begin();
	ptList1.insert(it++, Point(5, 2));
	ptList1.insert(++it, Point(1, 6));
	ptList1.insert(ptList1.begin(), Point(3, 0));


	printConteiner(ptList1);




	std::cout << "\nTask 1.1\n";
	//Напишите шаблон функции, которая будет выводить элементы
	//ЛЮБОГО КОНТЕЙНЕРА на печать. Проверьте работу шаблона на контейнерах
	//vector и list. Подсказка - хотелось бы увидеть тип контейнера.





	std::cout << "\nTask 1.2\n";
	//Сделайте любой из списков "реверсивным" - reverse()
	ptList1.reverse();




	std::cout << "\nTask 1.2\n";
	//Создайте список ptList2 из элементов Point таким образом, чтобы он стал 
	//копией вектора элементов типа Point, но значения элементов списка располагались
	//бы в обратном порядке 
	std::vector<Point> vecPoint;
	for (int i = 0; i < 5; i++)
	{
		vecPoint.push_back(Point(i + 3, i * 3));
	}
	std::list<Point> ptList2(vecPoint.rbegin(), vecPoint.rend());
	




	std::cout << "\nTask 1.3\n";
	//Отсортируйте списки  ptList1 и ptList2 - методом класса list - sort()
	//по возрастанию.
	//Подумайте: что должно быть перегружено в классе Point для того, чтобы
	//работала сортировка
	ptList1.sort();
	ptList2.sort();
	printConteiner(ptList1);
	printConteiner(ptList2);






	std::cout << "\nTask 1.4\n";
	//Объедините отсортированные списки - merge(). Посмотрите: что
	//при этом происходит с каждым списком.
	ptList1.merge(ptList2); //ptList2 - обнулился, ptList1 - отсортирован.
    printConteiner(ptList1);
    printConteiner(ptList2);




	
	std::cout << "\nTask 1.5\n";
	//Исключение элемента из списка - remove()
	//Исключите из списка элемент с определенным значением.
	//Подумайте: что должно быть перегружено в классе Point?
	ptList1.remove(Point(-3, 10));
	printConteiner(ptList1);




	std::cout << "\nTask 1.6\n";
	//Исключение элемента из списка, удовлетворяющего заданному условию:
	//любая из координат отрицательна - remove_if(). 
	ptList1.remove_if(pointIsNegative);
	printConteiner(ptList1);


	


	std::cout << "\nTask 1.7\n";
	//Исключение из списка подряд расположенных дублей - unique(). 
	ptList1.unique();
	printConteiner(ptList1);
	



	std::cout << "\nTask 2\n";
	///////////////////////////////////////////////////////////////////
	//Задание 2.Очередь с двумя концами - контейнер deque

	//Создайте пустой deque с элементами типа Point. С помощью
	//assign заполните deque копиями элементов вектора. С помощью
	//разработанного Вами в предыдущем задании универсального шаблона
	//выведите значения элементов на печать
	std::deque <Point> deqPoint;
	deqPoint.assign(vecPoint.begin(), vecPoint.end());
	printConteiner(deqPoint);




	std::cout << "\nTask 2.1\n";
	//Создайте deque с элементами типа MyString. Заполните его значениями
	//с помощью push_back(), push_front(), insert()
	//С помощью erase удалите из deque все элементы, в которых строчки
	//начинаются с 'A' или 'a'
	std::deque <MyString> myStrDeq;
	myStrDeq.push_back("Aaaff");
	myStrDeq.push_front("aav");
	myStrDeq.insert(myStrDeq.begin() + 2, "DFad");
	printConteiner(myStrDeq);

	for (std::deque<MyString>::const_iterator it = myStrDeq.begin(); it != myStrDeq.end(); )
	{
		if ((it->GetString())[0] == 'A' || (it->GetString())[0] == 'a')
		{
			it = myStrDeq.erase(it);
		}
		else
		{
			++it;
		}
	}
	printConteiner(myStrDeq);
	return 0;
}
