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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPD0DESIGNITEMINSTANCE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPD0DESIGNITEMINSTANCE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Rlz0ItemRealization.hxx>

#include <teamcenter/soa/client/model/CpdMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Cpd0DesignElement;


class TCSOACPDMODELMNGD_API Cpd0DesignItemInstance : public Teamcenter::Soa::Client::Model::Rlz0ItemRealization
{
public:
    Teamcenter::Soa::Common::AutoPtr<Cpd0DesignElement> get_cpd0reuse_element();
    const Teamcenter::Soa::Common::DateTime& get_cpd0structure_lmd();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cpd0DesignItemInstance")

   virtual ~Cpd0DesignItemInstance();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CpdMngd_undef.h>
#endif
