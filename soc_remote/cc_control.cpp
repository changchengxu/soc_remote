#include "stdafx.h"
#include "cc_control.h"
#include "gf_main.h"

#define  MCTRLTEXT		"text"
#define  MCTRLTYPE		"type"

control::control(void)
{		
	mevent=gcnew cc_event;
}

controls::controls(void)
{
	mcontrolItems=gcnew List<control^>;
}

Int32 controls::load(String^ fileName)
{
	DataTable^ dtTemp=gcnew DataTable;
	mcontrolItems->Clear();

	String^ printInfo="bind control... ...";
	ConsoleU::writeLine(printInfo, ConsoleU::Level::Warning);

	DataSet^ ds=gcnew DataSet();
	String^ fileExtension = Path::GetExtension(fileName);
	if (fileExtension != ".xml" || !File::Exists(fileName))
	{
		ConsoleU::writeLine("this file is not xml or path error,please select again!", ConsoleU::Level::Warning);
	}
	ds->ReadXml(fileName);
	dtTemp=ds->Tables[DIRCTRL];

	if(dtTemp==nullptr) {	printInfo="Cannot find node,please try again...";ConsoleU::writeLine(printInfo, ConsoleU::Level::Warning); return -1;}
	if(dtTemp->Rows==nullptr) {printInfo="Cannot find node rows,please try again..."; ConsoleU::writeLine(printInfo, ConsoleU::Level::Warning);return -1;}

	for each (DataRow^ row in dtTemp->Rows)
	{
		control^ ctrl=gcnew control;
		try
		{ctrl->Ctr_Text=row[CTRLTEXT]->ToString();}
		catch (FormatException^) {}
		try
		{ctrl->Ctr_X=Int32::Parse(row[CTRLX]->ToString());}
		catch (FormatException^) {}
		try
		{ctrl->Ctr_Y=Int32::Parse(row[CTRLY]->ToString());}
		catch (FormatException^) {}
		try
		{ctrl->Ctr_Width=Int32::Parse(row[CTRLWIDTH]->ToString());}
		catch (FormatException^) {}
		try
		{ctrl->Ctr_Height=Int32::Parse(row[CTRLHEIGHT]->ToString());}
		catch (FormatException^) {}
		try
		{ctrl->Ctr_Type=row[CTRLTYPE]->ToString();}
		catch (FormatException^) {}

#if print
		if(mprint!=nullptr)
		{ConsoleU::writeLine(mprint, ConsoleU::Level::Warning);}
#endif
		//ConsoleU::writeLine(String::Format("control event loaded. -> {0}", mevent->Ctr_Event), ConsoleU::Level::Info);
		DataSet^ ds=gcnew DataSet();
		ds->ReadXml(fileName);

		DataRelationCollection^ childRelations = dtTemp->ChildRelations;
		if (childRelations->Count > 0) {
			DataRelation^ relation = childRelations[String::Format("{0}_{1}",DIRCTRL, DIREVENT)];
			array<DataRow^>^ ruleRows = row->GetChildRows(relation);
			for each (DataRow^ ruleRow in ruleRows) {
				ctrl->mevent->addEvent(ruleRow,ds->Tables[DIREVENT]);//init controls event
			}
		}

		mcontrolItems->Add(ctrl);
	}
#if print
	ConsoleU::writeLine(String::Format("control loaded. -> {0}", ctrlCount), ConsoleU::Level::Normal);
#endif
	return 0;
}

#pragma region init DataSet
Int32 controls::loadDataSet(String^ dir,DataSet^ ds)
{
	load(dir);
	createDataSet(ds);
	DataTable^ dtCtrol=ds->Tables[DIRCTRL];
	DataTable^ dtEvent=ds->Tables[DIREVENT];
	for each(control^ ctrl in ctrlsItem)
	{
		DataRow^ dr=dtCtrol->NewRow();
		dr[CTRLTEXT]=ctrl->Ctr_Text;
		dr[CTRLX]=ctrl->Ctr_X;
		dr[CTRLY]=ctrl->Ctr_Y;
		dr[CTRLWIDTH]=ctrl->Ctr_Width;
		dr[CTRLHEIGHT]=ctrl->Ctr_Height;
		dr[CTRLTYPE]=ctrl->Ctr_Type;
		dtCtrol->Rows->Add(dr);
		for each(cc_event^ locEvent in ctrl->mevent->eventItems)
		{
			DataRow^ dr=dtEvent->NewRow();
			dr[CTRLEVENTNAME]=ctrl->Ctr_Text;
			dr[CTRLEVENT]=locEvent->mCtr_Event;
			dr[CTRLLINE]=locEvent->mCtrl_Line;
			dtEvent->Rows->Add(dr);
		}
	}
	return 0;
}

Int32 controls::createDataSet(DataSet^ ds)
{
	//init control
	DataTable^ dtCtrol = gcnew DataTable(DIRCTRL);
	array<Object^, 2>^ columnsCtrol= gcnew array<Object^, 2>{
		{ CTRLTEXT,			String::typeid},
		{ CTRLX,			Int32::typeid },
		{ CTRLY,			Int32::typeid },
		{ CTRLWIDTH,		Int32::typeid },
		{ CTRLHEIGHT,		Int32::typeid },
		{ CTRLTYPE,		    String::typeid },
	};

	Table::makeDataTable(dtCtrol, columnsCtrol);
	ds->Tables->Add(dtCtrol);

	//init control event
	DataTable^ dtEvent = gcnew DataTable(DIREVENT);
	array<Object^, 2>^ columnsEvent = gcnew array<Object^, 2>{
		{ CTRLEVENTNAME,	String::typeid},
		{ CTRLEVENT,		String::typeid },
		{ CTRLLINE,			String::typeid },
	};

	Table::makeDataTable(dtEvent, columnsEvent);
	ds->Tables->Add(dtEvent);

	// create relation
	DataRelation^ drPageReg = gcnew DataRelation("", dtCtrol->Columns[CTRLTEXT], 
		dtEvent->Columns[CTRLEVENTNAME]);
	drPageReg->Nested = true;
	ds->Relations->Add(drPageReg);
	return 0;
}
#pragma endregion



