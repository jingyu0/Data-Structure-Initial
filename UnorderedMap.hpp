#pragma once

#include "HashBucket.hpp"


namespace bite
{
	template<class K, class V, class K2Int = T2IntDef<K>>
	class unordered_map
	{
		typedef pair<K, V> ValueType;

		struct KOFV
		{
			const K& operator()(const ValueType& data)
			{
				return data.first;
			}
		};

		typedef HashBucket<ValueType, KOFV, K2Int> HB;
		typedef unordered_map<K, V, K2Int> Self;
	public:
		typename typedef HB::iterator iterator;

	public:
		unordered_map()
			: _ht()
		{}

		///////////////////////////////////////////////
		// iterator
		iterator begin()
		{
			return _ht.Begin();
		}

		iterator end()
		{
			return _ht.End();
		}

		///////////////////////////////////////
		// capacity
		size_t size()const
		{
			return _ht.Size();
		}

		bool empty()const
		{
			return _ht.Empty();
		}

		/////////////////////////////////////////
		// modify
		pair<iterator, bool> insert(const ValueType& data)
		{
			return _ht.Insert(data);
		}

		size_t Erase(const K& key)
		{
			return _ht.Erase(make_pair(key, V()));
		}

		void swap(Self& s)
		{
			_ht.Swap(s._ht);
		}

		void clear()
		{
			return _ht.Clear();
		}

		/////////////////////////////////////////
		// 
		iterator find(const K& key)
		{
			return _ht.Find(make_pair(key, V()));
		}

		//////////////////////////////////////////
		// bucket
		size_t bucket_count()const
		{
			return _ht.BucketCount();
		}

		size_t bucket_size(size_t bucketNo)const
		{
			return _ht.BucketSize(bucketNo);
		}

		size_t bucket(const K& key)const
		{
			return _ht.Bucket(make_pair(key, V()));
		}

	private:
		HB _ht;
	};
}

#include <string>
#include <iostream>
using namespace std;


void TestUnorderedMap1()
{
	bite::unordered_map<std::string, std::string, String2INT> m;
	m.insert(make_pair("apple", "苹果"));
	m.insert(make_pair("peach", "桃子"));
	m.insert(make_pair("banana", "相交"));
	m.insert(make_pair("watermelon", "西瓜"));
	m.insert(make_pair("orange", "橘子"));

	cout << m.size() << endl;

	m.insert(make_pair("orange", "橘子"));
	cout << m.size() << endl;

	auto it = m.find("banan");
	if (it != m.end())
	{
		cout << it->second << endl;
	}
	else
	{
		cout << "没有对应水果" << endl;
	}

// 	for (auto& e : m)
// 	{
// 		cout << e.first << "--->" << e.second << endl;
// 	}

	it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "---->" << it->second << endl;
		++it;
	}
	cout << endl;
}


#include <unordered_map>

void TestUnorderedMap2()
{
	unordered_map<std::string, std::string> m;
	m.insert(make_pair("apple", "苹果"));
	m.insert(make_pair("peach", "桃子"));
	m.insert(make_pair("banana", "相交"));
	m.insert(make_pair("watermelon", "西瓜"));
	m.insert(make_pair("orange", "橘子"));

	cout << m.size() << endl;

	m.insert(make_pair("orange", "橘子"));
	cout << m.size() << endl;

	auto it = m.find("banan");
	if (it != m.end())
	{
		cout << it->second << endl;
	}
	else
	{
		cout << "没有对应水果" << endl;
	}

	for (auto& e : m)
	{
		cout << e.first << "--->" << e.second << endl;
	}

	it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "---->" << it->second << endl;
		++it;
	}
	cout << endl;
}


