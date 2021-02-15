#pragma once
#include "../binarytree/binarytree.h"
#include "../hashtable/hashtable.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace BT_std;
using namespace HashT_std;
using namespace std;

#ifndef DATABASE_H
#define DATABASE_H

namespace Database_std
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