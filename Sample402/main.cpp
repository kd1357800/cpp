#include "car.h"
#include <iostream>
using namespace std;

int main() 
{
	unique_ptr<Car> pkuruma(new Car());
	//Car* pkuruma = nullptr;
	//pkuruma = new Car();//�C���X�^���X�쐬
	//Car nbox;//�C���X�^���X�쐬
	pkuruma->setSpeed(40);//�����o�ϐ��֑��
	pkuruma->drive(1.5);//�����o�֐��̎��s
	pkuruma->setSpeed(60);
	pkuruma->drive(2.0);
	cout << "���ړ�����:" << pkuruma->getMigration() << "km" << endl;
	//delete pkuruma;
	return 0;
	//�C���X�^���X����
}