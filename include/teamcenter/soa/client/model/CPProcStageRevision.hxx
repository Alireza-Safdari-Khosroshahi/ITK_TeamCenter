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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPPROCSTAGEREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPPROCSTAGEREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/model/SpecmgrMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class CPProcLineRevision;
                class CPPropertyListFormat;


class TCSOASPECMGRMODELMNGD_API CPProcStageRevision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    int get_sequence_number();
    int get_recirculate_to();
    Teamcenter::Soa::Common::AutoPtr<CPProcLineRevision> get_parent_line();
    Teamcenter::Soa::Common::AutoPtr<CPPropertyListFormat> get_property_list_format();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPProcStageRevision")

   virtual ~CPProcStageRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/SpecmgrMngd_undef.h>
#endif
