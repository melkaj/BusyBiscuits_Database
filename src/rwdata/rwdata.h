#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace rwdata_std
{
	class RWData
	{
	private:
		int fileNumber;


	public:
		RWData();
		~RWData();

		void ReadInData();
		void WriteData();

		void AppendData(int socialSecurity, string name, string occupation);

	};
}
