#include <iostream>
#include <string>
#include "bird.h"
#include "crow.h"
#include "chicken.h"
using namespace std;

int main()
{
	Bird* pBird1{}, * pBird2{};
	//Bird* pBird0{};
	//pBird0 = new Bird();		Bird�e�N���X�͎q�N���X�ɏ�����C���Ă�̂ŃC���X�^���X�͍��Ȃ�
	pBird1 = new Crow();
	pBird2 = new Chicken();
	pBird1->fly();
	pBird2->fly();
	pBird1->sing();
	pBird2->sing();
	delete pBird1;
	delete pBird2;
	return 0;
}
