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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPD0DESIGNSUBSETINSTANCE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPD0DESIGNSUBSETINSTANCE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Rlz0ModelRealization.hxx>

#include <teamcenter/soa/client/model/CpdMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ApprSearchCriteria;
                class Cpd0DesignSubsetElement;


class TCSOACPDMODELMNGD_API Cpd0DesignSubsetInstance : public Teamcenter::Soa::Client::Model::Rlz0ModelRealization
{
public:
    Teamcenter::Soa::Common::AutoPtr<ApprSearchCriteria> get_cpd0search_criteria();
    Teamcenter::Soa::Common::AutoPtr<Cpd0DesignSubsetElement> get_cpd0reuse_element();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cpd0DesignSubsetInstance")

   virtual ~Cpd0DesignSubsetInstance();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CpdMngd_undef.h>
#endif
