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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CBA0PROCUREMENTPROXY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CBA0PROCUREMENTPROXY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Cba0PersistentProxy.hxx>

#include <teamcenter/soa/client/model/CbaMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACBAMODELMNGD_API Cba0ProcurementProxy : public Teamcenter::Soa::Client::Model::Cba0PersistentProxy
{
public:
    const std::string& get_relation();
    const std::string& get_cba0MadeFromPartBase();
    const std::string& get_cba0MakeBuyIndicator();
    const std::string& get_cba0InfoAuthorization();
    const std::string& get_cba0InfoOutAuthorization();
    const std::string& get_cba0PartVersionNumber();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cba0ProcurementProxy")

   virtual ~Cba0ProcurementProxy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CbaMngd_undef.h>
#endif
