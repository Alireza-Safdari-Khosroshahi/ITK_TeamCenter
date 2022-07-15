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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_OFFICEDOCDATA_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_OFFICEDOCDATA_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_application_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API OfficeDocData : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_Title();
    const std::string& get_Subject();
    const std::string& get_Author();
    const std::string& get_Manager();
    const std::string& get_Company();
    const std::string& get_Category();
    const std::string& get_Keywords();
    const std::string& get_Comments();
    const std::string& get_Client();
    const std::string& get_Project();
    const std::string& get_Purpose();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("OfficeDocData")

   virtual ~OfficeDocData();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
