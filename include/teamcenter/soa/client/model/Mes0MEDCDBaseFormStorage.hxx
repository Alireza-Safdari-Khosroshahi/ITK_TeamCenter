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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MES0MEDCDBASEFORMSTORAGE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MES0MEDCDBASEFORMSTORAGE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/CmtmesMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTMESMODELMNGD_API Mes0MEDCDBaseFormStorage : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_mes0ValuePlaceholder();
    bool get_mes0isOptional();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mes0MEDCDBaseFormStorage")

   virtual ~Mes0MEDCDBaseFormStorage();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtmesMngd_undef.h>
#endif
