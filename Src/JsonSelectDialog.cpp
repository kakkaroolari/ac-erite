/**
 * @file Implements the "Find element by GUID" command.
 */

#include "Ville_Test.hpp"

#include "JsonSelectDialog.hpp"
//#include "BFSTreeSelector.hpp"
//#include "DatabaseGraph.hpp"
#include <math.h>

#if defined (_MSC_VER)
	#define snprintf _snprintf
#else
	// MSL and BSD Has snprintf, and vsnprintf in :: scope
#endif

JsonSelectDialog::JsonSelectDialog () :
	DG::ModalDialog (ACAPI_GetOwnResModule (), dialogResId, InvalidResModule),

	okButton		(GetReference (), OkButtonId),
	cancelButton	(GetReference (), CancelButtonId),
	databasePopup	(GetReference (), DatabasePopupId),
	guidStaticText	(GetReference (), GuidStaticTextId),
	guidEdit		(GetReference (), GuidEditId),
	separator		(GetReference (), SeparatorId)
{
	//Attach (*this);
	okButton.Attach (*this);
	cancelButton.Attach (*this);

	//FillDatabasePopup ();
}

JsonSelectDialog::~JsonSelectDialog ()
{
	okButton.Detach (*this);
	cancelButton.Detach (*this);
	//Detach (*this);
}


void JsonSelectDialog::ButtonClicked (const DG::ButtonClickEvent& ev)
{
	if (ev.GetSource () == &okButton) {
		PostCloseRequest (DG::ModalDialog::Accept);
	} else if (ev.GetSource () == &cancelButton) {
		PostCloseRequest (DG::ModalDialog::Cancel);
	}
}


//void JsonSelectDialog::PanelClosed (const DG::PanelCloseEvent& ev)
//{
//	if (ev.IsAccepted ()) {
//
//	}
//}


/**
* Open purulaatikko dialog
* @return error code if fails.
*/
GSErrCode JsonSelectDialog::CreatePurulaatikkoFromJson(void)
{
	GSErrCode                   err           = NoError;
	//	get the unique ID from the user
	JsonSelectDialog jsonDialog;
	jsonDialog.Invoke();

	return err;
}

