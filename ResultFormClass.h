//---------------------------------------------------------------------------

#ifndef ResultFormClassH
#define ResultFormClassH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "MainFormClass.h"
#include "Zoo.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>

//---------------------------------------------------------------------------
class TmainForm;

class TformResult : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *data_grid;
	TStatusBar *statusBar;
	TMainMenu *main_menu;
	TMenuItem *menu_file;
	TMenuItem *menu_save;
	TMenuItem *menu_exit;
	TMenuItem *menu_showKeys;
	TGridPanel *header_grid;
	TLabel *lbl_headerName;
	TLabel *lbl_headerSpicies;
	TLabel *lbl_headerRare;
	TLabel *lbl_headerKey;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall menu_saveClick(TObject *Sender);
	void __fastcall menu_exitClick(TObject *Sender);
	void __fastcall menu_showKeysClick(TObject *Sender);
private:	// User declarations
	ZooList* zooData;
	TmainForm* parent;
	void printData();
public:		// User declarations
	__fastcall TformResult(TmainForm* Owner, ZooList& zl, UnicodeString title = "");
};
//---------------------------------------------------------------------------
extern PACKAGE TformResult *formResult;
//---------------------------------------------------------------------------
#endif
