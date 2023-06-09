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
		static	 PlugInControlDialog^ pluginControlDialog;
		static	 ConfigDialog^ configDialog;
	};
}
#endif
