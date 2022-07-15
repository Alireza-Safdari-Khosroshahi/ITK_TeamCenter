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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRLOGICALASSIGNMENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRLOGICALASSIGNMENT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mfg0MELogicalAssignment.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Mfg0BvrLogicalAssignment : public Teamcenter::Soa::Client::Model::Mfg0MELogicalAssignment
{
public:
    const std::string& get_Mfg0equivalence_id();
    const std::string& get_Mfg0assignment_type();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0resolved_nodes();
    const std::string& get_Mfg0criteria_representation();
    const std::string& get_Mfg0assignment_name();
    const std::string& get_Mfg0assignment_description();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0BvrLogicalAssignment")

   virtual ~Mfg0BvrLogicalAssignment();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
