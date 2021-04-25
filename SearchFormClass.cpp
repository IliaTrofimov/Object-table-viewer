//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SearchFormClass.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TsearchForm *searchForm;
//---------------------------------------------------------------------------
__fastcall TsearchForm::TsearchForm(TmainForm* Owner, ZooList& data)
	: TForm(Owner), initialData(data)
{
	parent = Owner;
}

//---------------------------------------------------------------------------
// Обработка нажатия на "OK"

void __fastcall TsearchForm::btn_okClick(TObject *Sender)
{
	try
	{
		long spicies =
			(txt_spicies->Text != "") ? StrToUInt(txt_spicies->Text) : -1;
		long rare =
			(txt_rare->Text != "") ? StrToUInt(txt_rare->Text) : -1;
		UnicodeString name =
			(txt_name->Text != "") ? txt_name->Text : "";
		long key =
			(txt_key->Text != "") ? StrToUInt(txt_key->Text) : -1;
		int results =
			(radio_allResults->Checked || txt_resultCount->Text == "") ? -1
			: StrToUInt(txt_resultCount->Text);

		ZooList searchResult = (group_searchMode->ItemIndex == 0) ?
			initialData.select_and(results, name, spicies, rare) :
			initialData.select_or(results, name, spicies, rare);

		if(key != -1)
			searchResult.insert(ZooPair(key, initialData[key]));

		UnicodeString title = "Выборка: ";
		if(name != "") title += name + "; ";
		if(spicies != -1) title += "видов " + IntToStr(int(spicies)) + "; ";
		if(rare != -1) title += "редких " + IntToStr(int(rare)) + "; ";
		if(key != -1) title += "ключ " + IntToStr(int(key)) + "; ";

		if(searchResult.size() == 0)
            MessageBeep(0);

		TformResult* form = new TformResult(parent, searchResult, title);
		form->ShowModal();
	}
	catch(...)
	{
		MessageBeep(0);
	}
}


//---------------------------------------------------------------------------
// Обработка нажатия на "Cancel"

void __fastcall TsearchForm::btn_cancelClick(TObject *Sender)
{
	Close();
}


///---------------------------------------------------------------------------
// Обработка закрытия окна

void __fastcall TsearchForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	parent->enableSearch();
}

//---------------------------------------------------------------------------
// Обработка радио кнопки

void __fastcall TsearchForm::radio_allResultsClick(TObject *Sender)
{
	txt_resultCount->Enabled = !radio_allResults->Checked;
}

//---------------------------------------------------------------------------

