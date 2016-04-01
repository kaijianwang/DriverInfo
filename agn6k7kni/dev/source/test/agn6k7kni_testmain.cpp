#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/CompilerOutputter.h>
#include <fstream>
#include "agn6k7kni_testCppUnit.h"

int main( int argc, char **argv)
{
	std::ofstream fs("TestResult.txt");
	CppUnit::TextUi::TestRunner runner;
	runner.addTest( CppUnit::TestFactoryRegistry::getRegistry().makeTest());   // Add the top suite to the test runner
	runner.setOutputter( CppUnit::CompilerOutputter::defaultOutputter(  &runner.result(), fs ) );
	bool wasSucessful = runner.run( "" );

	char lock;
	std::cin >> lock;
	return 0;
}		
		