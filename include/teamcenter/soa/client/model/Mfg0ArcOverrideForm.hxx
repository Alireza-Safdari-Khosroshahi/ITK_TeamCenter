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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0ARCOVERRIDEFORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0ARCOVERRIDEFORM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Mfg0ArcOverrideForm : public Teamcenter::Soa::Client::Model::Form
{
public:
    double get_Mfg0StartPointX();
    double get_Mfg0StartPointY();
    double get_Mfg0StartPointZ();
    double get_Mfg0StartPointRX();
    double get_Mfg0StartPointRY();
    double get_Mfg0StartPointRZ();
    double get_Mfg0IntermediatePointX();
    double get_Mfg0IntermediatePointY();
    double get_Mfg0IntermediatePointZ();
    double get_Mfg0IntermediatePointRX();
    double get_Mfg0IntermediatePointRY();
    double get_Mfg0IntermediatePointRZ();
    double get_Mfg0EndPointX();
    double get_Mfg0EndPointY();
    double get_Mfg0EndPointZ();
    double get_Mfg0EndPointRX();
    double get_Mfg0EndPointRY();
    double get_Mfg0EndPointRZ();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0ArcOverrideForm")

   virtual ~Mfg0ArcOverrideForm();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
