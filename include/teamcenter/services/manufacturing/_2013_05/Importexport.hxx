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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2013_05_IMPORTEXPORT_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2013_05_IMPORTEXPORT_HXX

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
            namespace _2013_05
            {
                class Importexport;

class TCSOAMANUFACTURINGSTRONGMNGD_API Importexport
{
public:

    struct AdvancedImportInput;
    struct AdvancedImportResponse;
    struct ImportScope;

    /**
     * Advanced Input for importing the manufacturing features.
     */
    struct AdvancedImportInput
    {
        /**
         * A BOMLine object in the product structure. Under this object the connected parts
         * of imported manufacturing features are searched.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  context;
        /**
         * List of detail inputs. The detail input elaborates about the container, the import
         * mode and the input PLMXML file.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2013_05::Importexport::ImportScope > content;
    };

    /**
     * The response of PLMXML import of the manufacturing features.
     */
    struct AdvancedImportResponse
    {
        /**
         * The service data.The error conditions and the corresponding error codes are as listed
         * below.      200373 Import is tried to be done from an incomplete PLMXML file.
         * 200374 The preference MEImportMFGsManufacturingFeatureIdAttributeName does not
         * have any value.      200376 The preference MEImportMFGsManufacturingFeatureIdAttributeName
         * has incorrect value.      200375 The preference MEImportMFGsManufacturingFeatureIdAttributeName
         * does not have any value.      200377 The preference MEImportMFGsManufacturingFeatureIdAttributeName
         * has incorrect value.      200xxx Import has failed for a container.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
        /**
         * The name of the generated log file.
         */
        std::string logFileName;
        /**
         * The fms ticket for the transient file that captures the log of import.
         */
        std::string logFileTicket;
    };

    /**
     * The detail input for importing manufacturing features.
     */
    struct ImportScope
    {
        /**
         * The full path of the PLMXML file
         */
        std::string fileName;
        /**
         * The container under which manufacturing features are to be imported.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  container;
        /**
         * The mode of import. The possible values of the import mode are as follows.      keepExistingFeatures
         * - The existing discrete manufacturing features (MFGs)under the container should not
         * be deleted.      refreshWholeContainer - The existing discrete manufacturing features
         * under the container may be deleted.
         */
        std::string importMode;
    };




    /**
     * This service operation imports the discrete manufacturing features (MFGs) from a
     * PLMXML file into a target product structure in Teamcenter.        This operation
     * takes a scope line (container) as additional input and imports the MFGs under the
     * container.        Moreover, it takes the import mode as input which allows deciding
     * whether MFGs already present under the chosen container should be deleted or not.
     *
     * @param input
     *        Input for PLMXML import of manufacturing features.
     *
     * @return
     *         Response of the import functionality.        The response contains the FMS file ticket
     *         of the log file, the log file name and a ServiceData that contains errors.
     *         The error conditions and the corresponding error codes are as listed below.
     *         200373 Import is tried to be done from an incomplete PLMXML file.        200374
     *         The preference MEImportMFGsManufacturingFeatureIdAttributeName does not have any
     *         value.        200376 The preference MEImportMFGsManufacturingFeatureIdAttributeName
     *         has incorrect value.        200375 The preference MEImportMFGsManufacturingFeatureIdAttributeName
     *         does not have any value.        200377 The preference MEImportMFGsManufacturingFeatureIdAttributeName
     *         has incorrect value.        200xxx Import has failed for a container.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2013_05::Importexport::AdvancedImportResponse importManufacturingFeatures ( const Teamcenter::Services::Manufacturing::_2013_05::Importexport::AdvancedImportInput&  input ) = 0;


protected:
    virtual ~Importexport() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

