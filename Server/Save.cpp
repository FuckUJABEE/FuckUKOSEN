#include"Save.h"

#include<iostream>
#include<fstream>
#include<iomanip>

#ifdef DEBUG
#include<iostream>
#endif

std::string WStringToString(std::wstring oWString)
{
	// http://www.wabiapp.com/WabiSampleSource/windows/wstring_to_string.html

	int iBufferSize = WideCharToMultiByte(CP_OEMCP, 0, oWString.c_str(), -1, (char *)NULL, 0, NULL, NULL);
	CHAR* cpMultiByte = new CHAR[iBufferSize];
	WideCharToMultiByte(CP_OEMCP, 0, oWString.c_str(), -1, cpMultiByte, iBufferSize, NULL, NULL);

	std::string oRet(cpMultiByte, cpMultiByte + iBufferSize - 1);
	delete[] cpMultiByte;

	return(oRet);
}

bool Save::SaveToCSV()
{
	std::ofstream ofs(fileNameCSV, std::ios_base::app);

	if (ofs){
		ofs << saveData.registerString.c_str() << "," << saveData.position[0] << "," << saveData.position[1] << "," << saveData.explanation.c_str() << "\n";
		return true;
	}
	else{
		return false;
	}

	return false;
}

bool Save::MakeHTML()
{
	std::wstring tmp(L".html");
	std::ofstream ofs(saveData.registerString+tmp);

	if (ofs){
		answerString = saveData.registerString + tmp;

		ofs <<
			"<!DOCMENTTYPE html>\n" <<
			"<html>\n" <<
			"	<head>\n" <<
			"		<meta http - equiv = \"content-type\" content = \"text/html\" charset = \"Shift-JIS\">\n" <<
			"		<meta name = \"author\" content = \"@FuckUJABEE\">\n" <<
			"		<meta http - equiv = \"content-language\" content = \"ja\">\n" <<
			"		<link rel = \"stylesheet\" text = \"text/css\" href = \"common.css\">\n" <<
			"		<title>\n" <<
			"			" <<
			saveData.registerString.c_str() <<
			"\n" <<
			"		</title>\n" <<
			"	</head>\n" <<
			"	<body>\n" <<
			"		<h1>\n" <<
			"			Name\n" <<
			"		</h1>\n" <<
			"		<h2>\n" <<
			"			" <<
			saveData.registerString.c_str() <<
			"\n" <<
			"		</h2><br>\n" <<
			"		<h1>\n" <<
			"			Explanation\n" <<
			"		</h1>\n" <<
			"		<h2>\n" <<
			"			" <<
			saveData.explanation.c_str() <<
			"\n" <<
			"		</h2><br>\n" <<
			"		<h1>\n" <<
			"			Position\n" <<
			"		</h1>\n" <<
			"		<h2>\n" <<
			"			" <<
			saveData.position[0] <<
			"<br>\n" <<
			"			" <<
			saveData.position[1] <<
			"\n" <<
			"		</h2><br>\n" <<
			"		<span id = \"back_to_index\">\n" <<
			"			<a href = \"index.html\" >Back</a>\n" <<
			"		</span>\n" <<
			"	</body>\n" <<
			"</html>\n";

		return true;
	}
	else{
		std::cout << "Cannot make HTML" << std::endl;
		return false;
	}

	return false;
}

bool Save::ThrowToTerminal(SOCKET client)
{
	std::cout << std::endl;
	std::cout << "Save::ThrowToTerminal" << std::endl;

	std::string dist = WStringToString(answerString);

	int result = send(client, dist.c_str(), 64, 0);

	if (result < 0){
		std::cout << "Error" << std::endl;
	}

	return true;
}