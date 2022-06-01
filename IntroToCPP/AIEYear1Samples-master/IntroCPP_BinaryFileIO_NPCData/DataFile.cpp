#include "DataFile.h"
#include <fstream>
using namespace std;

DataFile::DataFile()
{
	recordCount = 0; //establishes data file
}

DataFile::~DataFile()
{
	Clear(); //destroys data file
}

void DataFile::AddRecord(string imageFilename, string name, int age)
{
	Image i = LoadImage(imageFilename.c_str()); //initialises image variable

	Record* r = new Record; //initialises record variable
	r->image = i;
	r->name = name;
	r->age = age;

	records.push_back(r);
	recordCount++;
}

DataFile::Record* DataFile::GetRecord(int index)
{
	//reads correct record and prints it into the window
	
	std::ifstream datafile(filename, std::ios::binary);

	//establishes record count and record variables
	recordCount = 0;
	datafile.read((char*)&recordCount, sizeof(int));

	//reads and skips unnessesary records 
	for (int i = 0; i < index; i++)
	{
		int nameSize = 0;
		int ageSize = 0;
		int width = 0, height = 0, imageSize = 0;

		datafile.read((char*)&width, sizeof(int));
		datafile.read((char*)&height, sizeof(int));

		imageSize = sizeof(Color) * width * height;

		datafile.read((char*)&nameSize, sizeof(int));
		datafile.read((char*)&ageSize, sizeof(int));

		int recordSize = imageSize + nameSize + ageSize;

		datafile.seekg(recordSize, std::ios::cur);
	}

	//reads and prints new record into window
	//-----------------------------------------------------------------------
	int nameSize = 0;
	int ageSize = 0;
	int width = 0, height = 0, format = 0, imageSize = 0;

	datafile.read((char*)&width, sizeof(int));
	datafile.read((char*)&height, sizeof(int));

	imageSize = sizeof(Color) * width * height;

	datafile.read((char*)&nameSize, sizeof(int));
	datafile.read((char*)&ageSize, sizeof(int));

	char* imgdata = new char[imageSize];
	datafile.read(imgdata, imageSize);

	Image img = LoadImageEx((Color*)imgdata, width, height);
	char* name = new char[nameSize + 1]{};
	int age = 0;

	datafile.read((char*)name, nameSize);
	datafile.read((char*)&age, ageSize);

	datafile.close();

	Record* r = new Record();
	r->image = img;
	r->name = string(name);
	r->age = age;

	delete[] imgdata;
	delete[] name;
	//------------------------------------------------------------------------
	return r;
}

void DataFile::Save(string filename)
{
	ofstream outfile(filename, ios::binary);

	//establishes record count and record variables
	int recordCount = records.size();
	outfile.write((char*)&recordCount, sizeof(int));

	//writes out the new record within the file
	for (int i = 0; i < recordCount; i++)
	{		
		Color* imgdata = GetImageData(records[i]->image);
				
		int imageSize = sizeof(Color) * records[i]->image.width * records[i]->image.height;
		int nameSize = records[i]->name.length();
		int ageSize = sizeof(int);

		outfile.write((char*)&records[i]->image.width, sizeof(int));
		outfile.write((char*)&records[i]->image.height, sizeof(int));
		
		outfile.write((char*)&nameSize, sizeof(int));
		outfile.write((char*)&ageSize, sizeof(int));

		outfile.write((char*)imgdata, imageSize);
		outfile.write((char*)records[i]->name.c_str(), nameSize);
		outfile.write((char*)&records[i]->age, ageSize);
	}

	outfile.close();
}

void DataFile::Load(string fileName)
{
	Clear();

	filename = fileName; //clears window to initialise new record
}

void DataFile::Clear()
{
	// deletes all records
	for (int i = 0; i < records.size(); i++)
	{
		delete records[i];
	} 
	records.clear();
	recordCount = 0;
}