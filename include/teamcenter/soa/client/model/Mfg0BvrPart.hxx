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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRPART_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRPART_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mfg0BvrMaterial.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Mfg0BvrPart : public Teamcenter::Soa::Client::Model::Mfg0BvrMaterial
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0other_to();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0assigned_to();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0consumed_to();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0handled_to();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0assembled_to();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0disassembled_to();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0all_to();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0BvrPart")

   virtual ~Mfg0BvrPart();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
