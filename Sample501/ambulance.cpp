#include <iostream>
#include "ambulance.h"

using namespace std;

Ambulance::Ambulance() : m_number(119)//ここで初期化
{
	cout << "Ambulanceクラスのインスタンス作成" << endl;
}
Ambulance::~Ambulance()
{
	cout << "Ambulanceクラスのインスタンス消去" << endl;
}

void Ambulance::sevePeople()
{
	cout << "救急救命活動" << endl
		<< "呼び出しは" << m_number << "番" << endl;
}
