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

#ifndef TEAMCENTER_SERVICES_BUSINESSMODELER__2008_06_DEEPCOPYRULES_HXX
#define TEAMCENTER_SERVICES_BUSINESSMODELER__2008_06_DEEPCOPYRULES_HXX

#include <teamcenter/soa/client/model/ItemRevision.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/businessmodeler/BusinessModeler_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Businessmodeler
        {
            namespace _2008_06
            {
                class Deepcopyrules;

class TCSOABUSINESSMODELERSTRONGMNGD_API Deepcopyrules
{
public:

    struct DeepCopyData;
    struct DeepCopyInfoKey;
    struct DeepCopyInfoKeyValue;
    struct DeepCopyInfoResponse;

    /**
     * Holds the relavent information regarding applicable deep copy rules.
     */
    struct DeepCopyData
    {
        /**
         * This is a tag representing object on which the deep copy action need to be performed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  otherSideObjectTag;
        /**
         * This is a string representing the name the relation that need to be deep copied.
         */
        std::string relationTypeName;
        /**
         * This is a string representing the new name for the new copy of the object represented
         * by <code>otherSideObjectTag</code>. The value for the <code>newName</code> will be
         * <code>NULL</code> if the <code>action</code> is not <code>CopyAsObject</code> or
         * <code>ReviseAndRelateToLatest</code>.
         */
        std::string newName;
        /**
         * This is an integer representing the action to be performed on the object represented
         * by <code>otherSideObjectTag</code>. The values for action are: <code>CopyAsObjectType
         * = 0, CopyAsRefType = 1, DontCopyType =2, RelateToLatest = 3, ReviseAndRelateToLatest
         * = 4</code>.
         */
        int action;
        /**
         * Boolean representing whether the given item revision is a primary object in the relation
         * that need to be deep copied.
         */
        bool isTargetPrimary;
        /**
         * Boolean representing whether the deep information is from a mandatory deep copy rule
         * configured by the administrator or not.
         */
        bool isRequired;
        /**
         * Boolean representing whether the Properties on  the Relation if any in the Relation
         * that exists between the Primary and the Secondary should be carried forward or not.
         */
        bool copyRelations;
    };

    /**
     * Holds the <b>ItemRevision</b> object tag (<code>itemRevisionTag</code>) and the operation
     * name for which the deep copy information should be obtained.
     */
    struct DeepCopyInfoKey
    {
        /**
         * The <b>ItemRevision</b> object on which the operation is being performed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRevisionTag;
        /**
         * The string representing the operation name (i.e., <code>Revise</code> or <code>SaveAs</code>
         * ).
         */
        std::string operation;
    };

    /**
     * Store key and value pair for DeepCopyData.
     */
    struct DeepCopyInfoKeyValue
    {
        /**
         * Structure representing the key for the Deep Copy Info.
         */
        Teamcenter::Services::Businessmodeler::_2008_06::Deepcopyrules::DeepCopyInfoKey key;
        /**
         * The resultant <code>deepCopyInfo</code> values are returned as a list.
         */
        std::vector< Teamcenter::Services::Businessmodeler::_2008_06::Deepcopyrules::DeepCopyData > deepCopyInfos;
    };

    /**
     * Holds the response for the <code>getDeepCopyInfo</code> method.
     */
    struct DeepCopyInfoResponse
    {
        /**
         * The resultant <code>deepCopyInfo</code> values are returned as a list.
         */
        std::vector< Teamcenter::Services::Businessmodeler::_2008_06::Deepcopyrules::DeepCopyInfoKeyValue > values;
        /**
         * Contains the status of the operation. This operation does not return any error code
         * but propagates the error code from lower level functions.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * Deep copy rules define whether objects belonging to a business object instance can
     * be copied when a user performs a save as or revise operation on that instance. Deep
     * copy rules can be applied to any business object type, and are inherited by children
     * business object types. This operation gets the applicable deep copy rules for the
     * given list of objects and the operation specified for each object.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * BMIDE (Server) - Set of services provided by BMIDE that allow efficiently underyling
     * capabilities to develop/modify business objects
     *
     * @param keys
     *        List of itemRevision object tag and the operation name for which deep copy information
     *        is needed.
     *
     * @return
     *         A structure containing the values of the applicable deep copy rules and status of
     *         the operation. This operation does not return any error other than propagating the
     *         errors received from low level functions which are called from within the operation.
     *
     */
    virtual Teamcenter::Services::Businessmodeler::_2008_06::Deepcopyrules::DeepCopyInfoResponse getDeepCopyInfo ( const std::vector< Teamcenter::Services::Businessmodeler::_2008_06::Deepcopyrules::DeepCopyInfoKey >& keys ) = 0;


protected:
    virtual ~Deepcopyrules() {}
};
            }
        }
    }
}

#include <teamcenter/services/businessmodeler/BusinessModeler_undef.h>
#endif

