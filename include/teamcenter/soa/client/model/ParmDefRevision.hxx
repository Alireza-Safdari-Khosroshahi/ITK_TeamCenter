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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PARMDEFREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PARMDEFREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/model/CcdmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class User;
                class Fnd0GenericConversionRule;


class TCSOACCDMMODELMNGD_API ParmDefRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    const std::string& get_comment();
    Teamcenter::Soa::Common::AutoPtr<User> get_controlEngineer();
    int get_size();
    const std::string& get_sizeUnits();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_userData();
    const std::string& get_parmDescriptor();
    Teamcenter::Soa::Common::AutoPtr<Fnd0GenericConversionRule> get_ccd0ConversionRule();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ParmDefRevision")

   virtual ~ParmDefRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CcdmMngd_undef.h>
#endif
