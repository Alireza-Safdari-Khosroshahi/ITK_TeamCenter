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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DC_DITAITEMREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DC_DITAITEMREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/DC_TopicRevision.hxx>

#include <teamcenter/soa/client/model/ContmgmtditaMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACONTMGMTDITAMODELMNGD_API DC_DitaItemRevision : public Teamcenter::Soa::Client::Model::DC_TopicRevision
{
public:
    const std::string& get_ditaAudience();
    const std::string& get_ditaImportance();
    const std::string& get_ditaOtherprops();
    const std::string& get_ditaPlatform();
    const std::string& get_ditaProduct();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DC_DitaItemRevision")

   virtual ~DC_DitaItemRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ContmgmtditaMngd_undef.h>
#endif
