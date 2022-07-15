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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0DLFOVERRIDEFORMSTORAGE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0DLFOVERRIDEFORMSTORAGE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Mfg0DLFOverrideFormStorage : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_Mfg0Datum_Type();
    bool get_Mfg0cntrl_i_direction();
    bool get_Mfg0cntrl_j_direction();
    bool get_Mfg0cntrl_k_direction();
    const std::string& get_Mfg0Datum_Usage_Type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0DLFOverrideFormStorage")

   virtual ~Mfg0DLFOverrideFormStorage();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
