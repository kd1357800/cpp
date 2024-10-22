#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//添え字番号を使ったループ
	vector<int> vec{ 20,11,9,33,40,25 };
	int max, min;
	max = min = vec[0];//先頭要素で初期化
	for (int i = 1; i < vec.size(); i++)
	{
		if (min > vec[i])min = vec[i];

		if (max < vec[i])max = vec[i];
	}
	cout << "最大値:" << max << "　最小値：" << min << endl;

	//イテレーターを使ったループ
	max = min = vec.at(0);//先頭要素で初期化

	for (auto itr = vec.begin(); itr != vec.end(); itr++)
	{
		if (min > *itr)min = *itr;

		if (max < *itr)max = *itr;
	}
	cout << "最大値:" << max << "　最小値：" << min << endl;

	//範囲forを使ったループ
	max = min = vec.front();//先頭要素で初期化

	for (auto i : vec)
	{
		if (min > i)min = i;

		if (max < i)max = i;
	}
	cout << "最大値:" << max << "　最小値：" << min << endl;

	return 0;
}

