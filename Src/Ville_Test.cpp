// *****************************************************************************
// Source code for the Panel Test Add-On
// API Development Kit 21; Mac/Win
//
// Namespaces:			Contact person:
//	PanelTest
//
// [SG compatible] - Yes
// *****************************************************************************

// --- Includes ----------------------------------------------------------------

#include "APIEnvir.h"
#include "ACAPinc.h"
#include "APIdefs.h"
#include "Tracer.h"

#include "Ville_Test_Resource.h"
#include "Panels.hpp"
#include "JsonSelectDialog.hpp"
#include "SettingsHandler.hpp"

#include "DGModule.hpp"

// -----------------------------------------------------------------------------
//
// Global variables and definitions
//
// -----------------------------------------------------------------------------

using namespace PanelTest;


//TestSettingsPanel*	settingsPanel  = nullptr;
//TestAttributePanel*	attributePanel = nullptr;
//TestInfoBoxPanel*	infoBoxPanel   = nullptr;
//TestSettingsHandler* settingsHandler = nullptr;


enum {
	//FILE_TYPE_MENU_ID = 32500,

	CREATE_PURULAATIKKO_MENU_ID = 32501,
	CREATE_PURULAATIKKO_MENU_HELP_ID = 32502
};

//int	registrationSuccess = 0;



// -----------------------------------------------------------------------------
//
// Required functions
//
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Dependency definitions
// -----------------------------------------------------------------------------

API_AddonType	__ACENV_CALL	CheckEnvironment (API_EnvirParams* envir)
{
	RSGetIndString (&envir->addOnInfo.name, 32000, 1, ACAPI_GetOwnResModule ());
	RSGetIndString (&envir->addOnInfo.description, 32000, 2, ACAPI_GetOwnResModule ());

	return APIAddon_Preload;
}


// -----------------------------------------------------------------------------
// Interface definitions
// -----------------------------------------------------------------------------

GSErrCode	__ACENV_CALL	RegisterInterface (void)
{
	//
	// Register a file type
	//
	//GSErrCode err = ACAPI_Register_FileType(1, 'TEXT', 0, "wwo", 0, FILE_TYPE_MENU_ID, 1, SaveAs2DSupported);

	//if (err == NoError) {
	GSErrCode err = ACAPI_Register_Menu(CREATE_PURULAATIKKO_MENU_ID, CREATE_PURULAATIKKO_MENU_HELP_ID, MenuCode_Extras, MenuFlag_SeparatorBefore);
	//}

	return err;
}


/**
* Menu command: "Create from Json"
*
* @return ARCHICAD error code.
*/
GSErrCode	__ACENV_CALL	MenuHandler(const API_MenuParams *menuParams)
{
	GSErrCode err = NoError;

	if (menuParams->menuItemRef.menuResID == CREATE_PURULAATIKKO_MENU_ID)
		err = JsonSelectDialog::CreatePurulaatikkoFromJson();
	Tracer::_trace("CreatePurulaatikkoFromJson err: %d", (int)err);

	return err;
}


/**
* Called after the Add-On has been loaded into memory. Function name is fixed.
*
* @return ARCHICAD error code.
*/
GSErrCode __ACENV_CALL	Initialize(void)
{
	//GSErrCode err = ACAPI_Install_FileTypeHandler(1, IOCommandHandler);

	//if (err == NoError) {
		GSErrCode err = ACAPI_Install_MenuHandler(CREATE_PURULAATIKKO_MENU_ID, MenuHandler);
	//}

	return err;
}		// Initialize ()

// -----------------------------------------------------------------------------
// Called when the Add-On is going to be unloaded
// -----------------------------------------------------------------------------

GSErrCode	__ACENV_CALL FreeData	(void)
{
	return NoError;
}		// FreeData ()
