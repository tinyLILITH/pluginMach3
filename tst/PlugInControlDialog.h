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


	public ref struct GD
	{
	public:
		static String^ inputBuff = "";
		static int modeSelect = 0;
		static int slowJogSwitch = 0;

	};

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
	public: System::IO::Ports::SerialPort^  Serial;
	protected: 

	protected: 
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  settingsTab;
	private: System::Windows::Forms::ComboBox^  baudList;
	private: System::Windows::Forms::ComboBox^  comList;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  lblCOM;
	private: System::Windows::Forms::Button^  connCOM;
	private: System::Windows::Forms::Button^  refreshCOM;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	public: System::Windows::Forms::ToolStripStatusLabel^  actualStatus;
	private: System::Windows::Forms::TabPage^  tabPage1;
	public: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	public: IMach4^ _mach;
	public: IMyScriptObject^ _mInst;
	public: System::Windows::Forms::Timer^  timer1;



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
			this->Serial = (gcnew System::IO::Ports::SerialPort(this->components));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->settingsTab = (gcnew System::Windows::Forms::TabPage());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->actualStatus = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->connCOM = (gcnew System::Windows::Forms::Button());
			this->refreshCOM = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblCOM = (gcnew System::Windows::Forms::Label());
			this->baudList = (gcnew System::Windows::Forms::ComboBox());
			this->comList = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->tabControl1->SuspendLayout();
			this->settingsTab->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Serial
			// 
			this->Serial->PortName = L"COM5";
			this->Serial->ReadBufferSize = 10;
			this->Serial->ReadTimeout = 10;
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
			this->settingsTab->Controls->Add(this->connCOM);
			this->settingsTab->Controls->Add(this->refreshCOM);
			this->settingsTab->Controls->Add(this->label2);
			this->settingsTab->Controls->Add(this->lblCOM);
			this->settingsTab->Controls->Add(this->baudList);
			this->settingsTab->Controls->Add(this->comList);
			this->settingsTab->Controls->Add(this->groupBox1);
			this->settingsTab->Location = System::Drawing::Point(4, 22);
			this->settingsTab->Name = L"settingsTab";
			this->settingsTab->Size = System::Drawing::Size(513, 235);
			this->settingsTab->TabIndex = 0;
			this->settingsTab->Text = L"Íàñòðîéêè ïîäêëþ÷åíèÿ";
			this->settingsTab->UseVisualStyleBackColor = true;
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripStatusLabel1, 
				this->actualStatus});
			this->statusStrip1->Location = System::Drawing::Point(0, 213);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(513, 22);
			this->statusStrip1->TabIndex = 7;
			this->statusStrip1->Text = L"Status";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(200, 17);
			this->toolStripStatusLabel1->Text = L"Ñòàòóñ ïîäêëþ÷åíèÿ êîíòðîëëåðà:";
			// 
			// actualStatus
			// 
			this->actualStatus->Name = L"actualStatus";
			this->actualStatus->Size = System::Drawing::Size(101, 17);
			this->actualStatus->Text = L"ÍÅ ÏÎÄÊËÞ×¨Í";
			// 
			// connCOM
			// 
			this->connCOM->Location = System::Drawing::Point(95, 79);
			this->connCOM->Name = L"connCOM";
			this->connCOM->Size = System::Drawing::Size(121, 23);
			this->connCOM->TabIndex = 5;
			this->connCOM->Text = L"Connect";
			this->connCOM->UseVisualStyleBackColor = true;
			this->connCOM->Click += gcnew System::EventHandler(this, &PlugInControlDialog::connCOM_Click);
			// 
			// refreshCOM
			// 
			this->refreshCOM->Location = System::Drawing::Point(222, 23);
			this->refreshCOM->Name = L"refreshCOM";
			this->refreshCOM->Size = System::Drawing::Size(98, 23);
			this->refreshCOM->TabIndex = 4;
			this->refreshCOM->Text = L"Update COM ";
			this->refreshCOM->UseVisualStyleBackColor = true;
			this->refreshCOM->Click += gcnew System::EventHandler(this, &PlugInControlDialog::refreshCOM_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(20, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(69, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"BAUDRATE:";
			// 
			// lblCOM
			// 
			this->lblCOM->AutoSize = true;
			this->lblCOM->Location = System::Drawing::Point(20, 28);
			this->lblCOM->Name = L"lblCOM";
			this->lblCOM->Size = System::Drawing::Size(34, 13);
			this->lblCOM->TabIndex = 2;
			this->lblCOM->Text = L"COM:";
			// 
			// baudList
			// 
			this->baudList->FormattingEnabled = true;
			this->baudList->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"9600", L"115200"});
			this->baudList->Location = System::Drawing::Point(95, 52);
			this->baudList->Name = L"baudList";
			this->baudList->Size = System::Drawing::Size(121, 21);
			this->baudList->TabIndex = 1;
			// 
			// comList
			// 
			this->comList->FormattingEnabled = true;
			this->comList->Location = System::Drawing::Point(95, 25);
			this->comList->Name = L"comList";
			this->comList->Size = System::Drawing::Size(121, 21);
			this->comList->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Location = System::Drawing::Point(6, 5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(318, 110);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Íàñòðîéêè ïîäêëþ÷åíèÿ ê êîíòðîëëåðó";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(216, 47);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(98, 23);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Close COM";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &PlugInControlDialog::button2_Click_1);
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->listBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Size = System::Drawing::Size(513, 235);
			this->tabPage1->TabIndex = 1;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(157, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PlugInControlDialog::button1_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(18, 12);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 95);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &PlugInControlDialog::listBox1_SelectedIndexChanged);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &PlugInControlDialog::timer1_Tick);
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
			this->groupBox1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion


		private: System::Void refreshCOM_Click(System::Object^  sender, System::EventArgs^  e) {

					 array<String^> ^AvailableSerialPorts;
	 array<unsigned char> ^aTemp;
	 String ^sTemp;

	try
	 {
		 comList->Items->Clear();
		AvailableSerialPorts = this->Serial->GetPortNames();

		comList->Items->Add("None");
		for(int Count = 0; Count < AvailableSerialPorts->Length; Count++)
		{
			sTemp = AvailableSerialPorts[Count];

			//Remove any non numeric last letter which can be added by microsoft bluetooth drivers
			aTemp = System::Text::Encoding::UTF8->GetBytes(sTemp);
			while (
				(aTemp->Length > 1) && 
				((aTemp[(aTemp->Length - 1)] < '0') || (aTemp[(aTemp->Length - 1)] > '9'))
				)
			{
				Array::Resize(aTemp, (aTemp->Length - 1));
			}
			sTemp = System::Text::Encoding::UTF8->GetString(aTemp);

			comList->Items->Add(sTemp);
		}
		comList->SelectedIndex = 0;
	 }

	 catch(System::Exception^ e)
	 {

	 }
}

