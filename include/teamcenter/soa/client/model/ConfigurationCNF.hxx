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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CONFIGURATIONCNF_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CONFIGURATIONCNF_HXX

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
                class ConfigurationExprLiteral;


class TCSOACLIENTMNGD_API ConfigurationCNF : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const Teamcenter::Soa::Client::IntVector& get_clauseIDs();
    int get_clause_count();
    int get_fingerprint();
    int get_sequence();
    size_t count_clause_literals();
    Teamcenter::Soa::Common::AutoPtr<ConfigurationExprLiteral> get_clause_literals_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ConfigurationCNF")

   virtual ~ConfigurationCNF();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
