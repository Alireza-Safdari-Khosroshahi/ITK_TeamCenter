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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPDATAMODELDEFINITION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPDATAMODELDEFINITION_HXX

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


class TCSOACLIENTMNGD_API AppDataModelDefinition : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_dataset_type_name();
    int get_definition_type();
    const Teamcenter::Soa::Client::StringVector& get_info();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AppDataModelDefinition")

   virtual ~AppDataModelDefinition();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
