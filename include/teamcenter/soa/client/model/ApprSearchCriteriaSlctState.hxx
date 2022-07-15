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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPRSEARCHCRITERIASLCTSTATE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPRSEARCHCRITERIASLCTSTATE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ApprSearchCriteria.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class MEAppearancePathNode;
                class MEAppearancePathNode;


class TCSOACLIENTMNGD_API ApprSearchCriteriaSlctState : public Teamcenter::Soa::Client::Model::ApprSearchCriteria
{
public:
    size_t count_selected_meapprpathnodes();
    Teamcenter::Soa::Common::AutoPtr<MEAppearancePathNode> get_selected_meapprpathnodes_at( size_t inx );
    size_t count_unselected_meapprpathnodes();
    Teamcenter::Soa::Common::AutoPtr<MEAppearancePathNode> get_unselected_meapprpathnodes_at( size_t inx );
    const Teamcenter::Soa::Client::StringVector& get_fnd0selected_occ_list();
    const Teamcenter::Soa::Client::StringVector& get_fnd0unselected_occ_list();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ApprSearchCriteriaSlctState")

   virtual ~ApprSearchCriteriaSlctState();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
