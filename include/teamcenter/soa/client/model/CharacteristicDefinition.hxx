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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CHARACTERISTICDEFINITION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CHARACTERISTICDEFINITION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/model/MrocoreMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAMROCOREMODELMNGD_API CharacteristicDefinition : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    int get_precision();
    bool get_isDerived();
    const std::string& get_charUnit();
    const std::string& get_charName();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CharacteristicDefinition")

   virtual ~CharacteristicDefinition();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/MrocoreMngd_undef.h>
#endif
