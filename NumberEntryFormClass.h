//---------------------------------------------------------------------------

#ifndef NumberEntryFormClassH
#define NumberEntryFormClassH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "MainFormClass.h"
//---------------------------------------------------------------------------
class TmainForm;

class TformNumEntry : public TForm
{
__published:	// IDE-managed Components
	TEdit *txt_number;
	TButton *btn_ok;
	void __fastcall btn_okClick(TObject *Sender);
private:	// User declarations
	TmainForm* parent;
public:		// User declarations
	__fastcall TformNumEntry(TmainForm* Owner);
	float min, max;
};
//---------------------------------------------------------------------------
extern PACKAGE TformNumEntry *formNumEntry;
//---------------------------------------------------------------------------
#endif
