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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ComboBox^  comList;

	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripStatusLabel^  connectStatus;
	public: System::IO::Ports::SerialPort^  Serial;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel2;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel3;
	private: System::Windows::Forms::ToolStripStatusLabel^  statusCOM;
	private: System::Windows::Forms::Label^  label1;


	private: System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comList = (gcnew System::Windows::Forms::ComboBox());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->connectStatus = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel3 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->statusCOM = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->Serial = (gcnew System::IO::Ports::SerialPort(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(120, 46);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(81, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Сохранить";
			this->button1->Click += gcnew System::EventHandler(this, &ConfigDialog::button1_Click);
			// 
			// comList
			// 
			this->comList->FormattingEnabled = true;
			this->comList->Location = System::Drawing::Point(106, 10);
			this->comList->Name = L"comList";
			this->comList->Size = System::Drawing::Size(205, 21);
			this->comList->TabIndex = 1;
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->toolStripStatusLabel1, 
				this->connectStatus, this->toolStripStatusLabel2, this->toolStripStatusLabel3, this->statusCOM});
			this->statusStrip1->Location = System::Drawing::Point(0, 81);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(323, 22);
			this->statusStrip1->TabIndex = 2;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(0, 17);
			// 
			// connectStatus
			// 
			this->connectStatus->Name = L"connectStatus";
			this->connectStatus->Size = System::Drawing::Size(0, 17);
			// 
			// toolStripStatusLabel2
			// 
			this->toolStripStatusLabel2->Name = L"toolStripStatusLabel2";
			this->toolStripStatusLabel2->Size = System::Drawing::Size(0, 17);
			// 
			// toolStripStatusLabel3
			// 
			this->toolStripStatusLabel3->Name = L"toolStripStatusLabel3";
			this->toolStripStatusLabel3->Size = System::Drawing::Size(144, 17);
			this->toolStripStatusLabel3->Text = L"Состояние контроллера:";
			// 
			// statusCOM
			// 
			this->statusCOM->Name = L"statusCOM";
			this->statusCOM->Size = System::Drawing::Size(101, 17);
			this->statusCOM->Text = L"НЕ ПОДКЛЮЧЕН";
			// 
			// Serial
			// 
			this->Serial->BaudRate = 115200;
			this->Serial->DiscardNull = true;
			this->Serial->ReadTimeout = 50;
			this->Serial->WriteTimeout = 50;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(5, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Порт устройства:";
			// 
			// ConfigDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(323, 103);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->comList);
			this->Controls->Add(this->button1);
			this->Name = L"ConfigDialog";
			this->Text = L"Настройки подключения";
			this->Load += gcnew System::EventHandler(this, &ConfigDialog::ConfigDialog_Load);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//Функции самописные

		void getCOMPorts(){
	
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
		 e->Message;
	 }
	
	}




	private: System::Void ConfigDialog_Load(System::Object^  sender, System::EventArgs^  e) {

	getCOMPorts(); // Получение списка COM портов
}



private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {


// Сохранение выбранного COM порта в файл
this->statusCOM->Text = Convert::ToString(comList->SelectedItem);

String^ filePath = "C:\\Mach3\\PlugIns\\ToolTurretSettings.txt";

if (!System::IO::File::Exists(filePath)) {
	
    System::IO::File::Create(filePath)->Close();
}

System::IO::StreamWriter^ outputFile = gcnew System::IO::StreamWriter(filePath);
outputFile->WriteLine(comList->SelectedItem);
this->statusCOM->Text = "COM порт сохранён";
outputFile->Close();
//---Сохранение выбранного COM порта в файл---------






}
};
}
