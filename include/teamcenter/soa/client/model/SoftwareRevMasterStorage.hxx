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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SOFTWAREREVMASTERSTORAGE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SOFTWAREREVMASTERSTORAGE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/EsmsoftwareMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAESMSOFTWAREMODELMNGD_API SoftwareRevMasterStorage : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_checksum();
    int get_sizeInROM();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SoftwareRevMasterStorage")

   virtual ~SoftwareRevMasterStorage();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/EsmsoftwareMngd_undef.h>
#endif
