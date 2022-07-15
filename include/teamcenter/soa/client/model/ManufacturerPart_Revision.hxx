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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MANUFACTURERPART_REVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MANUFACTURERPART_REVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Part_Revision.hxx>

#include <teamcenter/soa/client/model/VendormanagementMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAVENDORMANAGEMENTMODELMNGD_API ManufacturerPart_Revision : public Teamcenter::Soa::Client::Model::Part_Revision
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_Quality_Document();
    const std::string& get_vendor_part_num();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ManufacturerPart_Revision")

   virtual ~ManufacturerPart_Revision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/VendormanagementMngd_undef.h>
#endif
