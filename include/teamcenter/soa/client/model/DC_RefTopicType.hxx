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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DC_REFTOPICTYPE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DC_REFTOPICTYPE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/DC_TopicType.hxx>

#include <teamcenter/soa/client/model/ContmgmtbaseMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACONTMGMTBASEMODELMNGD_API DC_RefTopicType : public Teamcenter::Soa::Client::Model::DC_TopicType
{
public:
    const std::string& get_referenceType();
    const std::string& get_referenceVariant();
    const Teamcenter::Soa::Client::StringVector& get_fragmentTagNames();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DC_RefTopicType")

   virtual ~DC_RefTopicType();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ContmgmtbaseMngd_undef.h>
#endif
