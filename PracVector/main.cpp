#include <vector>
#include <iostream>
#include <string>
using namespace std;
void compare(int& max, int& min, const int& data)
{
	max = max < data ? data : max;
	min = min > data ? data : min;
}

int main()
{
	vector<int> vec{ 20,11,9,33,40,25 };
	int max, min;

	//☆
	max = *max_element(vec.begin(), vec.end());
	min = *min_element(vec.begin(), vec.end());

	cout << "最大値:" << max << "　最小値：" << min << endl;


	//添え字番号を使ったループ
	max = min = vec[0];//先頭要素で初期化
	for (int i = 1; i < vec.size(); i++)
	{
		compare(max, min, vec[i]);
	}

	cout << "最大値:" << max << "　最小値：" << min << endl;

	//イテレーターを使ったループ
	max = min = vec.at(0);//先頭要素で初期化

	for (auto itr = vec.begin(); itr != vec.end(); itr++)
	{
		compare(max, min, *itr);
	}
	cout << "最大値:" << max << "　最小値：" << min << endl;

	//範囲forを使ったループ
	max = min = vec.front();//先頭要素で初期化

	for (auto i : vec)
	{
		compare(max, min, i);
	}
	cout << "最大値:" << max << "　最小値：" << min << endl;

	return 0;
}

