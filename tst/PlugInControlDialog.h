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


	public: String ^sTemp;
	protected: 

	protected: 
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  settingsTab;










	private: System::Windows::Forms::TabPage^  tabPage1;



	public: IMach4^ _mach;
	public: IMyScriptObject^ _mInst;

	public: System::IO::Ports::SerialPort^  Serial;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	public: System::Windows::Forms::ToolStripStatusLabel^  actualStatus;
	public:  System::Windows::Forms::ToolStripStatusLabel^  notice;
	
	private: System::ComponentModel::IContainer^  components;
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
			this->components = (gcnew System::ComponentModel::Container());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->settingsTab = (gcnew System::Windows::Forms::TabPage());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->actualStatus = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->Serial = (gcnew System::IO::Ports::SerialPort(this->components));
			this->notice = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->tabControl1->SuspendLayout();
			this->settingsTab->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->settingsTab);
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(521, 261);
			this->tabControl1->TabIndex = 0;
			// 
			// settingsTab
			// 
			this->settingsTab->Controls->Add(this->statusStrip1);
			this->settingsTab->Location = System::Drawing::Point(4, 22);
			this->settingsTab->Name = L"settingsTab";
			this->settingsTab->Size = System::Drawing::Size(513, 235);
			this->settingsTab->TabIndex = 0;
			this->settingsTab->Text = L"Настройки подключения";
			this->settingsTab->UseVisualStyleBackColor = true;
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->actualStatus, this->notice});
			this->statusStrip1->Location = System::Drawing::Point(0, 213);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(513, 22);
			this->statusStrip1->TabIndex = 0;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// actualStatus
			// 
			this->actualStatus->Name = L"actualStatus";
			this->actualStatus->Size = System::Drawing::Size(118, 17);
			this->actualStatus->Text = L"toolStripStatusLabel1";
			// 
			// tabPage1
			// 
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Size = System::Drawing::Size(513, 235);
			this->tabPage1->TabIndex = 1;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// Serial
			// 
			this->Serial->ReadTimeout = 100;
			this->Serial->WriteTimeout = 100;
			// 
			// notice
			// 
			this->notice->Name = L"notice";
			this->notice->Size = System::Drawing::Size(118, 17);
			this->notice->Text = L"toolStripStatusLabel1";
			// 
			// PlugInControlDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::Disable;
			this->ClientSize = System::Drawing::Size(521, 261);
			this->Controls->Add(this->tabControl1);
			this->Name = L"PlugInControlDialog";
			this->Text = L"PlugInControlDialog";
			this->tabControl1->ResumeLayout(false);
			this->settingsTab->ResumeLayout(false);
			this->settingsTab->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion


		private: System::Void refreshCOM_Click(System::Object^  sender, System::EventArgs^  e) {

				 }

private: System::Void connCOM_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 }
private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
	 
			 
			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		 }
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }


private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {


		 }
};
}
