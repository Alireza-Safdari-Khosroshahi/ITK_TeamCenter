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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_GDEBVR_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_GDEBVR_HXX

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
                class POM_object;
                class GDEOccurrenceList;


class TCSOACLIENTMNGD_API GDEbvr : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<PSViewType> get_view_type();
    Teamcenter::Soa::Common::AutoPtr<POM_object> get_parent_object();
    Teamcenter::Soa::Common::AutoPtr<GDEOccurrenceList> get_gde_occ_list();
    const Teamcenter::Soa::Client::ModelObjectVector& get_gde_occurrences();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("GDEbvr")

   virtual ~GDEbvr();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
