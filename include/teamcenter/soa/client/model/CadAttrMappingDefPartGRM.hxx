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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CADATTRMAPPINGDEFPARTGRM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CADATTRMAPPINGDEFPARTGRM_HXX

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


class TCSOACLIENTMNGD_API CadAttrMappingDefPartGRM : public Teamcenter::Soa::Client::Model::CadAttrMappingDefPart
{
public:
    const std::string& get_relationship_name();
    const std::string& get_type_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CadAttrMappingDefPartGRM")

   virtual ~CadAttrMappingDefPartGRM();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
