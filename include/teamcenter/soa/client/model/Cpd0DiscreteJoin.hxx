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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPD0DISCRETEJOIN_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPD0DISCRETEJOIN_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Cpd0DesignFeature.hxx>

#include <teamcenter/soa/client/model/CpdMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACPDMODELMNGD_API Cpd0DiscreteJoin : public Teamcenter::Soa::Client::Model::Cpd0DesignFeature
{
public:
    const std::string& get_cpd0group_id();
    int get_cpd0num_of_sheets_welded();
    int get_cpd0num_of_welds_in_group();
    const std::string& get_cpd0standard();
    const std::string& get_cpd0output_type();
    const Teamcenter::Soa::Client::DoubleVector& get_cpd0position();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cpd0DiscreteJoin")

   virtual ~Cpd0DiscreteJoin();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CpdMngd_undef.h>
#endif
