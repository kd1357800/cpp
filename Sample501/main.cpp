#include "car.h"
#include "ambulance.h"
#include <iostream>
using namespace std;

int main() 
{
	cout << "Car�N���X�̏���" << endl;
	Car nbox;//�C���X�^���X�쐬
	//nbox.setSpeed(40);//�����o�ϐ��֑��
	nbox.drive(1.5);//�����o�֐��̎��s
	nbox.setSpeed(60);
	nbox.drive(2.0);
	cout << "���ړ�����:" << nbox.getMigration() << "km" << endl;
	cout << "Ambulance�N���X�̏���" << endl;
	Ambulance* pAmb = new Ambulance();
	pAmb->setSpeed(60);
	pAmb->drive(2);
	pAmb->sevePeople();
	delete pAmb;
	return 0;
	//�C���X�^���X����
}