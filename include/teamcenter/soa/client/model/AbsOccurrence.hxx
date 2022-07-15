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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ABSOCCURRENCE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ABSOCCURRENCE_HXX

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


class TCSOACLIENTMNGD_API AbsOccurrence : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_abs_occ_id();
    const std::string& get_usage_address();
    const std::string& get_logical_position();
    const Teamcenter::Soa::Common::DateTime& get_last_mod_date();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AbsOccurrence")

   virtual ~AbsOccurrence();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
