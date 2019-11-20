#pragma once

#include "HashBucket.hpp"


namespace bite
{
	template<class K, class K2Int = T2IntDef<K>>
	class unordered_set
	{
		typedef K ValueType;

		struct KOFV
		{
			const K& operator()(const ValueType& data)
			{
				return data;
			}
		};

		typedef HashBucket<ValueType, KOFV, K2Int> HB;

	public:
		typename typedef HB::iterator iterator;
		typedef unordered_set<K, K2Int> USET;
	public:
		unordered_set()
			: _ht()
		{}

		/////////////////////////////////////////////
		// capacity
		size_t size()const
		{
			return _ht.Size();
		}

		bool empty()const
		{
			return _ht.Empty();
		}

		/////////////////////////////////////////////
		// iterator
		iterator begin()
		{
			return _ht.Begin();
		}

		iterator end()
		{
			return _ht.End();
		}

		//////////////////////////////////////////////
		iterator find(const K& key)
		{
			return _ht.Find(key);
		}

		/////////////////////////////////////////////
		// modify
		pair<iterator, bool> insert(const K& key)
		{
			return _ht.Insert(key);
		}

		size_t erase(const K& key)
		{
			return _ht.Erase(key);
		}

		void clear()
		{
			return _ht.Clear();
		}

		void swap(USET& s)
		{
			_ht.Swap(s._ht);
		}

		//////////////////////////////////////////////
		// bucket
		size_t bucket_count()const
		{
			return _ht.BucketCount();
		}

		size_t bucket_size(size_t bucketNo)
		{
			return _ht.BucketSize(bucketNo);
		}

		size_t bucket(const K& key)
		{
			return _ht.Bucket(key);
		}
	private:
		HB _ht;
	};
}