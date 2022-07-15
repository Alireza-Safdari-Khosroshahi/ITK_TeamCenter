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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_RESERVATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_RESERVATION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Reservation : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_objects();
    int get_res_type();
    int get_res_state();
    const std::string& get_node();
    const std::string& get_path();
    const Teamcenter::Soa::Client::StringVector& get_iman_fnames();
    const Teamcenter::Soa::Client::StringVector& get_user_fnames();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Reservation")

   virtual ~Reservation();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
