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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0MARKUP_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0MARKUP_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Fnd0MarkupChange;


class TCSOACLIENTMNGD_API Fnd0Markup : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    bool get_fnd0active();
    const std::string& get_fnd0purpose();
    const Teamcenter::Soa::Client::StringVector& get_fnd0comment();
    size_t count_fnd0changes();
    Teamcenter::Soa::Common::AutoPtr<Fnd0MarkupChange> get_fnd0changes_at( size_t inx );
    bool get_fnd0loaded();
    int get_fnd0markup_status();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Fnd0PS_Markup();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0Markup")

   virtual ~Fnd0Markup();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
