//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "NumberEntryFormClass.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformNumEntry *formNumEntry;
//---------------------------------------------------------------------------
__fastcall TformNumEntry::TformNumEntry(TmainForm* Owner)
	: TForm(Owner), parent(Owner), min(0.0), max(1.0)
{}
//---------------------------------------------------------------------------

void __fastcall TformNumEntry::btn_okClick(TObject *Sender)
{
	 try
	 {
		float number = StrToFloat(txt_number->Text);

		if(number < min || number > max)
			MessageBeep(0);
		else
		{
			parent->rareSpiciesRate = number;
			ModalResult = mrOk;
		}
	 }
	 catch(...)
	 {
		MessageBeep(0);
	 }
}
//---------------------------------------------------------------------------
