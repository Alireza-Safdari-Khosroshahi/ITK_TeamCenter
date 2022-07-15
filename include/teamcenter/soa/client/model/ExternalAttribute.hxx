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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EXTERNALATTRIBUTE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EXTERNALATTRIBUTE_HXX

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
                class ExternalDataSource;


class TCSOACLIENTMNGD_API ExternalAttribute : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_table_name();
    const std::string& get_attr_name();
    int get_attr_type();
    int get_attr_len();
    Teamcenter::Soa::Common::AutoPtr<ExternalDataSource> get_data_source();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ExternalAttribute")

   virtual ~ExternalAttribute();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
