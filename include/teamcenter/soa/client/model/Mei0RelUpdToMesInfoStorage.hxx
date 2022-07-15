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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEI0RELUPDTOMESINFOSTORAGE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEI0RELUPDTOMESINFOSTORAGE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/CmtmesintegMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTMESINTEGMODELMNGD_API Mei0RelUpdToMesInfoStorage : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_mei0Description();
    const std::string& get_mei0Impact();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mei0RelUpdToMesInfoStorage")

   virtual ~Mei0RelUpdToMesInfoStorage();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtmesintegMngd_undef.h>
#endif
