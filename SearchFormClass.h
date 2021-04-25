//---------------------------------------------------------------------------

#ifndef SearchFormClassH
#define SearchFormClassH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

#include "ResultFormClass.h"
#include "MainFormClass.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TformResult;
class TmainForm;

class TsearchForm : public TForm
{
__published:	// IDE-managed Components
	TGridPanel *gridPanel_main;
	TGroupBox *groupBox_right;
	TButton *btn_ok;
	TButton *btn_cancel;
	TGridPanel *grdPanel_right;
	TLabel *lbl_id;
	TEdit *txt_key;
	TEdit *txt_name;
	TLabel *lbl_name;
	TLabel *lbl_spicies;
	TEdit *txt_spicies;
	TLabel *lbl_rare;
	TEdit *txt_rare;
	TGridPanel *gridPanel_left;
	TGroupBox *groupBox_left;
	TEdit *txt_resultCount;
	TCheckBox *radio_allResults;
	TRadioGroup *group_searchMode;
	void __fastcall btn_okClick(TObject *Sender);
	void __fastcall btn_cancelClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall radio_allResultsClick(TObject *Sender);
private:	// User declarations
	ZooList initialData;
	TmainForm* parent;
public:		// User declarations
	__fastcall TsearchForm(TmainForm* Owner, ZooList& data);
};
//---------------------------------------------------------------------------
extern PACKAGE TsearchForm *searchForm;
//---------------------------------------------------------------------------
#endif
