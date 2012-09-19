#pragma once
using namespace System;
using namespace System::Data;
using namespace System::Collections::Generic;
using namespace System::IO;

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Globalization;
using namespace System::IO;
using namespace GSoft::Utility;

#include "cc_event.h"

namespace soc_remote {
	namespace soc_control {
		ref class control
		{
		public:
			control(void);
			//property String^ Ctr_dir {
			//	String^ get(void) {
			//		return Ctr_mdir;
			//	}

			//	Void set(String^ value) {
			//		if (!File::Exists(value)) return;
			//		Ctr_mdir = value;
			//	}
			//}
			//Int32 CtrlLoad(String^ dir);
		public:
			Int32 Ctr_X;
			Int32 Ctr_Y;
			Int32 Ctr_Width;
			Int32 Ctr_Height;
			String^ Ctr_Type;
			String^ Ctr_Text;
			//String^ Ctr_Event;
			//String^ Ctrl_Line;
			cc_event^ mevent;

		};

		ref class controls
		{
		public:
			controls(void);
			property List<control^>^ ctrlsItem {
				List<control^>^ get(void) {
					return mcontrolItems;
				}
			}
			property Int32 ctrlCount {
				Int32 get(void) {
					if (mcontrolItems == nullptr) return -1;
					return mcontrolItems->Count;
				}
			}
			/*property control^ current {
				control^ get(void) {
					return CurrentCtr;
				}

				Void set(control^ value) {
					CurrentCtr = value;
				}
			}*/
			Int32 load(String^ fileName);
			Int32 loadDataSet(String^ dir,DataSet^ ds);

		private:
			List<control^>^ mcontrolItems;
		private:
			Int32 createDataSet(DataSet^ ds);
		};
	}
}
using namespace soc_remote::soc_control;