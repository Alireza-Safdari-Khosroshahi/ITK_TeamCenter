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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MDL0APPRSRCHCRTOPTIONSET_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MDL0APPRSRCHCRTOPTIONSET_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ApprSearchCriteria.hxx>

#include <teamcenter/soa/client/model/AppmodelMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class TransferOptionSet;


class TCSOAAPPMODELMODELMNGD_API Mdl0ApprSrchCrtOptionSet : public Teamcenter::Soa::Client::Model::ApprSearchCriteria
{
public:
    Teamcenter::Soa::Common::AutoPtr<TransferOptionSet> get_mdl0optionSet();
    const Teamcenter::Soa::Client::StringVector& get_mdl0optionNames();
    const Teamcenter::Soa::Client::StringVector& get_mdl0optionValues();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mdl0ApprSrchCrtOptionSet")

   virtual ~Mdl0ApprSrchCrtOptionSet();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AppmodelMngd_undef.h>
#endif
