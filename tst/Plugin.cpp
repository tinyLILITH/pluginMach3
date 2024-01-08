//=====================================================================
//
//	Plugin.cpp - the optional custom part of the plugin
//
//	this source file can be filled with the actual custom code that
//	makes the plugin work. it is the choice of the developer to enable
//	which functions will be used from the available MachDevice calls.
//
//	if this is a mixed mode dll each function can be declared as either
//	an unmanaged or managed function.
//
//	please see the documentation in Plugin.h for the #define stateInputments
//	that control each functions compilation.
//
//	if this is a mixed mode dll and you need to keep global managed
//	reference please see the MG class in ManagedGlobal.h
//
//	please read the notes and comments in MachDevice.cpp for general
//	information and disclaimers.
//
//=====================================================================

#include "stdafx.h"
#include "Plugin.h"
#include "MachDevice.h"
#include "ConfigDialog.h"
#include "PlugInControlDialog.h"
#include "XMLNetProfile.h"
#include "ManagedGlobal.h"
#include <stdlib.h>
#include <windows.h>


//---------------------------------------------------------------------
//	the default namespace for managed functions and classes
//---------------------------------------------------------------------

using namespace tst;

//---------------------------------------------------------------------
//	data area
//---------------------------------------------------------------------
int menuStart;



//Автоматический опрос COM порта
void ComPooling(){
PlugInControlDialog^ pluginControlDialog = MG::pluginControlDialog;

  pluginControlDialog -> _mach = (IMach4^) Marshal::GetActiveObject("Mach4.Document");
  pluginControlDialog ->_mInst = (IMyScriptObject^) pluginControlDialog -> _mach->GetScriptDispatch();
 array<String^> ^AvailableSerialPorts;
	 array<unsigned char> ^aTemp;
	 String ^sTemp;
	 try{
		AvailableSerialPorts = pluginControlDialog->Serial->GetPortNames();
		for(int Count = 0; Count < AvailableSerialPorts->Length; Count++)
		{
			sTemp = AvailableSerialPorts[Count];

			pluginControlDialog->Serial->PortName = sTemp;

			
			pluginControlDialog->Serial->Open();

				 if (pluginControlDialog->Serial->IsOpen){

					pluginControlDialog->Serial->WriteLine("?RDY$");
						
					if (pluginControlDialog->Serial->ReadTo("$") == "!OK"){

							pluginControlDialog->_mInst->SetUserLED(1234,1);
							pluginControlDialog->actualStatus->Text = sTemp;
							//pluginControlDialog->Serial->Close();
							//break;
							pluginControlDialog->listBox1->Items->Add(sTemp + "ВЕРНО");
					}
		
					else{
						pluginControlDialog->listBox1->Items->Add(sTemp + "неверно");
						pluginControlDialog->Serial->Close();
					}
				 }
			}

		}
	 			catch(System::Exception^ e)
				{
					// Обработка исключений
				}
}

//---------------------------------------------------------------------
//
//	piInitControl() - Plugin extension of InitControl()
//
//		XML file can NOT be accessed since SetProName hasn't
//		been called yet
//
//		called EVEN if plugin is disabled
//
//---------------------------------------------------------------------

#ifdef PI_INITCONTROL
#ifdef _MANAGED
#pragma PI_MIX_INITCONTROL
#endif
bool piInitControl() {
  menuStart = GetMenuRange(MENU_COUNT);

  return true;
}
#endif

//---------------------------------------------------------------------
//
//	piSetProName() - Plugin extension of SetProName()
//
//		XML file CAN be accessed
//
//		called EVEN if plugin is disabled
//
//---------------------------------------------------------------------

#ifdef PI_SETPRONAME
#ifdef _MANAGED
#pragma PI_MIX_SETPRONAME
#endif
char * piSetProName(LPCSTR name) {
  XMLNetProfile ^ profile = gcnew XMLNetProfile(gcnew String(ProfileName), "tstPlugin", true);

  profile -> Load();

  return "Revolver Tool Holder test plugin";
}
#endif

//---------------------------------------------------------------------
//
//	piPostInitControl() - Plugin extension of PostInitControl()
//
//		XML file can NOT be accessed
//
//		called ONLY if plugin is enabled
//
//---------------------------------------------------------------------

#ifdef PI_POSTINITCONTROL
#ifdef _MANAGED
#pragma PI_MIX_POSTINITCONTROL
#endif
void piPostInitControl() {



  PlugInControlDialog ^ pluginControlDialog = gcnew PlugInControlDialog();
  ConfigDialog ^ configDialog = gcnew ConfigDialog();


  pluginControlDialog -> _mach = (IMach4^) Marshal::GetActiveObject("Mach4.Document");
  pluginControlDialog ->_mInst = (IMyScriptObject^) pluginControlDialog -> _mach->GetScriptDispatch();

  // Store a reference to the form in the ManagedGlobal class for later use
  MG::pluginControlDialog = pluginControlDialog;
  MG::configDialog = configDialog;

  HMENU hMachMenu = GetMenu(MachView -> MachFrame -> m_hWnd);
  HMENU hPluginMenu = 0;
  int machMenuCnt = GetMenuItemCount(hMachMenu);
  MENUITEMINFO mii;
  LPTSTR txt;

  for (int i = 0; i < machMenuCnt; i++) {
    mii.cbSize = sizeof(MENUITEMINFO);
    mii.fMask = MIIM_FTYPE | MIIM_ID | MIIM_SUBMENU | MIIM_STRING;
    mii.dwTypeData = NULL;

    if (GetMenuItemInfo(hMachMenu, i, true, & mii)) {
      txt = (LPTSTR) malloc(++mii.cch);
      mii.dwTypeData = txt;

      if (GetMenuItemInfo(hMachMenu, i, true, & mii)) {
        if (strcmp(txt, "PlugIn Control") == 0) {
          hPluginMenu = mii.hSubMenu;
          i = machMenuCnt;
        }
      }

      free(txt);
    }

    if (hPluginMenu) {
      InsertMenu(hPluginMenu, -1, MF_BYPOSITION, menuStart, "tst");
    }
  }
  pluginControlDialog -> Show();
  ComPooling();


}
#endif

