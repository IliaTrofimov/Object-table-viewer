//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("NumberEntryFormClass.cpp", formNumEntry);
USEFORM("ResultFormClass.cpp", formResult);
USEFORM("SearchFormClass.cpp", searchForm);
USEFORM("MainFormClass.cpp", mainForm);
USEFORM("ABOUT.cpp", AboutBox);
USEFORM("EditFormClass.cpp", formEdit);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
        setlocale(LC_ALL,"russian");
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->Title = "Список зоопарков";
		Application->CreateForm(__classid(TmainForm), &mainForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
