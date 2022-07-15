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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DC_STYLESHEETREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DC_STYLESHEETREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/DC_ExtEntAdminRevision.hxx>

#include <teamcenter/soa/client/model/ContmgmtbaseMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACONTMGMTBASEMODELMNGD_API DC_StyleSheetRevision : public Teamcenter::Soa::Client::Model::DC_ExtEntAdminRevision
{
public:
    const std::string& get_styleSheetType();
    const std::string& get_styleSheetMainFile();
    const std::string& get_target();
    const std::string& get_styleSheetResCntType();
    int get_contentSize();
    const Teamcenter::Soa::Client::ModelObjectVector& get_DC_StylesheetToolR();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DC_StyleSheetRevision")

   virtual ~DC_StyleSheetRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ContmgmtbaseMngd_undef.h>
#endif
