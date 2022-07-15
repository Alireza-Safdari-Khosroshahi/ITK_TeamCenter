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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_POM_OBJECT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_POM_OBJECT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/BusinessObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class POMImc;


class TCSOACLIENTMNGD_API POM_object : public Teamcenter::Soa::Client::Model::BusinessObject
{
public:
    const std::string& get_timestamp();
    int get_pid();
    short get_object_properties();
    const Teamcenter::Soa::Common::DateTime& get_lsd();
    Teamcenter::Soa::Common::AutoPtr<POMImc> get_owning_site();
    const std::string& get_fnd0objectId();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_based_on();
    const std::string& get_fnd0mfkinfo();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("POM_object")

   virtual ~POM_object();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
