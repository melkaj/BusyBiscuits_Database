#pragma once
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef DATABASE_H
#define DATABASE_H

namespace database_std
{
	class Database
	{
	private:


	public:
		Database();
		~Database();

		void ReadInData();
		void WriteData();

	};
}

#endif	// DATABASE_H