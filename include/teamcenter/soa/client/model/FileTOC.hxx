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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FILETOC_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FILETOC_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API FileTOC : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_filename();
    const std::string& get_comments();
    const std::string& get_content_address();
    const std::string& get_person_name();
    const Teamcenter::Soa::Common::DateTime& get_creation_date();
    const Teamcenter::Soa::Client::StringVector& get_object_name_list();
    const Teamcenter::Soa::Client::StringVector& get_object_type_list();
    const Teamcenter::Soa::Client::ModelObjectVector& get_object_tag_list();
    const std::string& get_label();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("FileTOC")

   virtual ~FileTOC();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
