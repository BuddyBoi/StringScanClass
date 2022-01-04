#include <iostream>
#include <fstream>
#include <string>

class CStringScan
{
private:
	//file data
	int fileSize;
	std::string fileData;

	//log settings
	bool bLogging = true;

public:

	/// <summary>
	/// return character count of file
	/// </summary>
	/// <returns></returns>
	int GetSize()
	{
		return fileSize;
	}

	/// <summary>
	/// check if string exists in file
	/// </summary>
	/// <param name="str">string to compare to file data</param>
	/// <returns></returns>
	bool bHasString( std::string str )
	{
		int strPosition{ 0 };
		strPosition = fileData.find( str );
	
		//if string position is valid, string found
		if ( strPosition < fileSize && strPosition > 0 )
		{
			if(bLogging )
				std::cout << "string " + str + " found" << std::endl;
			
			return true;
		}

		if ( bLogging )
			std::cout << "string " + str + " not found" << std::endl;
		
		//no string found, return false
		return false;
	}

	/// <summary>
	/// select a file to be processed
	/// </summary>
	/// <param name="filePath"></param>
	void ScanFile( std::string filePath )
	{
		//get file as string
		std::ifstream fs;
		fs.open( filePath, std::ios::binary );
		if ( fs.fail() )
		{
			std::cerr << "Failed to open file!\n";
		}
		fs.seekg( 0, std::ios::end );
		size_t i = fs.tellg();
		char* buf = new char[i];
		fs.seekg( 0, std::ios::beg );
		fs.read( buf, i );
		fs.close();
		std::string s;
		s.assign( buf, i );
		delete[] buf;

		//assign filesize
		fileSize = s.length();

		//assign file data
		fileData = s;
	}
}; CStringScan StringScan;

int main()
{
	StringScan.ScanFile( "c:\\cheat.dll" );
	StringScan.bHasString( "aimbot" );
	StringScan.bHasString( "triggerbot" );
	StringScan.bHasString( "cheat" );
	StringScan.bHasString( "argentina" );
}
