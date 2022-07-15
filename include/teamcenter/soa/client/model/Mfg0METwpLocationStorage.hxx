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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0METWPLOCATIONSTORAGE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0METWPLOCATIONSTORAGE_HXX

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


class TCSOACLIENTMNGD_API Mfg0METwpLocationStorage : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    int get_Mfg0Length();
    int get_Mfg0Width();
    int get_Mfg0X();
    int get_Mfg0Y();
    int get_Mfg0Orientation();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0METwpLocationStorage")

   virtual ~Mfg0METwpLocationStorage();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
