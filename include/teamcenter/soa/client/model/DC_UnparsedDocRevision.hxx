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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DC_UNPARSEDDOCREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DC_UNPARSEDDOCREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/SpecElementRevision.hxx>

#include <teamcenter/soa/client/model/ContmgmtbaseMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACONTMGMTBASEMODELMNGD_API DC_UnparsedDocRevision : public Teamcenter::Soa::Client::Model::SpecElementRevision
{
public:
    int get_contentSize();
    const std::string& get_systemId();
    const std::string& get_publicId();
    const std::string& get_languageRef();
    const std::string& get_topicReference();
    const std::string& get_DocumentTitle();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DC_UnparsedDocRevision")

   virtual ~DC_UnparsedDocRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ContmgmtbaseMngd_undef.h>
#endif
