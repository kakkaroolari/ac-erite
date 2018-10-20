/**
 * @file Implements the "Find element by GUID" command.
 */

#include "Ville_Test.hpp"

#include "JsonSelectDialog.hpp"
//#include "BFSTreeSelector.hpp"
//#include "DatabaseGraph.hpp"
#include	"DGFileDialog.hpp"
#include "Tracer.h"
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
	selectFile   	(GetReference (), SelectFileId),
	guidStaticText	(GetReference (), GuidStaticTextId),
	guidEdit		(GetReference (), GuidEditId),
	separator		(GetReference (), SeparatorId)
{
	//Attach (*this);
	okButton.Attach (*this);
	cancelButton.Attach(*this);
	selectFile.Attach (*this);

	//FillDatabasePopup ();
}

JsonSelectDialog::~JsonSelectDialog ()
{
	okButton.Detach (*this);
	cancelButton.Detach (*this);
	selectFile.Detach(*this);
	//Detach (*this);
}


void JsonSelectDialog::ButtonClicked (const DG::ButtonClickEvent& ev)
{
	if (ev.GetSource () == &okButton) {
		// TODO: run it
		PostCloseRequest (DG::ModalDialog::Accept);
	} else if (ev.GetSource () == &cancelButton) {
		PostCloseRequest (DG::ModalDialog::Cancel);
	} else if (ev.GetSource() == &selectFile) {
		IO::Location jsonFileLoc;
		if (!GetOpenFile(&jsonFileLoc, "json", "*.json"))
		{
			// TODO: error not found
			return;
		}
		IO::Name	jsonName;
		jsonFileLoc.GetLastLocalName(&jsonName);
		guidEdit.SetText(jsonName);
		// debug stuff..
		IO::URL url;
		jsonFileLoc.ToURL(&url);
		char str[512] = { 0 };
		CHTruncate((const char*)url, str, sizeof(str));
		Tracer::_trace("Open JSON from: %s", str);
	}
}


// -----------------------------------------------------------------------------
// Open the selected JSON file
// -----------------------------------------------------------------------------
bool	JsonSelectDialog::GetOpenFile(IO::Location*	dloc, const char* fileExtensions, const GS::UniString& filterText)
{
	if (dloc == nullptr)
		return false;

	FTM::TypeID	retID;
	FTM::FileTypeManager	ftman("MyManager");
	FTM::FileType			type(nullptr, fileExtensions, 0, 0, 0);
	FTM::TypeID				id = FTM::FileTypeManager::SearchForType(type);
	if (id == FTM::UnknownType)
		id = ftman.AddType(type);

	DG::FileDialog	dlg(DG::FileDialog::OpenFile);			// Open only 1 file
	UIndex	i = dlg.AddFilter(id, DG::FileDialog::DisplayExtensions);	// Force it on mac...
	dlg.SetFilterText(i, filterText);

	if (!dlg.Invoke())
		return false;

	*dloc = dlg.GetSelectedFile();
	return true;
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

