#include <map>
#include <set>
#include <string>

void test_map_set1()
{
	set<int> s;
	s.insert(3);
	s.insert(5);
	s.insert(8);
	s.insert(1);
	s.insert(9);

	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	set<int>::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	//s.erase(5);

	auto pos = s.find(5); // O(logN)
	// auto pos = std::find(s.begin(), s.end(), 5); // O(N)
	if (pos != s.end())
	{
		s.erase(pos);
	}
	else
	{
		cout << "找不到" << endl;
	}

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_map_set2()
{
	map<string, string> dict;
	dict.insert(pair<string, string>("insert", "插入"));
	dict.insert(pair<string, string>("left", "左边"));
	dict.insert(pair<string, string>("right", "右边"));
	dict.insert(pair<string, string>("node", "节点"));
	dict.insert(pair<string, string>("tree", "树"));
	dict["sort"] = "排序";

	/*string str;
	while (cin >> str)
	{
	auto ret = dict.find(str);
	if (ret != dict.end())
	{
	cout << str << ":" << (*ret).second << endl;
	}
	else
	{
	cout << str << ":" << "非法词汇" << endl;
	}
	}*/

	//string strs[] = { "苹果", "西瓜", "草莓", "草莓", "西瓜", "草莓" };
	//map<string, int> countMap;
	//for (auto& e : strs)
	//{
	////	map<string, int>::iterator ret = countMap.find(e);
	//	auto ret = countMap.find(e);
	//	if (ret != countMap.end())
	//	{
	//		//(*ret).second++;
	//		ret->second++;
	//	}
	//	else
	//	{
	//		// 调用构造函数创建匿名对象
	//		//countMap.insert(pair<map<string, int>(e, 1));

	//		// template<class K, class V>
	//		/*inline pair<K, V> make_pair(const K& k, const V& v)
	//		{
	//			return pair<K, V>(k, v);
	//		}*/
	//		countMap.insert(make_pair(e, 1));
	//	}
	//}

	//string strs[] = { "苹果", "西瓜", "草莓", "草莓", "西瓜", "草莓" };
	//map<string, int> countMap;
	//for (auto& e : strs)
	//{
	//	//	map<string, int>::iterator ret = countMap.find(e);
	//	auto ret = countMap.find(e);
	//	if (ret != countMap.end())
	//	{
	//		//(*ret).second++;
	//		ret->second++;
	//	}
	//	else
	//	{
	//		// 调用构造函数创建匿名对象
	//		//countMap.insert(pair<map<string, int>(e, 1));

	//		// template<class K, class V>
	//		/*inline pair<K, V> make_pair(const K& k, const V& v)
	//		{
	//		return pair<K, V>(k, v);
	//		}*/
	//		countMap.insert(make_pair(e, 1));
	//	}
	//}

	/*V& operator[](const K& k)
	{
		pair<iterator, bool> ret = insert(make_pair(k, V()));
		return ret.first->second;
	}*/
	string strs[] = { "苹果", "西瓜", "草莓", "草莓", "西瓜", "草莓" };
	map<string, int> countMap;
	for (auto& e : strs)
	{
		countMap[e]++;
	}

	countMap["香蕉"];
	countMap["香蕉"] = 5;


	/*string strs[] = { "苹果", "苹果","苹果","西瓜", "草莓", "草莓", "西瓜", "草莓" };
	map<string, int> countMap;
	for (auto& e : strs)
	{
	pair<map<string, int>::iterator, bool> ret = countMap.insert(make_pair(e, 1));
	if (ret.second == false)
	{
	ret.first->second++;
	}
	}*/
}