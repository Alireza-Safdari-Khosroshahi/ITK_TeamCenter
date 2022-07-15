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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PRODUCTINTERFACE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PRODUCTINTERFACE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Interfaces.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API ProductInterface : public Teamcenter::Soa::Client::Model::Interfaces
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_PI_owning_part();
    const Teamcenter::Soa::Client::ModelObjectVector& get_PI_where_referenced();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_Feature_Form_Relation();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ProductInterface")

   virtual ~ProductInterface();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
