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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0GENERICCONVERSIONRULE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0GENERICCONVERSIONRULE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_application_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Fnd0GenericConversionRule : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_fnd0Name();
    const std::string& get_fnd0Description();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0GenericConversionRule")

   virtual ~Fnd0GenericConversionRule();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
