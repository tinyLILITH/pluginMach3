#pragma once;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;
using namespace Mach4;

namespace tst {

	/// <summary>
	/// Summary for PlugInControlDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>




	public ref class PlugInControlDialog : public System::Windows::Forms::Form
	{
	public:
		PlugInControlDialog(void)
		{

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}



	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PlugInControlDialog()
		{
			if (components)
			{
				delete components;
			}
		}

	public: IMach4^ _mach;
	public: IMyScriptObject^ _mInst;


	public: System::Windows::Forms::ListBox^  listBox1;
	public: System::Windows::Forms::Timer^  stopJog;
	private: System::ComponentModel::IContainer^  components;
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->stopJog = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(12, 12);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(497, 108);
			this->listBox1->TabIndex = 0;

			// 
			// PlugInControlDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::Disable;
			this->ClientSize = System::Drawing::Size(521, 261);
			this->Controls->Add(this->listBox1);
			this->Name = L"PlugInControlDialog";
			this->Text = L"PlugInControlDialog";
			this->ResumeLayout(false);

		}
#pragma endregion

	};
}
