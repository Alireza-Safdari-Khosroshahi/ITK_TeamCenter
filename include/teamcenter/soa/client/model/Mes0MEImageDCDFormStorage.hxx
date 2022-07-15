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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MES0MEIMAGEDCDFORMSTORAGE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MES0MEIMAGEDCDFORMSTORAGE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mes0MEDCDBaseFormStorage.hxx>

#include <teamcenter/soa/client/model/CmtmesMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTMESMODELMNGD_API Mes0MEImageDCDFormStorage : public Teamcenter::Soa::Client::Model::Mes0MEDCDBaseFormStorage
{
public:
    const std::string& get_mes0DataAcquisitionMethod();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mes0MEImageDCDFormStorage")

   virtual ~Mes0MEImageDCDFormStorage();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtmesMngd_undef.h>
#endif
