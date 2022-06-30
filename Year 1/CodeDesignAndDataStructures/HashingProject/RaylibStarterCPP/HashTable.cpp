#include "HashTable.h"

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
	return LoadTexture(file.c_str());
	
}