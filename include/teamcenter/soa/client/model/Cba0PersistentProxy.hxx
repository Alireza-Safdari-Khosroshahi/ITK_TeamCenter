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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CBA0PERSISTENTPROXY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CBA0PERSISTENTPROXY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Fnd0AbstractPersistentProxy.hxx>

#include <teamcenter/soa/client/model/CbaMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACBAMODELMNGD_API Cba0PersistentProxy : public Teamcenter::Soa::Client::Model::Fnd0AbstractPersistentProxy
{
public:
    const std::string& get_cba0PMMObjectID();
    const std::string& get_cba0DBEQueryStream();
    const Teamcenter::Soa::Common::DateTime& get_cba0EffectiveDateQuery();
    const Teamcenter::Soa::Common::DateTime& get_cba0EffectiveInDateQuery();
    const Teamcenter::Soa::Common::DateTime& get_cba0EffectiveOutDateQuery();
    const Teamcenter::Soa::Common::DateTime& get_cba0ProdEffectiveDateQry();
    const std::string& get_cba0IMPRECISEUNIQUEKEYID();
    const std::string& get_cba0EffectivePointQuery();
    const std::string& get_cba0EffectiveInPointQuery();
    const std::string& get_cba0EffectiveOutPointQuery();
    const std::string& get_cba0ProdEffectivePointQry();
    const std::string& get_cba0ProductionStream();
    const std::string& get_cba0MathBase();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cba0PersistentProxy")

   virtual ~Cba0PersistentProxy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CbaMngd_undef.h>
#endif
