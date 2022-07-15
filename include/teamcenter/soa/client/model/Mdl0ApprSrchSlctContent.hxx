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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MDL0APPRSRCHSLCTCONTENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MDL0APPRSRCHSLCTCONTENT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ApprSearchCriteriaSlctState.hxx>

#include <teamcenter/soa/client/model/AppmodelMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Mdl0ModelElement;
                class Mdl0ModelElement;


class TCSOAAPPMODELMODELMNGD_API Mdl0ApprSrchSlctContent : public Teamcenter::Soa::Client::Model::ApprSearchCriteriaSlctState
{
public:
    size_t count_mdl0selected_contents();
    Teamcenter::Soa::Common::AutoPtr<Mdl0ModelElement> get_mdl0selected_contents_at( size_t inx );
    size_t count_mdl0unselected_contents();
    Teamcenter::Soa::Common::AutoPtr<Mdl0ModelElement> get_mdl0unselected_contents_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mdl0ApprSrchSlctContent")

   virtual ~Mdl0ApprSrchSlctContent();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AppmodelMngd_undef.h>
#endif
