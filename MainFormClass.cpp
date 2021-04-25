//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainFormClass.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TmainForm *mainForm;

//---------------------------------------------------------------------------
// Внутренние функции

__fastcall TmainForm::TmainForm(TComponent* Owner)
	: TForm(Owner), zooData()
{
	rareSpiciesRate = 0.5;
    statusBar->Panels->Items[1]->Text = 0;
}


void TmainForm::printData()
{
	statusBar->Panels->Items[1]->Text = "Данные обновляются. Это может занять время..";
    data_grid->Cells[0][0] = "";
	data_grid->Cells[1][0] = "";
	data_grid->Cells[2][0] = "";
	data_grid->Cells[3][0] = "";

	data_grid->RowCount = zooData.size() + 1;
	size_t pos = 0;

	for (auto i = zooData.begin(); i != zooData.end(); i++)
	{
		data_grid->Cells[0][pos] = i->second.name;
		data_grid->Cells[1][pos] = i->second.spiciesCount;
		data_grid->Cells[2][pos] = i->second.rareCount;
		data_grid->Cells[3][pos] = i->first;
		pos += 1;
	}

	data_grid->Cells[0][pos] = "";
	data_grid->Cells[1][pos] = "";
	data_grid->Cells[2][pos] = "";
	data_grid->Cells[3][pos] = "";

	statusBar->Panels->Items[1]->Text = zooData.size();
}

void TmainForm::printOneItem(ZooPair z)
{
	data_grid->Cells[0][data_grid->RowCount - 1] = z.second.name;
	data_grid->Cells[1][data_grid->RowCount - 1] = z.second.spiciesCount;
	data_grid->Cells[2][data_grid->RowCount - 1] = z.second.rareCount;
	data_grid->Cells[3][data_grid->RowCount - 1] = z.first;
}

void TmainForm::editZooData(uint32_t key)
{
	ZooPair temp = ZooPair(key, zooData[key]);

	TformEdit* form = new TformEdit(this, &temp);
	if(form->ShowModal() == mrOk)
	{
		zooData.erase(key);
		if(zooData.insert(temp).second)
			printData();
	}
}

void TmainForm::addZooData()
{
	ZooPair temp = ZooPair(0, Zoo("", 0));
	TformEdit* form = new TformEdit(this, &temp, false);

	if(form->ShowModal() == mrOk)
	{
		if(!zooData.insert(temp).second)
            zooData[temp.first] = temp.second;
		printData();
	}
    data_grid->Row = data_grid->RowCount - 1;
}

void TmainForm::removeZoo(uint32_t key)
{
	if(zooData.erase(key) > 0)
	{
		printData();
		data_grid->Cells[0][data_grid->RowCount-1] = "";
		data_grid->Cells[1][data_grid->RowCount-1] = "";
		data_grid->Cells[2][data_grid->RowCount-1] = "";
        data_grid->Cells[3][data_grid->RowCount-1] = "";
	}
}


//---------------------------------------------------------------------------
// Разблокировка кнопок меню

void TmainForm::enableResult()
{
	menu_run->Enabled = true;
	menu_runA->Enabled = true;
	menu_runB->Enabled = true;
}

void TmainForm::enableSearch()
{
	menu_search->Enabled = true;
}


//---------------------------------------------------------------------------
// Обработка всплывающих окон

void __fastcall TmainForm::popup_editClick(TObject *Sender)
{
	auto pos = data_grid->Row;
	if(pos >= zooData.size())
		addZooData();
	else
		editZooData(StrToUInt(data_grid->Cells[3][pos]));
}

void __fastcall TmainForm::popup_removeClick(TObject *Sender)
{
	if(data_grid->Row == data_grid->RowCount - 1)
		MessageBeep(0);
	else
		removeZoo(StrToUInt(data_grid->Cells[3][data_grid->Row]));
}


//---------------------------------------------------------------------------
// Обслуживание кнопок главного меню. Раздел "файл"

void __fastcall TmainForm::menu_saveClick(TObject *Sender)
{
	try{zooData.print("C:\\Users\\iliat\\Desktop\\data.txt"); }
	catch(...){MessageBeep(0); }
}

void __fastcall TmainForm::menu_loadClick(TObject *Sender)
{
	try
	{
		zooData.load("C:\\Users\\iliat\\Desktop\\data.txt");
		printData();
	}
	catch(...){MessageBeep(0); }
}

void __fastcall TmainForm::menu_clearClick(TObject *Sender)
{
	zooData.clear();
	printData();
}

void __fastcall TmainForm::menu_exitClick(TObject *Sender)
{
	Close();
}


//---------------------------------------------------------------------------
// Обслуживание кнопок главного меню. Раздел "правка"

void __fastcall TmainForm::menu_editClick(TObject *Sender)
{
	TMenuItem* temp = (TMenuItem*)Sender;
	switch(temp->Tag)
	{
		case 0: addZooData(); break;
		case 1: popup_editClick(nullptr); break;
		case 2: popup_removeClick(nullptr); break;
		default: break;
	}
}

void __fastcall TmainForm::menu_showKeysClick(TObject *Sender)
{
	if (data_grid->ColCount == 4)
	{
		menu_showKeys->Caption = "Показать ключи";
		lbl_headerKey->Caption = "";
		data_grid->ColCount = 3;
	}
	else
	{
		menu_showKeys->Caption = "Скрыть ключи";
		lbl_headerKey->Caption = "Ключ";
        data_grid->ColCount = 4;
    }
}


//---------------------------------------------------------------------------
// Обслуживание кнопок главного меню. Раздел "запуск"

void __fastcall TmainForm::menu_runAClick(TObject *Sender)
{
	menu_run->Enabled = false;
	ZooList result = collect_maxSpicies(zooData);
	TformResult* form = new TformResult(this, result, "Максимальные элементы");
	form->Show();
}

void __fastcall TmainForm::menu_runBClick(TObject *Sender)
{
	TformNumEntry* entry = new TformNumEntry(this);
	if(entry->ShowModal() == mrOk)
	{
		menu_run->Enabled = false;
		ZooList result = collect_raresLessThan(zooData, rareSpiciesRate);
		TformResult* form = new TformResult(this, result,
			"Доля редких менeе " + FloatToStr(floor(rareSpiciesRate*1000)/1000));
		form->Show();
	}
}


//---------------------------------------------------------------------------
// Обслуживание кнопок главного меню. Раздел "о программе"

void __fastcall TmainForm::menu_aboutClick(TObject *Sender)
{
	TAboutBox* form = new TAboutBox(this);
    form->ShowModal();
}


//---------------------------------------------------------------------------
// Обслуживание кнопок главного меню. Раздел "поиск"

void __fastcall TmainForm::menu_searchClick(TObject *Sender)
{
    menu_search->Enabled = false;
	TsearchForm* form = new TsearchForm(this, zooData);
	form->Show();
}


//---------------------------------------------------------------------------
// Нажатие клавиш

void __fastcall TmainForm::data_gridKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
	switch(Key)
	{
	case vkReturn:
		popup_editClick(nullptr);
		break;
	case vkDelete:
		popup_removeClick(nullptr);
		break;
	case vkF1:
		for(int i = 1; i < 100000; i++)
			zooData.add("Zoo#"+IntToStr(int(i)), i, i);
		printData();
        break;
	default: break;
	}
}
//---------------------------------------------------------------------------

