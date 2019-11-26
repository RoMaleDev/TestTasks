#pragma once

#include "DBUtils.h"
#include "Query.h"

namespace ConverterForexData {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			ShowTable("Select Name from Brokers");
			//
			//TODO: добавьте код конструктора
			//
			isDataPresentSourceFoldersGridView = false;
			isDataPresentDestinationFolderTextBox = false;
			query = gcnew Query(SqlConn::DBUtils::GetDBConnection());
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::DataGridView^ brokerGridView;

	private: System::Windows::Forms::SplitContainer^ splitContainer2;
	private: System::Windows::Forms::TextBox^ brokerTextBox;
	private: System::Windows::Forms::Button^ addDestinationFolderButton;



	private: System::Windows::Forms::Button^ addSourceFolderButton;

	private: System::Windows::Forms::Button^ addBrokerButton;
	private: System::Windows::Forms::DataGridView^ sourceFoldersGridView;
	private: System::Windows::Forms::Button^ convertDataButton;

	private: bool isDataPresentSourceFoldersGridView;
		   bool isDataPresentDestinationFolderTextBox;
		   Query^ query;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ destinationFolderTextBox;

	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::TextBox^ sourceFolderTextBox;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->brokerTextBox = (gcnew System::Windows::Forms::TextBox());
			this->addBrokerButton = (gcnew System::Windows::Forms::Button());
			this->brokerGridView = (gcnew System::Windows::Forms::DataGridView());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->sourceFolderTextBox = (gcnew System::Windows::Forms::TextBox());
			this->addSourceFolderButton = (gcnew System::Windows::Forms::Button());
			this->sourceFoldersGridView = (gcnew System::Windows::Forms::DataGridView());
			this->addDestinationFolderButton = (gcnew System::Windows::Forms::Button());
			this->convertDataButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->destinationFolderTextBox = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->brokerGridView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sourceFoldersGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(784, 41);
			this->panel1->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(388, 24);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(262, 17);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Папка с исходными данными брокера:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(54, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(125, 17);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Список брокеров:";
			// 
			// panel2
			// 
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 491);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(784, 70);
			this->panel2->TabIndex = 1;
			// 
			// panel3
			// 
			this->panel3->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel3->Location = System::Drawing::Point(0, 41);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(40, 450);
			this->panel3->TabIndex = 2;
			// 
			// panel4
			// 
			this->panel4->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel4->Location = System::Drawing::Point(744, 41);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(40, 450);
			this->panel4->TabIndex = 3;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->IsSplitterFixed = true;
			this->splitContainer1->Location = System::Drawing::Point(40, 41);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->panel5);
			this->splitContainer1->Panel1->Controls->Add(this->brokerGridView);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->splitContainer2);
			this->splitContainer1->Size = System::Drawing::Size(704, 450);
			this->splitContainer1->SplitterDistance = 232;
			this->splitContainer1->SplitterWidth = 80;
			this->splitContainer1->TabIndex = 4;
			// 
			// panel5
			// 
			this->panel5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel5->BackColor = System::Drawing::SystemColors::Control;
			this->panel5->Controls->Add(this->brokerTextBox);
			this->panel5->Controls->Add(this->addBrokerButton);
			this->panel5->Location = System::Drawing::Point(0, 0);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(232, 52);
			this->panel5->TabIndex = 1;
			// 
			// brokerTextBox
			// 
			this->brokerTextBox->Location = System::Drawing::Point(6, 12);
			this->brokerTextBox->Name = L"brokerTextBox";
			this->brokerTextBox->Size = System::Drawing::Size(124, 20);
			this->brokerTextBox->TabIndex = 0;
			this->brokerTextBox->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox1_TextChanged);
			// 
			// addBrokerButton
			// 
			this->addBrokerButton->Enabled = false;
			this->addBrokerButton->Location = System::Drawing::Point(145, 12);
			this->addBrokerButton->Name = L"addBrokerButton";
			this->addBrokerButton->Size = System::Drawing::Size(75, 23);
			this->addBrokerButton->TabIndex = 0;
			this->addBrokerButton->Text = L"Добавить";
			this->addBrokerButton->UseVisualStyleBackColor = true;
			this->addBrokerButton->Click += gcnew System::EventHandler(this, &MainForm::addBrokerButton_Click);
			// 
			// brokerGridView
			// 
			this->brokerGridView->AllowUserToAddRows = false;
			this->brokerGridView->AllowUserToDeleteRows = false;
			this->brokerGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->brokerGridView->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->brokerGridView->BackgroundColor = System::Drawing::SystemColors::Control;
			this->brokerGridView->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->brokerGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->brokerGridView->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->brokerGridView->Location = System::Drawing::Point(0, 58);
			this->brokerGridView->Name = L"brokerGridView";
			this->brokerGridView->ReadOnly = true;
			this->brokerGridView->Size = System::Drawing::Size(232, 392);
			this->brokerGridView->TabIndex = 0;
			this->brokerGridView->CurrentCellChanged += gcnew System::EventHandler(this, &MainForm::brokerGridView_CurrentCellChanged);
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->FixedPanel = System::Windows::Forms::FixedPanel::Panel2;
			this->splitContainer2->IsSplitterFixed = true;
			this->splitContainer2->Location = System::Drawing::Point(0, 0);
			this->splitContainer2->Name = L"splitContainer2";
			this->splitContainer2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->panel6);
			this->splitContainer2->Panel1->Controls->Add(this->sourceFoldersGridView);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->addDestinationFolderButton);
			this->splitContainer2->Panel2->Controls->Add(this->convertDataButton);
			this->splitContainer2->Panel2->Controls->Add(this->label1);
			this->splitContainer2->Panel2->Controls->Add(this->destinationFolderTextBox);
			this->splitContainer2->Size = System::Drawing::Size(392, 450);
			this->splitContainer2->SplitterDistance = 305;
			this->splitContainer2->TabIndex = 0;
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->sourceFolderTextBox);
			this->panel6->Controls->Add(this->addSourceFolderButton);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel6->Location = System::Drawing::Point(0, 0);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(392, 52);
			this->panel6->TabIndex = 1;
			// 
			// sourceFolderTextBox
			// 
			this->sourceFolderTextBox->Location = System::Drawing::Point(39, 12);
			this->sourceFolderTextBox->Name = L"sourceFolderTextBox";
			this->sourceFolderTextBox->Size = System::Drawing::Size(228, 20);
			this->sourceFolderTextBox->TabIndex = 2;
			// 
			// addSourceFolderButton
			// 
			this->addSourceFolderButton->Location = System::Drawing::Point(298, 12);
			this->addSourceFolderButton->Name = L"addSourceFolderButton";
			this->addSourceFolderButton->Size = System::Drawing::Size(75, 23);
			this->addSourceFolderButton->TabIndex = 1;
			this->addSourceFolderButton->Text = L"Добавить";
			this->addSourceFolderButton->UseVisualStyleBackColor = true;
			this->addSourceFolderButton->Click += gcnew System::EventHandler(this, &MainForm::addSourceFolderButton_Click);
			// 
			// sourceFoldersGridView
			// 
			this->sourceFoldersGridView->AllowUserToAddRows = false;
			this->sourceFoldersGridView->AllowUserToDeleteRows = false;
			this->sourceFoldersGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->sourceFoldersGridView->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCellsExceptHeaders;
			this->sourceFoldersGridView->BackgroundColor = System::Drawing::SystemColors::Control;
			this->sourceFoldersGridView->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->sourceFoldersGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->sourceFoldersGridView->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->sourceFoldersGridView->Location = System::Drawing::Point(0, 58);
			this->sourceFoldersGridView->Name = L"sourceFoldersGridView";
			this->sourceFoldersGridView->ReadOnly = true;
			this->sourceFoldersGridView->Size = System::Drawing::Size(392, 247);
			this->sourceFoldersGridView->TabIndex = 0;
			// 
			// addDestinationFolderButton
			// 
			this->addDestinationFolderButton->Location = System::Drawing::Point(298, 46);
			this->addDestinationFolderButton->Name = L"addDestinationFolderButton";
			this->addDestinationFolderButton->Size = System::Drawing::Size(75, 23);
			this->addDestinationFolderButton->TabIndex = 2;
			this->addDestinationFolderButton->Text = L"Добавить";
			this->addDestinationFolderButton->UseVisualStyleBackColor = true;
			this->addDestinationFolderButton->Click += gcnew System::EventHandler(this, &MainForm::addDestinationFolderButton_Click);
			// 
			// convertDataButton
			// 
			this->convertDataButton->Enabled = false;
			this->convertDataButton->Location = System::Drawing::Point(31, 87);
			this->convertDataButton->Name = L"convertDataButton";
			this->convertDataButton->Size = System::Drawing::Size(342, 23);
			this->convertDataButton->TabIndex = 0;
			this->convertDataButton->Text = L"К О Н В Е Р Т И Р О В А Т Ь ";
			this->convertDataButton->UseVisualStyleBackColor = true;
			this->convertDataButton->Click += gcnew System::EventHandler(this, &MainForm::convertDataButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(36, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(273, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Папка с сконвертированными данными:";
			// 
			// destinationFolderTextBox
			// 
			this->destinationFolderTextBox->Location = System::Drawing::Point(31, 49);
			this->destinationFolderTextBox->Name = L"destinationFolderTextBox";
			this->destinationFolderTextBox->Size = System::Drawing::Size(236, 20);
			this->destinationFolderTextBox->TabIndex = 0;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->splitContainer1);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"ConverterForexData";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->brokerGridView))->EndInit();
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			this->splitContainer2->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sourceFoldersGridView))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: void ShowTable(String^ sql);
private: Void setDestinationFolderTextBox();
private: Void setSourceFoldersGridView();
	   Void MainForm::checkStateconvertDataButton();
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);		   
private: System::Void addBrokerButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void addSourceFolderButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void addDestinationFolderButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void brokerGridView_CurrentCellChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void convertDataButton_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
