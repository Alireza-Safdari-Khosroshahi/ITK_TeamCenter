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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPD0SHAPEDESIGN_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPD0SHAPEDESIGN_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Design.hxx>

#include <teamcenter/soa/client/model/CpdMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class POM_object;


class TCSOACPDMODELMNGD_API Cpd0ShapeDesign : public Teamcenter::Soa::Client::Model::Design
{
public:
    Teamcenter::Soa::Common::AutoPtr<POM_object> get_cpd0model_object();
    const std::string& get_cpd0delegate_uid();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_cpd0delegate();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cpd0ShapeDesign")

   virtual ~Cpd0ShapeDesign();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CpdMngd_undef.h>
#endif
