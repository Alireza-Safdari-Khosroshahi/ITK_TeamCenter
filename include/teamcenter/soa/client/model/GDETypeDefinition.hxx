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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_GDETYPEDEFINITION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_GDETYPEDEFINITION_HXX

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
                class PSViewType;


class TCSOACLIENTMNGD_API GDETypeDefinition : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_cardinality();
    size_t count_allowable_view_types();
    Teamcenter::Soa::Common::AutoPtr<PSViewType> get_allowable_view_types_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("GDETypeDefinition")

   virtual ~GDETypeDefinition();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
