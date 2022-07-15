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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CRFQUERYSOURCE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CRFQUERYSOURCE_HXX

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
                class ImanQuery;
                class TransferMode;


class TCSOACLIENTMNGD_API CrfQuerySource : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_qry_src_type();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_qry_src_generic_data_source();
    Teamcenter::Soa::Common::AutoPtr<ImanQuery> get_qry_src_tc_qry();
    Teamcenter::Soa::Common::AutoPtr<TransferMode> get_qry_src_tc_transfer_mode();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CrfQuerySource")

   virtual ~CrfQuerySource();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
