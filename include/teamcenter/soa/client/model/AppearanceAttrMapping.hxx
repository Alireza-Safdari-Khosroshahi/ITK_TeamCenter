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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPEARANCEATTRMAPPING_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPEARANCEATTRMAPPING_HXX

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
                class AppearanceAttrDefinition;
                class NoteType;


class TCSOACLIENTMNGD_API AppearanceAttrMapping : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    bool get_external();
    size_t count_mapped_attrs();
    Teamcenter::Soa::Common::AutoPtr<AppearanceAttrDefinition> get_mapped_attrs_at( size_t inx );
    size_t count_occ_note_types();
    Teamcenter::Soa::Common::AutoPtr<NoteType> get_occ_note_types_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AppearanceAttrMapping")

   virtual ~AppearanceAttrMapping();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
