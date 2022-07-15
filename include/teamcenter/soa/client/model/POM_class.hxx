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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_POM_CLASS_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_POM_CLASS_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_dd.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API POM_class : public Teamcenter::Soa::Client::Model::POM_dd
{
public:
    const std::string& get_superclass();
    const std::string& get_name();
    const std::string& get_tname();
    const std::string& get_vname();
    const std::string& get_applic_name();
    const std::string& get_auid();
    int get_n_vlas();
    int get_empty_length();
    int get_properties();
    int get_cpid();
    int get_null_length();
    int get_mapping();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("POM_class")

   virtual ~POM_class();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
