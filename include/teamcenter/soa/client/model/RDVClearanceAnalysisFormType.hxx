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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_RDVCLEARANCEANALYSISFORMTYPE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_RDVCLEARANCEANALYSISFORMTYPE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API RDVClearanceAnalysisFormType : public Teamcenter::Soa::Client::Model::Form
{
public:
    const Teamcenter::Soa::Client::StringVector& get_SelectedApprPathNodeUID();
    const Teamcenter::Soa::Client::StringVector& get_ComparableApprPathNodeUID();
    const std::string& get_SESSIONID();
    const Teamcenter::Soa::Client::StringVector& get_IssueAttributes();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("RDVClearanceAnalysisFormType")

   virtual ~RDVClearanceAnalysisFormType();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
