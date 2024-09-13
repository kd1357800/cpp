#include "car.h"
#include <iostream>
using namespace std;

int main() 
{
	unique_ptr<Car> pkuruma(new Car());
	//Car* pkuruma = nullptr;
	//pkuruma = new Car();//インスタンス作成
	//Car nbox;//インスタンス作成
	pkuruma->setSpeed(40);//メンバ変数へ代入
	pkuruma->drive(1.5);//メンバ関数の実行
	pkuruma->setSpeed(60);
	pkuruma->drive(2.0);
	cout << "総移動距離:" << pkuruma->getMigration() << "km" << endl;
	//delete pkuruma;
	return 0;
	//インスタンス消去
}