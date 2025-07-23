#include <iostream>
#include <list>
using namespace std;
int main()
{
	list<int> li{ 5,8,2 };
	li.push_back(1);//1
	li.push_back(2);//1,2
	li.push_front(3);//3,1,2
	auto itr = li.begin();//liの先頭イテレーター
	itr++;//イテレーターを一つ進める
	li.insert(itr, 4);//4を挿入 3,4,1,2
	li.sort();//昇順ソート
	li.unique();//重複データ削除
	li.remove(8);//8を削除
	li.reverse();//データ列を逆順にする
	//for (itr = li.begin(); itr!= li.end(); itr++)
	//{
	//	cout << *itr << " ";
	//}
	for (auto d : li)
	{
		cout << d << " ";
	}
	cout << endl;
	return 0;
}