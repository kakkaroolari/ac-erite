#ifndef __CREATEBYJSON_HPP__
#define __CREATEBYJSON_HPP__

/**
 * @file Implements the "Find element by unique ID" command.
 */

#include "DGDialog.hpp"
#include "DGButton.hpp"
#include "DGPopUp.hpp"
#include "DGStaticItem.hpp"
#include "DGEditControl.hpp"
#include "APIdefs_Database.h"
#include "APIdefs_Elements.h"

// predeclarations
namespace GS {
	template <class Type>
	class Array;
}

/**
* Purulaatikko dialog
* Open json file selector
*/

class JsonSelectDialog : public DG::ModalDialog,
				   public DG::ButtonItemObserver
{
private:
	enum {
		OkButtonId		 = 1,
		CancelButtonId	 = 2,
		DatabasePopupId	 = 3,
		GuidStaticTextId = 4,
		GuidEditId		 = 5,
		SeparatorId		 = 6
	};

private:
	static const short					dialogResId = 32501;

	DG::Button							okButton;
	DG::Button							cancelButton;
	DG::PopUp							databasePopup;
	DG::LeftText						guidStaticText;
	DG::TextEdit						guidEdit;
	DG::Separator						separator;

	//const GS::Array<API_DatabaseInfo>&	databaseList;
	//ULong&								databaseIndex;
	//API_Guid&							requestedGuid;

private:
	JsonSelectDialog& operator= (const JsonSelectDialog&);	//disabled

	//void FillDatabasePopup ();

protected:
	virtual void	ButtonClicked (const DG::ButtonClickEvent& ev) override;

public:
	JsonSelectDialog ();
	~JsonSelectDialog ();

	static GSErrCode  CreatePurulaatikkoFromJson(void);
    //static GSErrCode  SelectAndZoom  (API_DatabaseInfo homeDB, const API_Guid& requestedGuid);
};

#endif // __CREATEBYJSON_HPP__
