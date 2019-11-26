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
	/// Ñâîäêà äëÿ MainForm
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
			//TODO: äîáàâüòå êîä êîíñòğóêòîğà
			//
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^  âñòàâèòüÑòğîêóToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  âñòàâèòüÑòîëáåöToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  separateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  sepToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  çàêğûòüToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  âûõîäToolStripMenuItem;




	private: System::Windows::Forms::ToolStripMenuItem^  òàáëèöàToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  âòàâèòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  âñòàâèòüÑòğîêóÂÊîíåöToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  âñòàâèòüÑòğîêóÂûøåToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  âñòàâèòüÑòğîêóÍèæåToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  óäàëèòüÑòğîêóToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  âñòàâèòüÑòîëáåöÂÍà÷àëîToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  âñòàâèòüÑòîëáåöÂÊîíåöToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  óäàëèòüÑòîëáåöToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  óäàëèòüÑòğîêóToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  óäàëèòüÑòîëáåöToolStripMenuItem1;
	private: int col_index;
	private: int row_index;
	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^  îÏğîãğàììåToolStripMenuItem;



	protected:
		ConvertData *fData;
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ôàéëToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  îòêğûòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ñîõğàíèòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ñîõğàíèòüÊàêToolStripMenuItem;




	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Òğåáóåòñÿ ïåğåìåííàÿ êîíñòğóêòîğà.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Îáÿçàòåëüíûé ìåòîä äëÿ ïîääåğæêè êîíñòğóêòîğà - íå èçìåíÿéòå
		/// ñîäåğæèìîå äàííîãî ìåòîäà ïğè ïîìîùè ğåäàêòîğà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ôàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îòêğûòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->separateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->ñîõğàíèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ñîõğàíèòüÊàêToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sepToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->çàêğûòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->òàáëèöàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âòàâèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âñòàâèòüÑòğîêóÂÊîíåöToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âñòàâèòüÑòğîêóÂûøåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âñòàâèòüÑòğîêóÍèæåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->óäàëèòüÑòğîêóToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->âñòàâèòüÑòîëáåöÂÍà÷àëîToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âñòàâèòüÑòîëáåöÂÊîíåöToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->óäàëèòüÑòîëáåöToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->âñòàâèòüÑòğîêóToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âñòàâèòüÑòîëáåöToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->óäàëèòüÑòğîêóToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->óäàëèòüÑòîëáåöToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->îÏğîãğàììåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->contextMenuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->ôàéëToolStripMenuItem,
					this->òàáëèöàToolStripMenuItem, this->îÏğîãğàììåToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(784, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ôàéëToolStripMenuItem
			// 
			this->ôàéëToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->îòêğûòüToolStripMenuItem,
					this->separateToolStripMenuItem, this->ñîõğàíèòüToolStripMenuItem, this->ñîõğàíèòüÊàêToolStripMenuItem, this->sepToolStripMenuItem,
					this->çàêğûòüToolStripMenuItem, this->âûõîäToolStripMenuItem
			});
			this->ôàéëToolStripMenuItem->Name = L"ôàéëToolStripMenuItem";
			this->ôàéëToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->ôàéëToolStripMenuItem->Text = L"Ôàéë";
			// 
			// îòêğûòüToolStripMenuItem
			// 
			this->îòêğûòüToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"îòêğûòüToolStripMenuItem.Image")));
			this->îòêğûòüToolStripMenuItem->Name = L"îòêğûòüToolStripMenuItem";
			this->îòêğûòüToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->îòêğûòüToolStripMenuItem->Text = L"Îòêğûòü...";
			this->îòêğûòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::îòêğûòüToolStripMenuItem_Click);
			// 
			// separateToolStripMenuItem
			// 
			this->separateToolStripMenuItem->Name = L"separateToolStripMenuItem";
			this->separateToolStripMenuItem->Size = System::Drawing::Size(159, 6);
			// 
			// ñîõğàíèòüToolStripMenuItem
			// 
			this->ñîõğàíèòüToolStripMenuItem->Enabled = false;
			this->ñîõğàíèòüToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ñîõğàíèòüToolStripMenuItem.Image")));
			this->ñîõğàíèòüToolStripMenuItem->Name = L"ñîõğàíèòüToolStripMenuItem";
			this->ñîõğàíèòüToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->ñîõğàíèòüToolStripMenuItem->Text = L"Ñîõğàíèòü";
			this->ñîõğàíèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ñîõğàíèòüToolStripMenuItem_Click);
			// 
			// ñîõğàíèòüÊàêToolStripMenuItem
			// 
			this->ñîõğàíèòüÊàêToolStripMenuItem->Enabled = false;
			this->ñîõğàíèòüÊàêToolStripMenuItem->Name = L"ñîõğàíèòüÊàêToolStripMenuItem";
			this->ñîõğàíèòüÊàêToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->ñîõğàíèòüÊàêToolStripMenuItem->Text = L"Ñîõğàíèòü êàê...";
			this->ñîõğàíèòüÊàêToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ñîõğàíèòüÊàêToolStripMenuItem_Click);
			// 
			// sepToolStripMenuItem
			// 
			this->sepToolStripMenuItem->Name = L"sepToolStripMenuItem";
			this->sepToolStripMenuItem->Size = System::Drawing::Size(159, 6);
			// 
			// çàêğûòüToolStripMenuItem
			// 
			this->çàêğûòüToolStripMenuItem->Enabled = false;
			this->çàêğûòüToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"çàêğûòüToolStripMenuItem.Image")));
			this->çàêğûòüToolStripMenuItem->ImageTransparentColor = System::Drawing::SystemColors::ButtonFace;
			this->çàêğûòüToolStripMenuItem->Name = L"çàêğûòüToolStripMenuItem";
			this->çàêğûòüToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->çàêğûòüToolStripMenuItem->Text = L"Çàêğûòü";
			this->çàêğûòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::çàêğûòüToolStripMenuItem_Click);
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"âûõîäToolStripMenuItem.Image")));
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(162, 22);
			this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			this->âûõîäToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::âûõîäToolStripMenuItem_Click);
			// 
			// òàáëèöàToolStripMenuItem
			// 
			this->òàáëèöàToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(11) {
				this->âòàâèòüToolStripMenuItem,
					this->âñòàâèòüÑòğîêóÂÊîíåöToolStripMenuItem, this->âñòàâèòüÑòğîêóÂûøåToolStripMenuItem, this->âñòàâèòüÑòğîêóÍèæåToolStripMenuItem,
					this->óäàëèòüÑòğîêóToolStripMenuItem, this->toolStripMenuItem1, this->âñòàâèòüÑòîëáåöÂÍà÷àëîToolStripMenuItem, this->âñòàâèòüÑòîëáåöÂÊîíåöToolStripMenuItem,
					this->âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem, this->âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem, this->óäàëèòüÑòîëáåöToolStripMenuItem
			});
			this->òàáëèöàToolStripMenuItem->Enabled = false;
			this->òàáëèöàToolStripMenuItem->Name = L"òàáëèöàToolStripMenuItem";
			this->òàáëèöàToolStripMenuItem->Size = System::Drawing::Size(66, 20);
			this->òàáëèöàToolStripMenuItem->Text = L"Òàáëèöà";
			// 
			// âòàâèòüToolStripMenuItem
			// 
			this->âòàâèòüToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"âòàâèòüToolStripMenuItem.Image")));
			this->âòàâèòüToolStripMenuItem->Name = L"âòàâèòüToolStripMenuItem";
			this->âòàâèòüToolStripMenuItem->Size = System::Drawing::Size(222, 22);
			this->âòàâèòüToolStripMenuItem->Text = L"Âñòàâèòü ñòğîêó â íà÷àëî";
			this->âòàâèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::âòàâèòüToolStripMenuItem_Click);
			// 
			// âñòàâèòüÑòğîêóÂÊîíåöToolStripMenuItem
			// 
			this->âñòàâèòüÑòğîêóÂÊîíåöToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"âñòàâèòüÑòğîêóÂÊîíåöToolStripMenuItem.Image")));
			this->âñòàâèòüÑòğîêóÂÊîíåöToolStripMenuItem->Name = L"âñòàâèòüÑòğîêóÂÊîíåöToolStripMenuItem";
			this->âñòàâèòüÑòğîêóÂÊîíåöToolStripMenuItem->Size = System::Drawing::Size(222, 22);
			this->âñòàâèòüÑòğîêóÂÊîíåöToolStripMenuItem->Text = L"Âñòàâèòü ñòğîêó â êîíåö";
			this->âñòàâèòüÑòğîêóÂÊîíåöToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::âñòàâèòüÑòğîêóÂÊîíåöToolStripMenuItem_Click);
			// 
			// âñòàâèòüÑòğîêóÂûøåToolStripMenuItem
			// 
			this->âñòàâèòüÑòğîêóÂûøåToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"âñòàâèòüÑòğîêóÂûøåToolStripMenuItem.Image")));
			this->âñòàâèòüÑòğîêóÂûøåToolStripMenuItem->Name = L"âñòàâèòüÑòğîêóÂûøåToolStripMenuItem";
			this->âñòàâèòüÑòğîêóÂûøåToolStripMenuItem->Size = System::Drawing::Size(222, 22);
			this->âñòàâèòüÑòğîêóÂûøåToolStripMenuItem->Text = L"Âñòàâèòü ñòğîêó âûøå";
			this->âñòàâèòüÑòğîêóÂûøåToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::âñòàâèòüÑòğîêóÂûøåToolStripMenuItem_Click);
			// 
			// âñòàâèòüÑòğîêóÍèæåToolStripMenuItem
			// 
			this->âñòàâèòüÑòğîêóÍèæåToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"âñòàâèòüÑòğîêóÍèæåToolStripMenuItem.Image")));
			this->âñòàâèòüÑòğîêóÍèæåToolStripMenuItem->Name = L"âñòàâèòüÑòğîêóÍèæåToolStripMenuItem";
			this->âñòàâèòüÑòğîêóÍèæåToolStripMenuItem->Size = System::Drawing::Size(222, 22);
			this->âñòàâèòüÑòğîêóÍèæåToolStripMenuItem->Text = L"Âñòàâèòü ñòğîêó íèæå";
			this->âñòàâèòüÑòğîêóÍèæåToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::âñòàâèòüÑòğîêóÍèæåToolStripMenuItem_Click);
			// 
			// óäàëèòüÑòğîêóToolStripMenuItem
			// 
			this->óäàëèòüÑòğîêóToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"óäàëèòüÑòğîêóToolStripMenuItem.Image")));
			this->óäàëèòüÑòğîêóToolStripMenuItem->Name = L"óäàëèòüÑòğîêóToolStripMenuItem";
			this->óäàëèòüÑòğîêóToolStripMenuItem->Size = System::Drawing::Size(222, 22);
			this->óäàëèòüÑòğîêóToolStripMenuItem->Text = L"Óäàëèòü ñòğîêó";
			this->óäàëèòüÑòğîêóToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::óäàëèòüÑòğîêóToolStripMenuItem_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(219, 6);
			// 
			// âñòàâèòüÑòîëáåöÂÍà÷àëîToolStripMenuItem
			// 
			this->âñòàâèòüÑòîëáåöÂÍà÷àëîToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"âñòàâèòüÑòîëáåöÂÍà÷àëîToolStripMenuItem.Image")));
			this->âñòàâèòüÑòîëáåöÂÍà÷àëîToolStripMenuItem->Name = L"âñòàâèòüÑòîëáåöÂÍà÷àëîToolStripMenuItem";
			this->âñòàâèòüÑòîëáåöÂÍà÷àëîToolStripMenuItem->Size = System::Drawing::Size(222, 22);
			this->âñòàâèòüÑòîëáåöÂÍà÷àëîToolStripMenuItem->Text = L"Âñòàâèòü ñòîëáåö â íà÷àëî";
			this->âñòàâèòüÑòîëáåöÂÍà÷àëîToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::âñòàâèòüÑòîëáåöÂÍà÷àëîToolStripMenuItem_Click);
			// 
			// âñòàâèòüÑòîëáåöÂÊîíåöToolStripMenuItem
			// 
			this->âñòàâèòüÑòîëáåöÂÊîíåöToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"âñòàâèòüÑòîëáåöÂÊîíåöToolStripMenuItem.Image")));
			this->âñòàâèòüÑòîëáåöÂÊîíåöToolStripMenuItem->Name = L"âñòàâèòüÑòîëáåöÂÊîíåöToolStripMenuItem";
			this->âñòàâèòüÑòîëáåöÂÊîíåöToolStripMenuItem->Size = System::Drawing::Size(222, 22);
			this->âñòàâèòüÑòîëáåöÂÊîíåöToolStripMenuItem->Text = L"Âñòàâèòü ñòîëáåö â êîíåö";
			this->âñòàâèòüÑòîëáåöÂÊîíåöToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::âñòàâèòüÑòîëáåöÂÊîíåöToolStripMenuItem_Click);
			// 
			// âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem
			// 
			this->âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem.Image")));
			this->âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem->Name = L"âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem";
			this->âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem->Size = System::Drawing::Size(222, 22);
			this->âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem->Text = L"Âñòàâèòü ñòîëáåö ñëåâà";
			this->âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem_Click);
			// 
			// âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem
			// 
			this->âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem.Image")));
			this->âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem->Name = L"âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem";
			this->âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem->Size = System::Drawing::Size(222, 22);
			this->âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem->Text = L"Âñòàâèòü ñòîëáåö ñïğàâà";
			this->âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem_Click);
			// 
			// óäàëèòüÑòîëáåöToolStripMenuItem
			// 
			this->óäàëèòüÑòîëáåöToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"óäàëèòüÑòîëáåöToolStripMenuItem.Image")));
			this->óäàëèòüÑòîëáåöToolStripMenuItem->Name = L"óäàëèòüÑòîëáåöToolStripMenuItem";
			this->óäàëèòüÑòîëáåöToolStripMenuItem->Size = System::Drawing::Size(222, 22);
			this->óäàëèòüÑòîëáåöToolStripMenuItem->Text = L"Óäàëèòü ñòîëáåö";
			this->óäàëèòüÑòîëáåöToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::óäàëèòüÑòîëáåöToolStripMenuItem_Click);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->âñòàâèòüÑòğîêóToolStripMenuItem,
					this->âñòàâèòüÑòîëáåöToolStripMenuItem, this->óäàëèòüÑòğîêóToolStripMenuItem1, this->toolStripMenuItem2, this->âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem1,
					this->âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem1, this->óäàëèòüÑòîëáåöToolStripMenuItem1
			});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->contextMenuStrip1->Size = System::Drawing::Size(212, 142);
			// 
			// âñòàâèòüÑòğîêóToolStripMenuItem
			// 
			this->âñòàâèòüÑòğîêóToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"âñòàâèòüÑòğîêóToolStripMenuItem.Image")));
			this->âñòàâèòüÑòğîêóToolStripMenuItem->Name = L"âñòàâèòüÑòğîêóToolStripMenuItem";
			this->âñòàâèòüÑòğîêóToolStripMenuItem->Size = System::Drawing::Size(211, 22);
			this->âñòàâèòüÑòğîêóToolStripMenuItem->Text = L"Âñòàâèòü ñòğîêó âûøå";
			this->âñòàâèòüÑòğîêóToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::âñòàâèòüÑòğîêóToolStripMenuItem_Click);
			// 
			// âñòàâèòüÑòîëáåöToolStripMenuItem
			// 
			this->âñòàâèòüÑòîëáåöToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"âñòàâèòüÑòîëáåöToolStripMenuItem.Image")));
			this->âñòàâèòüÑòîëáåöToolStripMenuItem->Name = L"âñòàâèòüÑòîëáåöToolStripMenuItem";
			this->âñòàâèòüÑòîëáåöToolStripMenuItem->Size = System::Drawing::Size(211, 22);
			this->âñòàâèòüÑòîëáåöToolStripMenuItem->Text = L"Âñòàâèòü ñòğîêó íèæå";
			this->âñòàâèòüÑòîëáåöToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::âñòàâèòüÑòîëáåöToolStripMenuItem_Click);
			// 
			// óäàëèòüÑòğîêóToolStripMenuItem1
			// 
			this->óäàëèòüÑòğîêóToolStripMenuItem1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"óäàëèòüÑòğîêóToolStripMenuItem1.Image")));
			this->óäàëèòüÑòğîêóToolStripMenuItem1->Name = L"óäàëèòüÑòğîêóToolStripMenuItem1";
			this->óäàëèòüÑòğîêóToolStripMenuItem1->Size = System::Drawing::Size(211, 22);
			this->óäàëèòüÑòğîêóToolStripMenuItem1->Text = L"Óäàëèòü ñòğîêó";
			this->óäàëèòüÑòğîêóToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::óäàëèòüÑòğîêóToolStripMenuItem1_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(208, 6);
			// 
			// âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem1
			// 
			this->âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem1.Image")));
			this->âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem1->Name = L"âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem1";
			this->âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem1->Size = System::Drawing::Size(211, 22);
			this->âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem1->Text = L"Âñòàâèòü ñòîëáåö ñëåâà";
			this->âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem1_Click);
			// 
			// âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem1
			// 
			this->âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem1.Image")));
			this->âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem1->Name = L"âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem1";
			this->âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem1->Size = System::Drawing::Size(211, 22);
			this->âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem1->Text = L"Âñòàâèòü ñòîëáåö ñïğàâà";
			this->âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem1_Click);
			// 
			// óäàëèòüÑòîëáåöToolStripMenuItem1
			// 
			this->óäàëèòüÑòîëáåöToolStripMenuItem1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"óäàëèòüÑòîëáåöToolStripMenuItem1.Image")));
			this->óäàëèòüÑòîëáåöToolStripMenuItem1->Name = L"óäàëèòüÑòîëáåöToolStripMenuItem1";
			this->óäàëèòüÑòîëáåöToolStripMenuItem1->Size = System::Drawing::Size(211, 22);
			this->óäàëèòüÑòîëáåöToolStripMenuItem1->Text = L"Óäàëèòü ñòîëáåö";
			this->óäàëèòüÑòîëáåöToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::óäàëèòüÑòîëáåöToolStripMenuItem1_Click);
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
			// îÏğîãğàììåToolStripMenuItem
			// 
			this->îÏğîãğàììåToolStripMenuItem->Name = L"îÏğîãğàììåToolStripMenuItem";
			this->îÏğîãğàììåToolStripMenuItem->Size = System::Drawing::Size(103, 20);
			this->îÏğîãğàììåToolStripMenuItem->Text = L"Î ïğîãğàììå...";
			this->îÏğîãğàììåToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::îÏğîãğàììåToolStripMenuItem_Click);
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

	private: System::Void îòêğûòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);

	private: System::Void dataGridView1_CellMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e);
			 
	private: System::Void dataGridView1_CellEndEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e);
	
	private: System::Void âòàâèòüToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e); 
    private: System::Void âñòàâèòüÑòğîêóÂÊîíåöToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void âñòàâèòüÑòğîêóÂûøåToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void âñòàâèòüÑòğîêóÍèæåToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void óäàëèòüÑòğîêóToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
    
    private: System::Void âñòàâèòüÑòîëáåöÂÍà÷àëîToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void âñòàâèòüÑòîëáåöÂÊîíåöToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void óäàëèòüÑòîëáåöToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void âñòàâèòüÑòğîêóToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void âñòàâèòüÑòîëáåöToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void óäàëèòüÑòğîêóToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void âñòàâèòüÑòîëáåöÑëåâàToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void âñòàâèòüÑòîëáåöÑïğàâàToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e);
    private: System::Void óäàëèòüÑòîëáåöToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e);
    
	private: System::Void ñîõğàíèòüToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	 
	private: System::Void ñîõğàíèòüÊàêToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

    private: System::Void çàêğûòüToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void âûõîäToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
	private: System::Void îÏğîãğàììåToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
};
}
