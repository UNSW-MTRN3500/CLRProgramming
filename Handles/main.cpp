#using <System.dll>

using namespace System;

ref class Data
{
	double a;
	double b;
	double c;

public:
	Data(double a, double b, double c) : a(a), b(b), c(c) {}
	double Get_a() { return a; }
	double Get_b() { return b; }
	double Get_c() { return c; }
};

int main()
{
	//int n = 50;//allocated on the stack
	//On line 22 => Creating an object using stack semantics
	Data MyData(2, 3, 4);//space allocated on the heap
	//Exceptions to Stack Semantics => Strings and arrays
	Data^ MyDataHndl = % MyData;
	Data^ DataHndl = gcnew Data(2, 3, 4);//space allocated on the managed heap
	int^ a= gcnew int(50);//space allocated on the managed heap
	//Printing to the screen
	Console::WriteLine("{0,12:F3}", DataHndl->Get_a());
	Console::WriteLine("{0,12:F3}", MyDataHndl->Get_a());
	Console::WriteLine("{0,12:d}", a);
	//Wait for keypress;
	Console::ReadKey();
	return 0;
}