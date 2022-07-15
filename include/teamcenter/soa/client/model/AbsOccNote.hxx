/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

  Auto-generated source from Teamcenter Data Model.
                 DO NOT EDIT

 ==================================================
*/

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ABSOCCNOTE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ABSOCCNOTE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/AbsOccData.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class NoteType;


class TCSOACLIENTMNGD_API AbsOccNote : public Teamcenter::Soa::Client::Model::AbsOccData
{
public:
    const std::string& get_note_text();
    Teamcenter::Soa::Common::AutoPtr<NoteType> get_note_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AbsOccNote")

   virtual ~AbsOccNote();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
