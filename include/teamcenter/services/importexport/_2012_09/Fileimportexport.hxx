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

#ifndef TEAMCENTER_SERVICES_IMPORTEXPORT__2012_09_FILEIMPORTEXPORT_HXX
#define TEAMCENTER_SERVICES_IMPORTEXPORT__2012_09_FILEIMPORTEXPORT_HXX

#include <teamcenter/services/importexport/_2011_06/Fileimportexport.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/importexport/ImportExport_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Importexport
        {
            namespace _2012_09
            {
                class Fileimportexport;

class TCSOAIMPORTEXPORTSTRONGMNGD_API Fileimportexport
{
public:

    struct ImportFromApplicationInputData3;

    /**
     * Structure represents the parameters required to import a requirement specification.
     */
    struct ImportFromApplicationInputData3
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * Transient File write ticket for the file to be imported.
         */
        std::string transientFileWriteTicket;
        /**
         * Application format associated with the file to be imported into system.
         */
        std::string applicationFormat;
        /**
         * Subtype of specification element to be imported.
         */
        std::string createSpecElementType;
        /**
         * Type of the specification to be imported. RequirementSpec is default.
         */
        std::string specificationType;
        /**
         * Flag to determine live or non live import.
         */
        bool isLive;
        /**
         * BOMLine under which new structure will get imported.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  selectedBomLine;
        /**
         * List of FileMetaData that has the imported file information. One for each imported
         * specification.
         */
        std::vector< Teamcenter::Services::Importexport::_2011_06::Fileimportexport::FileMetaData > fileMetaDatalist;
        /**
         * List of options for import such as keywords. One for each imported specification.
         */
        std::vector< Teamcenter::Services::Importexport::_2011_06::Fileimportexport::ImportExportOptions > importOptions;
        /**
         * Description to be set for an Item.
         */
        std::string specDesc;
    };




    /**
     * This operation imports a Requirement Specification document containing Requirement
     * and Paragraph objects. It creates Requirement / Paragraph objects and associated
     * data (FullText for each created Item to store the content from the document and IMAN_Specification
     * relation between FullText and each created Item). The input structure for this operation
     * contains file meta data information, type of specification elements (SpecElement)
     * to be created, application format of the MS Word document being imported, keyword
     * parsing options to be used during import, live or static import mode to be used for
     * import, option to import as new specification or under the selected BOMLine object
     * and description to be set on the Item once imported.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param inputs
     *        The structure which holds the file meta data, format of the document, type of specification
     *        elements to be created.
     *
     * @return
     *         A list of created objects, one for each successfully imported Requirement Specification.
     *         The following partial error may be returned: 46147   Cannot add the child to the
     *         selected parent since this child type is not valid for parent type. 46180   The child
     *         cannot be added to the selected parent since the parent type is not valid for the
     *         child type.
     *
     */
    virtual Teamcenter::Services::Importexport::_2011_06::Fileimportexport::ImportFromApplicationResponse1 importFromApplication ( const std::vector< Teamcenter::Services::Importexport::_2012_09::Fileimportexport::ImportFromApplicationInputData3 >& inputs ) = 0;


protected:
    virtual ~Fileimportexport() {}
};
            }
        }
    }
}

#include <teamcenter/services/importexport/ImportExport_undef.h>
#endif

