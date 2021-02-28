// ======================================================================
// BusyBiscuits - Database (Name subject to change)
//
// rwdata.h - Header file for RWData class
//
// Written by: Meldin Kajoshaj, 2021
// ======================================================================

#pragma once
#include <string>
#include <unordered_map>

namespace rwdata_std
{
	class RWData: public Logger
	{
	private:
		int 		fileNumber;
		string 		db1FilePath, db2FilePath;

	public:
		RWData						();
		~RWData						();
		string		Getdb1FilePath  ();
		string		Getdb2FilePath  ();

		void 		WriteData		(string socialSecurity, string name, string occupation, bool isOverwrite);
		void 		ReadInData		(datastructure_std::Datastructure &datastructure);
		void 		ToggleMainFile	();

		void 		SaveData		(unordered_map<string, int> &ignoreEntry);
	};
}
