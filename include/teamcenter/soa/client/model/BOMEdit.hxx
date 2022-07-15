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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_BOMEDIT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_BOMEDIT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/CmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMMODELMNGD_API BOMEdit : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_CMBvrTag();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_CMChangeRevTag();
    int get_CMChangeType();
    bool get_CMIsDerived();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_CMCustomObjTag();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_CMOccurenceTag();
    const std::string& get_CMObjectString();
    double get_CMBomEditQty();
    const std::string& get_CMObjectName();
    double get_CMQuantityDiff();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_CMBOMSupersedure();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_CMProblemBvr();
    const std::string& get_CMObjectType();
    const std::string& get_CMObjectFullName();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("BOMEdit")

   virtual ~BOMEdit();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmMngd_undef.h>
#endif
