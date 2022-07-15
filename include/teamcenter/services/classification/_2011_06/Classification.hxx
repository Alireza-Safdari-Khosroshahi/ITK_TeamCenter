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

#ifndef TEAMCENTER_SERVICES_CLASSIFICATION__2011_06_CLASSIFICATION_HXX
#define TEAMCENTER_SERVICES_CLASSIFICATION__2011_06_CLASSIFICATION_HXX

#include <teamcenter/services/classification/_2007_01/Classification.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/classification/Classification_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Classification
        {
            namespace _2011_06
            {
                class Classification;

class TCSOACLASSIFICATIONSTRONGMNGD_API Classification
{
public:

    struct ClassInfo;
    struct GetLibraryHierarchyResponse;
    struct HierarchyInfoAndOptions;

    /**
     * Structure representing class description in ClassDef structure and business object
     */
    struct ClassInfo
    {
        /**
         * Reference of the class definition structures holding all the class properties for
         * the classes retrieved by this operation
         */
        Teamcenter::Services::Classification::_2007_01::Classification::ClassDef classDefn;
        /**
         * Reference to the business object found associated to this class.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  classBO;
    };

    /**
     * Holds classification objects returned by <code><b>getLibraryHierarchy()</b></code><code>
     * </code>method.
     */
    struct GetLibraryHierarchyResponse
    {
        /**
         * List of class references found for this library
         */
        std::vector< Teamcenter::Services::Classification::_2011_06::Classification::ClassInfo > clsInfo;
        /**
         * Any failures with Key-LOV ID mapped to the error message in the <code><b>ServiceData</b></code>
         * list of partial errors.
         */
        Teamcenter::Soa::Client::ServiceData svcData;
    };

    /**
     * Structure representing the ClassId and options
     */
    struct HierarchyInfoAndOptions
    {
        /**
         * Class ID to be deleted.
         */
        std::string id;
        /**
         * Flag to indicate if the delete operation should be recursively executed on the child
         * classes for the given class.
         */
        bool theRecurseOption;
        /**
         * Flag to indicate if the <b>Views</b> associated with the class being deleted should
         * be removed first. If views exist and this flag does not indicate deleting them first,
         * then a referential integrity error will be generated for the given class.
         */
        bool theViewsOption;
        /**
         * Flag to indicate if the <b>Classification objects (ICO)</b> should be delete first.
         * If ICOs exist and this flag does not indicate deleting them first, then a referential
         * integrity error will be generated for the given class.
         */
        bool theIcosOption;
        /**
         * Flag to indicate if the classified <b>Workspace Objects </b>should be deleted first.
         */
        bool theWSOOption;
        /**
         * Flag to indicate if only the child classes should be deleted.
         */
        bool theChildrenOnlyOption;
        /**
         * Flag to indicate if the operation to should continue on error.
         * <br>
         * <ul>
         * <li type="disc">FALSE: stop on first error
         * </li>
         * <li type="disc">TRUE: continue on error and report all failed objects back in the
         * list of failed objects.
         * </li>
         * </ul>
         */
        bool theIgnoreOption;
    };




    /**
     * Deletes classification class hierarchy based on the classification class identifier.
     * All the child classes can be recursively deleted along with any classification views
     * associated with those classification classes. If needed, the classification objects
     * associated with classification classes & any workspace objects associated with the
     * classification objects can also be deleted
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to delete a classification class hierarchy, or a part of it. User may
     * also need to delete the associated data for these classes such as classification
     * views, classification objects or workspace objects
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param optionsInput
     *        List of structure <code><b>HierarchyInfoAndOptions</b></code> that specifies the
     *        identifiers for classification classes whose class hierarchy needs to be deleted.
     *        It also includes information on the objects that needs to be deleted along with the
     *        classes & also the options for deleting children
     *
     * @return
     *         Any failures with Class ID mapped to the error message are returned in the <code><b>ServiceData</b></code>
     *         list of partial errors.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteChildrenInHierarchy ( const std::vector< Teamcenter::Services::Classification::_2011_06::Classification::HierarchyInfoAndOptions >& optionsInput ) = 0;

    /**
     * Gets the classification class details such as class ID, parent information, child
     * count etc. for the specified library values criteria
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The operation is called when the user queries to get class hierarchy information
     * using the given library values.  The operation is typically used for data dictionary
     * related functionality in classification area, and the library components are created
     * using this feature in Teamcenter. Data dictionary is a central organizational repository
     * for reusable components.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Classification - Application to allow Classification of product data-standard parts.
     *
     * @param libraryValues
     *        The library value is passed as an input to the operation and is used as a search
     *        criteria to get library hierarchy information
     *
     * @return
     *         Returns a <code><b>GetLibraryHierarchyResponse</b></code> structure containing -
     *         <br>
     *         <ul>
     *         <li type="disc">The vector <code><b>classDefn</b></code> which includes the class
     *         information in the hierarchy .
     *         </li>
     *         <li type="disc">Any failures with Classification object ID mapped to the error message
     *         in the <code><b>ServiceData</b></code> list of partial errors.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           The operation will only throw a <code><b>ServiceException</b></code> in cases
     *           when an error condition cannot be handled and an appropriate error message could
     *           not be added to the list of partial errors in <code><b>ServiceData</b></code>.
     */
    virtual Teamcenter::Services::Classification::_2011_06::Classification::GetLibraryHierarchyResponse getLibraryHierarchy ( const std::vector< std::string >& libraryValues ) = 0;


protected:
    virtual ~Classification() {}
};
            }
        }
    }
}

#include <teamcenter/services/classification/Classification_undef.h>
#endif

