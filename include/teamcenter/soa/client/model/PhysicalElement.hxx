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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PHYSICALELEMENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PHYSICALELEMENT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Item.hxx>

#include <teamcenter/soa/client/model/MrocoreMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAMROCOREMODELMNGD_API PhysicalElement : public Teamcenter::Soa::Client::Model::Item
{
public:
    int get_revisionCount();
    const Teamcenter::Soa::Client::ModelObjectVector& get_PhysicalElementOwner();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PhysicalElement")

   virtual ~PhysicalElement();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/MrocoreMngd_undef.h>
#endif
