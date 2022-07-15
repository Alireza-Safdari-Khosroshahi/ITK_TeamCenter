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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_GRAPHICREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_GRAPHICREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/SpecElementRevision.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class DCt_Language;


class TCSOACLIENTMNGD_API GraphicRevision : public Teamcenter::Soa::Client::Model::SpecElementRevision
{
public:
    const std::string& get_masterLanguageRef();
    const std::string& get_graphicName();
    const std::string& get_DocumentTitle();
    Teamcenter::Soa::Common::AutoPtr<DCt_Language> get_fnd0LanguageTagref();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("GraphicRevision")

   virtual ~GraphicRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
