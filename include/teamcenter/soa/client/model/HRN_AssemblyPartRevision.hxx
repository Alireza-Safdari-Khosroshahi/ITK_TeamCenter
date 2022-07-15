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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_HRN_ASSEMBLYPARTREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_HRN_ASSEMBLYPARTREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/model/HrnMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAHRNMODELMNGD_API HRN_AssemblyPartRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    double get_mass_information();
    const std::string& get_material_key();
    const std::string& get_mtl_ref_system();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("HRN_AssemblyPartRevision")

   virtual ~HRN_AssemblyPartRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/HrnMngd_undef.h>
#endif
