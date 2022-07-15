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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_SERIALNUMBERGENERATOR_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_SERIALNUMBERGENERATOR_HXX

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


class TCSOAMROCOREMODELMNGD_API SerialNumberGenerator : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const std::string& get_seriesPrefix();
    const std::string& get_seriesSuffix();
    int get_seriesCurrent();
    int get_seriesMaximum();
    int get_increment();
    bool get_isActive();
    int get_seriesCharacters();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_designItemTag();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SerialNumberGenerator")

   virtual ~SerialNumberGenerator();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/MrocoreMngd_undef.h>
#endif
