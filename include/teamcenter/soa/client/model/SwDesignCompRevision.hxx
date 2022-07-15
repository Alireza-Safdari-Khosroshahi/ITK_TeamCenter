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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SWDESIGNCOMPREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SWDESIGNCOMPREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Design_Revision.hxx>

#include <teamcenter/soa/client/model/EsddmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAESDDMMODELMNGD_API SwDesignCompRevision : public Teamcenter::Soa::Client::Model::Design_Revision
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_DependentOn();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SwDesignCompRevision")

   virtual ~SwDesignCompRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/EsddmMngd_undef.h>
#endif
