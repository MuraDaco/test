// emphiOS.cpp : file di progetto principale.

#include "stdafx.h"
#include "Form1.h"
#include "Form2.h"

using namespace emphiOS;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Attivare gli effetti visivi di Windows XP prima di creare i controlli
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	Form2^ prova = gcnew Form2();

	// Creare la finestra principale ed eseguirla
	Application::Run(gcnew Form1());
	return 0;
}
