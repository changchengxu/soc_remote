// soc_burner.cpp : main project file.
#include "stdafx.h"
#include "gf_main.h"

using namespace soc_remote;
using namespace System::IO;
using namespace System::Threading;
using namespace GSoft::Utility;
[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
#ifdef _DEBUG
	Directory::SetCurrentDirectory(String::Format("{0}/../Release", AppDomain::CurrentDomain->BaseDirectory));
#else
	Directory::SetCurrentDirectory(AppDomain::CurrentDomain->BaseDirectory);
#endif

#ifndef _DEBUG
	try {
#endif
		// check multiple instances
		if (!ProcessU::multiple(args)) {
			System::Environment::Exit(0);
		}

		// check open console
		if (Array::IndexOf(args, "-debug") >= 0) {
			// create but not log
			ConsoleU::createConsole();
			ConsoleU::hide();
		} 

		// check log file
		if (Array::IndexOf(args, "-log") >= 0) {			
			ConsoleU::createConsole(true);
			ConsoleU::hide();
		}

		// Enabling Windows XP visual effects before any controls are created
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false); 

#ifndef _DEBUG
		// Creates an instance of the methods that will handle the exception.
		ExceptionHandler^ eh = gcnew ExceptionHandler;

		// Adds the event handler to to the event.
		Application::ThreadException += gcnew ThreadExceptionEventHandler( eh, &ExceptionHandler::OnThreadException );
#endif

		// Create the main window and run it
		Application::Run(gcnew gf_main(args));
		return 0;

#ifndef _DEBUG
	} catch (Exception^ e) {
		Report::Send(e);
	}
#endif
}
