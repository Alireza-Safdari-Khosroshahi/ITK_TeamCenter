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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING_IMPORTEXPORTSERVICE_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING_IMPORTEXPORTSERVICE_HXX

#include <teamcenter/services/manufacturing/_2010_09/Importexport.hxx>
#include <teamcenter/services/manufacturing/_2013_05/Importexport.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/manufacturing/Manufacturing_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Manufacturing
        {
            class ImportexportService;

/**
 * Contains import-export services
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoamanufacturingstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoamanufacturingtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAMANUFACTURINGSTRONGMNGD_API ImportexportService
    : public Teamcenter::Services::Manufacturing::_2010_09::Importexport,
             public Teamcenter::Services::Manufacturing::_2013_05::Importexport
{
public:
    static ImportexportService* getService( Teamcenter::Soa::Client::Connection* );


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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ImportexportService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

