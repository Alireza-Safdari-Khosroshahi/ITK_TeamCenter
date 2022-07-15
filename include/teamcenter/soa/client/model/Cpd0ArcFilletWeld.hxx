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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPD0ARCFILLETWELD_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPD0ARCFILLETWELD_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Cpd0ArcWeld.hxx>

#include <teamcenter/soa/client/model/CpdMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACPDMODELMNGD_API Cpd0ArcFilletWeld : public Teamcenter::Soa::Client::Model::Cpd0ArcWeld
{
public:
    const std::string& get_cpd0fillet_type();
    const std::string& get_cpd0contour();
    const std::string& get_cpd0method();
    const std::string& get_cpd0joint_type();
    const std::string& get_cpd0groove_type();
    const std::string& get_cpd0fillet();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cpd0ArcFilletWeld")

   virtual ~Cpd0ArcFilletWeld();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CpdMngd_undef.h>
#endif
