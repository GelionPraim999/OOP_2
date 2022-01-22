#include <iostream>
#include <Windows.h>

using namespace std;
using std::cin;
using std::cout;
using std::endl;
 
int StringLength(const char* str);


 class String
 {
	int size; // Размер строки
	char* str; // Указатель на строку в динамической памяти 
public:
	explicit String(int size = 80)	
	{
		//Благодаря принимаемому парраметру size мы можем создавать строки заданного размера
		this->size = size;		
		this->str = new char [size] {};
		cout << "DefaultConst :\t" << this << endl;
      }
	String(const char* str)
	{
		// cout << sizeof(str) << endl;
		this->size = StringLength(str) + 1; // Сохраняем размер строки в байтах, с учетом терминирующего нуля
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)
	{ // Глубокое копирование ( Deep Copy)
		this->size = other.size;
		this->str = new char [size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConsructor: " << this << endl;
		
	}
	~String()
	{
		delete[] this->str; // Если конструктор выделяект память при помощи оператора new, 
		// то деструктор обязательно  должен освобождать эту память	операатором delete[]
		// в противном случае будет возникать утечка памяти.
		cout << "Destructor : \t" << this << endl;
	}
	//                        OPERATORS
	String& operator=(const String& other)
	{ 
		if (this == &other) return *this;
		int a = 2;
		int b = 3;
		a = b;
		delete[] this->str;
		
		// Глубокое копирование ( Deep Copy)

		this->size = other.size;
		this->str = new char [size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t " << this << endl;
		return *this;
	}
	void print() const
	{
		cout << "Size :\t" << size << endl;
		cout << "Str :\t" << str << endl;

	}
};
//#define NULL_TERMINATED_LINE
 
//#define BASE_CHECK
void main()
{
SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#ifdef NULL_TERMINATED_LINE
	'\0';
	

	const int SIZE = 50;
	char str[SIZE] = {};
	cout << "Введите строку : ";
	cin.getline(str, SIZE);

	 
	cout << str << endl;
#endif // NULL_TERMINATED_LINE



#ifdef BASE_CHECK
	String str1;
	str1.print();

	//String str2 = 25; // Преобразование  int в string запрещенно при помощи explicit
	String str2(25);// explicit конструктор можно вызвать только так
	str2.print();

	cout << sizeof("Hello") << endl;
	cout << "StringLength:" << StringLength("Hello") << endl;


	String str3 = "Hello";
	str3.print();

	str3 = str3;

	String str4 = str3; // Copy constructor
	str4.print();

	String str5;
	str5 = str4; // copy assignment
	str5.print();
#endif // BASE_CHECK
	cout << sizeof("Hello") << endl;
	cout << "StringLength:" << StringLength("Hello") << endl;
	String str1 = "Hello";
	str1.print();
	cout << sizeof("World") << endl;
	cout << "StringLength:" << StringLength("World") << endl;
	String str2 = "World";
	str2.print();
	

	cout << "==============/Д.З//HelloWorld====================\n";
	string a("Hello");
	string b("World");
	cout << a + b << "\n";
	 a,b += " --- Мы объединили  \n";
	cout << a << b << endl;
	

 }
int StringLength(const char* str) // Считает размер строки в символах. Без учета терминирующего нуля
{
	int i = 0;
	for (; str[i]; i++);
		return i;
}