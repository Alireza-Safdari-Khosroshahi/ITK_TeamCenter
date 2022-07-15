/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

   Auto-generated source from service interface.
                 DO NOT EDIT

 ==================================================
*/

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2010_09_IMPORTEXPORT_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2010_09_IMPORTEXPORT_HXX

#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/manufacturing/Manufacturing_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Manufacturing
        {
            namespace _2010_09
            {
                class Importexport;

class TCSOAMANUFACTURINGSTRONGMNGD_API Importexport
{
public:

    struct ImportInput;
    struct ImportResponse;

    /**
     * Input for importManufacturingFeatures
     */
    struct ImportInput
    {
        /**
         * The unique name of the PLMXML File in the transient volume.
         */
        std::string fileName;
        /**
         * The root object (in the structure to which we import the data). The root is always
         * a BOMLine that corresponds to an item in the product structure.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  root;
    };

    /**
     * The output of importManufaturingFeatures
     */
    struct ImportResponse
    {
        /**
         * The service data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * The full path of the log file (created by the import).
         */
        std::string logFileFullPath;
    };




    /**
     * imports MFGs from a given PLMXML file to TC.
     *
     * @param input
     *        The input contains the PLMXML file and the root of the structure to which the data
     *        should be imported.
     *
     * @return
     *         return a path to the log file and a ServiceData that contains errors
     *
     * @deprecated
     *         As of Teamcenter 10.1, use the importManufaturingFeatures operation from the _2012_09
     *         namespace.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10.1, use the importManufaturingFeatures operation from the _2012_09 namespace."))
#endif
    virtual Teamcenter::Services::Manufacturing::_2010_09::Importexport::ImportResponse importManufaturingFeatures ( const Teamcenter::Services::Manufacturing::_2010_09::Importexport::ImportInput&  input ) = 0;


protected:
    virtual ~Importexport() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

