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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPPROPERTYREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPPROPERTYREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/model/SpecmgrMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class CPPropertyListRevision;


class TCSOASPECMGRMODELMNGD_API CPPropertyRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    int get_sequence_number();
    Teamcenter::Soa::Common::AutoPtr<CPPropertyListRevision> get_parent_property_group();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPPropertyRevision")

   virtual ~CPPropertyRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/SpecmgrMngd_undef.h>
#endif
