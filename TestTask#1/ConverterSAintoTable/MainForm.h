#pragma once
#include "ConvertData.h"

using namespace System;
using namespace System::Collections;
using namespace System::ComponentModel;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Windows::Forms;

namespace ConverterSAintoTable {

	

	/// <summary>
	/// ������ ��� MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			this->fData = new ConvertData();
		    this->col_index = 0;
		    this->row_index = 0;
			//
			//TODO: �������� ��� ������������
			//
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^  ��������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  separateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  sepToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  �����ToolStripMenuItem;




	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ��������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  ����������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ��������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ��������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������������ToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  ��������������������ToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������������������ToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  ��������������ToolStripMenuItem1;
	private: int col_index;
	private: int row_index;
	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^  ����������ToolStripMenuItem;



	protected:
		ConvertData *fData;
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ������������ToolStripMenuItem;




	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->separateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sepToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->����������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->��������������������ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������������ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->contextMenuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->����ToolStripMenuItem,
					this->�������ToolStripMenuItem, this->����������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(784, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->�������ToolStripMenuItem,
					this->separateToolStripMenuItem, this->���������ToolStripMenuItem, this->������������ToolStripMenuItem, this->sepToolStripMenuItem,
					this->�������ToolStripMenuItem, this->�����ToolStripMenuItem
			});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"�������ToolStripMenuItem.Image")));
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->�������ToolStripMenuItem->Text = L"�������...";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::�������ToolStripMenuItem_Click);
			// 
			// separateToolStripMenuItem
			// 
			this->separateToolStripMenuItem->Name = L"separateToolStripMenuItem";
			this->separateToolStripMenuItem->Size = System::Drawing::Size(159, 6);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Enabled = false;
			this->���������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"���������ToolStripMenuItem.Image")));
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->���������ToolStripMenuItem->Text = L"���������";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::���������ToolStripMenuItem_Click);
			// 
			// ������������ToolStripMenuItem
			// 
			this->������������ToolStripMenuItem->Enabled = false;
			this->������������ToolStripMenuItem->Name = L"������������ToolStripMenuItem";
			this->������������ToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->������������ToolStripMenuItem->Text = L"��������� ���...";
			this->������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::������������ToolStripMenuItem_Click);
			// 
			// sepToolStripMenuItem
			// 
			this->sepToolStripMenuItem->Name = L"sepToolStripMenuItem";
			this->sepToolStripMenuItem->Size = System::Drawing::Size(159, 6);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Enabled = false;
			this->�������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"�������ToolStripMenuItem.Image")));
			this->�������ToolStripMenuItem->ImageTransparentColor = System::Drawing::SystemColors::ButtonFace;
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::�������ToolStripMenuItem_Click);
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"�����ToolStripMenuItem.Image")));
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->�����ToolStripMenuItem->Text = L"�����";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::�����ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(11) {
				this->�������ToolStripMenuItem,
					this->��������������������ToolStripMenuItem, this->������������������ToolStripMenuItem, this->������������������ToolStripMenuItem,
					this->�������������ToolStripMenuItem, this->toolStripMenuItem1, this->����������������������ToolStripMenuItem, this->���������������������ToolStripMenuItem,
					this->��������������������ToolStripMenuItem, this->���������������������ToolStripMenuItem, this->��������������ToolStripMenuItem
			});
			this->�������ToolStripMenuItem->Enabled = false;
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(66, 20);
			this->�������ToolStripMenuItem->Text = L"�������";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"�������ToolStripMenuItem.Image")));
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(222, 22);
			this->�������ToolStripMenuItem->Text = L"�������� ������ � ������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::�������ToolStripMenuItem_Click);
			// 
			// ��������������������ToolStripMenuItem
			// 
			this->��������������������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"��������������������ToolStripMenuItem.Image")));
			this->��������������������ToolStripMenuItem->Name = L"��������������������ToolStripMenuItem";
			this->��������������������ToolStripMenuItem->Size = System::Drawing::Size(222, 22);
			this->��������������������ToolStripMenuItem->Text = L"�������� ������ � �����";
			this->��������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::��������������������ToolStripMenuItem_Click);
			// 
			// ������������������ToolStripMenuItem
			// 
			this->������������������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"������������������ToolStripMenuItem.Image")));
			this->������������������ToolStripMenuItem->Name = L"������������������ToolStripMenuItem";
			this->������������������ToolStripMenuItem->Size = System::Drawing::Size(222, 22);
			this->������������������ToolStripMenuItem->Text = L"�������� ������ ����";
			this->������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::������������������ToolStripMenuItem_Click);
			// 
			// ������������������ToolStripMenuItem
			// 
			this->������������������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"������������������ToolStripMenuItem.Image")));
			this->������������������ToolStripMenuItem->Name = L"������������������ToolStripMenuItem";
			this->������������������ToolStripMenuItem->Size = System::Drawing::Size(222, 22);
			this->������������������ToolStripMenuItem->Text = L"�������� ������ ����";
			this->������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::������������������ToolStripMenuItem_Click);
			// 
			// �������������ToolStripMenuItem
			// 
			this->�������������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"�������������ToolStripMenuItem.Image")));
			this->�������������ToolStripMenuItem->Name = L"�������������ToolStripMenuItem";
			this->�������������ToolStripMenuItem->Size = System::Drawing::Size(222, 22);
			this->�������������ToolStripMenuItem->Text = L"������� ������";
			this->�������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::�������������ToolStripMenuItem_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(219, 6);
			// 
			// ����������������������ToolStripMenuItem
			// 
			this->����������������������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"����������������������ToolStripMenuItem.Image")));
			this->����������������������ToolStripMenuItem->Name = L"����������������������ToolStripMenuItem";
			this->����������������������ToolStripMenuItem->Size = System::Drawing::Size(222, 22);
			this->����������������������ToolStripMenuItem->Text = L"�������� ������� � ������";
			this->����������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::����������������������ToolStripMenuItem_Click);
			// 
			// ���������������������ToolStripMenuItem
			// 
			this->���������������������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"���������������������ToolStripMenuItem.Image")));
			this->���������������������ToolStripMenuItem->Name = L"���������������������ToolStripMenuItem";
			this->���������������������ToolStripMenuItem->Size = System::Drawing::Size(222, 22);
			this->���������������������ToolStripMenuItem->Text = L"�������� ������� � �����";
			this->���������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::���������������������ToolStripMenuItem_Click);
			// 
			// ��������������������ToolStripMenuItem
			// 
			this->��������������������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"��������������������ToolStripMenuItem.Image")));
			this->��������������������ToolStripMenuItem->Name = L"��������������������ToolStripMenuItem";
			this->��������������������ToolStripMenuItem->Size = System::Drawing::Size(222, 22);
			this->��������������������ToolStripMenuItem->Text = L"�������� ������� �����";
			this->��������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::��������������������ToolStripMenuItem_Click);
			// 
			// ���������������������ToolStripMenuItem
			// 
			this->���������������������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"���������������������ToolStripMenuItem.Image")));
			this->���������������������ToolStripMenuItem->Name = L"���������������������ToolStripMenuItem";
			this->���������������������ToolStripMenuItem->Size = System::Drawing::Size(222, 22);
			this->���������������������ToolStripMenuItem->Text = L"�������� ������� ������";
			this->���������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::���������������������ToolStripMenuItem_Click);
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"��������������ToolStripMenuItem.Image")));
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(222, 22);
			this->��������������ToolStripMenuItem->Text = L"������� �������";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::��������������ToolStripMenuItem_Click);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->��������������ToolStripMenuItem,
					this->���������������ToolStripMenuItem, this->�������������ToolStripMenuItem1, this->toolStripMenuItem2, this->��������������������ToolStripMenuItem1,
					this->���������������������ToolStripMenuItem1, this->��������������ToolStripMenuItem1
			});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->contextMenuStrip1->Size = System::Drawing::Size(212, 142);
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"��������������ToolStripMenuItem.Image")));
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(211, 22);
			this->��������������ToolStripMenuItem->Text = L"�������� ������ ����";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::��������������ToolStripMenuItem_Click);
			// 
			// ���������������ToolStripMenuItem
			// 
			this->���������������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"���������������ToolStripMenuItem.Image")));
			this->���������������ToolStripMenuItem->Name = L"���������������ToolStripMenuItem";
			this->���������������ToolStripMenuItem->Size = System::Drawing::Size(211, 22);
			this->���������������ToolStripMenuItem->Text = L"�������� ������ ����";
			this->���������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::���������������ToolStripMenuItem_Click);
			// 
			// �������������ToolStripMenuItem1
			// 
			this->�������������ToolStripMenuItem1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"�������������ToolStripMenuItem1.Image")));
			this->�������������ToolStripMenuItem1->Name = L"�������������ToolStripMenuItem1";
			this->�������������ToolStripMenuItem1->Size = System::Drawing::Size(211, 22);
			this->�������������ToolStripMenuItem1->Text = L"������� ������";
			this->�������������ToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::�������������ToolStripMenuItem1_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(208, 6);
			// 
			// ��������������������ToolStripMenuItem1
			// 
			this->��������������������ToolStripMenuItem1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"��������������������ToolStripMenuItem1.Image")));
			this->��������������������ToolStripMenuItem1->Name = L"��������������������ToolStripMenuItem1";
			this->��������������������ToolStripMenuItem1->Size = System::Drawing::Size(211, 22);
			this->��������������������ToolStripMenuItem1->Text = L"�������� ������� �����";
			this->��������������������ToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::��������������������ToolStripMenuItem1_Click);
			// 
			// ���������������������ToolStripMenuItem1
			// 
			this->���������������������ToolStripMenuItem1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"���������������������ToolStripMenuItem1.Image")));
			this->���������������������ToolStripMenuItem1->Name = L"���������������������ToolStripMenuItem1";
			this->���������������������ToolStripMenuItem1->Size = System::Drawing::Size(211, 22);
			this->���������������������ToolStripMenuItem1->Text = L"�������� ������� ������";
			this->���������������������ToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::���������������������ToolStripMenuItem1_Click);
			// 
			// ��������������ToolStripMenuItem1
			// 
			this->��������������ToolStripMenuItem1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"��������������ToolStripMenuItem1.Image")));
			this->��������������ToolStripMenuItem1->Name = L"��������������ToolStripMenuItem1";
			this->��������������ToolStripMenuItem1->Size = System::Drawing::Size(211, 22);
			this->��������������ToolStripMenuItem1->Text = L"������� �������";
			this->��������������ToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::��������������ToolStripMenuItem1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCellsExceptHeaders;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 27);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 55;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGridView1->ShowCellToolTips = false;
			this->dataGridView1->Size = System::Drawing::Size(760, 523);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView1_CellClick);
			this->dataGridView1->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView1_CellEndEdit);
			this->dataGridView1->CellMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &MainForm::dataGridView1_CellMouseClick);
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(103, 20);
			this->����������ToolStripMenuItem->Text = L"� ���������...";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::����������ToolStripMenuItem_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 562);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"ConverterSAintoTable";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->contextMenuStrip1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void ShowTable();

	private: void loadDataIntoFile(Stream^ fStream);

	private: void saveDataToFile(Stream^ fStream);

	private: void setSelectionMode(int colIndex, int rowIndex);

	private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);

	private: System::Void dataGridView1_CellMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e);
			 
	private: System::Void dataGridView1_CellEndEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	
	private: System::Void �������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e); 
    private: System::Void ��������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void ������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void ������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void �������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
    
    private: System::Void ����������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void ���������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void ��������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void ���������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void ��������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void ��������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void ���������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void �������������ToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void ��������������������ToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void ���������������������ToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void ��������������ToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e);
    
	private: System::Void ���������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	 
	private: System::Void ������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void �������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void �����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
	private: System::Void ����������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
};
}
