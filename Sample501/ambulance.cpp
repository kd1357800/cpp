#include <iostream>
#include "ambulance.h"

using namespace std;

Ambulance::Ambulance() : m_number(119)//�����ŏ�����
{
	cout << "Ambulance�N���X�̃C���X�^���X�쐬" << endl;
}
Ambulance::~Ambulance()
{
	cout << "Ambulance�N���X�̃C���X�^���X����" << endl;
}

void Ambulance::sevePeople()
{
	cout << "�~�}�~������" << endl
		<< "�Ăяo����" << m_number << "��" << endl;
}
