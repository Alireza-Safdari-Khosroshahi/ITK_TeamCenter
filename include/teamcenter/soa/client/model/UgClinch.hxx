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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_UGCLINCH_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_UGCLINCH_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/UgBasicWeld.hxx>

#include <teamcenter/soa/client/model/GmoMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAGMOMODELMNGD_API UgClinch : public Teamcenter::Soa::Client::Model::UgBasicWeld
{
public:
    int get_conn_number();
    const std::string& get__weld_tol();
    const std::string& get__weld_group_id();
    double get_x_loc();
    double get_y_loc();
    double get_z_loc();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("UgClinch")

   virtual ~UgClinch();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
