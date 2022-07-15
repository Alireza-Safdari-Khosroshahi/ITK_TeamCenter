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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DATATYPE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DATATYPE_HXX

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
                class Release;
                class Release;


class TCSOACLIENTMNGD_API DataType : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_name();
    const std::string& get_namespace();
    const std::string& get_description();
    Teamcenter::Soa::Common::AutoPtr<Release> get_createRelease();
    bool get_isDeprecated();
    Teamcenter::Soa::Common::AutoPtr<Release> get_deprecatedRelease();
    const std::string& get_deprecatedDescription();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DataType")

   virtual ~DataType();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
