#include "car.h"
int main() 
{
	Car nbox, tanto;//インスタンス作成
	nbox.speed = 40;//メンバ変数へ代入
	nbox.drive(1.5);//メンバ関数の実行
	tanto.speed = 50;
	tanto.drive(1.0);
	return 0;
}