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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CADATTRMAPPINGDEFPARTSNOFF_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CADATTRMAPPINGDEFPARTSNOFF_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/CadAttrMappingDefPart.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API CadAttrMappingDefPartSNoff : public Teamcenter::Soa::Client::Model::CadAttrMappingDefPart
{
public:
    const std::string& get_role_name();
    const std::string& get_level_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CadAttrMappingDefPartSNoff")

   virtual ~CadAttrMappingDefPartSNoff();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
