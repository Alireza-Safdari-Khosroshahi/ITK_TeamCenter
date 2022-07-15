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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2013_05_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2013_05_DATAMANAGEMENT_HXX

#include <teamcenter/services/manufacturing/_2009_10/Datamanagement.hxx>
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
                class Datamanagement;

class TCSOAMANUFACTURINGSTRONGMNGD_API Datamanagement
{
public:

    struct Data;
    struct AttributeDetailsStruct;
    struct ObjectAttributesInput;
    struct SyncStudyInput;
    struct SyncStudyResponse;

    /**
     * The structure specifies details of the attribute value.
     */
    struct Data
    {
        /**
         * Type of the data. Valid types are "Boolean", "Character", "Integer", "Double", "String",
         * "Tag" and "Date". Corresponding list in this structure need to be populated based
         * on the data type string.
         */
        std::string dataType;
        /**
         * The list of Boolean values.
         */
        std::vector< bool > boolAttributes;
        /**
         * The string representing the list of characters. Each character in the string is a
         * value of the attribute.
         */
        std::string charAttributes;
        /**
         * The list of integer values.
         */
        std::vector< int > integerAttributes;
        /**
         * The list of double values.
         */
        std::vector< double > doubleAttributes;
        /**
         * The list of string values.
         */
        std::vector< std::string > stringAttributes;
        /**
         * The list of business objects.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > tagAttributes;
        /**
         * The list of dates.
         */
        std::vector< Teamcenter::Soa::Common::DateTime > dateAttributes;
    };

    /**
     * The structure specifyies the attributes and its value.
     */
    struct AttributeDetailsStruct
    {
        /**
         * The string representing the name of the valid attribute which needs to be edited.
         */
        std::string attributeName;
        /**
         * The structure specifying details of the attribute value.
         */
        Teamcenter::Services::Manufacturing::_2013_05::Datamanagement::Data attributeValueDetails;
    };

    /**
     * The input structure contains object(s) to be edited and the details of the attributes
     * or relations which need to be edited.
     */
    struct ObjectAttributesInput
    {
        /**
         * The business object representing the <b>BOM line</b>. Attributes of the objects attached
         * to this <b>BOM line</b> will be edited.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * The business object attached to the <b>BOM line</b>. Attributes of this object are
         * edited.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  attachedObject;
        /**
         * List of the structure attributeDetailsStruct specifying the attributes and their
         * value.
         */
        std::vector< Teamcenter::Services::Manufacturing::_2013_05::Datamanagement::AttributeDetailsStruct > attributeDetails;
    };

    /**
     * The Mfg0BvrStudy objects to synchronize and the direction to synchronize (to/from
     * the study).
     */
    struct SyncStudyInput
    {
        /**
         * The Mfg0BvrStudy objects to synchronize
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  study;
        /**
         * The direction to synhronize (true = from BOP, false = to BOP)
         */
        bool direction;
    };

    /**
     * The FMS file ticket to the log file for the study synchronization.
     */
    struct SyncStudyResponse
    {
        /**
         * The fmd ticket to the log file
         */
        std::string logFileTicket;
        /**
         * Standard Service Data
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This service operation creates the attachment objects for a business object(s).
     * <br>
     * The operation considers the Incremental Change applied on the window of the object
     * for which attachment is to be created.
     * <br>
     * The operation takes following inputs.
     * <br>
     * <ul>
     * <li type="disc"><b>clientId</b> - Unique client Identifier.
     * </li>
     * <li type="disc"><b>context</b> - The business objects of the <b>BOM Line</b>. The
     * IC applied on the window of this line is considered while creating the attachment.
     * </li>
     * <li type="disc"><b>target</b> - The business object which is used as primary object
     * to connect the newly created object.
     * </li>
     * <li type="disc"><b>relation name</b> - The name of the relation used to connect the
     * target.
     * </li>
     * <li type="disc"><b>data</b> - Input data for create operation.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MPP - Core objects and relationships used by the Manufacturing Process Planner application.
     *
     * @param input
     *        A list of CreateIn objects representing the Create Input for Business Objects to
     *        be created.
     *
     * @return
     *         Contains a list of tags representing the objects that were created. Any failure will
     *         be returned with client id mapped to error message in the ServiceData list of partial
     *         errors. The possible errors reported are:
     *         <br>
     *         <ul>
     *         <li type="disc"><b>251024</b> - The creation of the new object has failed. Please
     *         contact your system administrator.
     *         </li>
     *         <li type="disc"><b>253012</b> - No property is specified.
     *         </li>
     *         <li type="disc"><b>253036</b> - The attribute '%1$' does not exist.
     *         </li>
     *         <li type="disc"><b>251046</b> - The relation type "%1$" is not defined. Please contact
     *         your system administrator.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2009_10::Datamanagement::CreateResponse createAttachments ( const std::vector< Teamcenter::Services::Manufacturing::_2009_10::Datamanagement::CreateIn >& input ) = 0;

    /**
     * This service operation sets the attributes of objects attached to the business object(s).
     * For example, if some attributes of a <b>Form</b> attached to an <b>Item</b> needs
     * to be edited, this operation can be used.
     * <br>
     * The operation considers the Incremental Change applied on the window of the object
     * whose attachment is to be edited.
     * <br>
     * The operation takes the business objects of the <b>BOMLine</b> and its attached object
     * which is to be edited. Along with that, it takes the name(s) of attributes  and their
     * corresponding values to be set.
     * <br>
     * This operation can set multiple attributes of multiple attached objects.
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MPP - Core objects and relationships used by the Manufacturing Process Planner application.
     *
     * @param input
     *        The input structure contains object(s) to be edited and the details of the attributes
     *        or relations which need to be edited.
     *
     * @return
     *         The ServiceData containing partial errors if any. The possible errors reported are:
     *         <br>
     *         <ul>
     *         <li type="disc"><b>253126</b> - The target object "%1$" cannot be modified, because
     *         the user does not have write access.
     *         </li>
     *         <li type="disc"><b>253012</b> - No property is specified.
     *         </li>
     *         <li type="disc"><b>253036</b> - The attribute '%1$' does not exist.
     *         </li>
     *         <li type="disc"><b>251046</b> - The relation type "%1$" is not defined. Please contact
     *         your system administrator.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData setAttributes ( const std::vector< Teamcenter::Services::Manufacturing::_2013_05::Datamanagement::ObjectAttributesInput >& input ) = 0;

    /**
     * This operation synchronizes a Simulation Study with the source BOP structure it is
     * associated with.
     *
     * @param input
     *        The Mfg0BvrStudy objects to synchronize and the direction to synchronize (to/from
     *        the study).
     *
     * @return
     *         The FMS file ticket to the log file for the study synchronization.
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2013_05::Datamanagement::SyncStudyResponse syncStudyAndSource ( const std::vector< Teamcenter::Services::Manufacturing::_2013_05::Datamanagement::SyncStudyInput >& input ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

