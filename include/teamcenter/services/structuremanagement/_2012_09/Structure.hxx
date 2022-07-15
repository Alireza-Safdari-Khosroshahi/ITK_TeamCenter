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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2012_09_STRUCTURE_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2012_09_STRUCTURE_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/structuremanagement/StructureManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Structuremanagement
        {
            namespace _2012_09
            {
                class Structure;

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API Structure
{
public:

    struct AddInformation;
    struct AddParam;
    struct AddResponse;
    struct ParentChildPair;

    /**
     * BOMLine properties and values.
     */
    typedef std::map< std::string, std::string > BOMLineProperties;

    /**
     * Contains information of the object to be added as a new line. When used by Add operation,
     * only one of the item/itemRev, element and line will be used.
     */
    struct AddInformation
    {
        /**
         * The item to be added. It can be null.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  item;
        /**
         * The item revision to be added. It can be null.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  itemRev;
        /**
         * The BOMView object to be added. It can be null.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  bomView;
        /**
         * The General Design Element object to be added. It can be null.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  element;
        /**
         * The BOMLine object to be pasted as new line. It can be ImanItemLine or GDELine. It
         * can be null.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  line;
        /**
         * A map to hold initial values of BOMLine properties. Occurrence type can be specified
         * here but will be handled specially if used by Add operation.
         */
        BOMLineProperties initialValues;
    };

    /**
     * The input for adding lines.
     */
    struct AddParam
    {
        /**
         * The parent where the objects are added.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  parent;
        /**
         * The information about the objects to be added.
         */
        std::vector< Teamcenter::Services::Structuremanagement::_2012_09::Structure::AddInformation > toBeAdded;
        /**
         * A  bit map of the flags. The lowest bit is reserved for as substitute. If the bit
         * is 1, it means the operation will add the object as substitute, otherwise it as normal
         * line. The second lowest bit is for propagating transform matrix, when specified as
         * 1, transform matrix will be propagated from source line to the new line. The third
         * lowest bit is used for pending cut lines. If set, the line will be removed after
         * being copied.  Other bits are not used.
         */
        int flags;
    };

    /**
     * The response for add operation
     */
    struct AddResponse
    {
        /**
         * The added lines.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > addedLines;
        /**
         * The serviceData object that contains partial errors.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Structure of a pair of parent and child objects for occurrence condition validation.
     */
    struct ParentChildPair
    {
        /**
         * The parent ItemRevision object where to add the child
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parent;
        /**
         * The child ItemRevision or GeneralDesignElement object to be added
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  child;
    };




    /**
     * The operation adds business objects as child lines or substitutes of the specified
     * lines with option to propagate transform matrix. .  The business objects can be item,
     * item revision, General Design Elements, ImanItemLines or GDELines . If the business
     * object to be added is a pending cut line, then the pending cut line will be processed
     * after it is added. . If the business object is a WorkArea object or a line of WorkArea
     * object and the object is to be added to WorkArea structure, then it will be added
     * with predecessor relation. . If the object to be added is a line that contains Incremental
     * Change Elements, the elements will be carried over to the newly created line. . BOMLine
     * property values can be specified for the new line. . Occurrence type can be specified
     * for the newline as one BOMLine property but will be handled specially.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Structure - Provides basic structure maintenance facilities.
     *
     * @param input
     *        The input for the operation which contains the parent where the objects are to be
     *        added, the objects to be added, initial property values, options of the operation.
     *
     * @return
     *         Created lines and service data that contains partial errors.
     *
     */
    virtual Teamcenter::Services::Structuremanagement::_2012_09::Structure::AddResponse add ( const std::vector< Teamcenter::Services::Structuremanagement::_2012_09::Structure::AddParam >& input ) = 0;

    /**
     * The operation is to validate occurrences of specified lines and their substitutes
     * against occurrence conditions with option to validate the whole substructure.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User imports a structure which has some substitutes and wants to validate the structure
     * against occurrence conditions.  Invoke the operation by passing in the root line
     * and the flag for recursive validation. Failed <b>BOMLine</b> validations are returned
     * in the <code>ServiceData</code> object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Structure - Provides basic structure maintenance facilities.
     *
     * @param lines
     *        The <b>BOMLine</b> that the validation will be performed.
     *
     * @param flag
     *        A flag of int type to tell if the operation will be recursive or not, 0 means no,
     *        1 means yes.
     *        <br>
     *        Note: when doing recursive validation, it will not load unloaded children.
     *
     * @return
     *         Partial Errors are returned in the <code>ServiceData</code> for any failed validation.
     *         The Partial Error will have the <b>BOMLine</b> object for the failure.
     *         <br>
     *         <ul>
     *         <li type="disc">214503: Iindicates the line is invalid.
     *         </li>
     *         <li type="disc">214504: Indicates the line has invalid substitute.
     *         </li>
     *         <li type="disc">43149: No revision for validation based on the preference <b>PS_Default_Rev_For_Occ_Cond_Validation</b>
     *         can be found. Please adjust the preference value.
     *         </li>
     *         <li type="disc">43150: The child object has failed the validation of a condition.
     *         </li>
     *         <li type="disc">43151: The type of the child item is not compatible to the type of
     *         the parent item.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData validateOccurrenceConditions ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  >& lines,
        int flag ) = 0;

    /**
     * The operation is to validate parent and child objects against occurrence conditions.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User invokes the operation to validate against occurrence conditions before creating
     * two occurrences by using an <b>ItemRevision</b> as parent for the two occurrences
     * and a <b>General Design Element</b> object as one child and another <b>ItemRevision</b>
     * as another child.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Structure - Provides basic structure maintenance facilities.
     *
     * @param input
     *        The parent child pairs to validate occurrence conditions
     *
     * @return
     *         Partial Errors are returned in the <code>ServiceData</code> for any failed validation..
     *         <br>
     *         <ul>
     *         <li type="disc">43149: No revision for validation based on the preference <b>PS_Default_Rev_For_Occ_Cond_Validation</b>
     *         can be found. Please adjust the preference value.
     *         </li>
     *         <li type="disc">43150: The child object has failed the validation of a condition.
     *         </li>
     *         <li type="disc">43151: The type of the child item is not compatible to the type of
     *         the parent item.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData validateParentChildConditions ( const std::vector< Teamcenter::Services::Structuremanagement::_2012_09::Structure::ParentChildPair >& input ) = 0;


protected:
    virtual ~Structure() {}
};
            }
        }
    }
}

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

