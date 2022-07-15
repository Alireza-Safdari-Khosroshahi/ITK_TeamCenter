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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MEVISINSPECTION_REVISION_MASTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MEVISINSPECTION_REVISION_MASTER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/model/DpvMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOADPVMODELMNGD_API MEVisInspection_Revision_Master : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_dpv0ValStatus();
    const Teamcenter::Soa::Common::DateTime& get_dpv0ValDate();
    const std::string& get_dpv0SendToSSAS();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MEVisInspection_Revision_Master")

   virtual ~MEVisInspection_Revision_Master();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/DpvMngd_undef.h>
#endif
