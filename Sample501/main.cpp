#include "car.h"
#include <iostream>
using namespace std;

int main() 
{
	Car nbox;//�C���X�^���X�쐬
	//nbox.setSpeed(40);//�����o�ϐ��֑��
	nbox.drive(1.5);//�����o�֐��̎��s
	nbox.setSpeed(60);
	nbox.drive(2.0);
	cout << "���ړ�����:" << nbox.getMigration() << "km" << endl;
	return 0;
	//�C���X�^���X����
}