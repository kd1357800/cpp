#include "car.h"
#include "ambulance.h"
#include <iostream>
using namespace std;

int main() 
{
	cout << "Carクラスの処理" << endl;
	Car nbox;//インスタンス作成
	//nbox.setSpeed(40);//メンバ変数へ代入
	nbox.drive(1.5);//メンバ関数の実行
	nbox.setSpeed(60);
	nbox.drive(2.0);
	cout << "総移動距離:" << nbox.getMigration() << "km" << endl;
	cout << "Ambulanceクラスの処理" << endl;
	Ambulance* pAmb = new Ambulance();
	pAmb->setSpeed(60);
	pAmb->drive(2);
	pAmb->sevePeople();
	delete pAmb;
	return 0;
	//インスタンス消去
}