// ======================================================================
// BusyBiscuits - Database (Name subject to change)
//
// rwdata.h - Header file for RWData class
//
// Written by: Meldin Kajoshaj, 2021
// ======================================================================

#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace rwdata_std
{
	class RWData
	{
	private:
		int 		fileNumber;
		string 		db1Filename, db2Filename;

		void 		SaveData		();

	public:
		RWData						();
		~RWData						();
		string		Getdb1Filename  ();
		string		Getdb2Filename  ();

		void 		WriteData		(string socialSecurity, string name, string occupation, bool isOverwrite);
		void 		ReadInData		(datastructure_std::Datastructure &datastructure);
		void 		ToggleMainFile	();

	};
}
