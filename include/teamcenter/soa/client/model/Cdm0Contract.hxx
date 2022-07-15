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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CDM0CONTRACT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CDM0CONTRACT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Document.hxx>

#include <teamcenter/soa/client/model/Cdm0contractmanagementMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACDM0CONTRACTMANAGEMENTMODELMNGD_API Cdm0Contract : public Teamcenter::Soa::Client::Model::Document
{
public:
    const std::string& get_cdm0ContractCategory();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cdm0Contract")

   virtual ~Cdm0Contract();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/Cdm0contractmanagementMngd_undef.h>
#endif
