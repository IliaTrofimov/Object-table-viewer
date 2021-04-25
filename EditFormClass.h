//---------------------------------------------------------------------------

#ifndef EditFormClassH
#define EditFormClassH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Zoo.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TformEdit : public TForm
{
__published:	// IDE-managed Components
	TButton *btn_ok;
	TButton *btn_cancel;
	TGridPanel *panel_grd;
	TLabel *lbl_name;
	TLabel *lbl_spicies;
	TLabel *lbl_rare;
	TEdit *txt_name;
	TEdit *txt_spicies;
	TEdit *txt_rare;
	TLabel *lbl_idValue;
	TLabel *lbl_id;
	void __fastcall btn_okClick(TObject *Sender);
	void __fastcall btn_cancelClick(TObject *Sender);
private:	// User declarations
	ZooPair* currentZooItem;
public:		// User declarations
	__fastcall TformEdit(TComponent* Owner, ZooPair* zoo, bool editMode = true);
};
//---------------------------------------------------------------------------
extern PACKAGE TformEdit *formEdit;
//---------------------------------------------------------------------------
#endif
