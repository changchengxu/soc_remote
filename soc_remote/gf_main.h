#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace GSoft::Utility;
using namespace System::IO;
using namespace System::IO::Ports;
using namespace System::Runtime::InteropServices;
using namespace System::Diagnostics;
using namespace System::Threading;
#include "cc_control.h"

#define VERSION 1.0
#define FILEPATH		"config"
#define TREENAME		"remote.xml"
#define CTRLNAME		"controlFile.xml"

#define DIRTREE			"dirtree"
#define DIRCTRL			"control"
#define DIREVENT		"event"

#define CURRENT			"current"
#define PARENT			"parent"
#define CURRENTNMAE		"currentname"
#define VMPU			"VMPU"
#define REMOTE			"Remote"

#define CTRLTEXT		"text"
#define CTRLX			"x"
#define CTRLY			"y"
#define CTRLWIDTH		"w"
#define CTRLHEIGHT		"h"
#define CTRLTYPE		"type"
#define CTRLEVENT		"event"
#define CTRLLINE		"line"
#define CTRLEVENTNAME	"eventname"

namespace soc_remote {

	/// <summary>
	/// Summary for gf_main
	/// </summary>
	public ref class gf_main : public System::Windows::Forms::Form
	{
	public:
		gf_main(array<System::String ^> ^args);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~gf_main();
	private: System::Windows::Forms::ToolStripContainer^  toolStripContainer1;
	protected: 
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::TreeView^  treeView_dir;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  viewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  debugToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^  dataGridView1;







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->toolStripContainer1 = (gcnew System::Windows::Forms::ToolStripContainer());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->treeView_dir = (gcnew System::Windows::Forms::TreeView());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->debugToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripContainer1->ContentPanel->SuspendLayout();
			this->toolStripContainer1->TopToolStripPanel->SuspendLayout();
			this->toolStripContainer1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolStripContainer1
			// 
			// 
			// toolStripContainer1.ContentPanel
			// 
			this->toolStripContainer1->ContentPanel->Controls->Add(this->panel2);
			this->toolStripContainer1->ContentPanel->Controls->Add(this->panel1);
			this->toolStripContainer1->ContentPanel->Size = System::Drawing::Size(714, 491);
			this->toolStripContainer1->Location = System::Drawing::Point(1, 1);
			this->toolStripContainer1->Name = L"toolStripContainer1";
			this->toolStripContainer1->Size = System::Drawing::Size(714, 515);
			this->toolStripContainer1->TabIndex = 0;
			this->toolStripContainer1->Text = L"toolStripContainer1";
			// 
			// toolStripContainer1.TopToolStripPanel
			// 
			this->toolStripContainer1->TopToolStripPanel->Controls->Add(this->menuStrip1);
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->Controls->Add(this->dataGridView1);
			this->panel2->Location = System::Drawing::Point(183, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(489, 489);
			this->panel2->TabIndex = 1;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(3, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 23;
			this->dataGridView1->Size = System::Drawing::Size(483, 483);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->Visible = false;
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->Controls->Add(this->treeView_dir);
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(176, 485);
			this->panel1->TabIndex = 0;
			// 
			// treeView_dir
			// 
			this->treeView_dir->Dock = System::Windows::Forms::DockStyle::Fill;
			this->treeView_dir->Location = System::Drawing::Point(0, 0);
			this->treeView_dir->Name = L"treeView_dir";
			this->treeView_dir->Size = System::Drawing::Size(176, 485);
			this->treeView_dir->TabIndex = 0;
			this->treeView_dir->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &gf_main::treeView_dir_AfterSelect);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Dock = System::Windows::Forms::DockStyle::None;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, 
				this->viewToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(714, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->loadToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// loadToolStripMenuItem
			// 
			this->loadToolStripMenuItem->Name = L"loadToolStripMenuItem";
			this->loadToolStripMenuItem->Size = System::Drawing::Size(97, 22);
			this->loadToolStripMenuItem->Text = L"load";
			// 
			// viewToolStripMenuItem
			// 
			this->viewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->debugToolStripMenuItem});
			this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			this->viewToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->viewToolStripMenuItem->Text = L"View";
			// 
			// debugToolStripMenuItem
			// 
			this->debugToolStripMenuItem->Name = L"debugToolStripMenuItem";
			this->debugToolStripMenuItem->Size = System::Drawing::Size(109, 22);
			this->debugToolStripMenuItem->Text = L"Debug";
			this->debugToolStripMenuItem->Click += gcnew System::EventHandler(this, &gf_main::debugToolStripMenuItem_Click);
			// 
			// gf_main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(671, 515);
			this->Controls->Add(this->toolStripContainer1);
			this->Name = L"gf_main";
			this->Text = L"soc_remote software";
			this->Load += gcnew System::EventHandler(this, &gf_main::gf_main_Load);
			this->Shown += gcnew System::EventHandler(this, &gf_main::gf_main_Shown);
			this->toolStripContainer1->ContentPanel->ResumeLayout(false);
			this->toolStripContainer1->TopToolStripPanel->ResumeLayout(false);
			this->toolStripContainer1->TopToolStripPanel->PerformLayout();
			this->toolStripContainer1->ResumeLayout(false);
			this->toolStripContainer1->PerformLayout();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		String^ mArgs;
		String^ dir;
		DockU^ mDockTuner;
	private:
		controls^ mctrls;
	private: System::Void gf_main_Shown(System::Object^  sender, System::EventArgs^  e) ;
	private: System::Void debugToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void gf_main_Load(System::Object^  sender, System::EventArgs^  e);
			 Void loadRemoteTree(void) ;
			 Void loadCtrls(Void);
			 //bool gf_main::nodeTextFunc(String^ nodeID,String^ nodeText);
			 Void gf_main::funcBack( DataRowCollection^ tempDtRows,String^ nodeID,String^ nodeText,TreeNode^ tmpNode);
	private: System::Void treeView_dir_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e);
};
}
using namespace soc_remote;