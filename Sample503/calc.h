#pragma once
#include <string>
using namespace std;

class Calc
{
public:
	Calc();
	Calc(int a, int b);

	int add();
	int add(int a, int b);
	double add(double a, double b);
	string add(string a, string b);
	int getA();
	int getB();

private:
	int m_a, m_b;

};