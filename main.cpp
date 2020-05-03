#include"filequery.h"
#include"shape.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void test1()
{
	cout << "test1" << endl;
	ifstream infile;
	infile.open("result.txt");
	FileQuery m(infile);
	m.PrintSentencesOrdered();
	m.PrintWordCount();
	m.PrintSentencesFiltered("was");
	m.ReplaceWord("was", "abc");
	m.PrintSentencesOrdered();
	m.PrintSentencesFiltered("was");
	m.PrintSentencesFiltered("abc");
}

void test2()
{
	cout << "test2" << endl;
	shape* sp;
	sp = new Circle(5);
	cout << "The area of the Circle is" << sp->Getarea() << endl;
	delete sp;
	sp = new Rectangle(4, 6);
	cout << "The area of the Rectangle is" << sp->Getarea() << endl;
	delete sp;
	sp = new Square(5);
	cout << "The area of the Square is" << sp->Getarea() << endl;
	delete sp;
}
int main()
{
	test1();
	test2();
	return 0;
}
