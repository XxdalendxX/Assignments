#include "HashTable.h"
#include "Hashing.h"


HashTable::HashTable(int bucketTot)
{
	totalBuckets = bucketTot;

	buckets = new Bucket[bucketTot] {};
}
HashTable::~HashTable()
{

}

Texture2D HashTable::Load(std::string file)
{
	unsigned int hash;
	hash = HashFunction::Dfault(file.c_str(), file.size());
	
	hash %= totalBuckets;

	if (buckets[hash].key == file)
	{
		return buckets[hash].texture;
	}
	else
	{
		while (!buckets[hash].key.empty())
		{
			if (buckets[hash].key == file)
			{
				return buckets[hash].texture;
			}
			hash++;
			hash %= totalBuckets;
		}
		buckets[hash].key = file;
		buckets[hash].texture = LoadTexture(file.c_str());
	}
	
	return buckets[hash].texture;
	
}