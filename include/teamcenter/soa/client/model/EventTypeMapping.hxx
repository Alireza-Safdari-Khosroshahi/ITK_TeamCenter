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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EVENTTYPEMAPPING_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EVENTTYPEMAPPING_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ImanType;
                class ImanEventType;


class TCSOACLIENTMNGD_API EventTypeMapping : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_imantype();
    const Teamcenter::Soa::Client::IntVector& get_eventtype_descriptors();
    size_t count_valid_eventtypes();
    Teamcenter::Soa::Common::AutoPtr<ImanEventType> get_valid_eventtypes_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("EventTypeMapping")

   virtual ~EventTypeMapping();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
