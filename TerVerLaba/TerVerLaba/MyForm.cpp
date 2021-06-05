#include "MyForm.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;


/*[STAThread]
void Main(cli::array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	TerVerLaba::MyForm form;
	Application::Run(% form);
}*/

using namespace TerVerLaba; // Название проекта
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}




