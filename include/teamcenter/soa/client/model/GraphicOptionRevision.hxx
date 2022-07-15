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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_GRAPHICOPTIONREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_GRAPHICOPTIONREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

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


class TCSOACLIENTMNGD_API GraphicOptionRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    const std::string& get_importOriginalName();
    int get_contentSize();
    const std::string& get_languageRef();
    const std::string& get_publicId();
    const std::string& get_systemId();
    const Teamcenter::Soa::Client::StringVector& get_graphicUsages();
    Teamcenter::Soa::Common::AutoPtr<DCt_Language> get_fnd0LanguageTagref();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("GraphicOptionRevision")

   virtual ~GraphicOptionRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
