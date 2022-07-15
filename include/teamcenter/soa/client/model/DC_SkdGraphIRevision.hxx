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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DC_SKDGRAPHIREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DC_SKDGRAPHIREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/GraphicRevision.hxx>

#include <teamcenter/soa/client/model/Contmgmts1000dMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACONTMGMTS1000DMODELMNGD_API DC_SkdGraphIRevision : public Teamcenter::Soa::Client::Model::GraphicRevision
{
public:
    const std::string& get_skdgraphic_prefix();
    const std::string& get_skdmodelic();
    const std::string& get_skdsdc();
    const std::string& get_skdsns();
    const std::string& get_skdrpc();
    const std::string& get_skdorig();
    const std::string& get_skdseqnum();
    const std::string& get_skdgraphic_variant();
    const std::string& get_skdgraphic_issno();
    const std::string& get_skdsecurity_class();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DC_SkdGraphIRevision")

   virtual ~DC_SkdGraphIRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/Contmgmts1000dMngd_undef.h>
#endif
