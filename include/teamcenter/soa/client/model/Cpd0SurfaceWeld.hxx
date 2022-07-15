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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPD0SURFACEWELD_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPD0SURFACEWELD_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Cpd0SurfaceAdd.hxx>

#include <teamcenter/soa/client/model/CpdMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACPDMODELMNGD_API Cpd0SurfaceWeld : public Teamcenter::Soa::Client::Model::Cpd0SurfaceAdd
{
public:
    const std::string& get_cpd0weld_process();
    const std::string& get_cpd0surface_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cpd0SurfaceWeld")

   virtual ~Cpd0SurfaceWeld();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CpdMngd_undef.h>
#endif
