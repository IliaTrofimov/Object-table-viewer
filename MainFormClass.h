//---------------------------------------------------------------------------

#ifndef MainFormClassH
#define MainFormClassH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.WinXCtrls.hpp>
#include <algorithm>
#include <string>

#include "Zoo.h"
#include "ABOUT.h"
#include "EditFormClass.h"
#include "SearchFormClass.h"
#include "ResultFormClass.h"
#include "NumberEntryFormClass.h"
//---------------------------------------------------------------------------
class TformEdit;
class TformResult;
class TformNumEntry;
class TsearchForm;
class TAboutBox;

class TmainForm : public TForm
{
friend TformNumEntry;

__published:	// IDE-managed Components
	TPopupMenu *popup_grid;
	TMenuItem *popup_edit;
	TMenuItem *popup_remove;
	TStringGrid *data_grid;
	TMainMenu *main_menu;
	TMenuItem *menu_file;
	TMenuItem *menu_clear;
	TMenuItem *menu_save;
	TMenuItem *menu_load;
	TMenuItem *menu_exit;
	TMenuItem *menu_edit;
	TMenuItem *menu_about;
	TStatusBar *statusBar;
	TMenuItem *menu_add;
	TMenuItem *menu_editElem;
	TMenuItem *menu_run;
	TMenuItem *menu_runA;
	TMenuItem *menu_runB;
	TMenuItem *menu_search;
	TGridPanel *header_grid;
	TLabel *lbl_headerName;
	TLabel *lbl_headerSpicies;
	TLabel *lbl_headerRare;
	TMenuItem *menu_showKeys;
	TLabel *lbl_headerKey;
	TMenuItem *menu_remove;

	void __fastcall popup_editClick(TObject *Sender);
	void __fastcall menu_clearClick(TObject *Sender);
	void __fastcall menu_exitClick(TObject *Sender);
	void __fastcall menu_editClick(TObject *Sender);
	void __fastcall menu_runAClick(TObject *Sender);
	void __fastcall menu_runBClick(TObject *Sender);
	void __fastcall popup_removeClick(TObject *Sender);
	void __fastcall menu_saveClick(TObject *Sender);
	void __fastcall menu_loadClick(TObject *Sender);
	void __fastcall menu_aboutClick(TObject *Sender);
	void __fastcall menu_showKeysClick(TObject *Sender);
	void __fastcall menu_searchClick(TObject *Sender);
	void __fastcall data_gridKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);

protected:	// User declarations
	ZooList zooData;
	void printData();
	void printOneItem(ZooPair z);
	void editZooData(uint32_t key);
	void addZooData();
	void removeZoo(uint32_t key);
	float rareSpiciesRate;
public:		// User declarations
	__fastcall TmainForm(TComponent* Owner);
	void enableResult();
    void enableSearch();
};
//---------------------------------------------------------------------------
extern PACKAGE TmainForm *mainForm;
//---------------------------------------------------------------------------
#endif
