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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPD0RESISTANCEWELD_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPD0RESISTANCEWELD_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Cpd0DiscreteJoin.hxx>

#include <teamcenter/soa/client/model/CpdMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACPDMODELMNGD_API Cpd0ResistanceWeld : public Teamcenter::Soa::Client::Model::Cpd0DiscreteJoin
{
public:
    double get_cpd0resistance();
    const std::string& get_cpd0gov_mtl_thk();
    const std::string& get_cpd0metal_comb();
    const std::string& get_cpd0spot_dimensional_ctrl();
    const std::string& get_cpd0spot_kpc();
    const std::string& get_cpd0spot_kpc_justification();
    const std::string& get_cpd0spot_process_ctrl();
    const std::string& get_cpd0stackup();
    int get_cpd0tol();
    const std::string& get_cpd0weld_class();
    const std::string& get_cpd0symbol_name();
    double get_cpd0weld_force();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cpd0ResistanceWeld")

   virtual ~Cpd0ResistanceWeld();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CpdMngd_undef.h>
#endif
