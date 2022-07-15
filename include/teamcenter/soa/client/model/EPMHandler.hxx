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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EPMHANDLER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EPMHANDLER_HXX

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


class TCSOACLIENTMNGD_API EPMHandler : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_handler_name();
    int get_number_of_arguments();
    const Teamcenter::Soa::Client::StringVector& get_arguments();
    const Teamcenter::Soa::Client::StringVector& get_handler_arguments();
    int get_parent_action_type();
    int get_handler_type();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_parent_task_template();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_parent_action();
    const std::string& get_object_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("EPMHandler")

   virtual ~EPMHandler();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
