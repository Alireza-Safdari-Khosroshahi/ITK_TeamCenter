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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CADATTRMAPPINGDEFPARTICS_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CADATTRMAPPINGDEFPARTICS_HXX

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


class TCSOACLIENTMNGD_API CadAttrMappingDefPartICS : public Teamcenter::Soa::Client::Model::CadAttrMappingDefPart
{
public:
    const std::string& get_type_id();
    int get_attr_id();
    const std::string& get_class_id();
    int get_fnd0attr_vla();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CadAttrMappingDefPartICS")

   virtual ~CadAttrMappingDefPartICS();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
