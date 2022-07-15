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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0MELOGICALASSIGNMENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0MELOGICALASSIGNMENT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ApprSearchCriteria;
                class PSOccurrenceType;


class TCSOACLIENTMNGD_API Mfg0MELogicalAssignment : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<ApprSearchCriteria> get_Mfg0search_criteria();
    Teamcenter::Soa::Common::AutoPtr<PSOccurrenceType> get_Mfg0occurrence_type();
    const std::string& get_Mfg0name();
    const std::string& get_Mfg0description();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0MEResolvedAssignmentRel();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0MELogicalAssignment")

   virtual ~Mfg0MELogicalAssignment();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
