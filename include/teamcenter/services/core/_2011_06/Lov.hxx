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

#ifndef TEAMCENTER_SERVICES_CORE__2011_06_LOV_HXX
#define TEAMCENTER_SERVICES_CORE__2011_06_LOV_HXX

#include <teamcenter/soa/client/model/ListOfValues.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            namespace _2011_06
            {
                class Lov;

class TCSOACORESTRONGMNGD_API Lov
{
public:

    struct LOVAttachment;
    struct LOVAttachmentsInput;
    struct LOVAttachmentsResponse;

    /**
     * A map of input objects to list of <b>LOVattachments</b> structure.
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> , std::vector< LOVAttachment > > InpoutObjectToLOVAttachmentsMap;

    /**
     * Structure to hold property and its LOV attachment.
     */
    struct LOVAttachment
    {
        /**
         * Name of the property to  which LOV attachment return.
         */
        std::string propName;
        /**
         * Attached LOV object.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ListOfValues>  lov;
    };

    /**
     * A structure holding objects and common properties for which LOV attachments are to
     * be returned.
     */
    struct LOVAttachmentsInput
    {
        /**
         * Instances of any business object for which LOV attachments are being evaluated.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > objects;
        /**
         * Names of common properties for which LOV attachments to be returned for each instance
         * in <code>objects</code>
         */
        std::vector< std::string > properties;
    };

    /**
     * LOV attachments for the given object properties.
     */
    struct LOVAttachmentsResponse
    {
        /**
         * A list of objects and its properties and associated LOV attachments.
         */
        InpoutObjectToLOVAttachmentsMap lovAttachments;
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * Returns valid LOV attachments for the properties of each object passed in as input.
     * It may return LOV or <b>null</b> based on condition validations. If none of the conditions
     * evaluated to be <b>True</b>, then no LOV attachment is returned for the property
     * of an instance.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * List of Values (LOV) - Component to define lists of values and to associate them
     * with attributes and properties.  Associations can be stored in the database (persistent)
     * or independently associated for each Teamcenter session (run time).
     *
     * @param objectStructArray
     *        LOV attachments are evaluated for each property of the structure LOVAttachmentsInut
     *        based on each object in <code>objects</code> list.
     *
     * @return
     *         Returns LOV attachments currently attached to properties.
     *
     *
     * @exception ServiceException
     *           None
     */
    virtual Teamcenter::Services::Core::_2011_06::Lov::LOVAttachmentsResponse getLOVAttachments ( const std::vector< Teamcenter::Services::Core::_2011_06::Lov::LOVAttachmentsInput >& objectStructArray ) = 0;


protected:
    virtual ~Lov() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

