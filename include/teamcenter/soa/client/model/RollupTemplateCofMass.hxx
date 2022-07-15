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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ROLLUPTEMPLATECOFMASS_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ROLLUPTEMPLATECOFMASS_HXX

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
                class RollupTemplate;


class TCSOACLIENTMNGD_API RollupTemplateCofMass : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_in_x();
    const std::string& get_in_y();
    const std::string& get_in_z();
    const std::string& get_in_mass();
    const std::string& get_in_tmatrix();
    const std::string& get_in_asserted();
    const std::string& get_out_x();
    const std::string& get_out_y();
    const std::string& get_out_z();
    Teamcenter::Soa::Common::AutoPtr<RollupTemplate> get_template();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("RollupTemplateCofMass")

   virtual ~RollupTemplateCofMass();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
