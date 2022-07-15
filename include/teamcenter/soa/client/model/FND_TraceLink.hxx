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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND_TRACELINK_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND_TRACELINK_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ImanRelation.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class PSBOMView;
                class PSBOMView;
                class Fnd0CustomNoteRevision;


class TCSOACLIENTMNGD_API FND_TraceLink : public Teamcenter::Soa::Client::Model::ImanRelation
{
public:
    const std::string& get_name();
    const std::string& get_description();
    Teamcenter::Soa::Common::AutoPtr<PSBOMView> get_fnd0PrimaryBomView();
    Teamcenter::Soa::Common::AutoPtr<PSBOMView> get_fnd0SecondaryBomView();
    size_t count_fnd0CustomNotes();
    Teamcenter::Soa::Common::AutoPtr<Fnd0CustomNoteRevision> get_fnd0CustomNotes_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("FND_TraceLink")

   virtual ~FND_TraceLink();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
