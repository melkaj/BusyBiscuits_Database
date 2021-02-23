#pragma once
#include <iostream>
#include <string>

using namespace std;

#ifndef RWDATA_H
#define RWDATA_H

namespace rwdata_std
{
	class RWData
	{
	private:


	public:
		RWData();
		~RWData();

		void ReadInData();
		void WriteData();

	};
}

#endif	// RWDATA_H