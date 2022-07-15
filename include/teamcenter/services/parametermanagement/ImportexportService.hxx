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

#ifndef TEAMCENTER_SERVICES_PARAMETERMANAGEMENT_IMPORTEXPORTSERVICE_HXX
#define TEAMCENTER_SERVICES_PARAMETERMANAGEMENT_IMPORTEXPORTSERVICE_HXX

#include <teamcenter/services/parametermanagement/_2012_02/Importexport.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/parametermanagement/ParameterManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Parametermanagement
        {
            class ImportexportService;

/**
 * The <i>ImportExport</i> service provides operations to communicate the parameter
 * data between Teamcenter and third party sides. The operations in this service allow
 * export of parameter definitions, parameter values and computed values/addresses from
 * Teamcenter to generate Flash files; and allow import of memory address and formula
 * information into Teamcenter to update the existing business objects, such as <b>ParmGrpDevRevision</b>,
 * <b>Ccd0MemoryLayoutRevision</b> and <b>Ccd0OverrideContRevision</b>.
 * <br>
 * The <i>ImportExport</i> service can be used for the following use cases:
 * <br>
 * <ul>
 * <li type="disc">Generate Flash files from <b>ProductVariantIntent</b>
 * </li>
 * <li type="disc">Generate Flash files from <b>Configured Parameter Project</b>
 * </li>
 * <li type="disc">Import the memory address and formula information into <b>Parameter
 * Project</b>/<b>Dictionary</b>
 * </li>
 * <li type="disc">Import the memory address and formula information into <b>Memory
 * Layout</b>
 * </li>
 * <li type="disc">Import the memory address and formula information into <b>Override
 * Container</b>
 * </li>
 * </ul>
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoaparametermanagementstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoaparametermanagementtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAPARAMETERMANAGEMENTSTRONGMNGD_API ImportexportService
    : public Teamcenter::Services::Parametermanagement::_2012_02::Importexport
{
public:
    static ImportexportService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation exports the parameter data (parameter definitions, parameter values,
     * computed values and computed address) for each ParmDataInputForExport supplied. The
     * ParmDataInputForExport contains the selected business objects and related information
     * such as memory layout, override container, export purpose, dataset, and form.  The
     * selected object can be <b>ProductVariantIntent</b> or <b>Configured Parameter Project</b>.
     * When multiple objects are passed, they need to be of the same type only. The dataset
     * shall be a sub type of <b>Ccd0ParmFile</b>. If the save flag is true, the operation
     * would create a new dataset containing the exported parameter data and attach the
     * dataset to the selected business objects with the relation <b>Ccd0HasOutputFiles</b>.
     * If a duplicate dataset (name and type are same) is found in Teamcenter and the override
     * flag is true, the operation would overwrite the existing dataset.
     * <br>
     * <br>
     * Note: Using this operation, customers need to define a sub type of <b>Ccd0ParmFile
     * </b>for export and provide the implementation to overwrite the method <i>Ccd0ParmFile::ccd0generateFile()</i>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use Case1: Generate Flash files from ProductVariantIntent/Configured Parameter
     * Project</b>.
     * <br>
     * You can generate Flash files using <i>exportParmData</i> operations by setting the
     * <code>purposeString</code> as FlashFile in the structure <code>inputForExportDataAndOptions</code>.
     * <br>
     * <br>
     * <b>Use Case2: Create new datasets containing the exported parameter data</b>.
     * <br>
     * You can create new datasets containing the exported parameter data. In the structure
     * <code>inputForExportDataAndOptions</code>, you need to set <code>saveFlag</code>
     * as true and provide the prefix name. These new creation datasets will be attached
     * to the selected business objects with the relation <b>Ccd0HasOutputFiles</b>. Meanwhile,
     * new form instances including the input attribute values will be populated and attached
     * to the datasets with the relation <b>Ccd0HasOutputFiles</b>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Calibration and Configuration Data Management - Calibration and Configuration Data
     * Management
     *
     * @param inputForExportDataAndOptions
     *        Structures containing the details of the selected objects and the related information
     *        for export.
     *
     * @return
     *         The exported business objects and populated datasets (only if the save flag is true)
     *         are returned via <code>ExportParmDataResponse</code>. If the input parameters are
     *         invalid, the errors are returned in <code>ServiceData</code>. Following are some
     *         possible errors returned in ServiceData:
     *         <br>
     *         <ul>
     *         <li type="disc">248130 The retrieval of the parameter values from the Configured
     *         Project has failed.
     *         </li>
     *         <li type="disc">248131 The retrieval of the records from the Override Container has
     *         failed.
     *         </li>
     *         <li type="disc">248132 The processing of the Memory Content object has failed for
     *         the Memory Layout
     *         </li>
     *         <li type="disc">248133 The retrieval of the start address from the Memory Block object
     *         has failed for the Memory Layout
     *         </li>
     *         <li type="disc">248134 The retrieval of the start address from Memory Layout has
     *         failed.
     *         </li>
     *         <li type="disc">248135 The retrieval of Child Memory Blocks from Parent Memory Blocks
     *         has failed for the Memory Layout
     *         </li>
     *         <li type="disc">248136 The retrieval of Memory Records from set of Memory Blocks
     *         of Memory Layout has failed.
     *         </li>
     *         <li type="disc">248137 The loading of Memory Blocks or Records of Memory Layout has
     *         failed.
     *         </li>
     *         <li type="disc">248139 The processing of the Parameter Value object has failed because
     *         its Master Parameter Definition Revision was not found.
     *         </li>
     *         <li type="disc">248140 The computation of an address for the Parameter Value object
     *         has failed.
     *         </li>
     *         <li type="disc">248141 Parameter Definition Revision does not have a Conversion rule.
     *         Failed to compute ECU Internal value.
     *         </li>
     *         <li type="disc">248143 The retrieval of values from the Parameter Value object has
     *         failed.
     *         </li>
     *         <li type="disc">248144 The flash file generation has failed.
     *         </li>
     *         <li type="disc">248145 The selected object is not a valid selection for parameter
     *         export.
     *         </li>
     *         <li type="disc">248146 The selected objects in the list are not of the same type.
     *         </li>
     *         <li type="disc">248147 The variant  is invalid.
     *         </li>
     *         <li type="disc">248148 The revision rule is invalid.
     *         </li>
     *         <li type="disc">248149 The input dataset is invalid. It should be a sub type of <b>Ccd0ParmFile</b>.
     *         </li>
     *         <li type="disc">248150 The selected object is not a valid Memory Layout object.
     *         </li>
     *         <li type="disc">248151 The selected object is not a valid Override Container object.
     *         </li>
     *         <li type="disc">248152 The <i>generateFile</i> method is not overridden by the custom
     *         library.
     *         </li>
     *         <li type="disc">248196 The selected project contains variant data. Therefore a Variant
     *         Rule configuration is required in order for the operation to perform.
     *         </li>
     *         <li type="disc">248197 The Architecture Breakdown Element of the selected project
     *         contains multiple part solutions. Projects without variant data should have only
     *         one part solution for one Architecture Breakdown Element.
     *         </li>
     *         <li type="disc">248199 The provided prefix has made the exported file name too long.
     *         The file name has been truncated to the allowed limit.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Parametermanagement::_2012_02::Importexport::ExportParmDataResponse exportParmData ( const std::vector< Teamcenter::Services::Parametermanagement::_2012_02::Importexport::ParmDataInputForExport >& inputForExportDataAndOptions ) = 0;

    /**
     * This operation imports the memory address and formula information from a user specified
     * file into the selected business object. The selection object can be <b>Parameter
     * Project </b>or <b>Dictionary</b> or <b>Memory Layout</b> or <b>Override Container</b>
     * or <b>ProductVariantIntent</b>. If the save flag is true, the operation would create
     * a new dataset containing the input file and attach the dataset to the selected object
     * with the relation <b>Ccd0HasInputSource</b>.
     * <br>
     * <br>
     * Note: Using this operation, customers need to define a sub type of <b>Ccd0ParmFile</b>
     * for import and provide the implementation to overwrite the method <i>Ccd0ParmFile::ccd0Parse()</i>.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use case1:  Import the memory address and formula information into Parameter Project/Dictionary</b>
     * <br>
     * You can update the existing parameter memory address and the existing parameter formula
     * in a <b>Parameter Project</b>/<b>Dictionary</b> using <i>importParmData</i> operation.
     * <br>
     * <br>
     * <b>Use case2:  Import the memory address and formula information into Memory Layout</b>
     * <br>
     * You can update the existing parameter memory address and the existing parameter formula
     * in a <b>Memory Layout</b> using <i>importParmData</i> operation.
     * <br>
     * <br>
     * <b>Use case3:  Import the memory address and formula information into Override Container</b>
     * <br>
     * You can update the existing override memory address and the existing override formula
     * in an <b>Override Container</b> using <i>importParmData</i> operation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Calibration and Configuration Data Management - Calibration and Configuration Data
     * Management
     *
     * @param inputImportDataAndOptions
     *        Structures containing the details of the selected objects and the related information
     *        for import.
     *
     * @return
     *         The imported business objects and populated datasets (only if the <code>save</code>
     *         flag is true) are returned via <code>ImportParmDataResponse</code>.  If the input
     *         parameters are invalid, the errors are returned in <code>ServiceData</code>.
     *         <br>
     *         <ul>
     *         <li type="disc">248153 The parameter is not present in the selected project breakdown.
     *         </li>
     *         <li type="disc">248154 The Memory Layout is not associated to the selected breakdown.
     *         </li>
     *         <li type="disc">248155 The start address of Memory Layout is not updated though it
     *         is different than Teamcenter data. Select the overwrite option during import to update
     *         the start address.
     *         </li>
     *         <li type="disc">248156 The Memory Layout could not be updated.
     *         </li>
     *         <li type="disc">248157 The start address of Memory Layout does not match with the
     *         Teamcenter data.
     *         </li>
     *         <li type="disc">248158 The parameter is already associated to a different Memory
     *         Layout. It cannot be associated to thise Memory Layout.
     *         </li>
     *         <li type="disc">248159 The parameter not associated to any Memory Layout. It is automatically
     *         associated to the Memory Layout.
     *         </li>
     *         <li type="disc">248160 No Override Container is associated with the selected project
     *         breakdown.
     *         </li>
     *         <li type="disc">248161 The Override Container associated with the selected project
     *         breakdown cannot be modified.
     *         </li>
     *         <li type="disc">248162 The overridden offset address for the parameter cannot be
     *         overridden because the Override Record object is not modifiable.
     *         </li>
     *         <li type="disc">248163 The Override Container associated to the selected project
     *         cannot be retrieved.
     *         </li>
     *         <li type="disc">248164 An error has occurred while creating and associating the Override
     *         Container to the selected project.
     *         </li>
     *         <li type="disc">248165 An error has occurred while updating the Conversion Rule:
     *         updates are allowed only to formula constants.
     *         </li>
     *         <li type="disc">248166 The parameter is not present in the selected parameter dictionary.
     *         </li>
     *         <li type="disc">248167 The Conversion Rule for the parameter cannot be updated.
     *         </li>
     *         <li type="disc">248168 The parameter cannot be updated.
     *         </li>
     *         <li type="disc">248169 The parameter is released. Create a new revision to update
     *         this parameter.
     *         </li>
     *         <li type="disc">248170 The Conversion Rule for the parameter does not exist. Create
     *         a new Conversion Rule and associate it based on the input import file.
     *         </li>
     *         <li type="disc">248171 An error has occurred while retrieving the projects for the
     *         selected Memory Layout.
     *         </li>
     *         <li type="disc">248172 An error has occurred while creating the Memory Layout.
     *         </li>
     *         <li type="disc">248173 An error has occurred while updating the offset address for
     *         the parameter associated with the Memory.
     *         </li>
     *         <li type="disc">248174 An error has occurred while creating the offset address record
     *         for the parameter associated with the Memory Layout.
     *         </li>
     *         <li type="disc">248175 An error has occurred while creating the override offset address
     *         record for the parameter associated with the Memory Layout.
     *         </li>
     *         <li type="disc">248176 The selected project does not have an override container record
     *         for the parameter associated with the Memory Layout.
     *         </li>
     *         <li type="disc">248177 An error has occurred while updating the override offset address
     *         record for the parameter associated with the Memory Layout.
     *         </li>
     *         <li type="disc">248178 An error has occurred while creating a table Conversion Rule
     *         for the parameter.
     *         </li>
     *         <li type="disc">248179 An error has occurred while creating the formula of the Conversion
     *         Rule for the parameter.
     *         </li>
     *         <li type="disc">248180 An error has occurred while updating the override formula
     *         of the Conversion Rule for the parameter.
     *         </li>
     *         <li type="disc">248181 An error has occurred while creating a Conversion Rule for
     *         the parameter.
     *         </li>
     *         <li type="disc">248182 No dictionary is associated with the project.
     *         </li>
     *         <li type="disc">248183 An internal error has occurred while importing the parameter
     *         definition data from the selected files.
     *         </li>
     *         <li type="disc">248184 The dataset is empty: no file is associated with it.
     *         </li>
     *         <li type="disc">248185 An invalid file type was selected for the Import operation.
     *         The selected file should match the selected Dataset type.
     *         </li>
     *         <li type="disc">248186 The selected import file is not a valid file.
     *         </li>
     *         <li type="disc">248187 The selected import file type is not supported by the Import
     *         operation.
     *         </li>
     *         <li type="disc">248188 An invalid Project was selected. Valid Projects are associated
     *         with a dictionary.
     *         </li>
     *         <li type="disc">248189 An error has occurred while retrieving the parameter definition
     *         from the dictionary.
     *         </li>
     *         <li type="disc">248190 The selected purpose is not supported by the parameter import
     *         process.
     *         </li>
     *         <li type="disc">248191 The entry is not a valid Dataset name.
     *         </li>
     *         <li type="disc">248192 The selected object is not a valid selection for the parameter
     *         data import.
     *         </li>
     *         <li type="disc">248193 An error has occurred while retrieving the memory records
     *         for the associated memory maps.
     *         </li>
     *         <li type="disc">248194 An error has occurred while creating the Override Container
     *         record.
     *         </li>
     *         <li type="disc">248195 Import of values is not supported.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Parametermanagement::_2012_02::Importexport::ImportParmDataResponse importParmData ( const std::vector< Teamcenter::Services::Parametermanagement::_2012_02::Importexport::ParmDataInputForImport >& inputImportDataAndOptions ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ImportexportService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/parametermanagement/ParameterManagement_undef.h>
#endif

