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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0APPRSCHCRITERIASCPATTR_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0APPRSCHCRITERIASCPATTR_HXX

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
                class AppearanceGroup;


class TCSOACLIENTMNGD_API Fnd0ApprSchCriteriaScpAttr : public Teamcenter::Soa::Client::Model::ApprSearchCriteria
{
public:
    const Teamcenter::Soa::Client::StringVector& get_fnd0occ_list();
    size_t count_fnd0meapprpathnodes();
    Teamcenter::Soa::Common::AutoPtr<MEAppearancePathNode> get_fnd0meapprpathnodes_at( size_t inx );
    size_t count_fnd0occ_grp();
    Teamcenter::Soa::Common::AutoPtr<AppearanceGroup> get_fnd0occ_grp_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0ApprSchCriteriaScpAttr")

   virtual ~Fnd0ApprSchCriteriaScpAttr();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
