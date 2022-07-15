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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PSOCCURRENCENOTES_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PSOCCURRENCENOTES_HXX

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
                class NoteType;


class TCSOACLIENTMNGD_API PSOccurrenceNotes : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    size_t count_note_types();
    Teamcenter::Soa::Common::AutoPtr<NoteType> get_note_types_at( size_t inx );
    const Teamcenter::Soa::Client::StringVector& get_note_texts();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PSOccurrenceNotes")

   virtual ~PSOccurrenceNotes();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
