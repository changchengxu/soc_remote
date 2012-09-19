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

namespace soc_remote
{
	namespace soc_control {
		ref class cc_event
		{
		public:
			cc_event(void);
		public:
			String^ mCtr_Event;
			String^ mCtrl_Line;
		public:
			property List<cc_event^>^ eventItems {
				List<cc_event^>^ get(void) {
					return mEventCollection;
				}
			}
			Int32 addEvent(DataRow^ row,DataTable^ dt);
		private:
			List<cc_event^>^ mEventCollection;

		};
	}
}
using namespace soc_remote::soc_control;