private: System::Void connCOM_Click(System::Object^  sender, System::EventArgs^  e) {

			 this->Serial->PortName = Convert::ToString(comList->SelectedItem);
			 this->Serial->BaudRate = Convert::ToInt32(baudList->SelectedItem);

					 this->Serial->Open();
					 Sleep(50);			 
					 /*
			 if (this->Serial->IsOpen){
				 this->Serial->WriteLine("?RDY$");

				 if (this->Serial->ReadTo("$") == "!OK")
					 {
					 this->actualStatus->ForeColor = System::Drawing::Color::Green;
						this->actualStatus->Text = "ÏÎÄÊËÞ×ÅÍÎ";
					 }
				 else
					 {
						this->Serial->Close();
						this->actualStatus->ForeColor = System::Drawing::Color::Red; 
						this->actualStatus->Text = "ÎÒÂÅÒ ÎÒ ÊÎÍÒÐÎËËÅÐÀ ÍÅ ÏÎËÓ×ÅÍ";
					 }
				 }

			 else
				 {
						this->actualStatus->ForeColor = System::Drawing::Color::Red; 
						this->actualStatus->Text = "ÍÅ ÏÎÄÊËÞ×ÅÍÎ";
				 }
				 */
			 
			 }
private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 this->Serial->Close();
					 Sleep(50);		 
			 
			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		 }
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
