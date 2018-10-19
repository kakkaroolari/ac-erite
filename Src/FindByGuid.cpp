/**
 * @file Implements the "Find element by GUID" command.
 */

#include "Ville_Test.hpp"

#include "FindByGuid.hpp"
//#include "BFSTreeSelector.hpp"
//#include "DatabaseGraph.hpp"
#include <math.h>

#if defined (_MSC_VER)
	#define snprintf _snprintf
#else
	// MSL and BSD Has snprintf, and vsnprintf in :: scope
#endif

FindDialog::FindDialog (const GS::Array<API_DatabaseInfo>& inDbList, ULong& inDbIndex, API_Guid& inRequestedGuid) :
	DG::ModalDialog (ACAPI_GetOwnResModule (), dialogResId, InvalidResModule),

	databaseList	(inDbList),
	databaseIndex	(inDbIndex),
	requestedGuid	(inRequestedGuid),

	okButton		(GetReference (), OkButtonId),
	cancelButton	(GetReference (), CancelButtonId),
	databasePopup	(GetReference (), DatabasePopupId),
	guidStaticText	(GetReference (), GuidStaticTextId),
	guidEdit		(GetReference (), GuidEditId),
	separator		(GetReference (), SeparatorId)
{
	Attach (*this);
	okButton.Attach (*this);
	cancelButton.Attach (*this);

	FillDatabasePopup ();
}

FindDialog::~FindDialog ()
{
	okButton.Detach (*this);
	cancelButton.Detach (*this);
	Detach (*this);
}

void FindDialog::FillDatabasePopup ()
{
	short       floorplanIndex = 0;
	UInt32		dbCount = databaseList.GetSize ();

	databasePopup.DeleteItem (DG::PopUp::AllItems);
	for (unsigned short index = 0; index < dbCount; index++) {
		databasePopup.AppendItem ();

		GS::UniString bufUstr = RSGetIndString (32505, databaseList[index].typeID + 1, ACAPI_GetOwnResModule ()) +
								" " + APIGuidToString (databaseList[index].databaseUnId.elemSetId) +
								" " + GS::UniString (databaseList[index].title);

		databasePopup.SetItemText (DG::PopUp::BottomItem, bufUstr);
		databasePopup.SetItemValue (DG::PopUp::BottomItem, index);

		if (databaseList[index].typeID == APIWind_FloorPlanID) {
			floorplanIndex = index;
		}
	}
	databasePopup.SelectItem (floorplanIndex + 1);
}

void FindDialog::ButtonClicked (const DG::ButtonClickEvent& ev)
{
	if (ev.GetSource () == &okButton) {
		PostCloseRequest (DG::ModalDialog::Accept);
	} else if (ev.GetSource () == &cancelButton) {
		PostCloseRequest (DG::ModalDialog::Cancel);
	}
}


void FindDialog::PanelClosed (const DG::PanelCloseEvent& ev)
{
	if (ev.IsAccepted ()) {
		databaseIndex = TruncateTo32Bit (databasePopup.GetItemValue (databasePopup.GetSelectedItem ()));

		GS::Guid guid;
		if (guid.ConvertFromString (guidEdit.GetText ()) == NoError) {
			requestedGuid = GSGuid2APIGuid (guid);
		} else {
			requestedGuid = APINULLGuid;
		}
	}
}


/**
* Finds an element by its GUID.
* Switches to the database, selects the element, and zooms to it.
* @return error code if fails.
*/
GSErrCode FindDialog::CreatePurulaatikkoFromJson(void)
{
	GSErrCode                   err           = NoError;

	return err;
}

