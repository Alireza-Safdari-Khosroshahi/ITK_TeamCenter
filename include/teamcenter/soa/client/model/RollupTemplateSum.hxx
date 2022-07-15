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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ROLLUPTEMPLATESUM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ROLLUPTEMPLATESUM_HXX

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
                class RollupTemplate;


class TCSOACLIENTMNGD_API RollupTemplateSum : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_in();
    const std::string& get_out();
    const std::string& get_in_asserted();
    Teamcenter::Soa::Common::AutoPtr<RollupTemplate> get_template();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("RollupTemplateSum")

   virtual ~RollupTemplateSum();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
