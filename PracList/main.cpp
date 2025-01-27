#include <iostream>
#include <list>
using namespace std;

int main()
{
	//パターンA
	{
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };

		for (auto d : li2)
		{
			li1.push_back(d);
		}
		cout << "連結結果";
		for (auto d : li1)
		{
			cout << d << " ";
		}
		cout << endl;
	}
	//パターンB
	{
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//li1.reverse();
		//for (auto d : li1)
		//{
		//	li2.push_front(d);
		//}
		//rbegin()データ末尾 rend()はデータ先頭
		for (auto it = li1.rbegin(); it != li1.rend(); it++)
		{
			li2.push_front(*it);
		}
		cout << "連結結果";
		for (auto d : li2)
		{
			cout << d << " ";
		}
		cout << endl;
	}
	//パターンC
	{
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		li1.merge(li2);
		cout << "連結結果";
		for (auto d : li1)
		{
			cout << d << " ";
		}
		cout << endl;
	}
	//パターンC(insert)
	{
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//第１引数：挿入される場所のイテレータ
		//第２引数：挿入するデータの先頭のイテレータ
		//第３引数：挿入するデータの末尾のイテレータ
		li1.insert(li1.end(), li2.begin(), li2.end());
		cout << "連結結果";
		for (auto d : li1)
		{
			cout << d << " ";
		}
		cout << endl;
	}
	//パターンC(splice)
	{
		list<int> li1{ 2,3,11,17 }, li2{ 5,7,13,19 };
		//第１引数：挿入される場所のイテレータ
		//第２引数：挿入するリスト
		li1.splice(li1.end(), li2);
		cout << "連結結果";
		for (auto d : li1)
		{
			cout << d << " ";
		}
		cout << endl;
	}
}