#include "car.h"
#include <iostream>

using namespace std;

Car::Car() : m_speed(40.0), m_migration(0.0)//�����ŏ�����
{
	cout << "Car�N���X�̃C���X�^���X�쐬" << endl;
}
Car::~Car()
{
	cout << "Car�N���X�̃C���X�^���X����" << endl;
}

double Car::getSpeed()
{
	return m_speed;
}
double Car::getMigration()
{
	return m_migration;
}
void Car::setSpeed(double speed)
{
	m_speed = speed;
}

//���s����
void Car::drive(double hour)
{
	cout << "����" << m_speed << "km��" << hour << "���ԑ��s" << endl;
	cout << m_speed * hour << "km�ړ����܂����B" << endl;
	m_migration += m_speed * hour;
}