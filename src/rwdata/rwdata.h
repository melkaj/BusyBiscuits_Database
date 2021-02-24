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


	public:
		RWData						();
		~RWData						();

		void 		ReadInData		();
		void 		WriteData		();
		void 		WriteData		(string socialSecurity, string name, string occupation, bool isOverwrite);
		void 		ToggleMainFile	();
		void 		ReadInData(datastructure_std::Datastructure* &datastructure);


		void 		AppendData		(string socialSecurity, string name, string occupation);

	};
}