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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_HRN_GENTERMINAL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_HRN_GENTERMINAL_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Item.hxx>

#include <teamcenter/soa/client/model/HrnMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAHRNMODELMNGD_API HRN_GenTerminal : public Teamcenter::Soa::Client::Model::Item
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_HRN_part_data();
    double get_cross_section();
    double get_outside_dia();
    const std::string& get_part_type();
    const std::string& get_plating_material();
    const std::string& get_process_type();
    const std::string& get_process_value();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("HRN_GenTerminal")

   virtual ~HRN_GenTerminal();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/HrnMngd_undef.h>
#endif
