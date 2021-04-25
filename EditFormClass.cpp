//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EditFormClass.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformEdit *formEdit;

//---------------------------------------------------------------------------
// Конструктор класса

__fastcall TformEdit::TformEdit(TComponent* Owner, ZooPair* zoo, bool editMode)
	: TForm(Owner), currentZooItem(zoo)
{
	if(editMode)
	{
		txt_spicies->Text = currentZooItem->second.spiciesCount;
		txt_rare->Text = currentZooItem->second.rareCount;
		txt_name->Text = currentZooItem->second.name;
		lbl_idValue->Caption = currentZooItem->first;
	}
	else
	{
        this->Caption = "Новый элемент";
    }
}


//---------------------------------------------------------------------------
// Обработка нажатия на "OK"

void __fastcall TformEdit::btn_okClick(TObject *Sender)
{
	if(txt_name->Text == "")
		MessageBeep(0);
	else
	{
		try
		{
			int spicies = StrToInt(txt_spicies->Text);
			int rare = StrToInt(txt_rare->Text);

			if(spicies >= 0 && rare >= 0 && rare <= spicies)
			{
				currentZooItem->second.spiciesCount = spicies;
				currentZooItem->second.rareCount = rare;
				currentZooItem->second.name = txt_name->Text;
				currentZooItem->first = currentZooItem->second.hash();
				ModalResult = mrOk;
			}
			else
				MessageBeep(0);
		}
		catch(...)
		{
			MessageBeep(0);
		}
	}
}


//---------------------------------------------------------------------------
// Обработка нажатия на "Cancel"

void __fastcall TformEdit::btn_cancelClick(TObject *Sender)
{
	Close();
}
