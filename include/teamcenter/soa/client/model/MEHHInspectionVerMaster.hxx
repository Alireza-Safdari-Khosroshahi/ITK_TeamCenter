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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEHHINSPECTIONVERMASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEHHINSPECTIONVERMASTER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/DpvMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOADPVMODELMNGD_API MEHHInspectionVerMaster : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const Teamcenter::Soa::Common::DateTime& get_dpv0ValDate();
    const std::string& get_dpv0ValStatus();
    const std::string& get_dpv0SendToSSAS();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MEHHInspectionVerMaster")

   virtual ~MEHHInspectionVerMaster();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/DpvMngd_undef.h>
#endif
