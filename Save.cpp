#include"Save.h"

#include<iostream>
#include<fstream>
#include<iomanip>

#ifdef DEBUG
#include<iostream>
#endif

bool Save::SaveToCSV()
{
	std::ofstream ofs(fileNameCSV, std::ios_base::app);

	if (ofs){
		ofs << saveData.registerString << "," << saveData.position[0] << "," << saveData.position[1] << "," << saveData.URL << "\n";
		return true;
	}
	else{
		return false;
	}

	return false;
}

bool Save::MakeHTML()
{
	std::ofstream ofs(saveData.registerString+".html");

	if (ofs){
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
			saveData.registerString <<
			"\n" <<
			"		</title>\n" <<
			"	</head>\n" <<
			"	<body>\n" <<
			"		<h1>\n" <<
			"			Name\n" <<
			"		</h1>\n" <<
			"		<h2>\n" <<
			"			" <<
			saveData.registerString <<
			"\n" <<
			"		</h2><br>\n" <<
			"		<h1>\n" <<
			"			Address\n" <<
			"		</h1>\n" <<
			"		<h2>\n" <<
			"			" <<
			saveData.URL <<
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

bool Save::ThrowToTerminal()
{
#ifdef DEBUG
	cout << "Save::ThrowToTerminal" <<endl;
#endif

	return true;
}