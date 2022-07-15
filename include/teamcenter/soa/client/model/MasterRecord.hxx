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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MASTERRECORD_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MASTERRECORD_HXX

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
                class RecordObject;
                class ImanFile;


class TCSOACLIENTMNGD_API MasterRecord : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_refresh_cache_records();
    size_t count_records();
    Teamcenter::Soa::Common::AutoPtr<RecordObject> get_records_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<ImanFile> get_master_xml_file();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MasterRecord")

   virtual ~MasterRecord();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
