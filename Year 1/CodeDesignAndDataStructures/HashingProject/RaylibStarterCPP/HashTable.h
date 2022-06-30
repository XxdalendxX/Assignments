#pragma once
#include <string>
#include "raylib.h"

class HashTable
{
public:
	struct Bucket
	{
		std::string key;
		Texture2D texture;
	};

private:
	Bucket* buckets;
	int totalBuckets;

public:
	HashTable(int bucketTot);
	~HashTable();

	Texture2D Load(std::string file);
};