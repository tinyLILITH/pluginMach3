#pragma once;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace tst {

	/// <summary>
	/// Summary for ConfigDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ConfigDialog : public System::Windows::Forms::Form
	{
	public:
		ConfigDialog(void)
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
		~ConfigDialog()
		{
			if (components)
			{
				delete components;
			}
		}










	private: System::ComponentModel::IContainer^  components;

	protected: 

	private:
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
		this->SuspendLayout();
		// 
		// ConfigDialog
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(220, 108);
		this->Name = L"ConfigDialog";
		this->Text = L"ConfigDialog";
		this->Load += gcnew System::EventHandler(this, &ConfigDialog::ConfigDialog_Load);
		this->ResumeLayout(false);

			}
#pragma endregion

	private: System::Void ConfigDialog_Load(System::Object^  sender, System::EventArgs^  e) 
			 
			 {

			 }


};
}
