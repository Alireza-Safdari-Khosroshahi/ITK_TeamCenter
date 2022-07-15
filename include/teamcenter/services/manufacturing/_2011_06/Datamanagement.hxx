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

#ifndef TEAMCENTER_SERVICES_MANUFACTURING__2011_06_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_MANUFACTURING__2011_06_DATAMANAGEMENT_HXX

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
            namespace _2011_06
            {
                class Datamanagement;

class TCSOAMANUFACTURINGSTRONGMNGD_API Datamanagement
{
public:

    struct ContextGroup;
    struct OpenContextInfo;
    struct OpenContextInput;
    struct OpenContextsResponse;
    struct OpenViewsResponse;

    /**
     * A group of contexts opened by openContexts operation
     */
    struct ContextGroup
    {
        /**
         * A vector with information on each opened context in the group
         */
        std::vector< Teamcenter::Services::Manufacturing::_2011_06::Datamanagement::OpenContextInfo > contexts;
        /**
         * The container of the context group (CC). This is relevant only in case the context
         * to open is a CC object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  collaborationContext;
    };

    /**
     * Contains information on an opened context
     */
    struct OpenContextInfo
    {
        /**
         * The opened context (The top line of the created window)
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  context;
        /**
         * The object which was passed to the method as input if this context was opened directly.
         * If this context was opened as an outcome of another context or if CC was opened then
         * this will be NULL
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * A vector with the top lines of the opened views (OG windows)
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > views;
        /**
         * The structure context containing this context. This is relevant only in case the
         * context to open is a CC or SC object
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  structureContext;
    };

    /**
     * Input for openContexts operation
     */
    struct OpenContextInput
    {
        /**
         * The object to open
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  object;
        /**
         * Defines whether to open all connected views
         */
        bool openViews;
        /**
         * Defines whether to open also associated contexts
         */
        bool openAssociatedContexts;
        /**
         * Defines additional context settings such as configuration (revision rule, variant
         * rule, IC), show-unconfigured options, etc.
         */
        Teamcenter::Services::Manufacturing::_2009_10::Datamanagement::CreateInput contextSettings;
    };

    /**
     * Response object for openContexts operation
     */
    struct OpenContextsResponse
    {
        /**
         * A vector with information of the method output
         */
        std::vector< Teamcenter::Services::Manufacturing::_2011_06::Datamanagement::ContextGroup > output;
        /**
         * The operation ServiceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Response object for openViews operation
     */
    struct OpenViewsResponse
    {
        /**
         * A vector with the opened views (the top lines of the created OG windows)
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > views;
        /**
         * The operation ServiceData
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This method is used to close contexts (base view windows). For each context, this
     * method closes the base view window and all the open views (OG windows) associated
     * to it
     *
     * @param contexts
     *        A vector with the contexts (top lines of the windows) to close
     *
     * @return
     *         The service data of the operation
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData closeContexts ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& contexts ) = 0;

    /**
     * This method is used to close opened views (OG windows).
     *
     * @param structureContext
     *        The structure context containing the views. Can be NULL if not using structire context.
     *
     * @param views
     *        A vector with the open views (top lines of the OG windows) to close
     *
     * @return
     *         The service data of the operation
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData closeViews ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  structureContext,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& views ) = 0;

    /**
     * This method is used to open existing objects in new base view windows.
     *
     * @param input
     *        A list of OpenContextInput representing the objects to open
     *
     * @return
     *         The response of the operation
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2011_06::Datamanagement::OpenContextsResponse openContexts ( const std::vector< Teamcenter::Services::Manufacturing::_2011_06::Datamanagement::OpenContextInput >& input ) = 0;

    /**
     * This method is used to open views (OG windows) for an already opened context (base
     * view window).
     *
     * @param context
     *        The context (top line of the base view window) for which the views will be opened
     *
     * @param structureContext
     *        The structure context containing the context. This can be null
     *
     * @param views
     *        A vector with the views to open
     *
     * @return
     *         The response of the operation
     *
     */
    virtual Teamcenter::Services::Manufacturing::_2011_06::Datamanagement::OpenViewsResponse openViews ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  context,
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  structureContext,
        const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& views ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/manufacturing/Manufacturing_undef.h>
#endif

