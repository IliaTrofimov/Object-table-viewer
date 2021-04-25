//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ResultFormClass.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformResult *formResult;

//---------------------------------------------------------------------------
// ���������� �������.

__fastcall TformResult::TformResult(TmainForm* Owner, ZooList& zl, UnicodeString title)
	: TForm(Owner)
{
	if(title != "")
		Caption += "; " + title;
	parent = Owner;
	zooData = &zl;
	printData();
}

void TformResult::printData()
{
	data_grid->RowCount = zooData->size();
	size_t pos = 0;
	for(auto i = zooData->begin(); i != zooData->end(); i++)
	{
		data_grid->Cells[0][pos] = i->second.name;
		data_grid->Cells[1][pos] = i->second.spiciesCount;
		data_grid->Cells[2][pos] = i->second.rareCount;
		data_grid->Cells[3][pos] = i->first;
		pos += 1;
	}
	statusBar->Panels->Items[1]->Text = zooData->size();
}


//---------------------------------------------------------------------------
// ������� ������ �� ����. �������� � �������� ������������� ����, ����� ��
// ������� ������ � ��������� �������

void __fastcall TformResult::FormClose(TObject *Sender, TCloseAction &Action)
{
	parent->enableResult();
}


//---------------------------------------------------------------------------
// ������ � �������� ����

void __fastcall TformResult::menu_saveClick(TObject *Sender)
{
    try{zooData->print("C:\\Users\\iliat\\Desktop\\data_result.txt"); }
	catch(...){MessageBeep(0); }
}

void __fastcall TformResult::menu_exitClick(TObject *Sender)
{
	Close();
}

void __fastcall TformResult::menu_showKeysClick(TObject *Sender)
{
    if (data_grid->ColCount == 4)
	{
		menu_showKeys->Caption = "�������� �����";
		lbl_headerKey->Caption = "";
		data_grid->ColCount = 3;
	}
	else
	{
		menu_showKeys->Caption = "������ �����";
		lbl_headerKey->Caption = "����";
        data_grid->ColCount = 4;
	}
}
//---------------------------------------------------------------------------