//---------------------------------------------------------------------
//
//	piConfig() - Plugin extension of Config()
//
//		called if user presses CONFIG in Config|Config Plugins
//		even if plugin is disabled
//
//		XML file CAN be accessed
//
//---------------------------------------------------------------------

#ifdef PI_CONFIG
#ifdef _MANAGED
#pragma PI_MIX_CONFIG
#endif
void piConfig() {
  ConfigDialog ^ configDialog = gcnew ConfigDialog();

  configDialog -> ShowDialog();
}
#endif

//---------------------------------------------------------------------
//
//	piStopPlug() - Plugin extension of StopPlug()
//
//---------------------------------------------------------------------

#ifdef PI_STOPPLUG
#ifdef _MANAGED
#pragma PI_MIX_STOPPLUG
#endif
void piStopPlug() {
 PlugInControlDialog ^ pluginControlDialog = gcnew PlugInControlDialog();
   pluginControlDialog -> _mach = (IMach4^) Marshal::GetActiveObject("Mach4.Document");
  pluginControlDialog ->_mInst = (IMyScriptObject^) pluginControlDialog -> _mach->GetScriptDispatch();

  XMLNetProfile ^ profile = gcnew XMLNetProfile(gcnew String(ProfileName), "RevolverTool test plugin", true);

  if (profile -> Load()) {

    profile -> Save();

  }
 pluginControlDialog->Serial->Close();
 pluginControlDialog->_mInst->SetUserLED(1234,0);

}
#endif

//---------------------------------------------------------------------
//
//	piUpdate() - Plugin extension of Update()
//
//		XML file can NOT be accessed
//
//		called ONLY if plugin is enabled
//
//		WARNING - when you enable a plugin it immediately is added
//		to the update loop. if you haven't initialized some items
//		because PostInitControl() hasn't been called you can get
//		some problems!!!
//
//---------------------------------------------------------------------

#ifdef PI_UPDATE
#ifdef _MANAGED
#pragma PI_MIX_UPDATE
#endif
  
void piUpdate() {
}

#endif

//---------------------------------------------------------------------
//
//	piNotify() - Plugin extension of Notify()
//
//		among other notices this is where we are notified when the
//		user clicks on our 'PlugIn Control' menu item.
//
//		XML file CAN be accessed on a menu item notify
//
//---------------------------------------------------------------------

#ifdef PI_NOTIFY
#ifdef _MANAGED
#pragma PI_MIX_NOTIFY
#endif
void piNotify(int id) {
  if (id == menuStart) {
    PlugInControlDialog ^ pluginControlDialog = gcnew PlugInControlDialog();

    //	xyzDemoConfig->enableDlg = MG::xyzDemoDialog->Visible;

    //вызов немодального окна
    pluginControlDialog -> Show();
	
  }
}
#endif

//---------------------------------------------------------------------
//
//	piDoDwell() - Plugin extension of DoDwell()
//
//---------------------------------------------------------------------

#ifdef PI_DODWELL
#ifdef _MANAGED
#pragma PI_MIX_DODWELL
#endif
void piDoDwell(double time) {

}
#endif

//---------------------------------------------------------------------
//
//	piReset() - Plugin extension of Reset()
//
//---------------------------------------------------------------------

#ifdef PI_RESET
#ifdef _MANAGED
#pragma PI_MIX_RESET
#endif

// Ф-я исполняется когда нажимаешь reset
void piReset() {

}
#endif

//---------------------------------------------------------------------
//
//	piJogOn() - Plugin extension of JogOn()
//
//---------------------------------------------------------------------

#ifdef PI_JOGON
#ifdef _MANAGED
#pragma PI_MIX_JOGON
#endif
void piJogOn(short axis, short dir, double speed) {

}

#endif

//---------------------------------------------------------------------
//
//	piJogOff() - Plugin extension of JogOff()
//
//---------------------------------------------------------------------

#ifdef PI_JOGOFF
#ifdef _MANAGED
#pragma PI_MIX_JOGOFF
#endif
void piJogOff(short axis) {}
#endif

//---------------------------------------------------------------------
//
//	piPurge() - Plugin extension of Purge()
//
//---------------------------------------------------------------------

#ifdef PI_PURGE
#ifdef _MANAGED
#pragma PI_MIX_PURGE
#endif
void piPurge(short flags) {

}
#endif

//---------------------------------------------------------------------
//
//	piProbe() - Plugin extension of Probe()
//
//---------------------------------------------------------------------

#ifdef PI_PROBE
#ifdef _MANAGED
#pragma PI_MIX_PROBE
#endif
void piProbe() {}
#endif

//---------------------------------------------------------------------
//
//	piHome() - Plugin extension of Home()
//
//---------------------------------------------------------------------

#ifdef PI_HOME
#ifdef _MANAGED
#pragma PI_MIX_HOME
#endif
void piHome(short axis) {}
#endif