#include "stdafx.h"
#include "gf_main.h"

#define  print 1

gf_main::gf_main(array<System::String ^> ^args) {
	InitializeComponent();	

	//
	//TODO: Add the constructor code here
	//
	Text = String::Format("{0} v{1} < build {2}-{3} >", Text, VERSION, __DATE__, __TIME__);
	ConsoleU::writeLine(Text, ConsoleU::Level::Warning);

	mArgs = String::Empty;
	for each (String^ arg in args) {
		mArgs += arg + " ";
	}
	mArgs = mArgs->Trim();

	ConsoleU::writeLine(String::Format("args = \"{0}\"", mArgs), ConsoleU::Level::Warning);
	ConsoleU::writeLine(String::Format("work dir = \"{0}\"", Directory::GetCurrentDirectory()),
		ConsoleU::Level::Warning);

	mctrls=gcnew controls;

	mDockTuner = gcnew DockU(this);
	mDockTuner->isEnabled = true;
}

gf_main::~gf_main() {
	if (components)	{
		delete components;
	}
}

Void gf_main::gf_main_Load(System::Object^ sender, System::EventArgs^ e)
{
	loadRemoteTree();

	//mctrls->load(dir);
	dir=String::Format("{0}/{1}/{2}", 
		Directory::GetCurrentDirectory(), FILEPATH, CTRLNAME);
	DataSet^ ds=gcnew DataSet;
	mctrls->loadDataSet(dir,ds);//init DataSet
	dataGridView1->DataSource=ds->Tables[DIREVENT];//init dataGridView 
	loadCtrls();//init control
}

Void gf_main::gf_main_Shown(System::Object^ sender, System::EventArgs^ e)
{
	ConsoleU::show();
}

#pragma region load tree
Void gf_main::loadRemoteTree(void) {
	treeView_dir->Nodes->Clear();
	DataTable^ dtTemp=gcnew DataTable;

	String^ printInfo="bind tree node... ...";
	ConsoleU::writeLine(printInfo, ConsoleU::Level::Warning);

	DataSet^ ds=gcnew DataSet();
	/*dir=String::Format("{0}/{1}/{2}", 
	Directory::GetCurrentDirectory(), FILEPATH, CTRLNAME);*/
	dir=String::Format("{0}/{1}/{2}", 
		Directory::GetCurrentDirectory(), FILEPATH, TREENAME);

	String^ fileExtension = Path::GetExtension(dir);
	if (fileExtension != ".xml" || !File::Exists(dir))
	{
		ConsoleU::writeLine("this file is not xml or path error,please select again!", ConsoleU::Level::Warning);
	}
	ds->ReadXml(dir);
	dtTemp=ds->Tables[DIRTREE];

	if(dtTemp==nullptr) {	printInfo="Cannot find node,please try again...";ConsoleU::writeLine(printInfo, ConsoleU::Level::Warning); return ;}
	if(dtTemp->Rows==nullptr) {printInfo="Cannot find node rows,please try again..."; ConsoleU::writeLine(printInfo, ConsoleU::Level::Warning);return ;}

	Int32 index=0;
	for each (DataRow^ row in dtTemp->Rows)
	{
		List<String^ >^ tempnode=gcnew List<String^ >;
		if(Int32::Parse(row[PARENT]->ToString())==0)
		{
			tempnode->Add(row[CURRENTNMAE]->ToString());
			tempnode->Add(row[CURRENT]->ToString());
			treeView_dir->Nodes->Add(row[CURRENTNMAE]->ToString());

			//for each (DataRow^ row in dtRows)
			//{
			//	if(row[PARENT]->ToString()==tempnode[1] && nodeTextFunc(tempnode[1],tempnode[0]))	
			//	{
			//		/*bool a=nodeTextFunc(tempnode[1],tempnode[0]);*/
			//		//String^ aa=tempnode[1];
			//		//String^ bb=tempnode[0];
			//		//String^ b=row[PARENT]->ToString();
			//		//String^ c=row[CURRENTNMAE]->ToString();
			//		treeView_dir->Nodes[index]->Nodes->Add(row[CURRENTNMAE]->ToString());
			//	}

			//}
			funcBack(dtTemp->Rows,tempnode[1],tempnode[0],treeView_dir->Nodes[index]);
			index++;
		}
	}
	treeView_dir->ExpandAll();
}

Void gf_main::funcBack( DataRowCollection^ tempDtRows,String^ nodeID,String^ nodeText,TreeNode^ tmpNode)
{  
	if(tempDtRows==nullptr) return;
	Int32 index=0;
	for each (DataRow^ mrow in tempDtRows)
	{
		List<String^ >^ tempnode=gcnew List<String^ >;
		//if(row[PARENT]->ToString()==nodeID && nodeTextFunc(nodeID,nodeText))	
		if(mrow[PARENT]->ToString()==nodeID)	
		{
			tempnode->Add(mrow[CURRENTNMAE]->ToString());
			tempnode->Add(mrow[CURRENT]->ToString());
			tmpNode->Nodes->Add(mrow[CURRENTNMAE]->ToString());
			funcBack(tempDtRows,tempnode[1],tempnode[0],tmpNode->Nodes[index]);
			index++;
		}
	}
}
#pragma endregion

#pragma region Treeview Select
Void gf_main::treeView_dir_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e)
{
#if print
	ConsoleU::writeLine(String::Format("node selected. -> {0}", e->Node->FullPath), ConsoleU::Level::Info);
#endif
	if(e->Node->Text==VMPU)
	{

		panel2->Visible=true;
		dataGridView1->Visible=false;
	}
	else if(e->Node->Text==REMOTE)
	{
		/*panel2->Visible=false;*/
		dataGridView1->Visible=true;
	}
}
#pragma endregion

#pragma region loadCtrl
Void gf_main::loadCtrls(void)
{
	if(mctrls->ctrlCount>0)
	{
		Int32 index=1;
		for each(control^ ctrl in mctrls->ctrlsItem)
		{
			if(ctrl->Ctr_Type=="button")
			{
				System::Windows::Forms::Button^ button;
				button = (gcnew System::Windows::Forms::Button());
				button->Name="button_"+index;
				button->Text=ctrl->Ctr_Text;
				button->TabIndex = index;
				this->panel2->Controls->Add(button);

				button->Location = System::Drawing::Point(ctrl->Ctr_X, ctrl->Ctr_Y);
				button->Size = System::Drawing::Size(ctrl->Ctr_Width, ctrl->Ctr_Height);
				button->UseVisualStyleBackColor = true;
				String^  color="0,1,2,3,4,5,6,7,8,9,UP,DOWN,LEFT,RIGHT";
				for each(String^ tempColor in color->Split(','))
				{
					if(ctrl->Ctr_Text==tempColor) {button->BackColor=System::Drawing::Color::Gray;}
				}
				//button->Click+=gcnew EventHandler();
#if print
				ConsoleU::writeLine(String::Format("buttonName={0}\"buttonText={1}\"X={2}\"Y={3}",button->Name,button->Text,ctrl->Ctr_X,ctrl->Ctr_Y), ConsoleU::Level::Info);
#endif
			}
			index++;
		}
	}
}
#pragma endregion

#pragma region open debug console
Void gf_main::debugToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	ToolStripMenuItem^ menuItem = (ToolStripMenuItem^) sender;
	menuItem->Checked = !menuItem->Checked;
	if (menuItem->Checked) {
		ConsoleU::createConsole();
	} else {
		ConsoleU::releaseConsole();
	}
}
#pragma endregion

