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

#ifndef TEAMCENTER_SERVICES_CORE__2012_09_DATAMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CORE__2012_09_DATAMANAGEMENT_HXX

#include <teamcenter/services/core/_2011_06/Datamanagement.hxx>
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
            namespace _2012_09
            {
                class Datamanagement;

class TCSOACORESTRONGMNGD_API Datamanagement
{
public:

    struct RelateInfoIn;

    /**
     * Information to perform relate operation
     */
    struct RelateInfoIn
    {
        /**
         * parent object to which the created object will be related. This value will be ignored
         * if relate is false. If value is null and relate is true, then a default target will
         * be used based on WsoInsertNoSelectionsPref.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  target;
        /**
         * Name of the property with which the created object will be related to the input target
         * object if defined or the default one.This value will be ignored if relate is false.
         * If value is empty and relate is true, then default relation will be used.
         */
        std::string propertyName;
        /**
         * A relation is created only if this value is true.
         */
        bool relate;
    };




    /**
     * This operation saves the given object and its related objects as new instances. Related
     * objects are identifed using deep copy rules. Optionally,this method relates the new
     * object to the input target object or to a default folder.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Metamodel - Framework to define data model, operations, extensions and for autogeneration
     * of the underlying code for appropriate dispatching. It provides the framework for
     * codeless configuration and codeful customization.
     *
     * @param saveAsInput
     *        The property values to be used for the new objects. The properties passed in should
     *        be defined in SaveAs descriptor.
     *
     * @param relateInfo
     *        The paste options used to relate the newly created object.
     *
     * @return
     *         A list of objects that are created through saveas operation, including children objects.
     *         CreatedList contains objects that are created by SaveAs operation.. It contains GRM
     *         relations created due to paste operation. UpdatedList contains target objects to
     *         which the newly created objects are related. Failure for any element in the input
     *         list is returned as a Partial Error in the ServiceData . The Partial Error includes
     *         the index of the failed element from the input list. 214424: SaveAs action succeeded.
     *         But server could not identify a suitable target object to relate the newly created
     *         object.. 214425:  When item revision is saved as new instance,server relates item
     *         to target folder. Presence of this error code indicates that server could not paste
     *         item and instead has pasted the created item revision. 214426: SaveAs operation on
     *         that specifc object has failed.
     *
     */
    virtual Teamcenter::Services::Core::_2011_06::Datamanagement::SaveAsObjectsResponse saveAsObjectAndRelate ( const std::vector< Teamcenter::Services::Core::_2011_06::Datamanagement::SaveAsIn >& saveAsInput,
        const std::vector< Teamcenter::Services::Core::_2012_09::Datamanagement::RelateInfoIn >& relateInfo ) = 0;


protected:
    virtual ~Datamanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/core/Core_undef.h>
#endif

