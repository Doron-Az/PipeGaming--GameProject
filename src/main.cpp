#include <iostream>
#include <fstream>
#include "Controller.h"

int main()
{
	try {
		Controller().run();
		return EXIT_SUCCESS;
	}

	catch (std::exception& e)
	{
		std::fstream errorFile;
		errorFile.open("log.txt" , std::fstream::out);
		errorFile << "Exeption: " << e.what() << '\n';
		errorFile.close();	
		exit(EXIT_SUCCESS);
	}
	catch (...)
	{
		std::fstream errorFile;
		errorFile.open("log.txt" ,std::fstream::out);
		errorFile << "Unknown exeption\n" << '\n';
		errorFile.close();
		exit(EXIT_FAILURE);
	}
}
//-----------------------------------------------------------------------------

