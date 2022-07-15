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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_GDEOCCURRENCE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_GDEOCCURRENCE_HXX

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
                class PSOccurrenceThread;
                class GDEbvr;
                class PSOccurrenceType;
                class PSOccurrenceNotes;
                class GeneralDesignElement;


class TCSOACLIENTMNGD_API GDEOccurrence : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_occ_name();
    Teamcenter::Soa::Common::AutoPtr<PSOccurrenceThread> get_occ_thread();
    Teamcenter::Soa::Common::AutoPtr<GDEbvr> get_parent_gde_bvr();
    Teamcenter::Soa::Common::AutoPtr<PSOccurrenceType> get_occ_type();
    double get_qty_value();
    int get_instance_number();
    double get_ext_transform_rot00();
    double get_ext_transform_rot10();
    double get_ext_transform_rot20();
    double get_ext_transform_per0();
    double get_ext_transform_rot01();
    double get_ext_transform_rot11();
    double get_ext_transform_rot21();
    double get_ext_transform_per1();
    double get_ext_transform_rot02();
    double get_ext_transform_rot12();
    double get_ext_transform_rot22();
    double get_ext_transform_per2();
    double get_ext_transform_tra0();
    double get_ext_transform_tra1();
    double get_ext_transform_tra2();
    double get_ext_transform_invscale();
    Teamcenter::Soa::Common::AutoPtr<PSOccurrenceNotes> get_notes_ref();
    Teamcenter::Soa::Common::AutoPtr<GeneralDesignElement> get_gde_object();
    const Teamcenter::Soa::Client::DoubleVector& get_ext_transform();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("GDEOccurrence")

   virtual ~GDEOccurrence();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
