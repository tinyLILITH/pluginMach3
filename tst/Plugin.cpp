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
int menuStart = 0;


void initCOM(){

String^ filePath = "C:\\Mach3\\PlugIns\\ToolTurretSettings.txt";


  try{
   
    if(System::IO::File::Exists(filePath)){
        System::IO::StreamReader^ inputFile = gcnew System::IO::StreamReader(filePath);	

		MG::CD->Serial->PortName = inputFile->ReadLine();

		MG::PCD->listBox1->Items->Add("Настройки считаны");
        inputFile->Close();

	
		if(!MG::CD->Serial->IsOpen)
		{
			MG::CD ->Serial->Open();
		}

		if( (MG::CD->Serial->IsOpen)){
			MG::PCD->listBox1->Items->Add("COM порт открыт");

			MG::CD->Serial->WriteLine("?RDY$");//Отправка тестового сообщения на контроллер
			MG::initRequestCOM = MG::CD->Serial->ReadLine();
			

			MG::PCD->listBox1->Items->Add(MG::initRequestCOM);

			//Читаем ответ если ответ совпадает - значит контроллер нужный
			if(MG::initRequestCOM == "!OK$\r"){
				MG::PCD->listBox1->Items->Add("Получен корректный ответ");
				 

			}

			else{
				MG::PCD->listBox1->Items->Add("Ответ от контроллера не получен");
				MG::CD->Serial->Close();
				MG::PCD->listBox1->Items->Add("Порт закрыт");
			}

		}

    } 

	else {
       MG::PCD->listBox1->Items->Add("Файл не найден");
    }
  }


catch(System::Exception^ e) {
	MG::PCD->listBox1->Items->Add("Ошибка:" + e->Message);
}

}

void changeTool(){

			//Инициализация смены инструметра по М6
			//Обработка смены инструмента (отправка данных на МК, получение ответа)

			if( (MG::_mInst->GetOEMLed(1235)) && (MG::_mInst->GetSelectedTool() != 0) ){
			
				//В последствии заменить на отправку по serial и получение ответа
				switch (MG::_mInst->GetSelectedTool()){
					case 1: {
						MG::CD->Serial->WriteLine("?T1$");
						if (MG::CD->Serial->ReadLine() == "!T1$\r"){
							MG::PCD->listBox1->Items->Add("Инструмент №1");
						}
					break;
					}

					case 2: {
						MG::CD->Serial->WriteLine("?T2$");
						if (MG::CD->Serial->ReadLine() == "!T2$\r"){
							MG::PCD->listBox1->Items->Add("Инструмент №2");
						}
					break;
					}
				
				}

	}
}


void updateCOM(){

	try{
		if ((MG::CD->Serial->IsOpen) && (MG::initRequestCOM == "!OK$\r") )
		{
			//Индикатор активного состояния контроллера резцедержателя
			MG::_mInst->SetUserLED(1234,1);

			changeTool();

		   //Вызывать после подтверждения от МК о завершении смены инструмента
			MG::_mInst->SetUserLED(1235,0);
		}

		else
		{
			MG::PCD->listBox1->Items->Add("Порт закрыт");
			MG::_mInst->SetUserLED(1234,0);
			initCOM();
		}
	}

	catch(System::Exception^ e) 
	{
		MG::PCD->listBox1->Items->Add("Ошибка:" + e->Message);
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


  // Store a reference to the form in the ManagedGlobal class for later use

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

//Показ окна
  MG::PCD -> Show();
  initCOM();

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
	MG::CD -> ShowDialog();
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

  XMLNetProfile ^ profile = gcnew XMLNetProfile(gcnew String(ProfileName), "RevolverTool test plugin", true);

  if (profile -> Load()) {

    profile -> Save();

  }

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
 updateCOM();
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
    //	xyzDemoConfig->enableDlg = MG::xyzDemoDialog->Visible;

    //вызов немодального окна
	  try{
		if (MG::PCD == nullptr || MG::PCD->IsDisposed)
			{
				MG::PCD = gcnew PlugInControlDialog();
			}

			MG::PCD->Show();
	  }
		
	  catch(System::Exception^ e) {
		  System::Windows::Forms::MessageBox::Show(e->Message);
	}
	     
	
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
