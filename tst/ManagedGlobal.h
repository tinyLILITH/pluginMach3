//=====================================================================
//
//	Plugin::MG - Plugin's ManagedGlobal (MG) class
//
//	place static members here to hold our global handles and managed
//	data which need to persist. they will need to be 'copied' to working
//	variables in the functions that use them so that the 'static' will
//	not interfere with operations.
//
//	see xyzdemo for examples of usage
//
//=====================================================================

#ifdef _MANAGED
#pragma managed

using namespace tst;

namespace tst
{

	public ref class MG
	{
	public:
		//--- sample of a global modeless dialog -----
		//static	MonitorDialog^ monitorDialog;
		//--------------------------------------------
		static	 PlugInControlDialog^ PCD = gcnew PlugInControlDialog();
		static	 ConfigDialog^ CD = gcnew ConfigDialog();
		static   IMach4^ _mach = (IMach4^) Marshal::GetActiveObject("Mach4.Document");
		static	 IMyScriptObject^ _mInst = (IMyScriptObject^) _mach->GetScriptDispatch();

		static String^ initRequestCOM = "";
		static String^ updRequestCOM = "";
		static String^ axisSelected = "";
		static String^ jogOverride = "";


	};
}
#endif
