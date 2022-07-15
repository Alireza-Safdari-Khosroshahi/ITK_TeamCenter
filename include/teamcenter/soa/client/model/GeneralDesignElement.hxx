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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_GENERALDESIGNELEMENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_GENERALDESIGNELEMENT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class POM_object;


class TCSOACLIENTMNGD_API GeneralDesignElement : public Teamcenter::Soa::Client::Model::Form
{
public:
    Teamcenter::Soa::Common::AutoPtr<POM_object> get_gde_bvr();
    const Teamcenter::Soa::Client::ModelObjectVector& get_gde_occurrences();
    const Teamcenter::Soa::Client::ModelObjectVector& get_gde_where_used();
    int get_cardinality();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_Rendering();
    const Teamcenter::Soa::Client::ModelObjectVector& get_allowable_view_types();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("GeneralDesignElement")

   virtual ~GeneralDesignElement();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
