#include "stdafx.h"
#include "cc_event.h"
#include "gf_main.h"

cc_event::cc_event(void)
{
	mEventCollection=gcnew List<cc_event^>;
}
Int32 cc_event::addEvent(DataRow^ dr,DataTable^ dt)
{
		if(dt!=nullptr)
		{
			DataRelationCollection^ relations = dt->ChildRelations;
			if (relations->Count > 0) {
				DataRelation^ relationAddress = relations[0];
				array<DataRow^>^ rowsAddress = dr->GetChildRows(relationAddress);
				for each (DataRow^ mRow in rowsAddress) {
					try {
						cc_event^ mevent =gcnew cc_event;
						mevent->mCtr_Event=mRow[CTRLEVENT]->ToString();
						mevent->mCtrl_Line=mRow[CTRLLINE]->ToString();

						mEventCollection->Add(mevent);
						} catch (FormatException^) {
						}
				}
			}
			else
			{
					try {
						cc_event^ mevent =gcnew cc_event;
						mevent->mCtr_Event=dr[CTRLTYPE]->ToString();
						mevent->mCtrl_Line=dr[CTRLLINE]->ToString();

						mEventCollection->Add(mevent);
					} catch (FormatException^) {
					}
			}
		}
		return 0;
}