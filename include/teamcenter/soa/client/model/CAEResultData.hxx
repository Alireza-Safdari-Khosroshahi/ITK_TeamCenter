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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CAERESULTDATA_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CAERESULTDATA_HXX

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
                class ImanFile;
                class ImanFile;


class TCSOACLIENTMNGD_API CAEResultData : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_name();
    const std::string& get_type();
    const std::string& get_description();
    bool get_external();
    const Teamcenter::Soa::Client::StringVector& get_external_files();
    Teamcenter::Soa::Common::AutoPtr<ImanFile> get_plmxml_file();
    size_t count_internal_files();
    Teamcenter::Soa::Common::AutoPtr<ImanFile> get_internal_files_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CAEResultData")

   virtual ~CAEResultData();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
